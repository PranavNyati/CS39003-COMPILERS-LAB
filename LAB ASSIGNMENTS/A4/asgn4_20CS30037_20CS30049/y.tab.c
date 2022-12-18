/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "asgn4_20CS30037_20CS30049.y"

    #include <stdio.h>
    extern int yylex();
    void yyerror(char *s);
    extern char* yytext;
    extern int yylineno;

#line 78 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 311 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   821

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  209
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  339

#define YYUNDEFTOK  2
#define YYMAXUTOK   342


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    47,    50,    53,    57,    59,    61,    65,
      67,    69,    71,    73,    75,    77,    79,    81,    85,    88,
      91,    93,    97,    99,   101,   103,   105,   107,   111,   114,
     117,   120,   123,   126,   130,   132,   136,   138,   140,   142,
     146,   148,   150,   154,   156,   158,   162,   164,   166,   168,
     170,   174,   176,   178,   182,   184,   188,   190,   194,   196,
     200,   202,   206,   208,   212,   214,   219,   221,   225,   227,
     229,   231,   233,   235,   237,   239,   241,   243,   245,   251,
     253,   257,   261,   265,   268,   272,   274,   276,   278,   282,
     285,   289,   291,   295,   297,   301,   303,   305,   307,   311,
     313,   315,   317,   319,   321,   323,   325,   327,   329,   331,
     333,   335,   341,   343,   347,   350,   353,   355,   357,   362,
     366,   369,   371,   375,   377,   381,   383,   385,   389,   393,
     397,   400,   403,   405,   407,   409,   411,   413,   415,   417,
     423,   426,   428,   431,   434,   437,   440,   442,   447,   449,
     453,   455,   459,   461,   465,   467,   472,   474,   478,   482,
     484,   486,   490,   492,   496,   499,   502,   506,   508,   512,
     514,   518,   520,   522,   524,   526,   528,   532,   534,   536,
     541,   545,   548,   551,   553,   557,   559,   563,   567,   570,
     573,   575,   577,   581,   583,   585,   587,   591,   593,   595,
     597,   601,   603,   607,   609,   613,   617,   620,   623,   625
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INT_CONSTANT",
  "FLOAT_CONSTANT", "CHAR_CONSTANT", "STRING_LITERAL", "EXTERN", "STATIC",
  "AUTO", "REGISTER", "CONST", "RESTRICT", "VOLATILE", "INLINE", "CASE",
  "DEFAULT", "VOID", "CHAR", "SHORT", "INT", "LONG", "FLOAT", "DOUBLE",
  "ENUM", "SIGNED", "UNSIGNED", "BOOL", "COMPLEX", "IMAGINARY", "DOT",
  "ARROW", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_CURLY_BRACE",
  "RIGHT_CURLY_BRACE", "LEFT_SQR_BRACKET", "RIGHT_SQR_BRACKET", "ADD",
  "SUBTRACT", "MULTIPLY", "DIVIDE", "MODULO", "SIZEOF", "LESS_THAN",
  "LESS_THAN_EQUALS", "GREATER_THAN", "GREATER_THAN_EQUALS", "EQUALS",
  "NOT_EQUALS", "AND", "OR", "NOT", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "BITWISE_AND",
  "BITWISE_OR", "BITWISE_NOT", "BITWISE_XOR", "SEMICOLON", "COMMA",
  "COLON", "INCREMENT", "DECREMENT", "ASSIGNMENT", "ADD_ASSIGNMENT",
  "SUB_ASSIGNMENT", "MUL_ASSIGNMENT", "DIV_ASSIGNMENT", "MOD_ASSIGNMENT",
  "LSHIFT_ASSIGNMENT", "RSHIFT_ASSIGNMENT", "BITWISE_AND_ASSIGNMENT",
  "BITWISE_XOR_ASSIGNMENT", "BITWISE_OR_ASSIGNMENT", "LEFT_SHIFT",
  "RIGHT_SHIFT", "QUESTION_MARK", "ELLIPSIS", "$accept",
  "primary_expression", "constant", "postfix_expression",
  "argument_expression_list_opt", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "AND_expression",
  "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "init_declarator_list_opt", "declaration_specifiers",
  "declaration_specifiers_opt", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "specifier_qualifier_list_opt", "enum_specifier", "identifier_opt",
  "enumerator_list", "enumerator", "type_qualifier", "function_specifier",
  "declarator", "pointer_opt", "direct_declarator",
  "type_qualifier_list_opt", "assignment_expression_opt",
  "identifier_list_opt", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "initializer", "initializer_list",
  "designation_opt", "designation", "designator_list", "designator",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list_opt", "block_item_list", "block_item",
  "expression_statement", "expression_opt", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list_opt",
  "declaration_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342
};
# endif

#define YYPACT_NINF (-190)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-208)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     780,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,    13,  -190,  -190,  -190,
    -190,  -190,  -190,    36,   780,   780,  -190,   780,   780,   722,
    -190,  -190,     4,    23,   149,     8,    22,  -190,   691,    32,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,   129,  -190,
      87,   149,  -190,    87,   480,  -190,    36,   107,   780,  -190,
      87,   -20,    93,   -25,  -190,  -190,  -190,  -190,   103,  -190,
    -190,  -190,  -190,  -190,   396,   106,  -190,  -190,  -190,   532,
    -190,  -190,  -190,   574,   574,  -190,  -190,    62,   738,   616,
    -190,   146,    66,    73,   125,   130,    82,    72,   120,   167,
     -34,  -190,  -190,  -190,   271,  -190,  -190,   187,   757,   135,
     616,  -190,    18,  -190,    -3,   230,  -190,   230,   189,   226,
     616,   -10,   480,  -190,   -17,  -190,   396,  -190,   396,  -190,
    -190,   232,   235,   616,   616,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,   616,  -190,
    -190,   616,   616,   616,   616,   616,   616,   616,   616,   616,
     616,   616,   616,   616,   616,   616,   616,   616,   616,   616,
     163,   616,   169,   207,   212,   214,   438,   228,   259,   195,
     196,   616,   197,  -190,  -190,  -190,  -190,   229,   271,  -190,
    -190,   199,  -190,  -190,  -190,  -190,  -190,     6,   234,   236,
     202,  -190,   203,   149,   626,   142,  -190,  -190,  -190,  -190,
    -190,   616,  -190,  -190,  -190,   522,  -190,   264,  -190,    47,
    -190,  -190,  -190,   269,   273,  -190,  -190,   274,   240,  -190,
      -5,  -190,  -190,  -190,  -190,   146,   146,    66,    66,    73,
      73,    73,    73,   125,   125,   130,    82,    72,   120,   167,
     122,   438,   243,   438,   616,   616,   616,   248,   341,   246,
    -190,  -190,   249,  -190,  -190,  -190,  -190,  -190,  -190,   186,
     313,   616,   280,  -190,   281,   616,  -190,   106,  -190,  -190,
    -190,   480,   285,   285,  -190,   616,  -190,   616,  -190,   438,
    -190,    11,    16,    33,   288,   616,   254,  -190,  -190,  -190,
    -190,  -190,   298,  -190,  -190,   300,    21,  -190,  -190,  -190,
    -190,   438,   438,   438,   616,   255,   616,  -190,  -190,  -190,
     104,   286,  -190,  -190,    69,   616,   258,  -190,   438,   272,
     323,   616,  -190,  -190,   438,   324,  -190,   438,  -190
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    95,    96,    97,    98,   125,   126,   127,   128,    99,
     100,   101,   102,   103,   104,   105,   120,   106,   107,   108,
     109,   110,   204,   131,    90,    90,   111,    90,    90,     0,
     201,   203,   118,     0,   141,     0,    83,    91,    93,     0,
     130,    89,    85,    86,    87,    88,     1,   202,     0,   148,
     146,   140,    82,   131,     0,   208,   131,     0,   206,   132,
     131,   129,   123,     0,   121,   147,   149,    92,    93,     2,
       6,     7,     8,     4,     0,   165,    30,    31,    29,     0,
      33,    28,    32,     0,     0,     9,     3,    22,    34,     0,
      36,    40,    43,    46,    51,    54,    56,    58,    60,    62,
      64,    66,   159,    94,   182,   205,   209,     0,   145,   141,
       0,   116,     0,    79,     0,   115,   158,   115,     0,     0,
       0,     0,     0,   164,     0,   167,     0,    26,     0,    23,
      24,     0,     0,    19,     0,    14,    15,    68,    72,    73,
      69,    70,    71,    74,    75,    76,    77,    78,     0,    34,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     0,   189,     0,     0,     0,
       0,   189,   188,   185,   186,   171,   172,     0,   181,   183,
     173,     0,   174,   175,   176,   133,   156,   131,     0,     0,
     150,   152,   144,   141,   143,   140,    81,   124,   117,   122,
       5,     0,   114,   112,   113,     0,   170,     0,   160,   165,
     162,   166,   168,     0,     0,    12,    13,     0,    18,    20,
       0,    67,    37,    38,    39,    41,    42,    44,    45,    47,
      49,    48,    50,    52,    53,    55,    57,    59,    61,    63,
       0,   189,     0,   189,     0,     0,     0,     0,   189,     0,
     198,   199,     0,   180,   184,   187,   154,   139,   138,     0,
       0,     0,    29,   142,     0,     0,    80,   165,    35,   169,
     161,     0,    27,     0,    11,     0,    10,     0,   177,   189,
     179,     0,     0,     0,     0,   189,     0,   197,   200,   151,
     153,   157,     0,   137,   134,     0,     0,   163,    21,    65,
     178,   189,   189,   189,     0,     0,   189,   135,   136,    16,
     165,   190,   192,   193,     0,   189,     0,    17,   189,     0,
       0,   189,   191,   194,   189,     0,   196,   189,   195
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,  -190,  -190,  -190,  -190,  -190,   -41,  -190,   -79,    48,
      75,    67,    74,   208,   210,   211,   206,   215,  -190,  -101,
     -51,  -190,   -73,  -108,   -36,  -190,     0,     9,  -190,   325,
    -190,   -66,   -29,   262,  -190,  -190,  -190,   275,   -28,  -190,
     -19,  -190,  -190,  -102,  -190,  -190,   326,   277,  -190,  -190,
     115,  -190,    91,  -117,   111,  -189,  -190,  -190,   265,  -144,
    -190,   333,  -190,  -190,   204,  -190,  -166,  -190,  -190,  -190,
    -190,   362,  -190,  -190,  -190
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    85,    86,    87,   227,   228,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     113,   148,   182,   207,    22,    35,    56,    42,    36,    37,
      24,    25,   116,   213,    26,    33,    63,    64,    27,    28,
      68,    39,    61,    50,   274,   198,    40,    51,   199,   200,
     201,   202,   118,   103,   121,   122,   123,   124,   125,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      29,    30,    31,    57,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,   114,    55,   102,    38,   220,    49,   204,   115,   206,
     150,   111,   217,   108,   119,   262,    32,   109,   168,   206,
     120,    62,   106,    66,    41,    41,   218,    41,    41,    23,
     281,   210,   257,   286,    43,    59,    44,    45,   127,  -119,
    -155,   107,   129,   130,   112,   311,   117,    34,   149,   115,
     312,   115,   169,   114,   208,   114,   221,   319,    48,   219,
     115,   230,   115,   252,   211,    60,   211,   313,   183,   149,
     206,   102,   232,   233,   234,  -155,    52,    34,   119,   149,
     211,    49,   229,   280,   120,   211,   212,   117,   212,   117,
     320,    53,   296,   131,   132,   133,   250,   231,   117,   134,
     117,   271,   211,   329,   -84,   154,   155,   288,   197,   290,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,    34,   315,
     149,   281,    62,   135,   136,   119,   278,   119,   211,   165,
     327,   120,   104,   120,   203,   310,   164,     5,     6,     7,
     326,   275,   183,   273,     5,     6,     7,   156,   157,   330,
     276,     5,     6,     7,   307,   335,   110,   321,   322,   323,
     158,   159,   160,   161,   149,    49,    54,    66,   266,   162,
     163,   291,   292,   293,   332,   166,   309,   151,   152,   153,
     336,   211,   287,   338,     1,     2,     3,     4,     5,     6,
       7,     8,   235,   236,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   223,   167,   224,
     302,   195,   295,   215,   305,   239,   240,   241,   242,   216,
     102,   237,   238,   251,   308,   225,   243,   244,   226,   253,
     254,   324,     5,     6,     7,   255,   149,   256,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   258,   259,   260,   261,   263,   211,   265,   267,   197,
     268,   269,   270,   299,   170,    70,    71,    72,    73,     1,
       2,     3,     4,     5,     6,     7,     8,   171,   172,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   279,   282,    74,   294,   104,   283,   284,   285,
      76,    77,    78,   289,   297,    79,   301,   298,   303,   304,
     277,   314,   316,   325,    80,   173,   331,   174,   175,   176,
     177,   178,   179,   180,   181,    81,   317,    82,   318,  -189,
     333,   328,    83,    84,    69,    70,    71,    72,    73,     1,
       2,     3,     4,     5,     6,     7,     8,   334,   337,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   245,   248,    74,   246,    65,   247,    67,   214,
      76,    77,    78,   249,   300,    79,   205,   209,   306,   222,
     105,    47,   264,     0,    80,     0,     0,     0,     0,    69,
      70,    71,    72,    73,     0,    81,     0,    82,     5,     6,
       7,     0,    83,    84,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,    74,
       0,     0,     0,     0,     0,    76,    77,    78,     0,     0,
      79,   170,    70,    71,    72,    73,     0,     0,     0,    80,
       0,     0,     0,     0,   171,   172,     0,     0,     0,     0,
      81,     0,    82,     0,     0,     0,     0,    83,    84,     0,
       0,    74,     0,   104,     0,     0,     0,    76,    77,    78,
       0,     0,    79,    69,    70,    71,    72,    73,     0,     0,
       0,    80,   173,     0,   174,   175,   176,   177,   178,   179,
     180,   181,    81,     0,    82,     0,     0,     0,     0,    83,
      84,     0,     0,    74,     0,    75,     0,     0,     0,    76,
      77,    78,     0,     0,    79,    69,    70,    71,    72,    73,
       0,     0,     0,    80,     0,    69,    70,    71,    72,    73,
       0,     0,     0,     0,    81,     0,    82,     0,     0,     0,
       0,    83,    84,     0,     0,    74,     0,   277,     0,     0,
       0,    76,    77,    78,     0,   126,    79,     0,     0,     0,
       0,    76,    77,    78,     0,    80,    79,    69,    70,    71,
      72,    73,     0,     0,     0,    80,    81,     0,    82,     0,
       0,     0,     0,    83,    84,     0,    81,     0,    82,     0,
       0,     0,     0,    83,    84,     0,     0,   128,     0,     0,
       0,     0,     0,    76,    77,    78,     0,     0,    79,    69,
      70,    71,    72,    73,     0,     0,     0,    80,     0,    69,
      70,    71,    72,    73,     0,     0,     0,     0,    81,     0,
      82,     0,     0,     0,     0,    83,    84,     0,     0,    74,
       0,     0,     0,     0,     0,    76,    77,    78,     0,    74,
      79,     0,     0,     0,     0,    76,    77,   272,     0,    80,
      79,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      81,     0,    82,     0,     0,     0,     0,    83,    84,     0,
      81,     0,    82,     0,     0,     0,     0,    83,    84,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    46,     0,     0,     0,  -207,     0,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
     196,     0,     0,     0,    54,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     0,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147
};

static const yytype_int16 yycheck[] =
{
       0,    74,    38,    54,    23,   122,    34,   109,    74,   110,
      89,    36,   120,    33,    31,   181,     3,    37,    52,   120,
      37,     3,    58,    51,    24,    25,    36,    27,    28,    29,
     219,    34,   176,    38,    25,     3,    27,    28,    79,    35,
      34,    60,    83,    84,    69,    34,    74,    41,    89,   115,
      34,   117,    86,   126,    36,   128,    73,    36,    35,    69,
     126,   134,   128,   171,    69,    33,    69,    34,   104,   110,
     171,   122,   151,   152,   153,    69,    68,    41,    31,   120,
      69,   109,   133,    36,    37,    69,   115,   115,   117,   117,
      69,    69,   258,    31,    32,    33,   169,   148,   126,    37,
     128,   203,    69,    34,    68,    39,    40,   251,   108,   253,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    41,   295,
     171,   320,     3,    71,    72,    31,   215,    31,    69,    67,
      36,    37,    35,    37,     9,   289,    64,    12,    13,    14,
     316,     9,   188,   204,    12,    13,    14,    84,    85,   325,
     211,    12,    13,    14,   281,   331,    73,   311,   312,   313,
      45,    46,    47,    48,   215,   203,    73,   205,   197,    49,
      50,   254,   255,   256,   328,    65,   287,    41,    42,    43,
     334,    69,    70,   337,     8,     9,    10,    11,    12,    13,
      14,    15,   154,   155,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,   126,    51,   128,
     271,    34,   258,    34,   275,   158,   159,   160,   161,     3,
     281,   156,   157,    70,   285,     3,   162,   163,     3,    70,
      33,   314,    12,    13,    14,    33,   287,    33,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    33,     3,    68,    68,    36,    69,    68,    34,   269,
      34,    69,    69,    87,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    38,    34,    33,    57,    35,    34,    34,    69,
      39,    40,    41,    70,    68,    44,     3,    68,    38,    38,
      35,    33,    68,    68,    53,    54,    68,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    38,    66,    38,    68,
      68,    55,    71,    72,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    34,    34,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   164,   167,    33,   165,    50,   166,    53,   117,
      39,    40,    41,   168,   269,    44,   109,   112,   277,   124,
      57,    29,   188,    -1,    53,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    64,    -1,    66,    12,    13,
      14,    -1,    71,    72,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,
      44,     3,     4,     5,     6,     7,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,
      64,    -1,    66,    -1,    -1,    -1,    -1,    71,    72,    -1,
      -1,    33,    -1,    35,    -1,    -1,    -1,    39,    40,    41,
      -1,    -1,    44,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,    39,
      40,    41,    -1,    -1,    44,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    53,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    33,    -1,    35,    -1,    -1,
      -1,    39,    40,    41,    -1,    33,    44,    -1,    -1,    -1,
      -1,    39,    40,    41,    -1,    53,    44,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    53,    64,    -1,    66,    -1,
      -1,    -1,    -1,    71,    72,    -1,    64,    -1,    66,    -1,
      -1,    -1,    -1,    71,    72,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    -1,    -1,    44,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    53,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,    33,
      44,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,    53,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      64,    -1,    66,    -1,    -1,    -1,    -1,    71,    72,    -1,
      64,    -1,    66,    -1,    -1,    -1,    -1,    71,    72,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    -1,    -1,    -1,    35,    -1,    -1,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    73,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    11,    12,    13,    14,    15,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   112,   114,   118,   119,   122,   126,   127,   158,
     159,   160,     3,   123,    41,   113,   116,   117,   128,   129,
     134,   114,   115,   115,   115,   115,     0,   159,    35,   126,
     131,   135,    68,    69,    73,   112,   114,   161,   162,     3,
      33,   130,     3,   124,   125,   134,   126,   117,   128,     3,
       4,     5,     6,     7,    33,    35,    39,    40,    41,    44,
      53,    64,    66,    71,    72,    89,    90,    91,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   141,    35,   149,   112,   128,    33,    37,
      73,    36,    69,   108,   110,   119,   120,   126,   140,    31,
      37,   142,   143,   144,   145,   146,    33,    94,    33,    94,
      94,    31,    32,    33,    37,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   109,    94,
      96,    41,    42,    43,    39,    40,    84,    85,    45,    46,
      47,    48,    49,    50,    64,    67,    65,    51,    52,    86,
       3,    16,    17,    54,    56,    57,    58,    59,    60,    61,
      62,    63,   110,   112,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    34,     3,   114,   133,   136,
     137,   138,   139,     9,   131,   135,   107,   111,    36,   125,
      34,    69,   120,   121,   121,    34,     3,   111,    36,    69,
     141,    73,   146,   140,   140,     3,     3,    92,    93,   108,
     110,   108,    96,    96,    96,    97,    97,    98,    98,    99,
      99,    99,    99,   100,   100,   101,   102,   103,   104,   105,
     110,    70,   111,    70,    33,    33,    33,   147,    33,     3,
      68,    68,   154,    36,   152,    68,   128,    34,    34,    69,
      69,   131,    41,   108,   132,     9,   108,    35,    96,    38,
      36,   143,    34,    34,    34,    69,    38,    70,   147,    70,
     147,   110,   110,   110,    57,   112,   154,    68,    68,    87,
     138,     3,   108,    38,    38,   108,   142,   141,   108,   107,
     147,    34,    34,    34,    33,   154,    68,    38,    38,    36,
      69,   147,   147,   147,   110,    68,   154,    36,    55,    34,
     154,    68,   147,    68,    34,   154,   147,    34,   147
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    89,    89,    89,    90,    90,    90,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    94,    94,    94,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    96,    96,    97,    97,    97,    97,
      98,    98,    98,    99,    99,    99,   100,   100,   100,   100,
     100,   101,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   110,
     110,   111,   112,   113,   113,   114,   114,   114,   114,   115,
     115,   116,   116,   117,   117,   118,   118,   118,   118,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   123,
     123,   124,   124,   125,   125,   126,   126,   126,   127,   128,
     129,   129,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   138,   138,   139,   139,   140,   141,
     141,   141,   142,   142,   143,   143,   144,   145,   145,   146,
     146,   147,   147,   147,   147,   147,   147,   148,   148,   148,
     149,   150,   150,   151,   151,   152,   152,   153,   154,   154,
     155,   155,   155,   156,   156,   156,   156,   157,   157,   157,
     157,   158,   158,   159,   159,   160,   161,   161,   162,   162
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       4,     4,     3,     3,     2,     2,     6,     7,     1,     0,
       1,     3,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     0,     2,     2,     2,     2,     1,
       0,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     0,     5,     6,     2,     1,
       0,     1,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     0,     1,     3,     5,     6,     6,     5,     4,     4,
       1,     0,     1,     0,     1,     0,     2,     3,     1,     2,
       1,     3,     1,     3,     2,     1,     1,     3,     1,     1,
       3,     4,     2,     4,     1,     0,     2,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       3,     1,     0,     1,     2,     1,     1,     2,     1,     0,
       5,     7,     5,     5,     7,     9,     8,     3,     2,     2,
       3,     1,     2,     1,     1,     4,     1,     0,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 45 "asgn4_20CS30037_20CS30049.y"
                    {    printf("primary-expression ==> identifier\n");   }
#line 1868 "y.tab.c"
    break;

  case 3:
#line 48 "asgn4_20CS30037_20CS30049.y"
                    {    printf("primary-expression ==> constant\n");   }
#line 1874 "y.tab.c"
    break;

  case 4:
#line 51 "asgn4_20CS30037_20CS30049.y"
                    {    printf("primary-expression ==> string-literal\n");   }
#line 1880 "y.tab.c"
    break;

  case 5:
#line 54 "asgn4_20CS30037_20CS30049.y"
                    {    printf("primary-expression ==> ( expression )\n");   }
#line 1886 "y.tab.c"
    break;

  case 6:
#line 58 "asgn4_20CS30037_20CS30049.y"
          {     printf("constant ==> int-const\n");      }
#line 1892 "y.tab.c"
    break;

  case 7:
#line 60 "asgn4_20CS30037_20CS30049.y"
          {     printf("constant ==> float-const\n");     }
#line 1898 "y.tab.c"
    break;

  case 8:
#line 62 "asgn4_20CS30037_20CS30049.y"
          {     printf("constant ==> char-const\n");     }
#line 1904 "y.tab.c"
    break;

  case 9:
#line 66 "asgn4_20CS30037_20CS30049.y"
                        {    printf("postfix-expression ==> primary-expression\n");   }
#line 1910 "y.tab.c"
    break;

  case 10:
#line 68 "asgn4_20CS30037_20CS30049.y"
                        {    printf("postfix-expression ==> postfix-expression [ expression ]\n");   }
#line 1916 "y.tab.c"
    break;

  case 11:
#line 70 "asgn4_20CS30037_20CS30049.y"
                        {    printf("postfix-expression ==> postfix-expression ( argument-expression-list-opt )\n");   }
#line 1922 "y.tab.c"
    break;

  case 12:
#line 72 "asgn4_20CS30037_20CS30049.y"
                        {    printf("postfix-expression ==> postfix-expression . identifier\n");   }
#line 1928 "y.tab.c"
    break;

  case 13:
#line 74 "asgn4_20CS30037_20CS30049.y"
                        {    printf("postfix-expression ==> postfix-expression -> identifier\n");   }
#line 1934 "y.tab.c"
    break;

  case 14:
#line 76 "asgn4_20CS30037_20CS30049.y"
                        {    printf("postfix-expression ==> postfix-expression ++\n");   }
#line 1940 "y.tab.c"
    break;

  case 15:
#line 78 "asgn4_20CS30037_20CS30049.y"
                        {    printf("postfix-expression ==> postfix-expression --\n");   }
#line 1946 "y.tab.c"
    break;

  case 16:
#line 80 "asgn4_20CS30037_20CS30049.y"
                        {    printf("postfix-expression ==> ( type_name ) { initializer-list }\n");   }
#line 1952 "y.tab.c"
    break;

  case 17:
#line 82 "asgn4_20CS30037_20CS30049.y"
                        {    printf("postfix-expression ==> ( type_name ) { initializer-list , }\n");   }
#line 1958 "y.tab.c"
    break;

  case 18:
#line 86 "asgn4_20CS30037_20CS30049.y"
                                { printf("argument-expression-list-opt ==> argument-expression-list\n");   }
#line 1964 "y.tab.c"
    break;

  case 19:
#line 88 "asgn4_20CS30037_20CS30049.y"
                                { printf("argument-expression-list-opt ==> epsilon\n");   }
#line 1970 "y.tab.c"
    break;

  case 20:
#line 92 "asgn4_20CS30037_20CS30049.y"
                                { printf("argument-expression-list ==> assignment_expression\n");   }
#line 1976 "y.tab.c"
    break;

  case 21:
#line 94 "asgn4_20CS30037_20CS30049.y"
                                { printf("argument-expression-list ==> argument-expression-list , assignment_expression\n");   }
#line 1982 "y.tab.c"
    break;

  case 22:
#line 98 "asgn4_20CS30037_20CS30049.y"
                    { printf("unary-expression ==> postfix-expression\n");   }
#line 1988 "y.tab.c"
    break;

  case 23:
#line 100 "asgn4_20CS30037_20CS30049.y"
                    { printf("unary-expression ==> ++ unary-expression\n");   }
#line 1994 "y.tab.c"
    break;

  case 24:
#line 102 "asgn4_20CS30037_20CS30049.y"
                    { printf("unary-expression ==> -- unary-expression\n");   }
#line 2000 "y.tab.c"
    break;

  case 25:
#line 104 "asgn4_20CS30037_20CS30049.y"
                    { printf("unary-expression ==> unary-operator cast-expression\n");   }
#line 2006 "y.tab.c"
    break;

  case 26:
#line 106 "asgn4_20CS30037_20CS30049.y"
                    { printf("unary-expression ==> sizeof unary-expression\n");   }
#line 2012 "y.tab.c"
    break;

  case 27:
#line 108 "asgn4_20CS30037_20CS30049.y"
                    { printf("unary-expression ==> sizeof ( type-name )\n");   }
#line 2018 "y.tab.c"
    break;

  case 28:
#line 112 "asgn4_20CS30037_20CS30049.y"
                    { printf("unary-operator ==> &\n");   }
#line 2024 "y.tab.c"
    break;

  case 29:
#line 115 "asgn4_20CS30037_20CS30049.y"
                    { printf("unary-operator ==> *\n");   }
#line 2030 "y.tab.c"
    break;

  case 30:
#line 118 "asgn4_20CS30037_20CS30049.y"
                    { printf("unary-operator ==> +\n");   }
#line 2036 "y.tab.c"
    break;

  case 31:
#line 121 "asgn4_20CS30037_20CS30049.y"
                    { printf("unary-operator ==> -\n");   }
#line 2042 "y.tab.c"
    break;

  case 32:
#line 124 "asgn4_20CS30037_20CS30049.y"
                    { printf("unary-operator ==> ~\n");   }
#line 2048 "y.tab.c"
    break;

  case 33:
#line 127 "asgn4_20CS30037_20CS30049.y"
                    { printf("unary-operator ==> !\n");   }
#line 2054 "y.tab.c"
    break;

  case 34:
#line 131 "asgn4_20CS30037_20CS30049.y"
                    { printf("cast-expression ==> unary-expression\n");   }
#line 2060 "y.tab.c"
    break;

  case 35:
#line 133 "asgn4_20CS30037_20CS30049.y"
                    { printf("cast-expression ==> ( type-name ) cast-expression\n");   }
#line 2066 "y.tab.c"
    break;

  case 36:
#line 137 "asgn4_20CS30037_20CS30049.y"
                            { printf("multiplicative-expression ==> cast-expression\n");   }
#line 2072 "y.tab.c"
    break;

  case 37:
#line 139 "asgn4_20CS30037_20CS30049.y"
                            { printf("multiplicative-expression ==> multiplicative-expression * cast-expression\n");   }
#line 2078 "y.tab.c"
    break;

  case 38:
#line 141 "asgn4_20CS30037_20CS30049.y"
                            { printf("multiplicative-expression ==> multiplicative-expression / cast-expression\n");   }
#line 2084 "y.tab.c"
    break;

  case 39:
#line 143 "asgn4_20CS30037_20CS30049.y"
                            { printf("multiplicative-expression ==> multiplicative-expression %% cast-expression\n");   }
#line 2090 "y.tab.c"
    break;

  case 40:
#line 147 "asgn4_20CS30037_20CS30049.y"
                        { printf("additive-expression ==> multiplicative-expression\n");   }
#line 2096 "y.tab.c"
    break;

  case 41:
#line 149 "asgn4_20CS30037_20CS30049.y"
                        { printf("additive-expression ==> additive-expression + multiplicative-expression\n");   }
#line 2102 "y.tab.c"
    break;

  case 42:
#line 151 "asgn4_20CS30037_20CS30049.y"
                        { printf("additive-expression ==> additive-expression - multiplicative-expression\n");   }
#line 2108 "y.tab.c"
    break;

  case 43:
#line 155 "asgn4_20CS30037_20CS30049.y"
                    { printf("shift-expression ==> additive-expression\n");   }
#line 2114 "y.tab.c"
    break;

  case 44:
#line 157 "asgn4_20CS30037_20CS30049.y"
                    { printf("shift-expression ==> shift-expression << additive-expression\n");   }
#line 2120 "y.tab.c"
    break;

  case 45:
#line 159 "asgn4_20CS30037_20CS30049.y"
                    { printf("shift-expression ==> shift-expression >> additive-expression\n");   }
#line 2126 "y.tab.c"
    break;

  case 46:
#line 163 "asgn4_20CS30037_20CS30049.y"
                        { printf("relational-expression ==> shift-expression\n");   }
#line 2132 "y.tab.c"
    break;

  case 47:
#line 165 "asgn4_20CS30037_20CS30049.y"
                        { printf("relational-expression ==> relational-expression < shift-expression\n");   }
#line 2138 "y.tab.c"
    break;

  case 48:
#line 167 "asgn4_20CS30037_20CS30049.y"
                        { printf("relational-expression ==> relational-expression > shift-expression\n");   }
#line 2144 "y.tab.c"
    break;

  case 49:
#line 169 "asgn4_20CS30037_20CS30049.y"
                        { printf("relational-expression ==> relational-expression <= shift-expression\n");   }
#line 2150 "y.tab.c"
    break;

  case 50:
#line 171 "asgn4_20CS30037_20CS30049.y"
                        { printf("relational-expression ==> relational-expression >= shift-expression\n");  }
#line 2156 "y.tab.c"
    break;

  case 51:
#line 175 "asgn4_20CS30037_20CS30049.y"
                        { printf("equality-expression ==> relational-expression\n");   }
#line 2162 "y.tab.c"
    break;

  case 52:
#line 177 "asgn4_20CS30037_20CS30049.y"
                        { printf("equality-expression ==> equality-expression == relational-expression\n");   }
#line 2168 "y.tab.c"
    break;

  case 53:
#line 179 "asgn4_20CS30037_20CS30049.y"
                        { printf("equality-expression ==> equality-expression != relational-expression\n");   }
#line 2174 "y.tab.c"
    break;

  case 54:
#line 183 "asgn4_20CS30037_20CS30049.y"
                    { printf("AND-expression ==> equality-expression\n");   }
#line 2180 "y.tab.c"
    break;

  case 55:
#line 185 "asgn4_20CS30037_20CS30049.y"
                    { printf("AND-expression ==> AND-expression & equality-expression\n");   }
#line 2186 "y.tab.c"
    break;

  case 56:
#line 189 "asgn4_20CS30037_20CS30049.y"
                            { printf("exclusive-OR-expression ==> AND-expression\n");   }
#line 2192 "y.tab.c"
    break;

  case 57:
#line 191 "asgn4_20CS30037_20CS30049.y"
                            { printf("exclusive-OR-expression ==> exclusive-OR-expression ^ AND-expression\n");   }
#line 2198 "y.tab.c"
    break;

  case 58:
#line 195 "asgn4_20CS30037_20CS30049.y"
                            { printf("inclusive-OR-expression ==> exclusive-OR-expression\n");   }
#line 2204 "y.tab.c"
    break;

  case 59:
#line 197 "asgn4_20CS30037_20CS30049.y"
                            { printf("inclusive-OR-expression ==> inclusive-OR-expression | exclusive-OR-expression\n");   }
#line 2210 "y.tab.c"
    break;

  case 60:
#line 201 "asgn4_20CS30037_20CS30049.y"
                            { printf("logical-AND-expression ==> inclusive-OR-expression\n");   }
#line 2216 "y.tab.c"
    break;

  case 61:
#line 203 "asgn4_20CS30037_20CS30049.y"
                            { printf("logical-AND-expression ==> logical-AND-expression && inclusive-OR-expression\n");   }
#line 2222 "y.tab.c"
    break;

  case 62:
#line 207 "asgn4_20CS30037_20CS30049.y"
                            { printf("logical-OR-expression ==> logical-AND-expression\n");   }
#line 2228 "y.tab.c"
    break;

  case 63:
#line 209 "asgn4_20CS30037_20CS30049.y"
                            { printf("logical-OR-expression ==> logical-OR-expression || logical-AND-expression\n");   }
#line 2234 "y.tab.c"
    break;

  case 64:
#line 213 "asgn4_20CS30037_20CS30049.y"
                            { printf("conditional-expression ==> logical-OR-expression\n");   }
#line 2240 "y.tab.c"
    break;

  case 65:
#line 215 "asgn4_20CS30037_20CS30049.y"
                            { printf("conditional-expression ==> logical-OR-expression ? expression : conditional-expression\n");   }
#line 2246 "y.tab.c"
    break;

  case 66:
#line 220 "asgn4_20CS30037_20CS30049.y"
                            { printf("assignment-expression ==> conditional-expression\n");   }
#line 2252 "y.tab.c"
    break;

  case 67:
#line 222 "asgn4_20CS30037_20CS30049.y"
                            { printf("assignment-expression ==> unary-expression assignment-operator assignment-expression\n");   }
#line 2258 "y.tab.c"
    break;

  case 68:
#line 226 "asgn4_20CS30037_20CS30049.y"
                        { printf("assignment-operator ==> =\n");   }
#line 2264 "y.tab.c"
    break;

  case 69:
#line 228 "asgn4_20CS30037_20CS30049.y"
                        { printf("assignment-operator ==> *=\n");   }
#line 2270 "y.tab.c"
    break;

  case 70:
#line 230 "asgn4_20CS30037_20CS30049.y"
                        { printf("assignment-operator ==> /=\n");   }
#line 2276 "y.tab.c"
    break;

  case 71:
#line 232 "asgn4_20CS30037_20CS30049.y"
                        { printf("assignment-operator ==> %%=\n");   }
#line 2282 "y.tab.c"
    break;

  case 72:
#line 234 "asgn4_20CS30037_20CS30049.y"
                        { printf("assignment-operator ==> +=\n");   }
#line 2288 "y.tab.c"
    break;

  case 73:
#line 236 "asgn4_20CS30037_20CS30049.y"
                        { printf("assignment-operator ==> -=\n");   }
#line 2294 "y.tab.c"
    break;

  case 74:
#line 238 "asgn4_20CS30037_20CS30049.y"
                        { printf("assignment-operator ==> <<=\n");   }
#line 2300 "y.tab.c"
    break;

  case 75:
#line 240 "asgn4_20CS30037_20CS30049.y"
                        { printf("assignment-operator ==> >>=\n");   }
#line 2306 "y.tab.c"
    break;

  case 76:
#line 242 "asgn4_20CS30037_20CS30049.y"
                        { printf("assignment-operator ==> &=\n");   }
#line 2312 "y.tab.c"
    break;

  case 77:
#line 244 "asgn4_20CS30037_20CS30049.y"
                        { printf("assignment-operator ==> ^=\n");   }
#line 2318 "y.tab.c"
    break;

  case 78:
#line 246 "asgn4_20CS30037_20CS30049.y"
                        { printf("assignment-operator ==> |=\n");   }
#line 2324 "y.tab.c"
    break;

  case 79:
#line 252 "asgn4_20CS30037_20CS30049.y"
                { printf("expression ==> assignment-expression\n");   }
#line 2330 "y.tab.c"
    break;

  case 80:
#line 254 "asgn4_20CS30037_20CS30049.y"
                { printf("expression ==> expression , assignment-expression\n");   }
#line 2336 "y.tab.c"
    break;

  case 81:
#line 258 "asgn4_20CS30037_20CS30049.y"
                        { printf("constant-expression ==> conditional-expression\n");   }
#line 2342 "y.tab.c"
    break;

  case 82:
#line 262 "asgn4_20CS30037_20CS30049.y"
                { printf("declaration ==> declaration_specifiers init-declarator-list-opt ;\n");   }
#line 2348 "y.tab.c"
    break;

  case 83:
#line 266 "asgn4_20CS30037_20CS30049.y"
                            { printf("init-declarator-list-opt ==> init-declarator-list\n");   }
#line 2354 "y.tab.c"
    break;

  case 84:
#line 268 "asgn4_20CS30037_20CS30049.y"
                            { printf("init-declarator-list-opt ==> epsilon\n");   }
#line 2360 "y.tab.c"
    break;

  case 85:
#line 273 "asgn4_20CS30037_20CS30049.y"
                            { printf("declaration_specifiers ==> storage-class-specifier declaration_specifiers-opt\n");   }
#line 2366 "y.tab.c"
    break;

  case 86:
#line 275 "asgn4_20CS30037_20CS30049.y"
                            { printf("declaration_specifiers ==> type-specifier declaration_specifiers-opt\n");   }
#line 2372 "y.tab.c"
    break;

  case 87:
#line 277 "asgn4_20CS30037_20CS30049.y"
                            { printf("declaration_specifiers ==> type_qualifier declaration_specifiers-opt\n");   }
#line 2378 "y.tab.c"
    break;

  case 88:
#line 279 "asgn4_20CS30037_20CS30049.y"
                            { printf("declaration_specifiers ==> function-specifier declaration_specifiers-opt\n");   }
#line 2384 "y.tab.c"
    break;

  case 89:
#line 283 "asgn4_20CS30037_20CS30049.y"
                                { printf("declaration_specifiers-opt ==> declaration_specifiers\n");   }
#line 2390 "y.tab.c"
    break;

  case 90:
#line 285 "asgn4_20CS30037_20CS30049.y"
                                { printf("declaration_specifiers-opt ==> epsilon\n");   }
#line 2396 "y.tab.c"
    break;

  case 91:
#line 290 "asgn4_20CS30037_20CS30049.y"
                        { printf("init-declarator-list ==> init-declarator\n");   }
#line 2402 "y.tab.c"
    break;

  case 92:
#line 292 "asgn4_20CS30037_20CS30049.y"
                        { printf("init-declarator-list ==> init-declarator-list , init-declarator\n");   }
#line 2408 "y.tab.c"
    break;

  case 93:
#line 296 "asgn4_20CS30037_20CS30049.y"
                    { printf("init-declarator ==> declarator\n");   }
#line 2414 "y.tab.c"
    break;

  case 94:
#line 298 "asgn4_20CS30037_20CS30049.y"
                    { printf("init-declarator ==> declarator = initializer\n");   }
#line 2420 "y.tab.c"
    break;

  case 95:
#line 302 "asgn4_20CS30037_20CS30049.y"
                            { printf("storage-class-specifier ==> extern\n");   }
#line 2426 "y.tab.c"
    break;

  case 96:
#line 304 "asgn4_20CS30037_20CS30049.y"
                            { printf("storage-class-specifier ==> static\n");   }
#line 2432 "y.tab.c"
    break;

  case 97:
#line 306 "asgn4_20CS30037_20CS30049.y"
                            { printf("storage-class-specifier ==> auto\n");   }
#line 2438 "y.tab.c"
    break;

  case 98:
#line 308 "asgn4_20CS30037_20CS30049.y"
                            { printf("storage-class-specifier ==> register\n");   }
#line 2444 "y.tab.c"
    break;

  case 99:
#line 312 "asgn4_20CS30037_20CS30049.y"
                    { printf("type-specifier ==> void\n");   }
#line 2450 "y.tab.c"
    break;

  case 100:
#line 314 "asgn4_20CS30037_20CS30049.y"
                    { printf("type-specifier ==> char\n");   }
#line 2456 "y.tab.c"
    break;

  case 101:
#line 316 "asgn4_20CS30037_20CS30049.y"
                    { printf("type-specifier ==> short\n");   }
#line 2462 "y.tab.c"
    break;

  case 102:
#line 318 "asgn4_20CS30037_20CS30049.y"
                    { printf("type-specifier ==> int\n");   }
#line 2468 "y.tab.c"
    break;

  case 103:
#line 320 "asgn4_20CS30037_20CS30049.y"
                    { printf("type-specifier ==> long\n");   }
#line 2474 "y.tab.c"
    break;

  case 104:
#line 322 "asgn4_20CS30037_20CS30049.y"
                    { printf("type-specifier ==> float\n");   }
#line 2480 "y.tab.c"
    break;

  case 105:
#line 324 "asgn4_20CS30037_20CS30049.y"
                    { printf("type-specifier ==> double\n");   }
#line 2486 "y.tab.c"
    break;

  case 106:
#line 326 "asgn4_20CS30037_20CS30049.y"
                    { printf("type-specifier ==> signed\n");   }
#line 2492 "y.tab.c"
    break;

  case 107:
#line 328 "asgn4_20CS30037_20CS30049.y"
                    { printf("type-specifier ==> unsigned\n");   }
#line 2498 "y.tab.c"
    break;

  case 108:
#line 330 "asgn4_20CS30037_20CS30049.y"
                    { printf("type-specifier ==> _Bool\n");   }
#line 2504 "y.tab.c"
    break;

  case 109:
#line 332 "asgn4_20CS30037_20CS30049.y"
                    { printf("type-specifier ==> _Complex\n");   }
#line 2510 "y.tab.c"
    break;

  case 110:
#line 334 "asgn4_20CS30037_20CS30049.y"
                    { printf("type-specifier ==> _Imaginary\n");   }
#line 2516 "y.tab.c"
    break;

  case 111:
#line 336 "asgn4_20CS30037_20CS30049.y"
                    { printf("type-specifier ==> enum-specifier\n");   }
#line 2522 "y.tab.c"
    break;

  case 112:
#line 342 "asgn4_20CS30037_20CS30049.y"
                            { printf("specifier-qualifier-list ==> type-specifier specifier-qualifier-list-opt\n");   }
#line 2528 "y.tab.c"
    break;

  case 113:
#line 344 "asgn4_20CS30037_20CS30049.y"
                            { printf("specifier-qualifier-list ==> type_qualifier specifier-qualifier-list-opt\n");   }
#line 2534 "y.tab.c"
    break;

  case 114:
#line 348 "asgn4_20CS30037_20CS30049.y"
                                { printf("specifier-qualifier-list-opt ==> specifier-qualifier-list\n");   }
#line 2540 "y.tab.c"
    break;

  case 115:
#line 350 "asgn4_20CS30037_20CS30049.y"
                                { printf("specifier-qualifier-list-opt ==> epsilon\n");   }
#line 2546 "y.tab.c"
    break;

  case 116:
#line 354 "asgn4_20CS30037_20CS30049.y"
                    { printf("enum-specifier ==> enum identifier-opt { enumerator-list }\n");   }
#line 2552 "y.tab.c"
    break;

  case 117:
#line 356 "asgn4_20CS30037_20CS30049.y"
                    { printf("enum-specifier ==> enum identifier-opt { enumerator-list , }\n");   }
#line 2558 "y.tab.c"
    break;

  case 118:
#line 358 "asgn4_20CS30037_20CS30049.y"
                    { printf("enum-specifier ==> enum identifier\n");   }
#line 2564 "y.tab.c"
    break;

  case 119:
#line 363 "asgn4_20CS30037_20CS30049.y"
                {     printf("identifier-opt ==> identifier\n");     }
#line 2570 "y.tab.c"
    break;

  case 120:
#line 366 "asgn4_20CS30037_20CS30049.y"
                {     printf("identifier-opt ==> epsilon\n");     }
#line 2576 "y.tab.c"
    break;

  case 121:
#line 370 "asgn4_20CS30037_20CS30049.y"
                    { printf("enumerator-list ==> enumerator\n");   }
#line 2582 "y.tab.c"
    break;

  case 122:
#line 372 "asgn4_20CS30037_20CS30049.y"
                    { printf("enumerator-list ==> enumerator-list , enumerator\n");   }
#line 2588 "y.tab.c"
    break;

  case 123:
#line 376 "asgn4_20CS30037_20CS30049.y"
                { printf("enumerator ==> enumeration-constant\n");   }
#line 2594 "y.tab.c"
    break;

  case 124:
#line 378 "asgn4_20CS30037_20CS30049.y"
                { printf("enumerator ==> enumeration-constant = constant-expression\n");   }
#line 2600 "y.tab.c"
    break;

  case 125:
#line 382 "asgn4_20CS30037_20CS30049.y"
                    { printf("type_qualifier ==> const\n");     }
#line 2606 "y.tab.c"
    break;

  case 126:
#line 384 "asgn4_20CS30037_20CS30049.y"
                    { printf("type_qualifier ==> restrict\n");     }
#line 2612 "y.tab.c"
    break;

  case 127:
#line 386 "asgn4_20CS30037_20CS30049.y"
                    { printf("type_qualifier ==> volatile\n");     }
#line 2618 "y.tab.c"
    break;

  case 128:
#line 390 "asgn4_20CS30037_20CS30049.y"
                        { printf("function_specifier ==> inline\n");     }
#line 2624 "y.tab.c"
    break;

  case 129:
#line 394 "asgn4_20CS30037_20CS30049.y"
                { printf("declarator ==> pointer-opt direct_declarator\n");     }
#line 2630 "y.tab.c"
    break;

  case 130:
#line 398 "asgn4_20CS30037_20CS30049.y"
                { printf("pointer-opt ==> pointer\n");   }
#line 2636 "y.tab.c"
    break;

  case 131:
#line 400 "asgn4_20CS30037_20CS30049.y"
                { printf("pointer-opt ==> epsilon\n");   }
#line 2642 "y.tab.c"
    break;

  case 132:
#line 404 "asgn4_20CS30037_20CS30049.y"
                    { printf("direct-declarator ==> identifier\n");     }
#line 2648 "y.tab.c"
    break;

  case 133:
#line 406 "asgn4_20CS30037_20CS30049.y"
                    { printf("direct-declarator ==> ( declarator )\n");     }
#line 2654 "y.tab.c"
    break;

  case 134:
#line 408 "asgn4_20CS30037_20CS30049.y"
                    { printf("direct-declarator ==> direct-declarator [ type-qualifier-list-opt assignment-expression-opt ]\n");     }
#line 2660 "y.tab.c"
    break;

  case 135:
#line 410 "asgn4_20CS30037_20CS30049.y"
                    { printf("direct-declarator ==> direct-declarator [ static type-qualifier-list-opt assignment-expression ]\n");     }
#line 2666 "y.tab.c"
    break;

  case 136:
#line 412 "asgn4_20CS30037_20CS30049.y"
                    { printf("direct-declarator ==> direct-declarator [ type-qualifier-list static assignment-expression ]\n");     }
#line 2672 "y.tab.c"
    break;

  case 137:
#line 414 "asgn4_20CS30037_20CS30049.y"
                    { printf("direct-declarator ==> direct-declarator [ type-qualifier-list-opt * ]\n");     }
#line 2678 "y.tab.c"
    break;

  case 138:
#line 416 "asgn4_20CS30037_20CS30049.y"
                    { printf("direct-declarator ==> direct-declarator ( parameter-type-list )\n");     }
#line 2684 "y.tab.c"
    break;

  case 139:
#line 418 "asgn4_20CS30037_20CS30049.y"
                    { printf("direct-declarator ==> direct-declarator ( identifier-list-opt )\n");     }
#line 2690 "y.tab.c"
    break;

  case 140:
#line 424 "asgn4_20CS30037_20CS30049.y"
                            { printf("type-qualifier-list-opt ==> type-qualifier-list\n");   }
#line 2696 "y.tab.c"
    break;

  case 141:
#line 426 "asgn4_20CS30037_20CS30049.y"
                            { printf("type-qualifier-list-opt ==> epsilon\n");   }
#line 2702 "y.tab.c"
    break;

  case 142:
#line 429 "asgn4_20CS30037_20CS30049.y"
                            { printf("assignment-expression-opt ==> assignment-expression\n");   }
#line 2708 "y.tab.c"
    break;

  case 143:
#line 431 "asgn4_20CS30037_20CS30049.y"
                            { printf("assignment-expression-opt ==> epsilon\n");   }
#line 2714 "y.tab.c"
    break;

  case 144:
#line 435 "asgn4_20CS30037_20CS30049.y"
                  { printf("identifier-list-opt ==> identifier-list\n"); }
#line 2720 "y.tab.c"
    break;

  case 145:
#line 437 "asgn4_20CS30037_20CS30049.y"
                  { printf("identifier-list-opt ==> epsilon \n"); }
#line 2726 "y.tab.c"
    break;

  case 146:
#line 441 "asgn4_20CS30037_20CS30049.y"
            { printf("pointer ==> * type-qualifier-list-opt\n");   }
#line 2732 "y.tab.c"
    break;

  case 147:
#line 443 "asgn4_20CS30037_20CS30049.y"
            { printf("pointer ==> * type-qualifier-list-opt pointer\n");   }
#line 2738 "y.tab.c"
    break;

  case 148:
#line 448 "asgn4_20CS30037_20CS30049.y"
                        { printf("type-qualifier-list ==> type-qualifier\n");   }
#line 2744 "y.tab.c"
    break;

  case 149:
#line 450 "asgn4_20CS30037_20CS30049.y"
                        { printf("type-qualifier-list ==> type-qualifier-list type-qualifier\n");   }
#line 2750 "y.tab.c"
    break;

  case 150:
#line 454 "asgn4_20CS30037_20CS30049.y"
                        { printf("parameter-type-list ==> parameter-list\n");   }
#line 2756 "y.tab.c"
    break;

  case 151:
#line 456 "asgn4_20CS30037_20CS30049.y"
                        { printf("parameter-type-list ==> parameter-list , ...\n");   }
#line 2762 "y.tab.c"
    break;

  case 152:
#line 460 "asgn4_20CS30037_20CS30049.y"
                    { printf("parameter-list ==> parameter-declaration\n");   }
#line 2768 "y.tab.c"
    break;

  case 153:
#line 462 "asgn4_20CS30037_20CS30049.y"
                    { printf("parameter-list ==> parameter-list , parameter-declaration\n");   }
#line 2774 "y.tab.c"
    break;

  case 154:
#line 466 "asgn4_20CS30037_20CS30049.y"
                            { printf("parameter-declaration ==> declaration-specifiers declarator\n");   }
#line 2780 "y.tab.c"
    break;

  case 155:
#line 468 "asgn4_20CS30037_20CS30049.y"
                            { printf("parameter-declaration ==> declaration-specifiers\n");   }
#line 2786 "y.tab.c"
    break;

  case 156:
#line 473 "asgn4_20CS30037_20CS30049.y"
                    { printf("identifier-list ==> identifier\n");   }
#line 2792 "y.tab.c"
    break;

  case 157:
#line 475 "asgn4_20CS30037_20CS30049.y"
                    { printf("identifier-list ==> identifier-list , identifier\n");   }
#line 2798 "y.tab.c"
    break;

  case 158:
#line 479 "asgn4_20CS30037_20CS30049.y"
            { printf("type-name ==> specifier-qualifier-list\n");   }
#line 2804 "y.tab.c"
    break;

  case 159:
#line 483 "asgn4_20CS30037_20CS30049.y"
                { printf("initializer ==> assignment-expression\n");   }
#line 2810 "y.tab.c"
    break;

  case 160:
#line 485 "asgn4_20CS30037_20CS30049.y"
                { printf("initializer ==> { initializer-list }\n");   }
#line 2816 "y.tab.c"
    break;

  case 161:
#line 487 "asgn4_20CS30037_20CS30049.y"
                { printf("initializer ==> { initializer-list , }\n");   }
#line 2822 "y.tab.c"
    break;

  case 162:
#line 491 "asgn4_20CS30037_20CS30049.y"
                    { printf("initializer-list ==> designation-opt initializer\n");   }
#line 2828 "y.tab.c"
    break;

  case 163:
#line 493 "asgn4_20CS30037_20CS30049.y"
                    { printf("initializer-list ==> initializer-list , designation-opt initializer\n");   }
#line 2834 "y.tab.c"
    break;

  case 164:
#line 497 "asgn4_20CS30037_20CS30049.y"
                    { printf("designation-opt ==> designation\n");   }
#line 2840 "y.tab.c"
    break;

  case 165:
#line 499 "asgn4_20CS30037_20CS30049.y"
                    { printf("designation-opt ==> epsilon\n");   }
#line 2846 "y.tab.c"
    break;

  case 166:
#line 503 "asgn4_20CS30037_20CS30049.y"
                { printf("designation ==> designator-list =\n");   }
#line 2852 "y.tab.c"
    break;

  case 167:
#line 507 "asgn4_20CS30037_20CS30049.y"
                    { printf("designator-list ==> designator\n");   }
#line 2858 "y.tab.c"
    break;

  case 168:
#line 509 "asgn4_20CS30037_20CS30049.y"
                    { printf("designator-list ==> designator-list designator\n");   }
#line 2864 "y.tab.c"
    break;

  case 169:
#line 513 "asgn4_20CS30037_20CS30049.y"
                { printf("designator ==> [ constant-expression ]\n");   }
#line 2870 "y.tab.c"
    break;

  case 170:
#line 515 "asgn4_20CS30037_20CS30049.y"
                { printf("designator ==> . identifier\n");   }
#line 2876 "y.tab.c"
    break;

  case 171:
#line 519 "asgn4_20CS30037_20CS30049.y"
            { printf("statement ==> labeled-statement\n");   }
#line 2882 "y.tab.c"
    break;

  case 172:
#line 521 "asgn4_20CS30037_20CS30049.y"
            { printf("statement ==> compound-statement\n");   }
#line 2888 "y.tab.c"
    break;

  case 173:
#line 523 "asgn4_20CS30037_20CS30049.y"
            { printf("statement ==> expression-statement\n");   }
#line 2894 "y.tab.c"
    break;

  case 174:
#line 525 "asgn4_20CS30037_20CS30049.y"
            { printf("statement ==> selection-statement\n");   }
#line 2900 "y.tab.c"
    break;

  case 175:
#line 527 "asgn4_20CS30037_20CS30049.y"
            { printf("statement ==> iteration-statement\n");   }
#line 2906 "y.tab.c"
    break;

  case 176:
#line 529 "asgn4_20CS30037_20CS30049.y"
            { printf("statement ==> jump-statement\n");   }
#line 2912 "y.tab.c"
    break;

  case 177:
#line 533 "asgn4_20CS30037_20CS30049.y"
                    { printf("labeled-statement ==> identifier : statement\n");   }
#line 2918 "y.tab.c"
    break;

  case 178:
#line 535 "asgn4_20CS30037_20CS30049.y"
                    { printf("labeled-statement ==> case constant-expression : statement\n");   }
#line 2924 "y.tab.c"
    break;

  case 179:
#line 537 "asgn4_20CS30037_20CS30049.y"
                    { printf("labeled-statement ==> default : statement\n");   }
#line 2930 "y.tab.c"
    break;

  case 180:
#line 542 "asgn4_20CS30037_20CS30049.y"
                    { printf("compound-statement ==> { block-item-list-opt }\n");   }
#line 2936 "y.tab.c"
    break;

  case 181:
#line 546 "asgn4_20CS30037_20CS30049.y"
                        { printf("block-item-list-opt ==> block-item-list\n");   }
#line 2942 "y.tab.c"
    break;

  case 182:
#line 548 "asgn4_20CS30037_20CS30049.y"
                        { printf("block-item-list-opt ==> epsilon\n");   }
#line 2948 "y.tab.c"
    break;

  case 183:
#line 552 "asgn4_20CS30037_20CS30049.y"
                    { printf("block-item-list ==> block-item\n");   }
#line 2954 "y.tab.c"
    break;

  case 184:
#line 554 "asgn4_20CS30037_20CS30049.y"
                    { printf("block-item-list ==> block-item-list block-item\n");   }
#line 2960 "y.tab.c"
    break;

  case 185:
#line 558 "asgn4_20CS30037_20CS30049.y"
            { printf("block-item ==> declaration\n");   }
#line 2966 "y.tab.c"
    break;

  case 186:
#line 560 "asgn4_20CS30037_20CS30049.y"
            { printf("block-item ==> statement\n");   }
#line 2972 "y.tab.c"
    break;

  case 187:
#line 564 "asgn4_20CS30037_20CS30049.y"
                        { printf("expression-statement ==> expression-opt ;\n");   }
#line 2978 "y.tab.c"
    break;

  case 188:
#line 568 "asgn4_20CS30037_20CS30049.y"
                    { printf("expression-opt ==> expression\n");   }
#line 2984 "y.tab.c"
    break;

  case 189:
#line 570 "asgn4_20CS30037_20CS30049.y"
                    { printf("expression-opt ==> epsilon\n");   }
#line 2990 "y.tab.c"
    break;

  case 190:
#line 574 "asgn4_20CS30037_20CS30049.y"
                        { printf("selection-statement ==> if ( expression ) statement\n");   }
#line 2996 "y.tab.c"
    break;

  case 191:
#line 576 "asgn4_20CS30037_20CS30049.y"
                        { printf("selection-statement ==> if ( expression ) statement else statement\n");   }
#line 3002 "y.tab.c"
    break;

  case 192:
#line 578 "asgn4_20CS30037_20CS30049.y"
                        { printf("selection-statement ==> switch ( expression ) statement\n");   }
#line 3008 "y.tab.c"
    break;

  case 193:
#line 582 "asgn4_20CS30037_20CS30049.y"
                        { printf("iteration-statement ==> while ( expression ) statement\n");   }
#line 3014 "y.tab.c"
    break;

  case 194:
#line 584 "asgn4_20CS30037_20CS30049.y"
                        { printf("iteration-statement ==> do statement while ( expression ) ;\n");   }
#line 3020 "y.tab.c"
    break;

  case 195:
#line 586 "asgn4_20CS30037_20CS30049.y"
                        { printf("iteration-statement ==> for ( expression-opt ; expression-opt ; expression-opt ) statement\n");   }
#line 3026 "y.tab.c"
    break;

  case 196:
#line 588 "asgn4_20CS30037_20CS30049.y"
                        { printf("iteration-statement ==> for ( declaration expression-opt ; expression-opt ) statement\n");   }
#line 3032 "y.tab.c"
    break;

  case 197:
#line 592 "asgn4_20CS30037_20CS30049.y"
                { printf("jump-statement ==> goto identifier ;\n");   }
#line 3038 "y.tab.c"
    break;

  case 198:
#line 594 "asgn4_20CS30037_20CS30049.y"
                { printf("jump-statement ==> continue ;\n");   }
#line 3044 "y.tab.c"
    break;

  case 199:
#line 596 "asgn4_20CS30037_20CS30049.y"
                { printf("jump-statement ==> break ;\n");   }
#line 3050 "y.tab.c"
    break;

  case 200:
#line 598 "asgn4_20CS30037_20CS30049.y"
                { printf("jump-statement ==> return expression-opt ;\n");   }
#line 3056 "y.tab.c"
    break;

  case 201:
#line 602 "asgn4_20CS30037_20CS30049.y"
                    { printf("translation-unit ==> external-declaration\n");   }
#line 3062 "y.tab.c"
    break;

  case 202:
#line 604 "asgn4_20CS30037_20CS30049.y"
                    { printf("translation-unit ==> translation-unit external-declaration\n");   }
#line 3068 "y.tab.c"
    break;

  case 203:
#line 608 "asgn4_20CS30037_20CS30049.y"
                        { printf("external-declaration ==> function-definition\n");   }
#line 3074 "y.tab.c"
    break;

  case 204:
#line 610 "asgn4_20CS30037_20CS30049.y"
                        { printf("external-declaration ==> declaration\n");   }
#line 3080 "y.tab.c"
    break;

  case 205:
#line 614 "asgn4_20CS30037_20CS30049.y"
                            { printf("function-definition ==> declaration-specifiers declarator declaration-list-opt compound-statement\n");   }
#line 3086 "y.tab.c"
    break;

  case 206:
#line 618 "asgn4_20CS30037_20CS30049.y"
                        { printf("declaration-list-opt ==> declaration-list\n");   }
#line 3092 "y.tab.c"
    break;

  case 207:
#line 620 "asgn4_20CS30037_20CS30049.y"
                        { printf("declaration-list-opt ==> epsilon\n");   }
#line 3098 "y.tab.c"
    break;

  case 208:
#line 624 "asgn4_20CS30037_20CS30049.y"
                    { printf("declaration-list ==> declaration\n");   }
#line 3104 "y.tab.c"
    break;

  case 209:
#line 626 "asgn4_20CS30037_20CS30049.y"
                    { printf("declaration-list ==> declaration-list declaration\n");   }
#line 3110 "y.tab.c"
    break;


#line 3114 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 629 "asgn4_20CS30037_20CS30049.y"


void yyerror(char *s) {

    printf("Error found : %s\n", s);
    printf("Line no. : %d\n", yylineno);
    printf("Unable to parse : %s, please try again\n", yytext);    
}
