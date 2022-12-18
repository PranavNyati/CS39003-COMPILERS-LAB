/* C Declarations and Definitions */
%{  
    /*
     
    Compilers Lab : Assignment 5
    Group Members:
        1. Pranav Nyati (20CS30037)
        2. Shreyas Jena (20CS30049)
    
    
    * Lexer for tinyC using Flex
    */
    #include <stdio.h>
    #include "assn5_20CS30037_20CS30049_translator.h"
    #include "assn5_20CS30037_20CS30049.tab.h"
%}

%option yylineno
%option noyywrap

%x SINGLE_LINE_COMMENT
%x MULTI_LINE_COMMENT

/* Regular Expression Definitions */

IDENTIFIER                      [_a-zA-Z][_a-zA-Z0-9]*

INT_CONSTANT                    [1-9][0-9]*|[0]

DIGIT_SEQUENCE                  [0-9]+
EXPONENT_PART                   [eE]([+-]?){DIGIT_SEQUENCE}
FRACTIONAL_CONSTANT             ({DIGIT_SEQUENCE}?\.{DIGIT_SEQUENCE})|({DIGIT_SEQUENCE}\.)
FLOAT_CONSTANT                  ({FRACTIONAL_CONSTANT}{EXPONENT_PART}?)|({DIGIT_SEQUENCE}{EXPONENT_PART})

ENUM_CONSTANT                   {IDENTIFIER}

ESCAPE_SEQUENCE                 \\['"?\\abfnrtv]
C_CHAR                          [^\'\\\n]|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE                 {C_CHAR}+
CHAR_CONSTANT                   \'({C_CHAR_SEQUENCE})\'

CONSTANT                        {INT_CONSTANT}|{FLOAT_CONSTANT}|{ENUM_CONSTANT}|{CHAR_CONSTANT}

S_CHAR                          [^\"\\\n]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE                 {S_CHAR}+
STRING_LITERAL                  \"({S_CHAR_SEQUENCE}?)\"

WS                              [ \t\n]

/* Definitions of Rules and Actions */
%%

"//"                            { BEGIN(SINGLE_LINE_COMMENT); }
<SINGLE_LINE_COMMENT>.          { /* eat up the comment */ }
<SINGLE_LINE_COMMENT>\n         { BEGIN(INITIAL); }
<SINGLE_LINE_COMMENT><<EOF>>    { BEGIN(INITIAL); }

"/*"                            { BEGIN(MULTI_LINE_COMMENT); }
<MULTI_LINE_COMMENT>"*/"        { BEGIN(INITIAL); }
<MULTI_LINE_COMMENT>.           { /* eat up the comment */ }
<MULTI_LINE_COMMENT>\n          { /* eat up the comment */ }

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
"struct"                        { return STRUCT; }
"switch"                        { return SWITCH; }
"typedef"                       { return TYPEDEF; }
"union"                         { return UNION; }
"unsigned"                      { return UNSIGNED; }
"void"                          { return VOID; }
"volatile"                      { return VOLATILE; }
"while"                         { return WHILE; }
"_Bool"                         { return BOOL; }
"_Complex"                      { return COMPLEX; }
"_Imaginary"                    { return IMAGINARY; }

"["                             { return LEFT_SQR_BRACKET; }
"]"                             { return RIGHT_SQR_BRACKET; }
"("                             { return LEFT_PAREN; }
")"                             { return RIGHT_PAREN; }
"{"                             { return LEFT_CURLY_BRACE; }
"}"                             { return RIGHT_CURLY_BRACE; }
"."                             { return DOT; }
"->"                            { return ARROW; }
"++"                            { return INCREMENT; }
"--"                            { return DECREMENT; }
"&"                             { return BITWISE_AND; }
"*"                             { return MULTIPLY; }
"+"                             { return ADD; }
"-"                             { return SUBTRACT; }
"~"                             { return BITWISE_NOR; }
"!"                             { return NOT; }
"/"                             { return DIVIDE; }
"%"                             { return MODULO; }
"<<"                            { return LEFT_SHIFT; }
">>"                            { return RIGHT_SHIFT; }
"<"                             { return LESS_THAN; }
">"                             { return GREATER_THAN; }
"<="                            { return LESS_THAN_EQUALS; }
">="                            { return GREATER_THAN_EQUALS; }
"=="                            { return EQUALS; }
"!="                            { return NOT_EQUALS; }
"^"                             { return BITWISE_XOR; }
"|"                             { return BITWISE_OR; }
"&&"                            { return LOGICAL_AND; }
"||"                            { return LOGICAL_OR; }
"?"                             { return QUESTION_MARK; }
":"                             { return COLON; }
";"                             { return SEMICOLON; }
"..."                           { return ELLIPSIS; }
"="                             { return ASSIGNMENT; }
"*="                            { return MUL_ASSIGNMENT; }
"/="                            { return DIV_ASSIGNMENT; }
"%="                            { return MOD_ASSIGNMENT; }
"+="                            { return ADD_ASSIGNMENT; }
"-="                            { return SUB_ASSIGNMENT; }
"<<="                           { return LSHIFT_ASSIGNMENT; }
">>="                           { return RSHIFT_ASSIGNMENT; }
"&="                            { return AND_ASSIGNMENT; }
"^="                            { return XOR_ASSIGNMENT; }
"|="                            { return OR_ASSIGNMENT; }
","                             { return COMMA; }
"#"                             { return HASH; }

{IDENTIFIER}                    { yylval.symptr = SymTbl_Current->lookup(yytext); return IDENTIFIER; }
{INT_CONSTANT}                  { yylval.intval = atoi(yytext); return INT_CONSTANT; }
{FLOAT_CONSTANT}                { yylval.charval = yytext; return FLOAT_CONSTANT; }
{CHAR_CONSTANT}                 { yylval.charval = yytext; return CHAR_CONSTANT; }
{STRING_LITERAL}                { yylval.charval = yytext; return STRING_LITERAL; }
{WS}                            { /* ignore whitespaces */ }

%%
