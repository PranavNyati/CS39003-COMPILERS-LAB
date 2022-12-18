%{
    /* 
    Compilers Lab : Assignment 6
    Group Members:
        1. Pranav Nyati - 20CS30037
        2. Shreyas Jena - 20CS30049
    
    * Bison specifications
    */
    #include <iostream>
    #include "assn6_20CS30037_20CS30049_translator.h"
    using namespace std;

    extern int yylex();                     // From lexer
    void yyerror(string s);                 // Function to report errors
    extern char* yytext;                    // From lexer, gives the text being currently scanned
    extern int yylineno;                    // Used for keeping track of the line number

    extern int nextinstr;                   // Used for keeping track of the next instruction
    extern QuadArray QuadList;              // List of all quads
    extern SymbolTable SymTbl_Global;       // Global symbol table
    extern SymbolTable* SymTbl;             // Pointer to the current symbol table
    extern vector<string> const_strs;     // List of all string constants

    int str_count = 0;                       // Counter for string constants
%}

%union 
{
    int intval;                     // For an integer value
    char charval;                   // For a char value
    float floatval;                 // For a float value
    string* strval;                    // For a string
    void* ptr;                      // For a pointer
    SymbolType* sym_type;            // For the type of a symbol
    Symbol* symptr;                   // For a symbol
    data_type types;                 // For the type of an expression
    opcode opc;                     // For an opcode
    Expression* expr;               // For an expression
    Declaration* dec;               // For a declaration
    vector<Declaration*> *dec_list;  // For a list of declarations
    Parameter* param;                     // For a parameter
    vector<Parameter*> *param_list;        // For a list of parameters
}

/*
    All tokens
*/
%token AUTO BREAK CASE CHAR_ CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT_ FOR GOTO_ IF INLINE INT_ LONG REGISTER RESTRICT RETURN_ SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID_ VOLATILE WHILE BOOL_ COMPLEX IMAGINARY
%token LEFT_SQR_BRACKET RIGHT_SQR_BRACKET LEFT_PAREN RIGHT_PAREN LEFT_CURLY_BRACE RIGHT_CURLY_BRACE 
%token DOT ARROW INCREMENT DECREMENT BITWISE_AND MULTIPLY ADD_ SUBTRACT BITWISE_NOR NOT DIVIDE MODULO 
%token LEFT_SHIFT RIGHT_SHIFT LESS_THAN GREATER_THAN LESS_THAN_EQUALS GREATER_THAN_EQUALS EQUALS NOT_EQUALS BITWISE_XOR BITWISE_OR 
%token LOGICAL_AND LOGICAL_OR QUESTION_MARK COLON SEMICOLON ELLIPSIS 
%token ASSIGNMENT  MUL_ASSIGNMENT DIV_ASSIGNMENT MOD_ASSIGNMENT ADD_ASSIGNMENT SUB_ASSIGNMENT LSHIFT_ASSIGNMENT RSHIFT_ASSIGNMENT AND_ASSIGNMENT XOR_ASSIGNMENT OR_ASSIGNMENT COMMA HASH

// Identifiers are treated with type str
%token <strval> IDENTIFIER

// Integer constants have a type intval
%token <intval> INT_CONSTANT

// Floating constants have a type floatval
%token <floatval> FLOAT_CONSTANT

// Character constants have a type charval
%token <charval> CHAR_CONSTANT

// String literals have a type str
%token <strval> STRING_LITERAL

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
        postfix_expression
        unary_expression
        cast_expression
        expression_statement
        statement
        compound_statement
        selection_statement
        iteration_statement
        labeled_statement 
        jump_statement
        block_item
        block_item_list
        initializer
        M
        N

// Non-terminals of type charval (unary operator)
%type <charval> unary_operator

// The pointer non-terminal is treated with type intval
%type <intval> pointer

// Non-terminals of type data_type (denoting types)
%type <types> type_specifier declaration_specifiers

// Non-terminals of type declaration
%type <dec> direct_declarator initializer_list init_declarator declarator function_prototype

// Non-terminals of type dec_list
%type <dec_list> init_declarator_list

// Non-terminals of type param
%type <param> parameter_declaration

// Non-terminals of type param_list
%type <param_list> parameter_list parameter_type_list parameter_type_list_opt argument_expression_list

// Helps in removing the dangling else problem
%expect 1
%nonassoc ELSE

// The start symbol is translation_unit
%start translation_unit

%%

primary_expression: 
        IDENTIFIER
        {
            $$ = new Expression();                      // Create new expression

            string str = *($1);
            SymTbl->lookup(str);                        // Look up the entry in the symbol table; if not found, add it
            $$->addr = str;                             // Store pointer to string identifier name
        }
        | INT_CONSTANT
        {
            $$ = new Expression();                      // Create new expression

            $$->addr = SymTbl->gentemp(INT);            // Generate a new temporary variable
            string tmp_var = $$->addr;
            emit(tmp_var, $1, ASSIGN);                  // emit the corresponding quad

            SymbolValue* val = new SymbolValue();
            val->init($1);                              // Initialize value with integer constant

            Symbol* var = SymTbl->lookup(tmp_var);
            var->init_val = val;                        // Store in symbol table
        }
        | FLOAT_CONSTANT
        {
            $$ = new Expression();                      // Create new expression
            $$->addr = SymTbl->gentemp(FLOAT);          // Generate a new temporary variable
            emit($$->addr, $1, ASSIGN);
            SymbolValue* val = new SymbolValue();
            val->init($1);                              // Set the initial value
            SymTbl->lookup($$->addr)->init_val = val;   // Store in symbol table
        }
        | CHAR_CONSTANT
        {
            $$ = new Expression();                      // Create new expression

            $$->addr = SymTbl->gentemp(CHAR);           // Generate a new temporary variable
            emit($$->addr, $1, ASSIGN);

            SymbolValue* val = new SymbolValue();
            val->init($1);                              // Set the initial value
            SymTbl->lookup($$->addr)->init_val = val;   // Store in symbol table
        }
        | STRING_LITERAL
        {
            $$ = new Expression();                      // Create new expression

            $$->addr = ".LC" + to_string(str_count++);
            const_strs.push_back(*($1));                // Add to the list of string constants
        }
        | LEFT_PAREN expression RIGHT_PAREN
        {
            $$ = $2;                                    // Simple assignment
        }
        ;

postfix_expression: 
        primary_expression
        {
            // ignore this production
        }
        | postfix_expression LEFT_SQR_BRACKET expression RIGHT_SQR_BRACKET
        {
            SymbolType to = SymTbl->lookup($1->addr)->type;      // Get the type of the expression
            string f = "";

            if(!($1->dim)) 
            {
                f = SymTbl->gentemp(INT);                       // Generate a new temporary variable
                emit(f, 0, ASSIGN);                             // Emit the corresponding quad
                $1->name = new string(f);
            }

            string temp = SymTbl->gentemp(INT);

            // Emit the necessary quads
            emit(temp, $3->addr, "", ASSIGN);
            emit(temp, temp, "4", MULT);
            emit(f, temp, "", ASSIGN);
            $$ = $1;
        }
        | postfix_expression LEFT_PAREN RIGHT_PAREN
        {   
            // Corresponds to calling a function with the function name but without any arguments
            SymbolTable* funcTable = SymTbl_Global.lookup($1->addr)->nested_table;
            emit($1->addr, "0", "", CALL);
        }
        | postfix_expression LEFT_PAREN argument_expression_list RIGHT_PAREN
        {   
            // Corresponds to calling a function with the function name and the appropriate number of arguments
            SymbolTable* funcTable = SymTbl_Global.lookup($1->addr)->nested_table;
            vector<Parameter*> parameters = *($3);                          // Get the list of parameters
            vector<Symbol*> paramsList = funcTable->symbols;

            for (int i = 0; i < (int)parameters.size(); i++) 
            {
                emit(parameters[i]->name, "", "", PARAM);               // Emit the parameters
            }

            data_type retType = funcTable->lookup("RETVAL")->type.type;  // Add an entry in the symbol table for the return value
            
            if(retType == VOID)                                         // If the function returns void
                emit($1->addr, (int)parameters.size(), CALL);
            else {                                                      // If the function returns a value
                string retVal = SymTbl->gentemp(retType);
                emit($1->addr, to_string(parameters.size()), retVal, CALL);
                $$ = new Expression();
                $$->addr = retVal;
            }
        }
        | postfix_expression DOT IDENTIFIER
        {
            // ignore this production
        }
        | postfix_expression ARROW IDENTIFIER
        {
            // ignore this production
        }
        | postfix_expression INCREMENT
        {   
            $$ = new Expression();                                          // Create new expression
            SymbolType t = SymTbl->lookup($1->addr)->type;                       // Get the type of the expression and generate a temporary variable
            if(t.type == ARRAY) {
                $$->addr = SymTbl->gentemp(SymTbl->lookup($1->addr)->type.base_type);
                emit($$->addr, $1->addr, *($1->name), ARR_IDX_ARG);
                string temp = SymTbl->gentemp(t.base_type);
                emit(temp, $1->addr, *($1->name), ARR_IDX_ARG);
                emit(temp, temp, "1", ADD);
                emit($1->addr, temp, *($1->name), ARR_IDX_RES);
            }
            else {
                $$->addr = SymTbl->gentemp(SymTbl->lookup($1->addr)->type.type);
                emit($$->addr, $1->addr, "", ASSIGN);                         // Assign the old value 
                emit($1->addr, $1->addr, "1", ADD);                           // Increment the value
            }
        }
        | postfix_expression DECREMENT
        {
            $$ = new Expression();                                          // Create new expression
            $$->addr = SymTbl->gentemp(SymTbl->lookup($1->addr)->type.type);          // Generate a new temporary variable
            SymbolType t = SymTbl->lookup($1->addr)->type;
            if(t.type == ARRAY) {
                $$->addr = SymTbl->gentemp(SymTbl->lookup($1->addr)->type.base_type);
                string temp = SymTbl->gentemp(t.base_type);
                emit(temp, $1->addr, *($1->name), ARR_IDX_ARG);
                emit($$->addr, temp, "", ASSIGN);
                emit(temp, temp, "1", SUB);
                emit($1->addr, temp, *($1->name), ARR_IDX_RES);
            }
            else {
                $$->addr = SymTbl->gentemp(SymTbl->lookup($1->addr)->type.type);
                emit($$->addr, $1->addr, "", ASSIGN);                         // Assign the old value
                emit($1->addr, $1->addr, "1", SUB);                           // Decrement the value
            }
        }
        | LEFT_PAREN type_name RIGHT_PAREN LEFT_CURLY_BRACE initializer_list RIGHT_CURLY_BRACE
        {
            // ignore this production
        }
        | LEFT_PAREN type_name RIGHT_PAREN LEFT_CURLY_BRACE initializer_list COMMA RIGHT_CURLY_BRACE
        {
            // ignore this production
        }
        ;

argument_expression_list: 
        assignment_expression
        {
            Parameter* first = new Parameter();                 // Create a new parameter
            first->name = $1->addr;
            first->type = SymTbl->lookup($1->addr)->type;
            $$ = new vector<Parameter*>;
            $$->push_back(first);                       // Add the parameter to the list
        }
        | argument_expression_list COMMA assignment_expression
        {
            Parameter* next = new Parameter();                  // Create a new parameter
            next->name = $3->addr;
            next->type = SymTbl->lookup(next->name)->type;
            $$ = $1;
            $$->push_back(next);                        // Add the parameter to the list
        }
        ;

unary_expression: 
        postfix_expression
        {
            // ignore this production
        }
        | INCREMENT unary_expression
        {
            $$ = new Expression();
            SymbolType type = SymTbl->lookup($2->addr)->type;
            if(type.type == ARRAY) {
                string t = SymTbl->gentemp(type.base_type);
                emit(t, $2->addr, *($2->name), ARR_IDX_ARG);
                emit(t, t, "1", ADD);
                emit($2->addr, t, *($2->name), ARR_IDX_RES);
                $$->addr = SymTbl->gentemp(SymTbl->lookup($2->addr)->type.base_type);
            }
            else {
                emit($2->addr, $2->addr, "1", ADD);                       // Increment the value
                $$->addr = SymTbl->gentemp(SymTbl->lookup($2->addr)->type.type);
            }
            $$->addr = SymTbl->gentemp(SymTbl->lookup($2->addr)->type.type);
            emit($$->addr, $2->addr, "", ASSIGN);                         // Assign the value
        }
        | DECREMENT unary_expression
        {
            $$ = new Expression();
            SymbolType type = SymTbl->lookup($2->addr)->type;
            if(type.type == ARRAY) {
                string t = SymTbl->gentemp(type.base_type);
                emit(t, $2->addr, *($2->name), ARR_IDX_ARG);
                emit(t, t, "1", SUB);
                emit($2->addr, t, *($2->name), ARR_IDX_RES);
                $$->addr = SymTbl->gentemp(SymTbl->lookup($2->addr)->type.base_type);
            }
            else {
                emit($2->addr, $2->addr, "1", SUB);                       // Decrement the value
                $$->addr = SymTbl->gentemp(SymTbl->lookup($2->addr)->type.type);
            }
            emit($$->addr, $2->addr, "", ASSIGN);                         // Assign the value
        }
        | unary_operator cast_expression
        {
            // Case of unary operator
            switch($1) {
                case '&':   // Address
                    $$ = new Expression();
                    $$->addr = SymTbl->gentemp(POINTER);                 // Generate temporary of the same base type
                    emit($$->addr, $2->addr, "", REFERENCE);          // Emit the quad
                    break;
                case '*':   // De-referencing
                    $$ = new Expression();
                    $$->addr = SymTbl->gentemp(INT);                     // Generate temporary of the same base type
                    $$->dim = 1;
                    $$->name = new string($2->addr);
                    emit($$->addr, $2->addr, "", DEREFERENCE);        // Emit the quad
                    break;
                case '-':   // Unary minus
                    $$ = new Expression();
                    $$->addr = SymTbl->gentemp();                        // Generate temporary of the same base type
                    emit($$->addr, $2->addr, "", U_MINUS);            // Emit the quad
                    break;
                case '!':   // Logical not 
                    $$ = new Expression();
                    $$->addr = SymTbl->gentemp(INT);                     // Generate temporary of the same base type
                    int temp = nextinstr + 2;
                    emit(to_string(temp), $2->addr, "0", GOTO_EQ);   // Emit the quads
                    temp = nextinstr + 3;
                    emit(to_string(temp), "", "", GOTO);
                    emit($$->addr, "1", "", ASSIGN);
                    temp = nextinstr + 2;
                    emit(to_string(temp), "", "", GOTO);
                    emit($$->addr, "0", "", ASSIGN);
                    break;
            }
        }
        | SIZEOF unary_expression
        {}
        | SIZEOF LEFT_PAREN type_name RIGHT_PAREN
        {}
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
        | ADD_
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
        {}
        | LEFT_PAREN type_name RIGHT_PAREN cast_expression
        {}
        ;

multiplicative_expression: 
        cast_expression
        {
            $$ = new Expression();                                  // Generate new expression
            SymbolType tp = SymTbl->lookup($1->addr)->type;
            if(tp.type == ARRAY) {                                  // If the type is an array
                string t = SymTbl->gentemp(tp.base_type);                // Generate a temporary
                if($1->name != NULL) {
                    emit(t, $1->addr, *($1->name), ARR_IDX_ARG);   // Emit the necessary quad
                    $1->addr = t;
                    $1->type = tp.base_type;
                    $$ = $1;
                }
                else
                    $$ = $1;        // Simple assignment
            }
            else
                $$ = $1;            // Simple assignment
        }
        | multiplicative_expression MULTIPLY cast_expression
        {   
            // Indicates multiplication
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }

            // Assign the result of the multiplication to the higher data type
            data_type final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            $$->addr = SymTbl->gentemp(final);                       // Store the final result in a temporary
            emit($$->addr, $1->addr, $3->addr, MULT);
        }
        | multiplicative_expression DIVIDE cast_expression
        {
            // Indicates division
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }

            // Assign the result of the division to the higher data type
            data_type final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            $$->addr = SymTbl->gentemp(final);                       // Store the final result in a temporary
            emit($$->addr, $1->addr, $3->addr, DIV);
        }
        | multiplicative_expression MODULO cast_expression
        {
            // Indicates modulo
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }

            // Assign the result of the modulo to the higher data type
            data_type final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            $$->addr = SymTbl->gentemp(final);                       // Store the final result in a temporary
            emit($$->addr, $1->addr, $3->addr, MOD);
        }
        ;

additive_expression: 
        multiplicative_expression
        {}
        | additive_expression ADD_ multiplicative_expression
        {   
            // Indicates addition
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }

            // Assign the result of the addition to the higher data type
            data_type final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            $$->addr = SymTbl->gentemp(final);                       // Store the final result in a temporary
            emit($$->addr, $1->addr, $3->addr, ADD);
        }
        | additive_expression SUBTRACT multiplicative_expression
        {
            // Indicates subtraction
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }

            // Assign the result of the subtraction to the higher data type
            data_type final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            $$->addr = SymTbl->gentemp(final);                       // Store the final result in a temporary
            emit($$->addr, $1->addr, $3->addr, SUB);
        }
        ;

shift_expression: 
        additive_expression
        {}
        | shift_expression LEFT_SHIFT additive_expression
        {
            // Indicates left shift
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }
            $$->addr = SymTbl->gentemp(one->type.type);              // Assign the result of the left shift to the data type of the left operand
            emit($$->addr, $1->addr, $3->addr, SL);
        }
        | shift_expression RIGHT_SHIFT additive_expression
        {
            // Indicates right shift
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }
            $$->addr = SymTbl->gentemp(one->type.type);              // Assign the result of the right shift to the data type of the left operand
            emit($$->addr, $1->addr, $3->addr, SR);
        }
        ;

relational_expression: 
        shift_expression
        {}
        | relational_expression LESS_THAN shift_expression
        {
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }
            $$ = new Expression();
            $$->addr = SymTbl->gentemp();
            $$->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit($$->addr, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", $1->addr, $3->addr, GOTO_LT);                // Emit "if x < y goto ..."
            emit($$->addr, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
        | relational_expression GREATER_THAN shift_expression
        {
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }
            $$ = new Expression();
            $$->addr = SymTbl->gentemp();
            $$->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit($$->addr, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", $1->addr, $3->addr, GOTO_GT);                // Emit "if x > y goto ..."
            emit($$->addr, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
        | relational_expression LESS_THAN_EQUALS shift_expression
        {
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }
            $$ = new Expression();
            $$->addr = SymTbl->gentemp();
            $$->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit($$->addr, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", $1->addr, $3->addr, GOTO_LTE);               // Emit "if x <= y goto ..."
            emit($$->addr, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
        | relational_expression GREATER_THAN_EQUALS shift_expression
        {
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }
            $$ = new Expression();
            $$->addr = SymTbl->gentemp();
            $$->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit($$->addr, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", $1->addr, $3->addr, GOTO_GTE);               // Emit "if x >= y goto ..."
            emit($$->addr, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
        ;

equality_expression: 
        relational_expression
        {
            $$ = new Expression();
            $$ = $1;                // Simple assignment
        }
        | equality_expression EQUALS relational_expression
        {
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }
            $$ = new Expression();
            $$->addr = SymTbl->gentemp();
            $$->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit($$->addr, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", $1->addr, $3->addr, GOTO_EQ);                // Emit "if x == y goto ..."
            emit($$->addr, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
        | equality_expression NOT_EQUALS relational_expression
        {
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }
            $$ = new Expression();
            $$->addr = SymTbl->gentemp();
            $$->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit($$->addr, "1", "", ASSIGN);
            $$->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", $1->addr, $3->addr, GOTO_NEQ);               // Emit "if x != y goto ..."
            emit($$->addr, "0", "", ASSIGN);
            $$->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
        ;

and_expression: 
        equality_expression
        {}
        | and_expression BITWISE_AND equality_expression
        {
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }
            $$ = new Expression();
            $$->addr = SymTbl->gentemp();                            // Create a temporary variable to store the result
            emit($$->addr, $1->addr, $3->addr, BW_AND);            // Emit the quad
        }
        ;

exclusive_or_expression: 
        and_expression
        {
            $$ = $1;    // Simple assignment
        }
        | exclusive_or_expression BITWISE_XOR and_expression
        {
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }
            $$ = new Expression();
            $$->addr = SymTbl->gentemp();                            // Create a temporary variable to store the result
            emit($$->addr, $1->addr, $3->addr, BW_XOR);            // Emit the quad
        }
        ;

inclusive_or_expression: 
        exclusive_or_expression
        {
            $$ = new Expression();
            $$ = $1;                // Simple assignment
        }
        | inclusive_or_expression BITWISE_OR exclusive_or_expression
        {
            $$ = new Expression();
            Symbol* one = SymTbl->lookup($1->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup($3->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, $3->addr, *($3->name), ARR_IDX_ARG);
                $3->addr = t;
                $3->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, $1->addr, *($1->name), ARR_IDX_ARG);
                $1->addr = t;
                $1->type = one->type.base_type;
            }
            $$ = new Expression();
            $$->addr = SymTbl->gentemp();                            // Create a temporary variable to store the result
            emit($$->addr, $1->addr, $3->addr, BW_OR);             // Emit the quad
        }
        ;

logical_and_expression: 
        inclusive_or_expression
        {}
        | logical_and_expression LOGICAL_AND M inclusive_or_expression
        {
            /*
                Here, we have augmented the grammar with the non-terminal M to facilitate backpatching
            */
            backpatch($1->truelist, $3->instr);                     // Backpatching
            $$->falselist = merge($1->falselist, $4->falselist);    // Generate falselist by merging the falselists of $1 and $4
            $$->truelist = $4->truelist;                            // Generate truelist from truelist of $4
            $$->type = BOOL;                                        // Set the type of the expression to boolean
        }
        ;

logical_or_expression: 
        logical_and_expression
        {}
        | logical_or_expression LOGICAL_OR M logical_and_expression
        {
            backpatch($1->falselist, $3->instr);                    // Backpatching
            $$->truelist = merge($1->truelist, $4->truelist);       // Generate falselist by merging the falselists of $1 and $4
            $$->falselist = $4->falselist;                          // Generate truelist from truelist of $4
            $$->type = BOOL;                                        // Set the type of the expression to boolean
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
            Symbol* one = SymTbl->lookup($5->addr);
            $$->addr = SymTbl->gentemp(one->type.type);      // Create a temporary for the expression
            $$->type = one->type.type;
            emit($$->addr, $9->addr, "", ASSIGN);         // Assign the conditional expression
            list<int> temp = makelist(nextinstr);
            emit("", "", "", GOTO);                     // Prevent fall-through
            backpatch($6->nextlist, nextinstr);         // Backpatch with nextinstr
            emit($$->addr, $5->addr, "", ASSIGN);
            temp = merge(temp, makelist(nextinstr));
            emit("", "", "", GOTO);                     // Prevent fall-through
            backpatch($2->nextlist, nextinstr);         // Backpatch with nextinstr
            convertIntToBool($1);                       // Convert the expression to boolean
            backpatch($1->truelist, $4->instr);         // When $1 is true, control goes to $4 (expression)
            backpatch($1->falselist, $8->instr);        // When $1 is false, control goes to $8 (conditional_expression)
            backpatch($2->nextlist, nextinstr);         // Backpatch with nextinstr
        }
        ;

M: %empty
        {   
            // Stores the next instruction value, and helps in backpatching
            $$ = new Expression();
            $$->instr = nextinstr;
        }
        ;

N: %empty
        {
            // Helps in control flow
            $$ = new Expression();
            $$->nextlist = makelist(nextinstr);
            emit("", "", "", GOTO);
        }
        ;

assignment_expression: 
        conditional_expression
        {}
        | unary_expression assignment_operator assignment_expression
        {
            Symbol* sym1 = SymTbl->lookup($1->addr);         // Get the first operand from the symbol table
            Symbol* sym2 = SymTbl->lookup($3->addr);         // Get the second operand from the symbol table
            if($1->dim == 0) {
                if(sym1->type.type != ARRAY)
                    emit($1->addr, $3->addr, "", ASSIGN);
                else
                    emit($1->addr, $3->addr, *($1->name), ARR_IDX_RES);
            }
            else
                emit(*($1->name), $3->addr, "", L_DEREF);
            $$ = $1;        // Assignment 
        }
        ;

assignment_operator: 
        ASSIGNMENT 
        {}
        | MUL_ASSIGNMENT 
        {}
        | DIV_ASSIGNMENT 
        {}
        | MOD_ASSIGNMENT 
        {}
        | ADD_ASSIGNMENT
        {}
        | SUB_ASSIGNMENT
        {}
        | LSHIFT_ASSIGNMENT
        {}
        | RSHIFT_ASSIGNMENT
        {}
        | AND_ASSIGNMENT
        {}
        | XOR_ASSIGNMENT
        {}
        | OR_ASSIGNMENT
        {}
        ;

expression: 
        assignment_expression
        {}
        | expression COMMA assignment_expression
        {}
        ;

constant_expression: 
        conditional_expression
        {}
        ;

declaration: 
        declaration_specifiers init_declarator_list SEMICOLON
        {
            data_type currType = $1;
            int currSize = -1;
            // Assign correct size for the data type
            if(currType == INT)
                currSize = _SIZE_INT;
            else if(currType == CHAR)
                currSize = _SIZE_CHAR;
            else if(currType == FLOAT)
                currSize = _SIZE_FLOAT;
            vector<Declaration*> decs = *($2);
            for (vector<Declaration*>::iterator it = decs.begin(); it != decs.end(); it++) {
                Declaration* currDec = *it;
                if(currDec->type == FUNCTION) {
                    SymTbl = &SymTbl_Global;
                    emit(currDec->name, "", "", FUNC_END);
                    Symbol* one = SymTbl->lookup(currDec->name);        // Create an entry for the function
                    Symbol* two = one->nested_table->lookup("RETVAL", currType, currDec->num_ptrs);
                    one->size = 0;
                    one->init_val = NULL;
                    continue;
                }

                Symbol* three = SymTbl->lookup(currDec->name, currType);        // Create an entry for the variable in the symbol table
                three->nested_table = NULL;
                if(currDec->li == vector<int>() && currDec->num_ptrs == 0) {
                    three->type.type = currType;
                    three->size = currSize;
                    if(currDec->init_val != NULL) {
                        string rval = currDec->init_val->addr;
                        emit(three->name, rval, "", ASSIGN);
                        three->init_val = SymTbl->lookup(rval)->init_val;
                    }
                    else
                        three->init_val = NULL;
                }
                else if(currDec->li != vector<int>()) {         // Handle array types
                    three->type.type = ARRAY;
                    three->type.base_type = currType;
                    three->type.dims = currDec->li;
                    vector<int> temp = three->type.dims;
                    int sz = currSize;
                    for (int i = 0; i < (int)temp.size(); i++)
                        sz *= temp[i];
                    SymTbl->offset += sz;
                    three->size = sz;
                    SymTbl->offset -= 4;
                }
                else if(currDec->num_ptrs != 0) {               // Handle pointer types
                    three->type.type = POINTER;
                    three->type.base_type = currType;
                    three->type.num_ptrs = currDec->num_ptrs;
                    SymTbl->offset += (_SIZE_POINTER - currSize);
                    three->size = _SIZE_POINTER;
                }
            }
        }
        | declaration_specifiers SEMICOLON
        {}
        ;

declaration_specifiers: 
        storage_class_specifier declaration_specifiers
        {}
        |storage_class_specifier
        {}
        | type_specifier declaration_specifiers
        {}
        | type_specifier
        {}
        | type_qualifier declaration_specifiers
        {}
        | type_qualifier
        {}
        | function_specifier declaration_specifiers
        {}
        | function_specifier
        {}
        ;

init_declarator_list: 
        init_declarator
        {
            $$ = new vector<Declaration*>;      // Create a vector of declarations and add $1 to it
            $$->push_back($1);
        }
        | init_declarator_list COMMA init_declarator
        {
            $1->push_back($3);                  // Add $3 to the vector of declarations
            $$ = $1;
        }
        ;

init_declarator: 
        declarator
        {
            $$ = $1;
            $$->init_val = NULL;         // Initialize the init_val to NULL as no initialization is done
        }
        | declarator ASSIGNMENT  initializer
        {   
            $$ = $1;
            $$->init_val = $3;           // Initialize the init_val to the value provided
        }
        ;

storage_class_specifier: 
        EXTERN
        {}
        | STATIC
        {}
        | AUTO
        {}
        | REGISTER
        {}
        ;

type_specifier: 
        VOID_
        {
            $$ = VOID;
        }
        | CHAR_
        {
            $$ = CHAR;
        }
        | SHORT
        {}
        | INT_
        {
            $$ = INT; 
        }
        | LONG
        {}
        | FLOAT_
        {
            $$ = FLOAT;
        }
        | DOUBLE
        {}
        | SIGNED
        {}
        | UNSIGNED
        {}
        | BOOL_
        {}
        | COMPLEX
        {}
        | IMAGINARY
        {}
        | enum_specifier
        {}
        ;

specifier_qualifier_list: 
        type_specifier specifier_qualifier_list_opt
        {}
        | type_qualifier specifier_qualifier_list_opt
        {}
        ;

specifier_qualifier_list_opt: 
        specifier_qualifier_list
        {}
        | %empty
        {}
        ;

enum_specifier: 
        ENUM LEFT_CURLY_BRACE enumerator_list RIGHT_CURLY_BRACE
        {}
        | ENUM IDENTIFIER LEFT_CURLY_BRACE enumerator_list RIGHT_CURLY_BRACE
        {}
        | ENUM IDENTIFIER LEFT_CURLY_BRACE enumerator_list COMMA RIGHT_CURLY_BRACE
        {}
        | ENUM IDENTIFIER
        {}
        ;

enumerator_list: 
        enumerator
        {}
        | enumerator_list COMMA enumerator
        {}
        ;

enumerator: 
        IDENTIFIER
        {}
        | IDENTIFIER ASSIGNMENT  constant_expression
        {}
        ;

type_qualifier: 
        CONST
        {}
        | RESTRICT
        {}
        | VOLATILE
        {}
        ;

function_specifier: 
        INLINE
        {}
        ;

declarator: 
        pointer direct_declarator
        {
            $$ = $2;
            $$->num_ptrs = $1;
        }
        | direct_declarator
        {
            $$ = $1;
            $$->num_ptrs = 0;
        }
        ;

direct_declarator: 
        IDENTIFIER
        {
            $$ = new Declaration();
            $$->name = *($1);
        }
        | LEFT_PAREN declarator RIGHT_PAREN
        {}
        | direct_declarator LEFT_SQR_BRACKET type_qualifier_list_opt RIGHT_SQR_BRACKET
        {
            $1->type = ARRAY;       // Array type
            $1->nextType = INT;     // Array of ints
            $$ = $1;
            $$->li.push_back(0);
        }
        | direct_declarator LEFT_SQR_BRACKET type_qualifier_list_opt assignment_expression RIGHT_SQR_BRACKET
        {
            $1->type = ARRAY;       // Array type
            $1->nextType = INT;     // Array of ints
            $$ = $1;
            int index = SymTbl->lookup($4->addr)->init_val->int_;
            $$->li.push_back(index);
        }
        | direct_declarator LEFT_SQR_BRACKET STATIC type_qualifier_list assignment_expression RIGHT_SQR_BRACKET
        {}
        | direct_declarator LEFT_SQR_BRACKET type_qualifier_list STATIC assignment_expression RIGHT_SQR_BRACKET
        {}
        | direct_declarator LEFT_SQR_BRACKET type_qualifier_list_opt MULTIPLY RIGHT_SQR_BRACKET
        {
            $1->type = POINTER;     // Pointer type
            $1->nextType = INT;
            $$ = $1;
        }
        | direct_declarator LEFT_PAREN parameter_type_list_opt RIGHT_PAREN
        {
            $$ = $1;
            $$->type = FUNCTION;    // Function type
            Symbol* funcData = SymTbl->lookup($$->name, $$->type);
            SymbolTable* funcTable = new SymbolTable();
            funcData->nested_table = funcTable;
            vector<Parameter*> paramList = *($3);   // Get the parameter list

            for (int i = 0; i < (int)paramList.size(); i++) {
                Parameter* curParam = paramList[i];

                if(curParam->type.type == ARRAY)    // If the parameter is an array
                {         
                    funcTable->lookup(curParam->name, curParam->type.type);
                    funcTable->lookup(curParam->name)->type.base_type = INT;
                    funcTable->lookup(curParam->name)->type.dims.push_back(0);
                }

                else if(curParam->type.type == POINTER)    // If the parameter is a pointer
                {
                    funcTable->lookup(curParam->name, curParam->type.type);
                    funcTable->lookup(curParam->name)->type.base_type = INT;
                    funcTable->lookup(curParam->name)->type.dims.push_back(0);
                }

                else                                        // If the parameter is a anything other than an array or a pointer
                    funcTable->lookup(curParam->name, curParam->type.type);
            }

            SymTbl = funcTable;         // Set the pointer to the symbol table to the function's symbol table
            emit($$->name, "", "", FUNC_BEG);
        }
        | direct_declarator LEFT_PAREN identifier_list RIGHT_PAREN
        {}
        ;

parameter_type_list_opt:
        parameter_type_list
        {}
        | %empty
        {
            $$ = new vector<Parameter*>;
        }
        ;

type_qualifier_list_opt: 
        type_qualifier_list
        {}
        | %empty
        {}
        ;

pointer: 
        MULTIPLY type_qualifier_list
        {}
        | MULTIPLY
        {
            $$ = 1;
        }
        | MULTIPLY type_qualifier_list pointer
        {}
        | MULTIPLY pointer
        {
            $$ = 1 + $2;
        }
        ;

type_qualifier_list: 
        type_qualifier
        {}
        | type_qualifier_list type_qualifier
        {}
        ;

parameter_type_list: 
        parameter_list
        | parameter_list COMMA ELLIPSIS
        ;

parameter_list: 
        parameter_declaration
        {
            $$ = new vector<Parameter*>;         // Create a new vector of parameters
            $$->push_back($1);              // Add the parameter to the vector
        }
        | parameter_list COMMA parameter_declaration
        {
            $1->push_back($3);              // Add the parameter to the vector
            $$ = $1;
        }
        ;

parameter_declaration: 
        declaration_specifiers declarator
        {
            $$ = new Parameter();
            $$->name = $2->name;
            if($2->type == ARRAY) {
                $$->type.type = ARRAY;
                $$->type.base_type = $1;
            }
            else if($2->pc != 0) {
                $$->type.type = POINTER;
                $$->type.base_type = $1;
            }
            else
                $$->type.type = $1;
        }
        | declaration_specifiers
        {}
        ;

identifier_list: 
        IDENTIFIER
        {}
        | identifier_list COMMA IDENTIFIER
        {}
        ;

type_name: 
        specifier_qualifier_list
        {}
        ;

initializer: 
        assignment_expression
        {
            $$ = $1;   // Simple assignment
        }
        | LEFT_CURLY_BRACE initializer_list RIGHT_CURLY_BRACE
        {}
        | LEFT_CURLY_BRACE initializer_list COMMA RIGHT_CURLY_BRACE
        {}
        ;

initializer_list: 
        designation_opt initializer
        {}
        | initializer_list COMMA designation_opt initializer
        {}
        ;

designation_opt: 
        designation
        {}
        | %empty
        {}
        ;

designation: 
        designator_list ASSIGNMENT 
        {}
        ;

designator_list: 
        designator
        {}
        | designator_list designator
        {}
        ;

designator: 
        LEFT_SQR_BRACKET constant_expression RIGHT_SQR_BRACKET
        {}
        | DOT IDENTIFIER
        {}
        ;

statement: 
        labeled_statement
        {}
        | compound_statement
        | expression_statement
        | selection_statement
        | iteration_statement
        | jump_statement
        ;

labeled_statement: 
        IDENTIFIER COLON statement
        {}
        | CASE constant_expression COLON statement
        {}
        | DEFAULT COLON statement
        {}
        ;

compound_statement: 
        LEFT_CURLY_BRACE RIGHT_CURLY_BRACE
        {}
        | LEFT_CURLY_BRACE block_item_list RIGHT_CURLY_BRACE
        {
            $$ = $2;
        }
        ;

block_item_list: 
        block_item
        {
            $$ = $1;    // Simple assignment
            backpatch($1->nextlist, nextinstr);
        }
        | block_item_list M block_item
        {   
            /*
                This production rule has been augmented with the non-terminal M
            */
            $$ = new Expression();
            backpatch($1->nextlist, $2->instr);    // After $1, move to block_item via $2
            $$->nextlist = $3->nextlist;
        }
        ;

block_item: 
        declaration
        {
            $$ = new Expression();   // Create new expression
        }
        | statement
        ;

expression_statement: 
        expression SEMICOLON
        {}
        | SEMICOLON
        {
            $$ = new Expression();  // Create new expression
        }
        ;

selection_statement: 
        IF LEFT_PAREN expression N RIGHT_PAREN M statement N
        {
            /*
                This production rule has been augmented for control flow
            */
            backpatch($4->nextlist, nextinstr);         // nextlist of N now has nextinstr
            convertIntToBool($3);                       // Convert expression to bool
            backpatch($3->truelist, $6->instr);         // Backpatching - if expression is true, go to M
            $$ = new Expression();                      // Create new expression
            // Merge falselist of expression, nextlist of statement and nextlist of the last N
            $7->nextlist = merge($8->nextlist, $7->nextlist);
            $$->nextlist = merge($3->falselist, $7->nextlist);
        }
        | IF LEFT_PAREN expression N RIGHT_PAREN M statement N ELSE M statement N
        {
            /*
                This production rule has been augmented for control flow
            */
            backpatch($4->nextlist, nextinstr);         // nextlist of N now has nextinstr
            convertIntToBool($3);                       // Convert expression to bool
            backpatch($3->truelist, $6->instr);         // Backpatching - if expression is true, go to first M, else go to second M
            backpatch($3->falselist, $10->instr);
            $$ = new Expression();                      // Create new expression
            // Merge nextlist of statement, nextlist of N and nextlist of the last statement
            $$->nextlist = merge($7->nextlist, $8->nextlist);
            $$->nextlist = merge($$->nextlist, $11->nextlist);
            $$->nextlist = merge($$->nextlist, $12->nextlist);
        }
        | SWITCH LEFT_PAREN expression RIGHT_PAREN statement
        {}
        ;

iteration_statement: 
        WHILE M LEFT_PAREN expression N RIGHT_PAREN M statement
        {   
            /*
                This production rule has been augmented with non-terminals like M and N to handle the control flow and backpatching
            */
            $$ = new Expression();                   // Create a new expression
            emit("", "", "", GOTO);
            backpatch(makelist(nextinstr - 1), $2->instr);
            backpatch($5->nextlist, nextinstr);
            convertIntToBool($4);                   // Convert expression to bool
            $$->nextlist = $4->falselist;           // Exit loop if expression is false
            backpatch($4->truelist, $7->instr);     // Backpatching - if expression is true, go to M
            backpatch($8->nextlist, $2->instr);     // Backpatching - go to the beginning of the loop
        }
        | DO M statement M WHILE LEFT_PAREN expression N RIGHT_PAREN SEMICOLON
        {
            /*
                This production rule has been augmented with non-terminals like M and N to handle the control flow and backpatching
            */
            $$ = new Expression();                  // Create a new expression  
            backpatch($8->nextlist, nextinstr);     // Backpatching 
            convertIntToBool($7);                   // Convert expression to bool
            backpatch($7->truelist, $2->instr);     // Backpatching - if expression is true, go to M
            backpatch($3->nextlist, $4->instr);     // Backpatching - go to the beginning of the loop
            $$->nextlist = $7->falselist;
        }
        | FOR LEFT_PAREN expression_statement M expression_statement N M expression N RIGHT_PAREN M statement
        {
            /*
                This production rule has been augmented with non-terminals like M and N to handle the control flow and backpatching
            */
            $$ = new Expression();                   // Create a new expression
            emit("", "", "", GOTO);
            $12->nextlist = merge($12->nextlist, makelist(nextinstr - 1));
            backpatch($12->nextlist, $7->instr);    // Backpatching - go to the beginning of the loop
            backpatch($9->nextlist, $4->instr);     
            backpatch($6->nextlist, nextinstr);     
            convertIntToBool($5);                   // Convert expression to bool
            backpatch($5->truelist, $11->instr);    // Backpatching - if expression is true, go to M
            $$->nextlist = $5->falselist;           // Exit loop if expression is false
        }
        ;

jump_statement: 
        GOTO_ IDENTIFIER SEMICOLON
        {}
        | CONTINUE SEMICOLON
        {}
        | BREAK SEMICOLON
        {}
        | RETURN_ SEMICOLON
        {
            if(SymTbl->lookup("RETVAL")->type.type == VOID) {
                emit("", "", "", RETURN);           // Emit the quad when return type is void
            }
            $$ = new Expression();
        }
        | RETURN_ expression SEMICOLON
        {
            if(SymTbl->lookup("RETVAL")->type.type == SymTbl->lookup($2->addr)->type.type) {
                emit($2->addr, "", "", RETURN);      // Emit the quad when return type is not void
            }
            $$ = new Expression();
        }
        ;

translation_unit: 
        external_declaration
        {}
        | translation_unit external_declaration
        {}
        ;

external_declaration: 
        function_definition
        {}
        | declaration
        {}
        ;

function_definition: 
        declaration_specifiers declarator declaration_list compound_statement
        {}
        | function_prototype compound_statement
        {
            SymTbl = &SymTbl_Global;                     // Reset the symbol table to global symbol table
            emit($1->name, "", "", FUNC_END);
        }
        ;

function_prototype:
        declaration_specifiers declarator
        {
            data_type currType = $1;
            int currSize = -1;
            if(currType == CHAR)
                currSize = _SIZE_CHAR;
            if(currType == INT)
                currSize = _SIZE_INT;
            if(currType == FLOAT)
                currSize = _SIZE_FLOAT;
            Declaration* currDec = $2;
            Symbol* sym = SymTbl_Global.lookup(currDec->name);
            if(currDec->type == FUNCTION) {
                Symbol* retval = sym->nested_table->lookup("RETVAL", currType, currDec->num_ptrs);   // Create entry for return value
                sym->size = 0;
                sym->init_val = NULL;
            }
            $$ = $2;
        }
        ;

declaration_list: 
        declaration
        {}
        | declaration_list declaration
        {}
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
