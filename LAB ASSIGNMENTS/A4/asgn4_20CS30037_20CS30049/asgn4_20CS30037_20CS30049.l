%{
    #include <stdio.h>
    #include "y.tab.h"
    #define KEYWORD                         500
    #define PUNCTUATOR                      501
    #define SINGLE_LINE_COMMENT_START       502
    #define SINGLE_LINE_COMMENT_END         503
    #define MULTI_LINE_COMMENT_START        504
    #define MULTI_LINE_COMMENT_END          505
    #define INVALID_TOKEN                   506
%}

%option yylineno

%x SINGLE_LINE_COMMENT    
%x MULTI_LINE_COMMENT     

IDENTIFIER      [A-Za-z_][A-Za-z0-9_]*

DIGIT           [0-9]
NON_ZERO_DIGIT  [1-9]
DIGIT_SEQ       {DIGIT}+ 
INT_CONSTANT    {NON_ZERO_DIGIT}{DIGIT}*|"0"


FRAC_CONSTANT   ({DIGIT_SEQ}?)\.({DIGIT_SEQ})|{DIGIT_SEQ}\.
EXPONENT_PART   [eE]([-+]?){DIGIT_SEQ} 
FLOAT_CONSTANT  {FRAC_CONSTANT}({EXPONENT_PART}?)|{DIGIT_SEQ}{EXPONENT_PART}

ESCAPE_SEQ      \\['"?\\abfnrtv]

C_CHAR          [^\'\n\\]|{ESCAPE_SEQ}
C_CHAR_SEQ      {C_CHAR}+
CHAR_CONSTANT   \'{C_CHAR_SEQ}\'

S_CHAR          [^\"\n\\]|{ESCAPE_SEQ}
S_CHAR_SEQ      {S_CHAR}+
STRING_LITERAL  \"({S_CHAR_SEQ}?)\"

WHITE_SPACE     [ \n\t]

%%

"auto"                          { return AUTO; }
"break"                         { return BREAK; }
"case"                          { return CASE; }
"char"                          { return CHAR; }
"const"                         { return CONST; }
"continue"                      { return CONTINUE; }
"default"                       { return DEFAULT; }
"do"                            { return DO; }
"double"                        { return DOUBLE; }
"else"                          { return ELSE; }
"enum"                          { return ENUM; }
"extern"                        { return EXTERN; }
"float"                         { return FLOAT; }
"for"                           { return FOR; }
"goto"                          { return GOTO; }
"if"                            { return IF; }
"inline"                        { return INLINE; }
"int"                           { return INT; }
"long"                          { return LONG; }
"register"                      { return REGISTER; }
"restrict"                      { return RESTRICT; }
"return"                        { return RETURN; }
"short"                         { return SHORT; }
"signed"                        { return SIGNED; }
"sizeof"                        { return SIZEOF; }
"static"                        { return STATIC; }
"switch"                        { return SWITCH; }
"unsigned"                      { return UNSIGNED; }
"void"                          { return VOID; }
"volatile"                      { return VOLATILE; }
"while"                         { return WHILE; }
"_Bool"                         { return BOOL; }
"_Complex"                      { return COMPLEX; }
"_Imaginary"                    { return IMAGINARY; }

{IDENTIFIER}                    { return IDENTIFIER; }
{INT_CONSTANT}                  { return INT_CONSTANT; }
{FLOAT_CONSTANT}                { return FLOAT_CONSTANT; }
{CHAR_CONSTANT}                 { return CHAR_CONSTANT; }
{STRING_LITERAL}                { return STRING_LITERAL; }

"["                             { return LEFT_SQR_BRACKET; }
"++"                            { return INCREMENT; }
"/"                             { return DIVIDE; }
"?"                             { return QUESTION_MARK; }
"="                             { return ASSIGNMENT; }
","                             { return COMMA; }
"]"                             { return RIGHT_SQR_BRACKET; }
"("                             { return LEFT_PAREN; }
"{"                             { return LEFT_CURLY_BRACE; }
"}"                             { return RIGHT_CURLY_BRACE; }
"."                             { return DOT; }
"->"                            { return ARROW; }
"*"                             { return MULTIPLY; }
"+"                             { return ADD; }
"-"                             { return SUBTRACT; }
"~"                             { return BITWISE_NOT; }
"!"                             { return NOT; }
"%"                             { return MODULO; }
"<<"                            { return LEFT_SHIFT; }
">>"                            { return RIGHT_SHIFT; }
"<"                             { return LESS_THAN; }
">"                             { return GREATER_THAN; }
"<="                            { return LESS_THAN_EQUALS; }
">="                            { return GREATER_THAN_EQUALS; }
":"                             { return COLON; }
";"                             { return SEMICOLON; }
"..."                           { return ELLIPSIS; }
"*="                            { return MUL_ASSIGNMENT; }
"/="                            { return DIV_ASSIGNMENT; }
"%="                            { return MOD_ASSIGNMENT; }
"+="                            { return ADD_ASSIGNMENT; }
"-="                            { return SUB_ASSIGNMENT; }
"<<="                           { return LSHIFT_ASSIGNMENT; }
"--"                            { return DECREMENT; }
")"                             { return RIGHT_PAREN; }
"&"                             { return BITWISE_AND; }
"=="                            { return EQUALS; }
"^"                             { return BITWISE_XOR; }
"|"                             { return BITWISE_OR; }
"&&"                            { return AND; }
"||"                            { return OR; }
">>="                           { return RSHIFT_ASSIGNMENT; }
"!="                            { return NOT_EQUALS; }
"&="                            { return BITWISE_AND_ASSIGNMENT; }
"|="                            { return BITWISE_OR_ASSIGNMENT; }
"^="                            { return BITWISE_XOR_ASSIGNMENT; }

"//"                            { BEGIN(SINGLE_LINE_COMMENT);   }
<SINGLE_LINE_COMMENT>"\n"       { BEGIN(INITIAL);   }
<SINGLE_LINE_COMMENT>.          { /* ignore the contents of the comment */ }  

"/*"                            { BEGIN(MULTI_LINE_COMMENT);    }
<MULTI_LINE_COMMENT>"*/"        { BEGIN(INITIAL);   }
<MULTI_LINE_COMMENT>.           { /* ignore the contents of the comment */ }
<MULTI_LINE_COMMENT>\n          { /* ignore the contents of the comment */ }

{WHITE_SPACE}                     {/*ignore the whitespaces*/}
.                               {return INVALID_TOKEN;}

%%

