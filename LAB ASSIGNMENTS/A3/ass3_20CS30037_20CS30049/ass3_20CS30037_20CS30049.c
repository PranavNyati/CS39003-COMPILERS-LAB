//     COMPILERS LAB: ASSIGNMENT 3  (Lexer for TinyC) 
//     PRANAV NYATI (ROLL : 20CS30037)
//     SHREYAS JENA (ROLL : 20CS30049)

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

extern char* yytext;
extern int yylex();

int main() {
    int token_val;
    while(token_val = yylex()) {
        switch(token_val) {
            case KEYWORD: 
                printf("< KEYWORD, %d, %s >\n", token_val, yytext); 
                break;
            case IDENTIFIER: 
                printf("< IDENTIFIER, %d, %s >\n", token_val, yytext); 
                break;
            case INT_CONSTANT: 
                printf("< INTEGER_CONSTANT, %d, %s >\n", token_val, yytext); 
                break;
            case FLOAT_CONSTANT: 
                printf("< FLOAT_CONSTANT, %d, %s >\n", token_val, yytext); 
                break;
            case CHAR_CONSTANT: 
                printf("< CHARACTER_CONSTANT, %d, %s >\n", token_val, yytext); 
                break;
            case STRING_LITERAL: 
                printf("< STRING_LITERAL, %d, %s >\n", token_val, yytext); 
                break;
            case PUNCTUATOR: 
                printf("< PUNCTUATOR, %d, %s >\n", token_val, yytext); 
                break;
            case MULTI_LINE_COMMENT_START: 
                printf("< MULTI_LINE_COMMENT, %d >\n", token_val);  
                break;
			case MULTI_LINE_COMMENT_END: 
                printf("< MULTI_LINE_COMMENT, %d >\n", token_val);  
                break;
            case SINGLE_LINE_COMMENT_START: 
                printf("< SINGLE_LINE_COMMENT, %d >\n", token_val); 
                break;
			case SINGLE_LINE_COMMENT_END: 
                printf("< SINGLE_LINE_COMMENT, %d >\n", token_val); 
                break;
            default:
                printf("< INVALID_TOKEN, %d, %s >\n", token_val, yytext);
                break;
        }
    }
    return 0;
}