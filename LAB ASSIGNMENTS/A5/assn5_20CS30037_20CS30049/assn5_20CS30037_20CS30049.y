%{
    /* 
    Compilers Lab : Assignment 5
    Group Members:
        1. Pranav Nyati (20CS30037)
        2. Shreyas Jena (20CS30049)
    
    
    * Bison specifications
    */

    #include <iostream>
    #include "assn5_20CS30037_20CS30049_translator.h"
    using namespace std;

    extern int yylex();         // From lexer
    void yyerror(string s);     // Function to report errors
    extern char* yytext;        // From lexer, gives the text being currently scanned
    extern int yylineno;        // Used for keeping track of the line number
    extern string prevType;      // Used for storing the last encountered type
%}

%union {
    int intval;             // For an integer value
    char* charval;          // For a char value
    int instr;              // A special type for instruction number, needed in backpatching
    char unaryOp;           // For unary operators
    int numParams;          // For number of parameters to a function
    Expression* expr;       // For an expression
    Statement* stmt;        // For a statement
    Symbol* symptr;           // For a symbol
    SymbolType* symType;    // For the type of a symbol
    Array* arr;             // For arrays
}

/*
    All tokens
*/
%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR GOTO IF INLINE INT LONG REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE BOOL COMPLEX IMAGINARY
%token LEFT_SQR_BRACKET RIGHT_SQR_BRACKET LEFT_PAREN RIGHT_PAREN LEFT_CURLY_BRACE RIGHT_CURLY_BRACE 
%token DOT ARROW INCREMENT DECREMENT BITWISE_AND MULTIPLY ADD SUBTRACT BITWISE_NOR NOT DIVIDE MODULO 
%token LEFT_SHIFT RIGHT_SHIFT LESS_THAN GREATER_THAN LESS_THAN_EQUALS GREATER_THAN_EQUALS EQUALS NOT_EQUALS BITWISE_XOR BITWISE_OR 
%token LOGICAL_AND LOGICAL_OR QUESTION_MARK COLON SEMICOLON ELLIPSIS 
%token ASSIGNMENT MUL_ASSIGNMENT DIV_ASSIGNMENT MOD_ASSIGNMENT ADD_ASSIGNMENT SUB_ASSIGNMENT LSHIFT_ASSIGNMENT RSHIFT_ASSIGNMENT AND_ASSIGNMENT XOR_ASSIGNMENT OR_ASSIGNMENT COMMA HASH

// Identifiers are treated with type Symbol*
%token <symptr> IDENTIFIER

// Integer constants have a type intval
%token <intval> INT_CONSTANT

// Floating constants have a type charval
%token <charval> FLOAT_CONSTANT

// Character constants have a type charval
%token <charval> CHAR_CONSTANT

// String literals have a type charval
%token <charval> STRING_LITERAL

// The start symbol is translation_unit
%start translation_unit

// Helps in removing the dangling else problem
%right THEN ELSE

// Non-terminals of type unaryOp (unary operator)
%type <unaryOp> unary_operator

// Non-terminals of type numParams (number of parameters)
%type <numParams> argument_expression_list argument_expression_list_opt

// Non-terminals of type expr (denoting expressions)
%type <expr> 
        expression
        primary_expression 
        multiplicative_expression
        additive_expression
        shift_expression
        relational_expression
        equality_expression
        and_expression
        exclusive_or_expression
        inclusive_or_expression
        logical_and_expression
        logical_or_expression
        conditional_expression
        assignment_expression
        expression_statement

// Non-terminals of type stmt (denoting statements)
%type <stmt>
        statement
        compound_statement
        loop_statement
        selection_statement
        iteration_statement
        labeled_statement 
        jump_statement
        block_item
        block_item_list
        block_item_list_opt

// The pointer non-terminal is treated with type symbolType
%type <symType> pointer

// Non-terminals of type symp (Symbol*)
%type <symptr> constant initializer
%type <symptr> direct_declarator init_declarator declarator

// Non-terminals of type arr
%type <arr> postfix_expression unary_expression cast_expression

// Auxiliary non-terminal M of type instr to help in backpatching
%type <instr> M

// Auxiliary non-terminal N of type stmt to help in control flow statements
%type <stmt> N

%%

primary_expression: 
        IDENTIFIER
        {
            $$ = new Expression();  // Create new expression
            $$->addr = $1;           // Store pointer to entry in the symbol table
            $$->type = "non_bool";
        }
        | constant
        {
            $$ = new Expression();  // Create new expression
            $$->addr = $1;           // Store pointer to entry in the symbol table
        }
        | STRING_LITERAL
        {
            $$ = new Expression();  // Create new expression
            $$->addr = SymbolTable::gentemp(new SymbolType("ptr"), $1);  // Create a new temporary, and store the value in that temporary
            $$->addr->sym_type->arrElementType = new SymbolType("char");
        }
        | LEFT_PAREN expression RIGHT_PAREN
        {
            $$ = $2;    // Simple assignment
        }
        ;

constant: 
        INT_CONSTANT
        {
            $$ = SymbolTable::gentemp(new SymbolType("int"), to_string($1));   // Create a new temporary, and store the value in that temporary
            emit("=", $$->name, $1);
        }
        | FLOAT_CONSTANT
        {
            $$ = SymbolTable::gentemp(new SymbolType("float"), string($1));     // Create a new temporary, and store the value in that temporary
            emit("=", $$->name, string($1));
        }
        | CHAR_CONSTANT
        {
            $$ = SymbolTable::gentemp(new SymbolType("float"), string($1));     // Create a new temporary, and store the value in that temporary
            emit("=", $$->name, string($1));
        }
        ;

postfix_expression: 
        primary_expression
        {
            $$ = new Array();           // Create a new Array
            $$->array = $1->addr;        // Store the location of the primary expression
            $$->type = $1->addr->sym_type;   // Update the type
            $$->addr = $$->array;
        }
        | postfix_expression LEFT_SQR_BRACKET expression RIGHT_SQR_BRACKET
        {
            $$ = new Array();               // Create a new Array
            $$->type = $1->type->arrElementType;   // Set the type equal to the element type
            $$->array = $1->array;          // Copy the base
            $$->addr = SymbolTable::gentemp(new SymbolType("int"));  // Store address of new temporary
            $$->arr_type = "arr";              // Set atype to "arr"

            if($1->arr_type == "arr") {        // If we have an "arr" type then, multiply the size of the sub-type of Array with the expression value and add
                Symbol* sym = SymbolTable::gentemp(new SymbolType("int"));
                int sz = sizeOfType($$->type);
                emit("*", sym->name, $3->addr->name, to_string(sz));
                emit("+", $$->addr->name, $1->addr->name, sym->name);
            }
            else {                          // Compute the size
                int sz = sizeOfType($$->type);
                emit("*", $$->addr->name, $3->addr->name, to_string(sz));
            }
        }
        | postfix_expression LEFT_PAREN argument_expression_list_opt RIGHT_PAREN
        {   
            // Corresponds to calling a function with the function name and the appropriate number of parameters
            $$ = new Array();
            $$->array = SymbolTable::gentemp($1->type);
            emit("call", $$->array->name, $1->array->name, to_string($3));
        }
        | postfix_expression DOT IDENTIFIER
        { /* Ignored */ }
        | postfix_expression ARROW IDENTIFIER
        { /* Ignored */ }
        | postfix_expression INCREMENT
        {   
            $$ = new Array();
            $$->array = SymbolTable::gentemp($1->array->sym_type);      // Generate a new temporary
            emit("=", $$->array->name, $1->array->name);            // First assign the old value
            emit("+", $1->array->name, $1->array->name, "1");       // Then add 1
        }
        | postfix_expression DECREMENT
        {
            $$ = new Array();
            $$->array = SymbolTable::gentemp($1->array->sym_type);      // Generate a new temporary
            emit("=", $$->array->name, $1->array->name);            // First assign the old value
            emit("-", $1->array->name, $1->array->name, "1");       // Then subtract 1
        }
        | LEFT_PAREN type_name RIGHT_PAREN LEFT_CURLY_BRACE initializer_list RIGHT_CURLY_BRACE
        { /* Ignored */ }
        | LEFT_PAREN type_name RIGHT_PAREN LEFT_CURLY_BRACE initializer_list COMMA RIGHT_CURLY_BRACE
        { /* Ignored */ }
        ;

argument_expression_list_opt: 
        argument_expression_list
        {
            $$ = $1;    // Assign $1 to $$
        }
        | %empty
        {
            $$ = 0;     // No arguments, just equate to zero
        }
        ;

argument_expression_list: 
        assignment_expression
        {
            $$ = 1;                         // consider one argument
            emit("param", $1->addr->name);   // emit parameter
        }
        | argument_expression_list COMMA assignment_expression
        {
            $$ = $1 + 1;                    // consider one more argument, so add 1
            emit("param", $3->addr->name);   // emit parameter
        }
        ;

unary_expression: 
        postfix_expression
        {
            $$ = $1;    // Assign $1 to $$
        }
        | INCREMENT unary_expression
        {
            emit("+", $2->array->name, $2->array->name, "1");   // Add 1
            $$ = $2;    // Assign
        }
        | DECREMENT unary_expression
        {
            emit("-", $2->array->name, $2->array->name, "1");   // Subtract 1
            $$ = $2;    // Assign
        }
        | unary_operator cast_expression
        {
            // Case of unary operator
            $$ = new Array();
            switch($1) {
                case '&':   // Address
                    $$->array = SymbolTable::gentemp(new SymbolType("ptr"));    // Generate a pointer temporary
                    $$->array->sym_type->arrElementType = $2->array->sym_type;                 // Assign corresponding type
                    emit("= &", $$->array->name, $2->array->name);              // Emit the quad
                    break;
                case '*':   // De-referencing
                    $$->arr_type = "ptr";
                    $$->addr = SymbolTable::gentemp($2->array->sym_type->arrElementType);   // Generate a temporary of the appropriate type
                    $$->array = $2->array;                                      // Assign
                    emit("= *", $$->addr->name, $2->array->name);                // Emit the quad
                    break;
                case '+':   // Unary plus
                    $$ = $2;    // Simple assignment
                    break;
                case '-':   // Unary minus
                    $$->array = SymbolTable::gentemp(new SymbolType($2->array->sym_type->type));    // Generate temporary of the same base type
                    emit("= -", $$->array->name, $2->array->name);                              // Emit the quad
                    break;
                case '~':   // Bitwise not
                    $$->array = SymbolTable::gentemp(new SymbolType($2->array->sym_type->type));    // Generate temporary of the same base type
                    emit("= ~", $$->array->name, $2->array->name);                              // Emit the quad
                    break;
                case '!':   // Logical not 
                    $$->array = SymbolTable::gentemp(new SymbolType($2->array->sym_type->type));    // Generate temporary of the same base type
                    emit("= !", $$->array->name, $2->array->name);                              // Emit the quad
                    break;
            }
        }
        | SIZEOF unary_expression
        { /* Ignored */ }
        | SIZEOF LEFT_PAREN type_name RIGHT_PAREN
        { /* Ignored */ }
        ;

unary_operator:
        BITWISE_AND
        {
            $$ = '&';
        }
        | MULTIPLY
        {
            $$ = '*';
        }
        | ADD
        {
            $$ = '+';
        }
        | SUBTRACT
        {
            $$ = '-';
        }
        | BITWISE_NOR
        {
            $$ = '~';
        }
        | NOT
        {
            $$ = '!';
        }
        ;

cast_expression: 
        unary_expression
        {
            $$ = $1;    // Simple assignment
        }
        | LEFT_PAREN type_name RIGHT_PAREN cast_expression
        {
            $$ = new Array();
            $$->array = convertType($4->array, prevType);    // Generate a new symbol of the appropriate type
        }
        ;

multiplicative_expression: 
        cast_expression
        {
            $$ = new Expression();          // Generate new expression
            if($1->arr_type == "arr") {        // atype "arr"
                $$->addr = SymbolTable::gentemp($1->addr->sym_type);  // Generate new temporary
                emit("=[]", $$->addr->name, $1->array->name, $1->addr->name);     // Emit the quad
            }
            else if($1->arr_type == "ptr") {   // atype "ptr"
                $$->addr = $1->addr;          // Assign the symbol table entry
            }
            else {
                $$->addr = $1->array;
            }
        }
        | multiplicative_expression MULTIPLY cast_expression
        {   
            // Indicates multiplication
            if(typecheck($1->addr, $3->array)) {     // Check for type compatibility
                $$ = new Expression();                                                  // Generate new expression
                $$->addr = SymbolTable::gentemp(new SymbolType($1->addr->sym_type->type));    // Generate new temporary
                emit("*", $$->addr->name, $1->addr->name, $3->array->name);               // Emit the quad
            }
            else {
                yyerror("Type Error");
            }
        }
        | multiplicative_expression DIVIDE cast_expression
        {
            // Indicates division
            if(typecheck($1->addr, $3->array)) {     // Check for type compatibility
                $$ = new Expression();                                                  // Generate new expression
                $$->addr = SymbolTable::gentemp(new SymbolType($1->addr->sym_type->type));    // Generate new temporary
                emit("/", $$->addr->name, $1->addr->name, $3->array->name);               // Emit the quad
            }
            else {
                yyerror("Type Error");
            }
        }
        | multiplicative_expression MODULO cast_expression
        {
            // Indicates modulo
            if(typecheck($1->addr, $3->array)) {     // Check for type compatibility
                $$ = new Expression();                                                  // Generate new expression
                $$->addr = SymbolTable::gentemp(new SymbolType($1->addr->sym_type->type));    // Generate new temporary
                emit("%", $$->addr->name, $1->addr->name, $3->array->name);               // Emit the quad
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

additive_expression: 
        multiplicative_expression
        {
            $$ = $1;    // Simple assignment
        }
        | additive_expression ADD multiplicative_expression
        {   
            // Indicates addition
            if(typecheck($1->addr, $3->addr)) {       // Check for type compatibility
                $$ = new Expression();                                                  // Generate new expression
                $$->addr = SymbolTable::gentemp(new SymbolType($1->addr->sym_type->type));    // Generate new temporary
                emit("+", $$->addr->name, $1->addr->name, $3->addr->name);                 // Emit the quad
            }
            else {
                yyerror("Type Error");
            }
        }
        | additive_expression SUBTRACT multiplicative_expression
        {
            // Indicates subtraction
            if(typecheck($1->addr, $3->addr)) {       // Check for type compatibility
                $$ = new Expression();                                                  // Generate new expression
                $$->addr = SymbolTable::gentemp(new SymbolType($1->addr->sym_type->type));    // Generate new temporary
                emit("-", $$->addr->name, $1->addr->name, $3->addr->name);                 // Emit the quad
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

shift_expression: 
        additive_expression
        {
            $$ = $1;    // Simple assignment
        }
        | shift_expression LEFT_SHIFT additive_expression
        {
            // Indicates left shift
            if($3->addr->sym_type->type == "int") {      // Check for type compatibility (int)
                $$ = new Expression();                                      // Generate new expression
                $$->addr = SymbolTable::gentemp(new SymbolType("int"));      // Generate new temporary
                emit("<<", $$->addr->name, $1->addr->name, $3->addr->name);    // Emit the quad
            }
            else {
                yyerror("Type Error");
            }
        }
        | shift_expression RIGHT_SHIFT additive_expression
        {
            // Indicates right shift
            if($3->addr->sym_type->type == "int") {      // Check for type compatibility (int)
                $$ = new Expression();                                      // Generate new expression
                $$->addr = SymbolTable::gentemp(new SymbolType("int"));      // Generate new temporary
                emit(">>", $$->addr->name, $1->addr->name, $3->addr->name);    // Emit the quad
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

relational_expression: 
        shift_expression
        {
            $$ = $1;    // Simple assignment
        }
        | relational_expression LESS_THAN shift_expression
        {
            if(typecheck($1->addr, $3->addr)) {                   // Check for type compatibility
                $$ = new Expression();                          // Generate new expression of type bool
                $$->type = "bool";
                $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
                $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
                emit("<", "", $1->addr->name, $3->addr->name);    // Emit "if x < y goto ..."
                emit("goto", "");                               // Emit "goto ..."
            }
            else {
                yyerror("Type Error");
            }
        }
        | relational_expression GREATER_THAN shift_expression
        {
            if(typecheck($1->addr, $3->addr)) {                   // Check for type compatibility
                $$ = new Expression();                          // Generate new expression of type bool
                $$->type = "bool";
                $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
                $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
                emit(">", "", $1->addr->name, $3->addr->name);    // Emit "if x > y goto ..."
                emit("goto", "");                               // Emit "goto ..."
            }
            else {
                yyerror("Type Error");
            }
        }
        | relational_expression LESS_THAN_EQUALS shift_expression
        {
            if(typecheck($1->addr, $3->addr)) {                   // Check for type compatibility
                $$ = new Expression();                          // Generate new expression of type bool
                $$->type = "bool";
                $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
                $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
                emit("<=", "", $1->addr->name, $3->addr->name);   // Emit "if x <= y goto ..."
                emit("goto", "");                               // Emit "goto ..."
            }
            else {
                yyerror("Type Error");
            }
        }
        | relational_expression GREATER_THAN_EQUALS shift_expression
        {
            if(typecheck($1->addr, $3->addr)) {                   // Check for type compatibility
                $$ = new Expression();                          // Generate new expression of type bool
                $$->type = "bool";
                $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
                $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
                emit(">=", "", $1->addr->name, $3->addr->name);   // Emit "if x >= y goto ..."
                emit("goto", "");                               // Emit "goto ..."
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

equality_expression: 
        relational_expression
        {
            $$ = $1;    // Simple assignment
        }
        | equality_expression EQUALS relational_expression
        {
            if(typecheck($1->addr, $3->addr)) {                   // Check for type compatibility
                convertBoolToInt($1);                           // Convert bool to int
                convertBoolToInt($3);
                $$ = new Expression();                          // Generate new expression of type bool
                $$->type = "bool";
                $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
                $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
                emit("==", "", $1->addr->name, $3->addr->name);   // Emit "if x == y goto ..."
                emit("goto", "");                               // Emit "goto ..."
            }
            else {
                yyerror("Type Error");
            }
        }
        | equality_expression NOT_EQUALS relational_expression
        {
            if(typecheck($1->addr, $3->addr)) {                   // Check for type compatibility
                convertBoolToInt($1);                           // Convert bool to int
                convertBoolToInt($3);
                $$ = new Expression();                          // Generate new expression of type bool
                $$->type = "bool";
                $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
                $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
                emit("!=", "", $1->addr->name, $3->addr->name);   // Emit "if x != y goto ..."
                emit("goto", "");                               // Emit "goto ..."
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

and_expression: 
        equality_expression
        {
            $$ = $1;    // Simple assignment
        }
        | and_expression BITWISE_AND equality_expression
        {
            if(typecheck($1->addr, $3->addr)) {                               // Check for type compatibility
                convertBoolToInt($1);                                       // Convert bool to int
                convertBoolToInt($3);
                $$ = new Expression();
                $$->type = "not_bool";                                      // The new result is not bool
                $$->addr = SymbolTable::gentemp(new SymbolType("int"));      // Create a new temporary
                emit("&", $$->addr->name, $1->addr->name, $3->addr->name);     // Emit the quad
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

exclusive_or_expression: 
        and_expression
        {
            $$ = $1;    // Simple assignment
        }
        | exclusive_or_expression BITWISE_XOR and_expression
        {
            if(typecheck($1->addr, $3->addr)) {                               // Check for type compatibility
                convertBoolToInt($1);                                       // Convert bool to int
                convertBoolToInt($3);
                $$ = new Expression();
                $$->type = "not_bool";                                      // The new result is not bool
                $$->addr = SymbolTable::gentemp(new SymbolType("int"));      // Create a new temporary
                emit("^", $$->addr->name, $1->addr->name, $3->addr->name);     // Emit the quad
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

inclusive_or_expression: 
        exclusive_or_expression
        {
            $$ = $1;    // Simple assignment
        }
        | inclusive_or_expression BITWISE_OR exclusive_or_expression
        {
            if(typecheck($1->addr, $3->addr)) {                               // Check for type compatibility
                convertBoolToInt($1);                                       // Convert bool to int
                convertBoolToInt($3);
                $$ = new Expression();
                $$->type = "not_bool";                                      // The new result is not bool
                $$->addr = SymbolTable::gentemp(new SymbolType("int"));      // Create a new temporary
                emit("|", $$->addr->name, $1->addr->name, $3->addr->name);     // Emit the quad
            }
            else {
                yyerror("Type Error");
            }
        }
        ;

logical_and_expression: 
        inclusive_or_expression
        {
            $$ = $1;    // Simple assignment
        }
        | logical_and_expression LOGICAL_AND M inclusive_or_expression
        {
            /*
                Here, we have augmented the grammar with the non-terminal M to facilitate backpatching
            */
            convertIntToBool($1);                                   // Convert the expressions from int to bool
            convertIntToBool($4);
            $$ = new Expression();                                  // Create a new bool expression for the result
            $$->type = "bool";
            backpatch($1->truelist, $3);                            // Backpatching
            $$->truelist = $4->truelist;                            // Generate truelist from truelist of $4
            $$->falselist = merge($1->falselist, $4->falselist);    // Generate falselist by merging the falselists of $1 and $4
        }
        ;

logical_or_expression: 
        logical_and_expression
        {
            $$ = $1;    // Simple assignment
        }
        | logical_or_expression LOGICAL_OR M logical_and_expression
        {
            convertIntToBool($1);                                   // Convert the expressions from int to bool
            convertIntToBool($4);
            $$ = new Expression();                                  // Create a new bool expression for the result
            $$->type = "bool";
            backpatch($1->falselist, $3);                           // Backpatching
            $$->falselist = $4->falselist;                          // Generate falselist from falselist of $4
            $$->truelist = merge($1->truelist, $4->truelist);       // Generate truelist by merging the truelists of $1 and $4
        }
        ;

conditional_expression: 
        logical_or_expression
        {
            $$ = $1;    // Simple assignment
        }
        | logical_or_expression N QUESTION_MARK M expression N COLON M conditional_expression
        {   
            /*
                Note the augmented grammar with the non-terminals M and N
            */
            $$->addr = SymbolTable::gentemp($5->addr->sym_type);      // Generate temporary for the expression
            $$->addr->update_symbol($5->addr->sym_type);
            emit("=", $$->addr->name, $9->addr->name);            // Assign the conditional expression
            list<int> l1 = makelist(nextinstr());
            emit("goto", "");                                   // Prevent fall-through
            backpatch($6->nextlist, nextinstr());               // Make list with next instruction
            emit("=", $$->addr->name, $5->addr->name);
            list<int> l2 = makelist(nextinstr());               // Make list with next instruction
            l1 = merge(l1, l2);                                 // Merge the two lists
            emit("goto", "");                                   // Prevent fall-through
            backpatch($2->nextlist, nextinstr());               // Backpatching
            convertIntToBool($1);                               // Convert expression to bool
            backpatch($1->truelist, $4);                        // When $1 is true, control goes to $4 (expression)
            backpatch($1->falselist, $8);                       // When $1 is false, control goes to $8 (conditional_expression)
            backpatch(l1, nextinstr());
        }
        ;

M: %empty
        {   
            // Stores the next instruction value, and helps in backpatching
            $$ = nextinstr();
        }
        ;

N: %empty
        {
            // Helps in control flow
            $$ = new Statement();
            $$->nextlist = makelist(nextinstr());
            emit("goto", "");
        }
        ;

assignment_expression: 
        conditional_expression
        {
            $$ = $1;    // Simple assignment
        }
        | unary_expression assignment_operator assignment_expression
        {
            if($1->arr_type == "arr") {        // If atype is "arr", convert and emit
                $3->addr = convertType($3->addr, $1->type->type);
                emit("[]=", $1->array->name, $1->addr->name, $3->addr->name);
            }
            else if($1->arr_type == "ptr") {   // If atype is "ptr", emit 
                emit("*=", $1->array->name, $3->addr->name);
            }
            else {
                $3->addr = convertType($3->addr, $1->array->sym_type->type);
                emit("=", $1->array->name, $3->addr->name);
            }
            $$ = $3;
        }
        ;

assignment_operator: 
        ASSIGNMENT
        { /* Ignored */ }
        | MUL_ASSIGNMENT
        { /* Ignored */ }
        | DIV_ASSIGNMENT
        { /* Ignored */ }
        | MOD_ASSIGNMENT
        { /* Ignored */ }
        | ADD_ASSIGNMENT
        { /* Ignored */ }
        | SUB_ASSIGNMENT
        { /* Ignored */ }
        | LSHIFT_ASSIGNMENT
        { /* Ignored */ }
        | RSHIFT_ASSIGNMENT
        { /* Ignored */ }
        | AND_ASSIGNMENT
        { /* Ignored */ }
        | XOR_ASSIGNMENT
        { /* Ignored */ }
        | OR_ASSIGNMENT
        { /* Ignored */ }
        ;

expression: 
        assignment_expression
        {
            $$ = $1;
        }
        | expression COMMA assignment_expression
        { /* Ignored */ }
        ;

constant_expression: 
        conditional_expression
        { /* Ignored */ }
        ;

declaration: 
        declaration_specifiers init_declarator_list SEMICOLON
        { /* Ignored */ }
        | declaration_specifiers SEMICOLON
        { /* Ignored */ }
        ;

declaration_specifiers: 
        storage_class_specifier declaration_specifiers
        { /* Ignored */ }
        |storage_class_specifier
        { /* Ignored */ }
        | type_specifier declaration_specifiers
        { /* Ignored */ }
        | type_specifier
        { /* Ignored */ }
        | type_qualifier declaration_specifiers
        { /* Ignored */ }
        | type_qualifier
        { /* Ignored */ }
        | function_specifier declaration_specifiers
        { /* Ignored */ }
        | function_specifier
        { /* Ignored */ }
        ;

init_declarator_list: 
        init_declarator
        { /* Ignored */ }
        | init_declarator_list COMMA init_declarator
        { /* Ignored */ }
        ;

init_declarator: 
        declarator
        {
            $$ = $1;
        }
        | declarator ASSIGNMENT initializer
        {   
            // Find out the initial value and emit it
            if($3->val != "") {
                $1->val = $3->val;
            }
            emit("=", $1->name, $3->name);
        }
        ;

storage_class_specifier: 
        EXTERN
        { /* Ignored */ }
        | STATIC
        { /* Ignored */ }
        | AUTO
        { /* Ignored */ }
        | REGISTER
        { /* Ignored */ }
        ;

type_specifier: 
        VOID
        {
            prevType = "void";   // Store the latest encountered type in prevType
        }
        | CHAR
        {
            prevType = "char";   // Store the latest encountered type in prevType
        }
        | SHORT
        { /* Ignored */ }
        | INT
        {
            prevType = "int";    // Store the latest encountered type in prevType
        }
        | LONG
        { /* Ignored */ }
        | FLOAT
        {
            prevType = "float";  // Store the latest encountered type in prevType
        }
        | DOUBLE
        { /* Ignored */ }
        | SIGNED
        { /* Ignored */ }
        | UNSIGNED
        { /* Ignored */ }
        | BOOL
        { /* Ignored */ }
        | COMPLEX
        { /* Ignored */ }
        | IMAGINARY
        { /* Ignored */ }
        | enum_specifier
        { /* Ignored */ }
        ;

specifier_qualifier_list: 
        type_specifier specifier_qualifier_list_opt
        { /* Ignored */ }
        | type_qualifier specifier_qualifier_list_opt
        { /* Ignored */ }
        ;

specifier_qualifier_list_opt: 
        specifier_qualifier_list
        { /* Ignored */ }
        | %empty
        { /* Ignored */ }
        ;

enum_specifier: 
        ENUM identifier_opt LEFT_CURLY_BRACE enumerator_list RIGHT_CURLY_BRACE
        { /* Ignored */ }
        | ENUM identifier_opt LEFT_CURLY_BRACE enumerator_list COMMA RIGHT_CURLY_BRACE
        { /* Ignored */ }
        | ENUM IDENTIFIER
        { /* Ignored */ }
        ;

identifier_opt: 
        IDENTIFIER
        {/* Ignored */}
        | %empty
        {/* Ignored */}
        ;

enumerator_list: 
        enumerator
        {/* Ignored */}
        | enumerator_list COMMA enumerator
        {/* Ignored */}
        ;

enumerator: 
        IDENTIFIER
        {/* Ignored */}
        | IDENTIFIER ASSIGNMENT constant_expression
        {/* Ignored */}
        ;

type_qualifier: 
        CONST
        {/* Ignored */}
        | RESTRICT
        {/* Ignored */}
        | VOLATILE
        {/* Ignored */}
        ;

function_specifier: 
        INLINE
        {/* Ignored */}
        ;

declarator: 
        pointer direct_declarator
        {
            SymbolType* t = $1;
            // In case of multi-dimesnional arrays, keep on going down in a hierarchial fashion to get the base type
            while(t->arrElementType != NULL) {
                t = t->arrElementType;
            }
            t->arrElementType = $2->sym_type;  // Store the base type
            $$ = $2->update_symbol($1);    // Update
        }
        | direct_declarator
        {/* Ignored */}
        ;

direct_declarator: 
        IDENTIFIER
        {
            $$ = $1->update_symbol(new SymbolType(prevType));   // For an identifier, update the type to prevType
            currentSym = $$;                         // Update pointer to current symbol
        }
        | LEFT_PAREN declarator RIGHT_PAREN
        {
            $$ = $2;    // Simple assignment
        }
        | direct_declarator LEFT_SQR_BRACKET type_qualifier_list assignment_expression RIGHT_SQR_BRACKET
        { /* Ignored */ }
        | direct_declarator LEFT_SQR_BRACKET type_qualifier_list RIGHT_SQR_BRACKET
        { /* Ignored */ }
        | direct_declarator LEFT_SQR_BRACKET assignment_expression RIGHT_SQR_BRACKET
        {
            SymbolType* t = $1->sym_type;
            SymbolType* prev = NULL;
            // Keep moving recursively to get the base type
            while(t->type == "arr") {
                prev = t;
                t = t->arrElementType;
            }
            if(prev == NULL) {
                int temp = atoi($3->addr->val.c_str());                // Get initial value
                SymbolType* tp = new SymbolType("arr", $1->sym_type, temp); // Create that type
                $$ = $1->update_symbol(tp);                                    // Update the symbol table for that symbol
            }
            else {
                int temp = atoi($3->addr->val.c_str());                // Get initial value
                prev->arrElementType = new SymbolType("arr", t, temp);         // Create that type
                $$ = $1->update_symbol($1->sym_type);                              // Update the symbol table for that symbol
            }
        }
        | direct_declarator LEFT_SQR_BRACKET RIGHT_SQR_BRACKET
        {
            SymbolType* t = $1->sym_type;
            SymbolType* prev = NULL;
            // Keep moving recursively to get the base type
            while(t->type == "arr") {
                prev = t;
                t = t->arrElementType;
            }
            if(prev == NULL) {
                SymbolType* tp = new SymbolType("arr", $1->sym_type, 0);
                $$ = $1->update_symbol(tp);
            }
            else {
                prev->arrElementType = new SymbolType("arr", t, 0);
                $$ = $1->update_symbol($1->sym_type);
            }
        }
        | direct_declarator LEFT_SQR_BRACKET STATIC type_qualifier_list assignment_expression RIGHT_SQR_BRACKET
        { /* Ignored */ }
        | direct_declarator LEFT_SQR_BRACKET STATIC assignment_expression RIGHT_SQR_BRACKET
        { /* Ignored */ }
        | direct_declarator LEFT_SQR_BRACKET type_qualifier_list STATIC assignment_expression RIGHT_SQR_BRACKET
        { /* Ignored */ }
        | direct_declarator LEFT_SQR_BRACKET type_qualifier_list MULTIPLY RIGHT_SQR_BRACKET
        { /* Ignored */ }
        | direct_declarator LEFT_SQR_BRACKET MULTIPLY RIGHT_SQR_BRACKET
        { /* Ignored */ }
        | direct_declarator LEFT_PAREN change_table parameter_type_list RIGHT_PAREN
        {
            SymTbl_Current->name = $1->name;
            if($1->sym_type->type != "void") {
                Symbol* s = SymTbl_Current->lookup("return");    // Lookup for return value
                s->update_symbol($1->sym_type);
            }
            $1->nestedTblPtr = SymTbl_Current;
            SymTbl_Current->parent = SymTbl_Global;   // Update parent symbol table
            switchTable(SymTbl_Global);          // Switch current table to point to the global symbol table
            currentSym = $$;             // Update current symbol
        }
        | direct_declarator LEFT_PAREN identifier_list RIGHT_PAREN
        { /* Ignored */ }
        | direct_declarator LEFT_PAREN change_table RIGHT_PAREN
        {
            SymTbl_Current->name = $1->name;
            if($1->sym_type->type != "void") {
                Symbol* s = SymTbl_Current->lookup("return");    // Lookup for return value
                s->update_symbol($1->sym_type);
            }
            $1->nestedTblPtr = SymTbl_Current;
            SymTbl_Current->parent = SymTbl_Global;   // Update parent symbol table
            switchTable(SymTbl_Global);          // Switch current table to point to the global symbol table
            currentSym = $$;             // Update current symbol
        }
        ;

type_qualifier_list_opt: 
        type_qualifier_list
        { /* Ignored */ }
        | %empty
        { /* Ignored */ }
        ;

pointer: 
        MULTIPLY type_qualifier_list_opt
        {
            $$ = new SymbolType("ptr");     //  Create new type "ptr"
        }
        | MULTIPLY type_qualifier_list_opt pointer
        {
            $$ = new SymbolType("ptr", $3); //  Create new type "ptr"
        }
        ;

type_qualifier_list: 
        type_qualifier
        { /* Ignored */ }
        | type_qualifier_list type_qualifier
        { /* Ignored */ }
        ;

parameter_type_list: 
        parameter_list
        { /* Ignored */ }
        | parameter_list COMMA ELLIPSIS
        { /* Ignored */ }
        ;

parameter_list: 
        parameter_declaration
        { /* Ignored */ }
        | parameter_list COMMA parameter_declaration
        { /* Ignored */ }
        ;

parameter_declaration: 
        declaration_specifiers declarator
        { /* Ignored */ }
        | declaration_specifiers
        { /* Ignored */ }
        ;

identifier_list: 
        IDENTIFIER
        { /* Ignored */ }
        | identifier_list COMMA IDENTIFIER
        { /* Ignored */ }
        ;

type_name: 
        specifier_qualifier_list
        { /* Ignored */ }
        ;

initializer: 
        assignment_expression
        {
            $$ = $1->addr;   // Simple assignment
        }
        | LEFT_CURLY_BRACE initializer_list RIGHT_CURLY_BRACE
        { /* Ignored */ }
        | LEFT_CURLY_BRACE initializer_list COMMA RIGHT_CURLY_BRACE
        { /* Ignored */ }
        ;

initializer_list: 
        designation_opt initializer
        { /* Ignored */ }
        | initializer_list COMMA designation_opt initializer
        { /* Ignored */ }
        ;

designation_opt: 
        designation
        { /* Ignored */ }
        | %empty
        { /* Ignored */ }
        ;

designation: 
        designator_list ASSIGNMENT
        { /* Ignored */ }
        ;

designator_list: 
        designator
        { /* Ignored */ }
        | designator_list designator
        { /* Ignored */ }
        ;

designator: 
        LEFT_SQR_BRACKET constant_expression RIGHT_SQR_BRACKET
        { /* Ignored */ }
        | DOT IDENTIFIER
        { /* Ignored */ }
        ;

statement: 
        labeled_statement
        { /* Ignored */ }
        | compound_statement
        {
            $$ = $1;    // Simple assignment
        }
        | expression_statement
        {
            $$ = new Statement();           // Create new statement
            $$->nextlist = $1->nextlist;    // Assign same nextlist
        }
        | selection_statement
        {
            $$ = $1;    // Simple assignment
        }
        | iteration_statement
        {
            $$ = $1;    // Simple assignment
        }
        | jump_statement
        {
            $$ = $1;    // Simple assignment
        }
        ;

/* New non-terminal that has been added to facilitate the structure of loops */
loop_statement:
        labeled_statement
        { /* Ignored */ }
        | expression_statement
        {
            $$ = new Statement();           // Create new statement
            $$->nextlist = $1->nextlist;    // Assign same nextlist
        }
        | selection_statement
        {
            $$ = $1;    // Simple assignment
        }
        | iteration_statement
        {
            $$ = $1;    // Simple assignment
        }
        | jump_statement
        {
            $$ = $1;    // Simple assignment
        }
        ;

labeled_statement: 
        IDENTIFIER COLON statement
        { /* Ignored */ }
        | CASE constant_expression COLON statement
        { /* Ignored */ }
        | DEFAULT COLON statement
        { /* Ignored */ }
        ;

compound_statement: 
        LEFT_CURLY_BRACE X change_table block_item_list_opt RIGHT_CURLY_BRACE
        {
            /*
                Here, the grammar has been augmented with non-terminals like X and change_table to allow creation of nested symbol tables
            */
            $$ = $4;
            switchTable(SymTbl_Current->parent);     // Update current symbol table
        }
        ;

block_item_list_opt: 
        block_item_list
        {
            $$ = $1;    // Simple assignment
        }
        | %empty
        {
            $$ = new Statement();   // Create new statement
        }
        ;

block_item_list: 
        block_item
        {
            $$ = $1;    // Simple assignment
        }
        | block_item_list M block_item
        {   
            /*
                This production rule has been augmented with the non-terminal M
            */
            $$ = $3;
            backpatch($1->nextlist, $2);    // After $1, move to block_item via $2
        }
        ;

block_item: 
        declaration
        {
            $$ = new Statement();   // Create new statement
        }
        | statement
        {
            $$ = $1;    // Simple assignment
        }
        ;

expression_statement: 
        expression SEMICOLON
        {
            $$ = $1;    // Simple assignment
        }
        | SEMICOLON
        {
            $$ = new Expression();  // Create new expression
        }
        ;

selection_statement: 
        IF LEFT_PAREN expression N RIGHT_PAREN M statement N %prec THEN
        {
            /*
                This production rule has been augmented for control flow
            */
            backpatch($4->nextlist, nextinstr());                   // nextlist of N now has nextinstr
            convertIntToBool($3);                                   // Convert expression to bool
            $$ = new Statement();                                   // Create new statement
            backpatch($3->truelist, $6);                            // Backpatching - if expression is true, go to M
            // Merge falselist of expression, nextlist of statement and nextlist of the last N
            list<int> temp = merge($3->falselist, $7->nextlist);
            $$->nextlist = merge($8->nextlist, temp);
        }
        | IF LEFT_PAREN expression N RIGHT_PAREN M statement N ELSE M statement
        {
            /*
                This production rule has been augmented for control flow
            */
            backpatch($4->nextlist, nextinstr());                   // nextlist of N now has nextinstr
            convertIntToBool($3);                                   // Convert expression to bool
            $$ = new Statement();                                   // Create new statement
            backpatch($3->truelist, $6);                            // Backpatching - if expression is true, go to first M, else go to second M
            backpatch($3->falselist, $10);
            // Merge nextlist of statement, nextlist of N and nextlist of the last statement
            list<int> temp = merge($7->nextlist, $8->nextlist);
            $$->nextlist = merge($11->nextlist, temp);
        }
        | SWITCH LEFT_PAREN expression RIGHT_PAREN statement
        { /* Ignored */ }
        ;

iteration_statement: 
        WHILE W LEFT_PAREN X change_table M expression RIGHT_PAREN M loop_statement
        {   
            /*
                This production rule has been augmented with non-terminals like W, X, change_table and M to handle the control flow, 
                backpatching, detect the kind of loop, create a separate symbol table for the loop block and give it an appropriate name
            */
            $$ = new Statement();                   // Create a new statement
            convertIntToBool($7);                   // Convert expression to bool
            backpatch($10->nextlist, $6);           // Go back to M1 and expression after one iteration of loop_statement
            backpatch($7->truelist, $9);            // Go to M2 and loop_statement if expression is true
            $$->nextlist = $7->falselist;           // Exit loop if expression is false
            emit("goto", to_string($6));   // Emit to prevent fall-through
            BlockName = "";
            switchTable(SymTbl_Current->parent);
        }
        | WHILE W LEFT_PAREN X change_table M expression RIGHT_PAREN LEFT_CURLY_BRACE M block_item_list_opt RIGHT_CURLY_BRACE
        {
            /*
                This production rule has been augmented with non-terminals like W, X, change_table and M to handle the control flow, 
                backpatching, detect the kind of loop, create a separate symbol table for the loop block and give it an appropriate name
            */
            $$ = new Statement();                   // Create a new statement
            convertIntToBool($7);                   // Convert expression to bool
            backpatch($11->nextlist, $6);           // Go back to M1 and expression after one iteration
            backpatch($7->truelist, $10);           // Go to M2 and block_item_list_opt if expression is true
            $$->nextlist = $7->falselist;           // Exit loop if expression is false
            emit("goto", to_string($6));   // Emit to prevent fall-through
            BlockName = "";
            switchTable(SymTbl_Current->parent);
        }
        | DO D M loop_statement M WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON
        {
            /*
                This production rule has been augmented with non-terminals like D and M to handle the control flow, backpatching and detect the kind of loop
            */
            $$ = new Statement();                   // Create a new statement     
            convertIntToBool($8);                   // Convert expression to bool
            backpatch($8->truelist, $3);            // Go back to M1 and loop_statement if expression is true
            backpatch($4->nextlist, $5);            // Go to M2 to check expression after statement is complete
            $$->nextlist = $8->falselist;           // Exit loop if expression is false  
            BlockName = "";
        }
        | DO D LEFT_CURLY_BRACE M block_item_list_opt RIGHT_CURLY_BRACE M WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON
        {
            /*
                This production rule has been augmented with non-terminals like D and M to handle the control flow, backpatching and detect the kind of loop
            */
            $$ = new Statement();                   // Create a new statement  
            convertIntToBool($10);                  // Convert expression to bool
            backpatch($10->truelist, $4);           // Go back to M1 and block_item_list_opt if expression is true
            backpatch($5->nextlist, $7);            // Go to M2 to check expression after block_item_list_opt is complete
            $$->nextlist = $10->falselist;          // Exit loop if expression is false  
            BlockName = "";
        }
        | FOR F LEFT_PAREN X change_table declaration M expression_statement M expression N RIGHT_PAREN M loop_statement
        {
            /*
                This production rule has been augmented with non-terminals like F, X, change_table and M to handle the control flow, 
                backpatching, detect the kind of loop, create a separate symbol table for the loop block and give it an appropriate name
            */
            $$ = new Statement();                   // Create a new statement
            convertIntToBool($8);                   // Convert expression to bool
            backpatch($8->truelist, $13);           // Go to M3 if expression is true
            backpatch($11->nextlist, $7);           // Go back to M1 after N
            backpatch($14->nextlist, $9);           // Go back to expression after loop_statement
            emit("goto", to_string($9));   // Emit to prevent fall-through
            $$->nextlist = $8->falselist;           // Exit loop if expression_statement is false
            BlockName = "";
            switchTable(SymTbl_Current->parent);
        }
        | FOR F LEFT_PAREN X change_table expression_statement M expression_statement M expression N RIGHT_PAREN M loop_statement
        {
            /*
                This production rule has been augmented with non-terminals like F, X, change_table and M to handle the control flow, 
                backpatching, detect the kind of loop, create a separate symbol table for the loop block and give it an appropriate name
            */
            $$ = new Statement();                   // Create a new statement
            convertIntToBool($8);                   // Convert expression to bool
            backpatch($8->truelist, $13);           // Go to M3 if expression is true
            backpatch($11->nextlist, $7);           // Go back to M1 after N
            backpatch($14->nextlist, $9);           // Go back to expression after loop_statement
            emit("goto", to_string($9));   // Emit to prevent fall-through
            $$->nextlist = $8->falselist;           // Exit loop if expression_statement is false
            BlockName = "";
            switchTable(SymTbl_Current->parent);
        }
        | FOR F LEFT_PAREN X change_table declaration M expression_statement M expression N RIGHT_PAREN M LEFT_CURLY_BRACE block_item_list_opt RIGHT_CURLY_BRACE
        {
            /*
                This production rule has been augmented with non-terminals like F, X, change_table and M to handle the control flow, 
                backpatching, detect the kind of loop, create a separate symbol table for the loop block and give it an appropriate name
            */
            $$ = new Statement();                   // Create a new statement
            convertIntToBool($8);                   // Convert expression to bool
            backpatch($8->truelist, $13);           // Go to M3 if expression is true
            backpatch($11->nextlist, $7);           // Go back to M1 after N
            backpatch($15->nextlist, $9);           // Go back to expression after loop_statement
            emit("goto", to_string($9));   // Emit to prevent fall-through
            $$->nextlist = $8->falselist;           // Exit loop if expression_statement is false
            BlockName = "";
            switchTable(SymTbl_Current->parent);
        }
        | FOR F LEFT_PAREN X change_table expression_statement M expression_statement M expression N RIGHT_PAREN M LEFT_CURLY_BRACE block_item_list_opt RIGHT_CURLY_BRACE
        {
            /*
                This production rule has been augmented with non-terminals like F, X, change_table and M to handle the control flow, 
                backpatching, detect the kind of loop, create a separate symbol table for the loop block and give it an appropriate name
            */
            $$ = new Statement();                   // Create a new statement
            convertIntToBool($8);                   // Convert expression to bool
            backpatch($8->truelist, $13);           // Go to M3 if expression is true
            backpatch($11->nextlist, $7);           // Go back to M1 after N
            backpatch($15->nextlist, $9);           // Go back to expression after loop_statement
            emit("goto", to_string($9));            // Emit to prevent fall-through
            $$->nextlist = $8->falselist;           // Exit loop if expression_statement is false
            BlockName = "";
            switchTable(SymTbl_Current->parent);
        }
        ;

F: %empty
        {   
            /*
            This non-terminal indicates the start of a for loop
            */
            BlockName = "FOR";
        }
        ;

W: %empty
        {
            /*
            This non-terminal indicates the start of a while loop
            */
            BlockName = "WHILE";
        }
        ;

D: %empty
        {
            /*
            This non-terminal indicates the start of a do-while loop
            */
            BlockName = "DO_WHILE";
        }
        ;

X: %empty
        {   
            // Used for creating new nested symbol tables for nested blocks
            string newST = SymTbl_Current->name + "." + BlockName + "$" + to_string(SymTbl_Count++);  // Generate name for new symbol table
            Symbol* sym = SymTbl_Current->lookup(newST);
            sym->nestedTblPtr = new SymbolTable(newST);  // Create new symbol table
            sym->name = newST;
            sym->nestedTblPtr->parent = SymTbl_Current;
            sym->sym_type = new SymbolType("block");    // The type will be "block"
            currentSym = sym;    // Change the current symbol pointer
        }
        ;

change_table: %empty
        {   
            // Used for changing the symbol table on encountering functions
            if(currentSym->nestedTblPtr != NULL) {
                // If the symbol table already exists, switch to that table
                switchTable(currentSym->nestedTblPtr);
                emit("label", SymTbl_Current->name);
            }
            else {
                // If the symbol table does not exist already, create it and switch to it
                switchTable(new SymbolTable(""));
            }
        }
        ;

jump_statement: 
        GOTO IDENTIFIER SEMICOLON
        { /* Ignored */ }
        | CONTINUE SEMICOLON
        {
            $$ = new Statement();
        }
        | BREAK SEMICOLON
        {
            $$ = new Statement();
        }
        | RETURN expression SEMICOLON
        {
            $$ = new Statement();
            emit("return", $2->addr->name);  // Emit return alongwith return value
        }
        | RETURN SEMICOLON
        {
            $$ = new Statement();
            emit("return", "");             // Emit return without any return value
        }
        ;

translation_unit: 
        external_declaration
        { /* Ignored */ }
        | translation_unit external_declaration
        { /* Ignored */ }
        ;

external_declaration: 
        function_definition
        { /* Ignored */ }
        | declaration
        { /* Ignored */ }
        ;

function_definition: 
        declaration_specifiers declarator declaration_list_opt change_table LEFT_CURLY_BRACE block_item_list_opt RIGHT_CURLY_BRACE
        {   
            SymTbl_Current->parent = SymTbl_Global;
            SymTbl_Count = 0;
            switchTable(SymTbl_Global);          // After reaching end of a function, change cureent symbol table to the global symbol table
        }
        ;

declaration_list_opt: 
        declaration_list
        { /* Ignored */ }
        | %empty
        { /* Ignored */ }
        ;

declaration_list: 
        declaration
        { /* Ignored */ }
        | declaration_list declaration
        { /* Ignored */ }
        ;

%%

void yyerror(string s) {
    /*
        This function prints any error encountered while parsing
    */
    cout << "Error occurred: " << s << endl;
    cout << "Line no.: " << yylineno << endl;
    cout << "Unable to parse: " << yytext << endl; 
}
