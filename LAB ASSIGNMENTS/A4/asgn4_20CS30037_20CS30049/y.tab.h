/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    INT_CONSTANT = 259,
    FLOAT_CONSTANT = 260,
    CHAR_CONSTANT = 261,
    STRING_LITERAL = 262,
    EXTERN = 263,
    STATIC = 264,
    AUTO = 265,
    REGISTER = 266,
    CONST = 267,
    RESTRICT = 268,
    VOLATILE = 269,
    INLINE = 270,
    CASE = 271,
    DEFAULT = 272,
    VOID = 273,
    CHAR = 274,
    SHORT = 275,
    INT = 276,
    LONG = 277,
    FLOAT = 278,
    DOUBLE = 279,
    ENUM = 280,
    SIGNED = 281,
    UNSIGNED = 282,
    BOOL = 283,
    COMPLEX = 284,
    IMAGINARY = 285,
    DOT = 286,
    ARROW = 287,
    LEFT_PAREN = 288,
    RIGHT_PAREN = 289,
    LEFT_CURLY_BRACE = 290,
    RIGHT_CURLY_BRACE = 291,
    LEFT_SQR_BRACKET = 292,
    RIGHT_SQR_BRACKET = 293,
    ADD = 294,
    SUBTRACT = 295,
    MULTIPLY = 296,
    DIVIDE = 297,
    MODULO = 298,
    SIZEOF = 299,
    LESS_THAN = 300,
    LESS_THAN_EQUALS = 301,
    GREATER_THAN = 302,
    GREATER_THAN_EQUALS = 303,
    EQUALS = 304,
    NOT_EQUALS = 305,
    AND = 306,
    OR = 307,
    NOT = 308,
    IF = 309,
    ELSE = 310,
    SWITCH = 311,
    WHILE = 312,
    DO = 313,
    FOR = 314,
    GOTO = 315,
    CONTINUE = 316,
    BREAK = 317,
    RETURN = 318,
    BITWISE_AND = 319,
    BITWISE_OR = 320,
    BITWISE_NOT = 321,
    BITWISE_XOR = 322,
    SEMICOLON = 323,
    COMMA = 324,
    COLON = 325,
    INCREMENT = 326,
    DECREMENT = 327,
    ASSIGNMENT = 328,
    ADD_ASSIGNMENT = 329,
    SUB_ASSIGNMENT = 330,
    MUL_ASSIGNMENT = 331,
    DIV_ASSIGNMENT = 332,
    MOD_ASSIGNMENT = 333,
    LSHIFT_ASSIGNMENT = 334,
    RSHIFT_ASSIGNMENT = 335,
    BITWISE_AND_ASSIGNMENT = 336,
    BITWISE_XOR_ASSIGNMENT = 337,
    BITWISE_OR_ASSIGNMENT = 338,
    LEFT_SHIFT = 339,
    RIGHT_SHIFT = 340,
    QUESTION_MARK = 341,
    ELLIPSIS = 342
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INT_CONSTANT 259
#define FLOAT_CONSTANT 260
#define CHAR_CONSTANT 261
#define STRING_LITERAL 262
#define EXTERN 263
#define STATIC 264
#define AUTO 265
#define REGISTER 266
#define CONST 267
#define RESTRICT 268
#define VOLATILE 269
#define INLINE 270
#define CASE 271
#define DEFAULT 272
#define VOID 273
#define CHAR 274
#define SHORT 275
#define INT 276
#define LONG 277
#define FLOAT 278
#define DOUBLE 279
#define ENUM 280
#define SIGNED 281
#define UNSIGNED 282
#define BOOL 283
#define COMPLEX 284
#define IMAGINARY 285
#define DOT 286
#define ARROW 287
#define LEFT_PAREN 288
#define RIGHT_PAREN 289
#define LEFT_CURLY_BRACE 290
#define RIGHT_CURLY_BRACE 291
#define LEFT_SQR_BRACKET 292
#define RIGHT_SQR_BRACKET 293
#define ADD 294
#define SUBTRACT 295
#define MULTIPLY 296
#define DIVIDE 297
#define MODULO 298
#define SIZEOF 299
#define LESS_THAN 300
#define LESS_THAN_EQUALS 301
#define GREATER_THAN 302
#define GREATER_THAN_EQUALS 303
#define EQUALS 304
#define NOT_EQUALS 305
#define AND 306
#define OR 307
#define NOT 308
#define IF 309
#define ELSE 310
#define SWITCH 311
#define WHILE 312
#define DO 313
#define FOR 314
#define GOTO 315
#define CONTINUE 316
#define BREAK 317
#define RETURN 318
#define BITWISE_AND 319
#define BITWISE_OR 320
#define BITWISE_NOT 321
#define BITWISE_XOR 322
#define SEMICOLON 323
#define COMMA 324
#define COLON 325
#define INCREMENT 326
#define DECREMENT 327
#define ASSIGNMENT 328
#define ADD_ASSIGNMENT 329
#define SUB_ASSIGNMENT 330
#define MUL_ASSIGNMENT 331
#define DIV_ASSIGNMENT 332
#define MOD_ASSIGNMENT 333
#define LSHIFT_ASSIGNMENT 334
#define RSHIFT_ASSIGNMENT 335
#define BITWISE_AND_ASSIGNMENT 336
#define BITWISE_XOR_ASSIGNMENT 337
#define BITWISE_OR_ASSIGNMENT 338
#define LEFT_SHIFT 339
#define RIGHT_SHIFT 340
#define QUESTION_MARK 341
#define ELLIPSIS 342

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "asgn4_20CS30037_20CS30049.y"

    int intval;
    float floatval;
    char *strval;
    char charval;

#line 238 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
