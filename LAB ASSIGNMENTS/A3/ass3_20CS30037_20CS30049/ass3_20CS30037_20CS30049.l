%{
    #include <stdio.h>
    #define KEYWORD                         500
    #define IDENTIFIER                      501
    #define INT_CONSTANT                    502
    #define FLOAT_CONSTANT                  503
    #define CHAR_CONSTANT                   504
    #define STRING_LITERAL                  505
    #define PUNCTUATOR                      506
    #define SINGLE_LINE_COMMENT_START       507
    #define SINGLE_LINE_COMMENT_END         508
    #define MULTI_LINE_COMMENT_START        509
    #define MULTI_LINE_COMMENT_END          510
    #define INVALID_TOKEN                   511
%}

%x SINGLE_LINE_COMMENT    
%x MULTI_LINE_COMMENT     

KEYWORD        "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"_Bool"|"_Complex"|"_Imaginary"

IDENTIFIER      [A-Za-z_][A-Za-z0-9_]*

DIGIT           [0-9]
NON_ZERO_DIGIT  [1-9]
DIGIT_SEQ       {DIGIT}+ 
INT_CONSTANT    {NON_ZERO_DIGIT}{DIGIT}*|"0"


FRAC_CONSTANT   ({DIGIT_SEQ}?)\.({DIGIT_SEQ})|{DIGIT_SEQ}\.
EXPONENT_PART   [eE]([-+]?){DIGIT_SEQ} 
FLOAT_CONSTANT  {FRAC_CONSTANT}({EXPONENT_PART}?)|{DIGIT_SEQ}{EXPONENT_PART}

ENUM_CONSTANT   {IDENTIFIER}

ESCAPE_SEQ      \\['"?\\abfnrtv]

C_CHAR          [^\'\n\\]|{ESCAPE_SEQ}
C_CHAR_SEQ      {C_CHAR}+
CHAR_CONSTANT   \'{C_CHAR_SEQ}\'

S_CHAR          [^\"\n\\]|{ESCAPE_SEQ}
S_CHAR_SEQ      {S_CHAR}+
STRING_LITERAL  \"({S_CHAR_SEQ}?)\"

PUNCTUATOR      "["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#"

WHITE_SPACE     [ \n\t]

%%

{KEYWORD}                         { return KEYWORD; }
{IDENTIFIER}                      { return IDENTIFIER; }
{PUNCTUATOR}                      { return PUNCTUATOR;}


{INT_CONSTANT}                    { return INT_CONSTANT;}
{FLOAT_CONSTANT}                  { return FLOAT_CONSTANT;}
{CHAR_CONSTANT}                   { return CHAR_CONSTANT; }
{STRING_LITERAL}                  { return STRING_LITERAL; }

"//"                            { BEGIN(SINGLE_LINE_COMMENT); return SINGLE_LINE_COMMENT_START;}
<SINGLE_LINE_COMMENT>"\n"       { BEGIN(INITIAL); return SINGLE_LINE_COMMENT_END;}
<SINGLE_LINE_COMMENT>.          { /* ignore the contents of the comment */ }  

"/*"                            { BEGIN(MULTI_LINE_COMMENT); return MULTI_LINE_COMMENT_START; }
<MULTI_LINE_COMMENT>"*/"        { BEGIN(INITIAL); return MULTI_LINE_COMMENT_END; }
<MULTI_LINE_COMMENT>.           { /* ignore the contents of the comment */ }
<MULTI_LINE_COMMENT>\n          { /* ignore the contents of the comment */ }

{WHITE_SPACE}                     {/*ignore the whitespaces*/}
.                               {return INVALID_TOKEN;}

%%

