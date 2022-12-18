%{
    #include <stdio.h>
    extern int yylex();
    void yyerror(char *s);
    extern char* yytext;
    extern int yylineno;
%}

%union {
    int intval;
    float floatval;
    char *strval;
    char charval;
}

%token IDENTIFIER
%token <intval> INT_CONSTANT
%token <floatval> FLOAT_CONSTANT
%token <charval> CHAR_CONSTANT
%token <strval> STRING_LITERAL

%token EXTERN STATIC AUTO REGISTER CONST RESTRICT VOLATILE INLINE CASE DEFAULT
%token VOID CHAR SHORT INT LONG FLOAT DOUBLE ENUM SIGNED UNSIGNED BOOL COMPLEX IMAGINARY
%token DOT ARROW LEFT_PAREN RIGHT_PAREN LEFT_CURLY_BRACE RIGHT_CURLY_BRACE LEFT_SQR_BRACKET RIGHT_SQR_BRACKET
%token ADD SUBTRACT MULTIPLY DIVIDE MODULO SIZEOF
%token LESS_THAN LESS_THAN_EQUALS GREATER_THAN GREATER_THAN_EQUALS EQUALS NOT_EQUALS
%token AND OR NOT
%token IF ELSE SWITCH
%token WHILE DO FOR
%token GOTO CONTINUE BREAK RETURN
%token BITWISE_AND BITWISE_OR BITWISE_NOT BITWISE_XOR
%token SEMICOLON COMMA COLON
%token INCREMENT DECREMENT
%token ASSIGNMENT ADD_ASSIGNMENT SUB_ASSIGNMENT MUL_ASSIGNMENT DIV_ASSIGNMENT MOD_ASSIGNMENT LSHIFT_ASSIGNMENT RSHIFT_ASSIGNMENT BITWISE_AND_ASSIGNMENT BITWISE_XOR_ASSIGNMENT BITWISE_OR_ASSIGNMENT
%token LEFT_SHIFT RIGHT_SHIFT
%token QUESTION_MARK ELLIPSIS

%start translation_unit

%nonassoc RIGHT_PAREN
%nonassoc ELSE

%%
primary_expression: IDENTIFIER 
                    {    printf("primary-expression ==> identifier\n");   }  
                    
                    | constant 
                    {    printf("primary-expression ==> constant\n");   } 
                    
                    | STRING_LITERAL 
                    {    printf("primary-expression ==> string-literal\n");   } 
                    
                    | LEFT_PAREN expression RIGHT_PAREN
                    {    printf("primary-expression ==> ( expression )\n");   }
                    ;

constant: INT_CONSTANT     
          {     printf("constant ==> int-const\n");      } 
          | FLOAT_CONSTANT 
          {     printf("constant ==> float-const\n");     } 
          | CHAR_CONSTANT 
          {     printf("constant ==> char-const\n");     }
          ;

postfix_expression: primary_expression
                        {    printf("postfix-expression ==> primary-expression\n");   } 
                    |   postfix_expression LEFT_SQR_BRACKET expression RIGHT_SQR_BRACKET
                        {    printf("postfix-expression ==> postfix-expression [ expression ]\n");   }
                    |   postfix_expression LEFT_PAREN argument_expression_list_opt RIGHT_PAREN
                        {    printf("postfix-expression ==> postfix-expression ( argument-expression-list-opt )\n");   }
                    |   postfix_expression DOT IDENTIFIER
                        {    printf("postfix-expression ==> postfix-expression . identifier\n");   }
                    |   postfix_expression ARROW IDENTIFIER
                        {    printf("postfix-expression ==> postfix-expression -> identifier\n");   }
                    |   postfix_expression INCREMENT
                        {    printf("postfix-expression ==> postfix-expression ++\n");   }
                    |   postfix_expression DECREMENT 
                        {    printf("postfix-expression ==> postfix-expression --\n");   }
                    |   LEFT_PAREN type_name RIGHT_PAREN LEFT_CURLY_BRACE initializer_list RIGHT_CURLY_BRACE
                        {    printf("postfix-expression ==> ( type_name ) { initializer-list }\n");   }
                    |   LEFT_PAREN type_name RIGHT_PAREN LEFT_CURLY_BRACE initializer_list COMMA RIGHT_CURLY_BRACE
                        {    printf("postfix-expression ==> ( type_name ) { initializer-list , }\n");   }
                    ;

argument_expression_list_opt: argument_expression_list
                                { printf("argument-expression-list-opt ==> argument-expression-list\n");   }
                            |
                                { printf("argument-expression-list-opt ==> epsilon\n");   }
                            ;

argument_expression_list:   assignment_expression
                                { printf("argument-expression-list ==> assignment_expression\n");   }
                            | argument_expression_list COMMA assignment_expression
                                { printf("argument-expression-list ==> argument-expression-list , assignment_expression\n");   }
                            ;

unary_expression:   postfix_expression
                    { printf("unary-expression ==> postfix-expression\n");   } 
                    |INCREMENT unary_expression
                    { printf("unary-expression ==> ++ unary-expression\n");   } 
                    | DECREMENT unary_expression
                    { printf("unary-expression ==> -- unary-expression\n");   } 
                    | unary_operator cast_expression
                    { printf("unary-expression ==> unary-operator cast-expression\n");   } 
                    | SIZEOF unary_expression
                    { printf("unary-expression ==> sizeof unary-expression\n");   } 
                    | SIZEOF LEFT_PAREN type_name RIGHT_PAREN
                    { printf("unary-expression ==> sizeof ( type-name )\n");   }
                    ;

unary_operator:     BITWISE_AND
                    { printf("unary-operator ==> &\n");   } 
                    
                    | MULTIPLY
                    { printf("unary-operator ==> *\n");   } 
                    
                    | ADD
                    { printf("unary-operator ==> +\n");   } 
                    
                    | SUBTRACT
                    { printf("unary-operator ==> -\n");   }
                    
                    | BITWISE_NOT
                    { printf("unary-operator ==> ~\n");   }
                    
                    | NOT
                    { printf("unary-operator ==> !\n");   }
                    ;

cast_expression:    unary_expression
                    { printf("cast-expression ==> unary-expression\n");   }
                    | LEFT_PAREN type_name RIGHT_PAREN cast_expression
                    { printf("cast-expression ==> ( type-name ) cast-expression\n");   }
                    ;

multiplicative_expression:  cast_expression
                            { printf("multiplicative-expression ==> cast-expression\n");   }
                            | multiplicative_expression MULTIPLY cast_expression
                            { printf("multiplicative-expression ==> multiplicative-expression * cast-expression\n");   }
                            | multiplicative_expression DIVIDE cast_expression
                            { printf("multiplicative-expression ==> multiplicative-expression / cast-expression\n");   }                        
                            | multiplicative_expression MODULO cast_expression
                            { printf("multiplicative-expression ==> multiplicative-expression %% cast-expression\n");   } 
                            ;                      

additive_expression:    multiplicative_expression
                        { printf("additive-expression ==> multiplicative-expression\n");   }
                        | additive_expression ADD multiplicative_expression
                        { printf("additive-expression ==> additive-expression + multiplicative-expression\n");   }
                        | additive_expression SUBTRACT multiplicative_expression
                        { printf("additive-expression ==> additive-expression - multiplicative-expression\n");   }
                        ;

shift_expression:   additive_expression
                    { printf("shift-expression ==> additive-expression\n");   }
                    | shift_expression LEFT_SHIFT additive_expression
                    { printf("shift-expression ==> shift-expression << additive-expression\n");   }
                    | shift_expression RIGHT_SHIFT additive_expression
                    { printf("shift-expression ==> shift-expression >> additive-expression\n");   }
                    ;

relational_expression:  shift_expression
                        { printf("relational-expression ==> shift-expression\n");   }
                        | relational_expression LESS_THAN shift_expression
                        { printf("relational-expression ==> relational-expression < shift-expression\n");   }                
                        | relational_expression GREATER_THAN shift_expression
                        { printf("relational-expression ==> relational-expression > shift-expression\n");   }                
                        | relational_expression LESS_THAN_EQUALS shift_expression
                        { printf("relational-expression ==> relational-expression <= shift-expression\n");   }                                    
                        | relational_expression GREATER_THAN_EQUALS shift_expression
                        { printf("relational-expression ==> relational-expression >= shift-expression\n");  }
                        ;                
                        
equality_expression:    relational_expression
                        { printf("equality-expression ==> relational-expression\n");   }                
                        | equality_expression EQUALS relational_expression
                        { printf("equality-expression ==> equality-expression == relational-expression\n");   }                                        
                        | equality_expression NOT_EQUALS relational_expression
                        { printf("equality-expression ==> equality-expression != relational-expression\n");   }
                        ;                                                           
                        
AND_expression:     equality_expression
                    { printf("AND-expression ==> equality-expression\n");   }                                        
                    | AND_expression BITWISE_AND equality_expression
                    { printf("AND-expression ==> AND-expression & equality-expression\n");   }
                    ;                                    

exclusive_OR_expression:    AND_expression
                            { printf("exclusive-OR-expression ==> AND-expression\n");   }                                        
                            | exclusive_OR_expression BITWISE_XOR AND_expression
                            { printf("exclusive-OR-expression ==> exclusive-OR-expression ^ AND-expression\n");   }
                            ;                                      
                            
inclusive_OR_expression:    exclusive_OR_expression
                            { printf("inclusive-OR-expression ==> exclusive-OR-expression\n");   }                                        
                            | inclusive_OR_expression BITWISE_OR exclusive_OR_expression
                            { printf("inclusive-OR-expression ==> inclusive-OR-expression | exclusive-OR-expression\n");   }
                            ;                                        

logical_AND_expression:     inclusive_OR_expression
                            { printf("logical-AND-expression ==> inclusive-OR-expression\n");   }
                            | logical_AND_expression AND inclusive_OR_expression
                            { printf("logical-AND-expression ==> logical-AND-expression && inclusive-OR-expression\n");   }
                            ;

logical_OR_expression:      logical_AND_expression
                            { printf("logical-OR-expression ==> logical-AND-expression\n");   }
                            | logical_OR_expression OR logical_AND_expression
                            { printf("logical-OR-expression ==> logical-OR-expression || logical-AND-expression\n");   }
                            ;

conditional_expression:     logical_OR_expression
                            { printf("conditional-expression ==> logical-OR-expression\n");   }
                            | logical_OR_expression QUESTION_MARK expression COLON conditional_expression
                            { printf("conditional-expression ==> logical-OR-expression ? expression : conditional-expression\n");   }
                            ;


assignment_expression:      conditional_expression
                            { printf("assignment-expression ==> conditional-expression\n");   }
                            | unary_expression assignment_operator assignment_expression
                            { printf("assignment-expression ==> unary-expression assignment-operator assignment-expression\n");   }
                            ;

assignment_operator:    ASSIGNMENT
                        { printf("assignment-operator ==> =\n");   }
                        | MUL_ASSIGNMENT
                        { printf("assignment-operator ==> *=\n");   } 
                        | DIV_ASSIGNMENT
                        { printf("assignment-operator ==> /=\n");   }   
                        | MOD_ASSIGNMENT
                        { printf("assignment-operator ==> %%=\n");   }                                                                    
                        | ADD_ASSIGNMENT
                        { printf("assignment-operator ==> +=\n");   }
                        | SUB_ASSIGNMENT
                        { printf("assignment-operator ==> -=\n");   }
                        | LSHIFT_ASSIGNMENT
                        { printf("assignment-operator ==> <<=\n");   }
                        | RSHIFT_ASSIGNMENT
                        { printf("assignment-operator ==> >>=\n");   }
                        | BITWISE_AND_ASSIGNMENT
                        { printf("assignment-operator ==> &=\n");   }
                        | BITWISE_XOR_ASSIGNMENT
                        { printf("assignment-operator ==> ^=\n");   }
                        | BITWISE_OR_ASSIGNMENT
                        { printf("assignment-operator ==> |=\n");   }
                        ;



expression:     assignment_expression
                { printf("expression ==> assignment-expression\n");   }
                | expression COMMA assignment_expression
                { printf("expression ==> expression , assignment-expression\n");   }
                ;

constant_expression:    conditional_expression
                        { printf("constant-expression ==> conditional-expression\n");   }
                        ;

declaration:    declaration_specifiers init_declarator_list_opt SEMICOLON
                { printf("declaration ==> declaration_specifiers init-declarator-list-opt ;\n");   }
                ;

init_declarator_list_opt:   init_declarator_list
                            { printf("init-declarator-list-opt ==> init-declarator-list\n");   } 
                            |
                            { printf("init-declarator-list-opt ==> epsilon\n");   }
                            ;


declaration_specifiers:     storage_class_specifier declaration_specifiers_opt
                            { printf("declaration_specifiers ==> storage-class-specifier declaration_specifiers-opt\n");   }
                            | type_specifier declaration_specifiers_opt
                            { printf("declaration_specifiers ==> type-specifier declaration_specifiers-opt\n");   }
                            | type_qualifier declaration_specifiers_opt
                            { printf("declaration_specifiers ==> type_qualifier declaration_specifiers-opt\n");   }
                            | function_specifier declaration_specifiers_opt
                            { printf("declaration_specifiers ==> function-specifier declaration_specifiers-opt\n");   }
                            ;

declaration_specifiers_opt:    declaration_specifiers
                                { printf("declaration_specifiers-opt ==> declaration_specifiers\n");   } 
                                |
                                { printf("declaration_specifiers-opt ==> epsilon\n");   }
                                ;


init_declarator_list:   init_declarator
                        { printf("init-declarator-list ==> init-declarator\n");   }
                        | init_declarator_list COMMA init_declarator
                        { printf("init-declarator-list ==> init-declarator-list , init-declarator\n");   }
                        ;

init_declarator:    declarator
                    { printf("init-declarator ==> declarator\n");   }
                    | declarator ASSIGNMENT initializer
                    { printf("init-declarator ==> declarator = initializer\n");   }
                    ;

storage_class_specifier:    EXTERN
                            { printf("storage-class-specifier ==> extern\n");   }
                            | STATIC
                            { printf("storage-class-specifier ==> static\n");   }
                            | AUTO
                            { printf("storage-class-specifier ==> auto\n");   }
                            | REGISTER
                            { printf("storage-class-specifier ==> register\n");   }
                            ;

type_specifier:     VOID
                    { printf("type-specifier ==> void\n");   }
                    | CHAR
                    { printf("type-specifier ==> char\n");   }
                    | SHORT
                    { printf("type-specifier ==> short\n");   }
                    | INT
                    { printf("type-specifier ==> int\n");   }
                    | LONG
                    { printf("type-specifier ==> long\n");   }
                    | FLOAT
                    { printf("type-specifier ==> float\n");   }
                    | DOUBLE
                    { printf("type-specifier ==> double\n");   }
                    | SIGNED
                    { printf("type-specifier ==> signed\n");   }
                    | UNSIGNED
                    { printf("type-specifier ==> unsigned\n");   }
                    | BOOL
                    { printf("type-specifier ==> _Bool\n");   }
                    | COMPLEX
                    { printf("type-specifier ==> _Complex\n");   }
                    | IMAGINARY
                    { printf("type-specifier ==> _Imaginary\n");   }
                    | enum_specifier
                    { printf("type-specifier ==> enum-specifier\n");   }
                    ;



specifier_qualifier_list:   type_specifier specifier_qualifier_list_opt
                            { printf("specifier-qualifier-list ==> type-specifier specifier-qualifier-list-opt\n");   }
                            | type_qualifier specifier_qualifier_list_opt
                            { printf("specifier-qualifier-list ==> type_qualifier specifier-qualifier-list-opt\n");   }
                            ;

specifier_qualifier_list_opt:   specifier_qualifier_list
                                { printf("specifier-qualifier-list-opt ==> specifier-qualifier-list\n");   } 
                                |
                                { printf("specifier-qualifier-list-opt ==> epsilon\n");   }
                                ;

enum_specifier:     ENUM identifier_opt LEFT_CURLY_BRACE enumerator_list RIGHT_CURLY_BRACE
                    { printf("enum-specifier ==> enum identifier-opt { enumerator-list }\n");   }
                    | ENUM identifier_opt LEFT_CURLY_BRACE enumerator_list COMMA RIGHT_CURLY_BRACE
                    { printf("enum-specifier ==> enum identifier-opt { enumerator-list , }\n");   }
                    | ENUM IDENTIFIER
                    { printf("enum-specifier ==> enum identifier\n");   }
                    ;


identifier_opt: IDENTIFIER 
                {     printf("identifier-opt ==> identifier\n");     } 
                
                |
                {     printf("identifier-opt ==> epsilon\n");     }
                ;

enumerator_list:    enumerator
                    { printf("enumerator-list ==> enumerator\n");   }
                    | enumerator_list COMMA enumerator
                    { printf("enumerator-list ==> enumerator-list , enumerator\n");   }
                    ;

enumerator:     IDENTIFIER  
                { printf("enumerator ==> enumeration-constant\n");   }
                | IDENTIFIER ASSIGNMENT constant_expression
                { printf("enumerator ==> enumeration-constant = constant-expression\n");   }
                ;

type_qualifier:     CONST
                    { printf("type_qualifier ==> const\n");     }
                    | RESTRICT
                    { printf("type_qualifier ==> restrict\n");     }
                    | VOLATILE
                    { printf("type_qualifier ==> volatile\n");     }
                    ;

function_specifier:     INLINE
                        { printf("function_specifier ==> inline\n");     }
                        ;
                        
declarator:     pointer_opt direct_declarator
                { printf("declarator ==> pointer-opt direct_declarator\n");     }
                ;

pointer_opt:    pointer
                { printf("pointer-opt ==> pointer\n");   } 
                |
                { printf("pointer-opt ==> epsilon\n");   }
                ;

direct_declarator:  IDENTIFIER
                    { printf("direct-declarator ==> identifier\n");     }
                    | LEFT_PAREN declarator RIGHT_PAREN
                    { printf("direct-declarator ==> ( declarator )\n");     }
                    | direct_declarator LEFT_SQR_BRACKET type_qualifier_list_opt assignment_expression_opt RIGHT_SQR_BRACKET
                    { printf("direct-declarator ==> direct-declarator [ type-qualifier-list-opt assignment-expression-opt ]\n");     }
                    | direct_declarator LEFT_SQR_BRACKET STATIC type_qualifier_list_opt assignment_expression RIGHT_SQR_BRACKET
                    { printf("direct-declarator ==> direct-declarator [ static type-qualifier-list-opt assignment-expression ]\n");     }
                    | direct_declarator LEFT_SQR_BRACKET type_qualifier_list STATIC assignment_expression RIGHT_SQR_BRACKET
                    { printf("direct-declarator ==> direct-declarator [ type-qualifier-list static assignment-expression ]\n");     }
                    | direct_declarator LEFT_SQR_BRACKET type_qualifier_list_opt MULTIPLY RIGHT_SQR_BRACKET
                    { printf("direct-declarator ==> direct-declarator [ type-qualifier-list-opt * ]\n");     }
                    | direct_declarator LEFT_PAREN parameter_type_list RIGHT_PAREN
                    { printf("direct-declarator ==> direct-declarator ( parameter-type-list )\n");     }
                    | direct_declarator LEFT_PAREN identifier_list_opt RIGHT_PAREN
                    { printf("direct-declarator ==> direct-declarator ( identifier-list-opt )\n");     }
                    ;



type_qualifier_list_opt:    type_qualifier_list
                            { printf("type-qualifier-list-opt ==> type-qualifier-list\n");   } 
                            |
                            { printf("type-qualifier-list-opt ==> epsilon\n");   }
                            ;
assignment_expression_opt:  assignment_expression
                            { printf("assignment-expression-opt ==> assignment-expression\n");   } 
                            |
                            { printf("assignment-expression-opt ==> epsilon\n");   }
                            ;

identifier_list_opt: identifier_list
                  { printf("identifier-list-opt ==> identifier-list\n"); }
                  |
                  { printf("identifier-list-opt ==> epsilon \n"); }
                  ;

pointer:    MULTIPLY type_qualifier_list_opt
            { printf("pointer ==> * type-qualifier-list-opt\n");   }
            | MULTIPLY type_qualifier_list_opt pointer
            { printf("pointer ==> * type-qualifier-list-opt pointer\n");   }
            ;


type_qualifier_list:    type_qualifier
                        { printf("type-qualifier-list ==> type-qualifier\n");   }
                        | type_qualifier_list type_qualifier
                        { printf("type-qualifier-list ==> type-qualifier-list type-qualifier\n");   }
                        ;

parameter_type_list:    parameter_list
                        { printf("parameter-type-list ==> parameter-list\n");   }
                        | parameter_list COMMA ELLIPSIS
                        { printf("parameter-type-list ==> parameter-list , ...\n");   }
                        ;

parameter_list:     parameter_declaration
                    { printf("parameter-list ==> parameter-declaration\n");   }
                    | parameter_list COMMA parameter_declaration
                    { printf("parameter-list ==> parameter-list , parameter-declaration\n");   }
                    ;

parameter_declaration:      declaration_specifiers declarator
                            { printf("parameter-declaration ==> declaration-specifiers declarator\n");   }
                            | declaration_specifiers
                            { printf("parameter-declaration ==> declaration-specifiers\n");   }
                            ;


identifier_list:    IDENTIFIER
                    { printf("identifier-list ==> identifier\n");   }
                    | identifier_list COMMA IDENTIFIER
                    { printf("identifier-list ==> identifier-list , identifier\n");   }
                    ;

type_name:  specifier_qualifier_list
            { printf("type-name ==> specifier-qualifier-list\n");   }
            ;

initializer:    assignment_expression
                { printf("initializer ==> assignment-expression\n");   }
                | LEFT_CURLY_BRACE initializer_list RIGHT_CURLY_BRACE
                { printf("initializer ==> { initializer-list }\n");   }
                | LEFT_CURLY_BRACE initializer_list COMMA RIGHT_CURLY_BRACE
                { printf("initializer ==> { initializer-list , }\n");   }
                ;

initializer_list:   designation_opt initializer
                    { printf("initializer-list ==> designation-opt initializer\n");   }
                    | initializer_list COMMA designation_opt initializer
                    { printf("initializer-list ==> initializer-list , designation-opt initializer\n");   }
                    ;

designation_opt:    designation
                    { printf("designation-opt ==> designation\n");   }
                    | 
                    { printf("designation-opt ==> epsilon\n");   }
                    ;

designation:    designator_list ASSIGNMENT
                { printf("designation ==> designator-list =\n");   }
                ;

designator_list:    designator
                    { printf("designator-list ==> designator\n");   }
                    | designator_list designator
                    { printf("designator-list ==> designator-list designator\n");   }
                    ;

designator:     LEFT_SQR_BRACKET constant_expression RIGHT_SQR_BRACKET
                { printf("designator ==> [ constant-expression ]\n");   }
                | DOT IDENTIFIER
                { printf("designator ==> . identifier\n");   }
                ;

statement:  labeled_statement
            { printf("statement ==> labeled-statement\n");   }
            | compound_statement
            { printf("statement ==> compound-statement\n");   }
            | expression_statement
            { printf("statement ==> expression-statement\n");   }
            | selection_statement
            { printf("statement ==> selection-statement\n");   }
            | iteration_statement
            { printf("statement ==> iteration-statement\n");   }
            | jump_statement
            { printf("statement ==> jump-statement\n");   }
            ;

labeled_statement:  IDENTIFIER COLON statement
                    { printf("labeled-statement ==> identifier : statement\n");   }
                    | CASE constant_expression COLON statement
                    { printf("labeled-statement ==> case constant-expression : statement\n");   }
                    | DEFAULT COLON statement
                    { printf("labeled-statement ==> default : statement\n");   }
                    ;


compound_statement:  LEFT_CURLY_BRACE block_item_list_opt RIGHT_CURLY_BRACE
                    { printf("compound-statement ==> { block-item-list-opt }\n");   }
                    ;

block_item_list_opt:    block_item_list
                        { printf("block-item-list-opt ==> block-item-list\n");   } 
                        |
                        { printf("block-item-list-opt ==> epsilon\n");   }
                        ;

block_item_list:    block_item
                    { printf("block-item-list ==> block-item\n");   }
                    | block_item_list block_item
                    { printf("block-item-list ==> block-item-list block-item\n");   }
                    ;

block_item: declaration
            { printf("block-item ==> declaration\n");   }
            | statement
            { printf("block-item ==> statement\n");   }
            ;

expression_statement:   expression_opt SEMICOLON
                        { printf("expression-statement ==> expression-opt ;\n");   }
                        ;

expression_opt:     expression
                    { printf("expression-opt ==> expression\n");   } 
                    |
                    { printf("expression-opt ==> epsilon\n");   }
                    ;

selection_statement:    IF LEFT_PAREN expression RIGHT_PAREN statement
                        { printf("selection-statement ==> if ( expression ) statement\n");   }
                        | IF LEFT_PAREN expression RIGHT_PAREN statement ELSE statement
                        { printf("selection-statement ==> if ( expression ) statement else statement\n");   }
                        | SWITCH LEFT_PAREN expression RIGHT_PAREN statement
                        { printf("selection-statement ==> switch ( expression ) statement\n");   }
                        ;

iteration_statement:    WHILE LEFT_PAREN expression RIGHT_PAREN statement
                        { printf("iteration-statement ==> while ( expression ) statement\n");   }
                        | DO statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON
                        { printf("iteration-statement ==> do statement while ( expression ) ;\n");   }
                        | FOR LEFT_PAREN expression_opt SEMICOLON expression_opt SEMICOLON expression_opt RIGHT_PAREN statement
                        { printf("iteration-statement ==> for ( expression-opt ; expression-opt ; expression-opt ) statement\n");   }
                        | FOR LEFT_PAREN declaration expression_opt SEMICOLON expression_opt RIGHT_PAREN statement
                        { printf("iteration-statement ==> for ( declaration expression-opt ; expression-opt ) statement\n");   }
                        ;

jump_statement: GOTO IDENTIFIER SEMICOLON
                { printf("jump-statement ==> goto identifier ;\n");   }
                | CONTINUE SEMICOLON
                { printf("jump-statement ==> continue ;\n");   }
                | BREAK SEMICOLON
                { printf("jump-statement ==> break ;\n");   }
                | RETURN expression_opt SEMICOLON
                { printf("jump-statement ==> return expression-opt ;\n");   }
                ;

translation_unit:   external_declaration
                    { printf("translation-unit ==> external-declaration\n");   }
                    | translation_unit external_declaration
                    { printf("translation-unit ==> translation-unit external-declaration\n");   }
                    ;

external_declaration:   function_definition
                        { printf("external-declaration ==> function-definition\n");   }
                        | declaration
                        { printf("external-declaration ==> declaration\n");   }
                        ;

function_definition:    declaration_specifiers declarator declaration_list_opt compound_statement
                            { printf("function-definition ==> declaration-specifiers declarator declaration-list-opt compound-statement\n");   }
                        ;

declaration_list_opt: declaration_list
                        { printf("declaration-list-opt ==> declaration-list\n");   }
                    | 
                        { printf("declaration-list-opt ==> epsilon\n");   }
                    ;

declaration_list: declaration
                    { printf("declaration-list ==> declaration\n");   }
                | declaration_list declaration
                    { printf("declaration-list ==> declaration-list declaration\n");   }
                ;

%%

void yyerror(char *s) {

    printf("Error found : %s\n", s);
    printf("Line no. : %d\n", yylineno);
    printf("Unable to parse : %s, please try again\n", yytext);    
}
