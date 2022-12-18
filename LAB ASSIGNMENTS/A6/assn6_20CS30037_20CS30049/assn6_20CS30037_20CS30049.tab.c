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
#line 1 "assn6_20CS30037_20CS30049.y"

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

#line 97 "assn6_20CS30037_20CS30049.tab.c"

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
#ifndef YY_YY_ASSN6_20CS30037_20CS30049_TAB_H_INCLUDED
# define YY_YY_ASSN6_20CS30037_20CS30049_TAB_H_INCLUDED
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
    AUTO = 258,
    BREAK = 259,
    CASE = 260,
    CHAR_ = 261,
    CONST = 262,
    CONTINUE = 263,
    DEFAULT = 264,
    DO = 265,
    DOUBLE = 266,
    ELSE = 267,
    ENUM = 268,
    EXTERN = 269,
    FLOAT_ = 270,
    FOR = 271,
    GOTO_ = 272,
    IF = 273,
    INLINE = 274,
    INT_ = 275,
    LONG = 276,
    REGISTER = 277,
    RESTRICT = 278,
    RETURN_ = 279,
    SHORT = 280,
    SIGNED = 281,
    SIZEOF = 282,
    STATIC = 283,
    STRUCT = 284,
    SWITCH = 285,
    TYPEDEF = 286,
    UNION = 287,
    UNSIGNED = 288,
    VOID_ = 289,
    VOLATILE = 290,
    WHILE = 291,
    BOOL_ = 292,
    COMPLEX = 293,
    IMAGINARY = 294,
    LEFT_SQR_BRACKET = 295,
    RIGHT_SQR_BRACKET = 296,
    LEFT_PAREN = 297,
    RIGHT_PAREN = 298,
    LEFT_CURLY_BRACE = 299,
    RIGHT_CURLY_BRACE = 300,
    DOT = 301,
    ARROW = 302,
    INCREMENT = 303,
    DECREMENT = 304,
    BITWISE_AND = 305,
    MULTIPLY = 306,
    ADD_ = 307,
    SUBTRACT = 308,
    BITWISE_NOR = 309,
    NOT = 310,
    DIVIDE = 311,
    MODULO = 312,
    LEFT_SHIFT = 313,
    RIGHT_SHIFT = 314,
    LESS_THAN = 315,
    GREATER_THAN = 316,
    LESS_THAN_EQUALS = 317,
    GREATER_THAN_EQUALS = 318,
    EQUALS = 319,
    NOT_EQUALS = 320,
    BITWISE_XOR = 321,
    BITWISE_OR = 322,
    LOGICAL_AND = 323,
    LOGICAL_OR = 324,
    QUESTION_MARK = 325,
    COLON = 326,
    SEMICOLON = 327,
    ELLIPSIS = 328,
    ASSIGNMENT = 329,
    MUL_ASSIGNMENT = 330,
    DIV_ASSIGNMENT = 331,
    MOD_ASSIGNMENT = 332,
    ADD_ASSIGNMENT = 333,
    SUB_ASSIGNMENT = 334,
    LSHIFT_ASSIGNMENT = 335,
    RSHIFT_ASSIGNMENT = 336,
    AND_ASSIGNMENT = 337,
    XOR_ASSIGNMENT = 338,
    OR_ASSIGNMENT = 339,
    COMMA = 340,
    HASH = 341,
    IDENTIFIER = 342,
    INT_CONSTANT = 343,
    FLOAT_CONSTANT = 344,
    CHAR_CONSTANT = 345,
    STRING_LITERAL = 346
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "assn6_20CS30037_20CS30049.y"

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

#line 258 "assn6_20CS30037_20CS30049.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASSN6_20CS30037_20CS30049_TAB_H_INCLUDED  */



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
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  207
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  357

#define YYUNDEFTOK  2
#define YYMAXUTOK   346


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
      85,    86,    87,    88,    89,    90,    91
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   134,   134,   142,   156,   165,   176,   183,   190,   194,
     214,   220,   243,   247,   251,   269,   288,   292,   299,   307,
     318,   322,   340,   357,   392,   394,   399,   403,   407,   411,
     415,   419,   426,   428,   433,   451,   475,   499,   526,   528,
     552,   579,   581,   602,   626,   628,   655,   682,   709,   739,
     744,   771,   801,   803,   827,   831,   855,   860,   884,   886,
     899,   901,   911,   915,   938,   946,   956,   958,   975,   977,
     979,   981,   983,   985,   987,   989,   991,   993,   995,  1000,
    1002,  1007,  1012,  1070,  1075,  1077,  1079,  1081,  1083,  1085,
    1087,  1089,  1094,  1099,  1107,  1112,  1120,  1122,  1124,  1126,
    1131,  1135,  1139,  1141,  1145,  1147,  1151,  1153,  1155,  1157,
    1159,  1161,  1163,  1168,  1170,  1175,  1177,  1182,  1184,  1186,
    1188,  1193,  1195,  1200,  1202,  1207,  1209,  1211,  1216,  1221,
    1226,  1234,  1239,  1241,  1248,  1256,  1258,  1260,  1266,  1299,
    1304,  1306,  1313,  1315,  1320,  1322,  1326,  1328,  1335,  1337,
    1342,  1343,  1347,  1352,  1360,  1375,  1380,  1382,  1387,  1392,
    1396,  1398,  1403,  1405,  1410,  1412,  1417,  1422,  1424,  1429,
    1431,  1436,  1438,  1439,  1440,  1441,  1442,  1446,  1448,  1450,
    1455,  1457,  1464,  1469,  1481,  1485,  1489,  1491,  1498,  1511,
    1526,  1531,  1545,  1557,  1575,  1577,  1579,  1581,  1588,  1598,
    1600,  1605,  1607,  1612,  1614,  1622,  1644,  1646
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR_",
  "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN",
  "FLOAT_", "FOR", "GOTO_", "IF", "INLINE", "INT_", "LONG", "REGISTER",
  "RESTRICT", "RETURN_", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT",
  "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID_", "VOLATILE", "WHILE",
  "BOOL_", "COMPLEX", "IMAGINARY", "LEFT_SQR_BRACKET", "RIGHT_SQR_BRACKET",
  "LEFT_PAREN", "RIGHT_PAREN", "LEFT_CURLY_BRACE", "RIGHT_CURLY_BRACE",
  "DOT", "ARROW", "INCREMENT", "DECREMENT", "BITWISE_AND", "MULTIPLY",
  "ADD_", "SUBTRACT", "BITWISE_NOR", "NOT", "DIVIDE", "MODULO",
  "LEFT_SHIFT", "RIGHT_SHIFT", "LESS_THAN", "GREATER_THAN",
  "LESS_THAN_EQUALS", "GREATER_THAN_EQUALS", "EQUALS", "NOT_EQUALS",
  "BITWISE_XOR", "BITWISE_OR", "LOGICAL_AND", "LOGICAL_OR",
  "QUESTION_MARK", "COLON", "SEMICOLON", "ELLIPSIS", "ASSIGNMENT",
  "MUL_ASSIGNMENT", "DIV_ASSIGNMENT", "MOD_ASSIGNMENT", "ADD_ASSIGNMENT",
  "SUB_ASSIGNMENT", "LSHIFT_ASSIGNMENT", "RSHIFT_ASSIGNMENT",
  "AND_ASSIGNMENT", "XOR_ASSIGNMENT", "OR_ASSIGNMENT", "COMMA", "HASH",
  "IDENTIFIER", "INT_CONSTANT", "FLOAT_CONSTANT", "CHAR_CONSTANT",
  "STRING_LITERAL", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "M", "N", "assignment_expression",
  "assignment_operator", "expression", "constant_expression",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "specifier_qualifier_list", "specifier_qualifier_list_opt",
  "enum_specifier", "enumerator_list", "enumerator", "type_qualifier",
  "function_specifier", "declarator", "direct_declarator",
  "parameter_type_list_opt", "type_qualifier_list_opt", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name", "initializer",
  "initializer_list", "designation_opt", "designation", "designator_list",
  "designator", "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "function_prototype", "declaration_list", YY_NULLPTR
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346
};
# endif

#define YYPACT_NINF (-270)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-206)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1096,  -270,  -270,  -270,  -270,   -16,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,   -18,  1096,  1096,  -270,  1096,  1096,  1059,
    -270,  -270,    16,    11,    69,   -15,    35,  -270,  -270,   -24,
    -270,   660,    78,   -20,  -270,  -270,  -270,  -270,  -270,  -270,
     283,  -270,    47,    -1,  -270,    11,   105,  -270,  -270,    35,
    -270,   -15,   704,  -270,   -18,  1019,   182,   623,    78,    92,
     872,    94,   113,  -270,   146,   103,   150,   718,   916,   152,
    -270,   534,  -270,   930,   930,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,   133,  -270,  -270,  -270,  -270,  -270,   200,   265,
     872,  -270,    66,    27,    97,   176,    95,   157,   154,   155,
     158,    98,  -270,  -270,    21,  -270,  -270,  -270,  -270,   198,
    -270,  -270,  -270,  -270,  -270,   872,  -270,    11,    20,  -270,
    -270,  -270,  -270,   170,    36,  -270,  -270,  -270,  -270,  -270,
      39,   762,   188,  -270,   -15,   207,  -270,   166,  -270,    -2,
    -270,  -270,  -270,   181,  -270,   448,   448,   791,   183,   872,
    -270,    68,   534,  -270,   872,   212,     4,  1130,  -270,  1130,
     219,   534,  -270,  -270,   448,   872,   841,   178,   184,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,   872,  -270,   872,   872,   872,   872,   872,   872,
     872,   872,   872,   872,   872,   872,   872,   872,   872,   872,
    -270,  -270,   203,  -270,   872,  -270,   372,  -270,  -270,  -270,
       8,   872,   187,    23,   704,  -270,   -17,  -270,   179,  -270,
     236,   237,   872,  -270,  -270,   702,  -270,   194,   448,  -270,
    -270,  -270,  -270,   197,  -270,   241,     6,   872,  -270,  -270,
    -270,  -270,   858,   252,  -270,   -22,  -270,     9,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,    66,    66,    27,    27,    97,
      97,    97,    97,   176,   176,    95,   157,   154,   872,   872,
    -270,  -270,  -270,  -270,   271,  -270,  -270,   117,  -270,  -270,
    -270,   273,  -270,  -270,   274,  -270,  -270,  -270,  -270,   287,
     791,   281,   282,   448,   197,    36,  -270,   282,  -270,  -270,
     872,   155,   158,   872,  -270,  -270,   704,  -270,  -270,   288,
    -270,  -270,  -270,   286,    30,  -270,   197,  -270,   872,  -270,
     448,  -270,  -270,   173,   279,   197,   872,  -270,   448,  -270,
    -270,   308,   197,   340,  -270,   872,   284,   310,  -270,  -270,
    -270,  -270,   448,   448,  -270,  -270,  -270
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    98,   101,   125,   106,     0,    96,   105,   128,   103,
     104,    99,   126,   102,   107,    97,   108,   100,   127,   109,
     110,   111,   202,     0,    85,    87,   112,    89,    91,     0,
     199,   201,     0,     0,   120,     0,   145,    83,   131,     0,
      92,    94,   130,     0,    84,    86,    88,    90,     1,   200,
       0,   204,   123,     0,   121,     0,     0,   148,   147,   144,
      82,     0,     0,   206,     0,     0,   143,   141,   129,     0,
       0,     0,     0,    64,     0,     0,     0,     0,     0,     0,
      64,     0,   180,     0,     0,    26,    27,    28,    29,    30,
      31,   187,     2,     3,     4,     5,     6,     8,    20,    32,
       0,    34,    38,    41,    44,    49,    52,    54,    56,    58,
      60,    62,    66,    79,     0,   184,   185,   171,   172,    64,
     182,   173,   174,   175,   176,     0,   117,     0,     0,   132,
     149,   146,    93,    94,   165,     2,   159,    95,   207,   203,
       0,     0,   142,   156,   155,     0,   140,   150,   152,     0,
     196,    32,    81,     0,   195,     0,     0,     0,     0,     0,
     197,     0,     0,    24,     0,     0,     0,   116,   158,   116,
       0,     0,    21,    22,     0,     0,     0,     0,     0,    14,
      15,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    64,     0,   186,     0,   181,     0,   124,   122,   118,
       0,     0,     0,     0,     0,   164,     0,   167,     0,   133,
      27,     0,     0,   154,   138,     0,   139,     0,     0,   179,
      64,    64,   194,    65,   198,     0,     0,     0,     7,   115,
     113,   114,     0,     0,   177,     0,    10,     0,    18,    12,
      13,    67,    35,    36,    37,    39,    40,    42,    43,    45,
      46,    47,    48,    50,    51,    53,    55,    57,     0,     0,
      64,    80,   183,   119,     0,   170,   160,   165,   162,   166,
     168,     0,   137,   134,     0,   151,   153,   157,   178,     0,
       0,     0,    25,     0,    65,   165,    33,     0,     9,    11,
       0,    59,    61,     0,   169,   161,     0,   135,   136,     0,
      65,    64,   190,     0,     0,    19,    65,   163,     0,    64,
       0,    64,    16,   165,     0,    65,     0,    65,     0,    17,
      64,     0,    65,   188,   191,     0,     0,     0,    64,    63,
     192,    64,     0,     0,    65,   193,   189
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -270,  -270,  -270,  -270,   -70,  -270,   -94,   -27,    25,    56,
     -26,   147,   149,   151,    80,    82,  -270,   -69,   -68,  -139,
     -31,  -270,   -72,  -110,   -25,    10,  -270,   298,  -270,   -55,
     -23,   193,  -270,   309,  -123,     7,  -270,    -3,   320,  -270,
    -270,    60,   -59,  -270,  -270,   130,  -270,  -112,  -207,    61,
    -269,  -270,  -270,   141,  -153,  -270,    13,  -270,   153,  -146,
    -270,  -270,  -270,  -270,   339,  -270,  -270,  -270
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    97,    98,   257,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   156,   212,
     113,   192,   114,   153,    22,    64,    39,    40,    24,    25,
     168,   250,    26,    53,    54,    27,    28,   133,    42,   145,
     141,    43,    59,   146,   147,   148,   149,   170,   137,   223,
     224,   225,   226,   227,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    29,    30,    31,    32,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     151,   152,   239,   240,   218,   161,   193,   142,   163,   166,
      23,   241,   165,   172,   173,   217,    63,   288,   316,   308,
      41,   254,    35,   221,    35,   115,   167,    35,    33,   222,
     151,   136,    56,    36,    44,    45,    36,    46,    47,    23,
     138,   236,     3,    57,   126,    51,     3,   248,    60,   303,
     245,   216,   309,   283,    37,   151,   152,   289,    12,   253,
      50,    61,    12,   214,   316,   219,   130,    38,   286,    38,
      18,    34,    38,    57,    18,   332,   221,   144,   139,   197,
     198,   228,   222,   237,   127,   298,    36,   243,   169,   214,
     166,   214,   246,   213,   310,    52,    58,   218,    52,   166,
     262,   263,   264,   255,   301,   220,   214,   167,   287,   327,
     231,   284,   167,    55,   167,   333,   167,   194,    66,   131,
      67,   125,   195,   196,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     244,   233,   278,   279,   249,   258,   249,    57,   129,   130,
     322,   151,   152,   214,   320,   199,   200,   221,   306,   205,
     206,   261,   315,   222,   150,   323,   154,   211,   -65,   169,
     265,   266,   299,   300,   169,   304,   169,   337,   169,   273,
     274,   329,   151,   281,   155,   344,     3,   334,   157,     3,
     158,   115,   159,   136,   164,     3,   341,   291,   343,   354,
     355,   294,    12,   347,   174,    12,    78,   207,   151,   151,
     140,    12,   313,   221,    18,   356,   232,    18,   339,   222,
     208,    81,   209,    18,   267,   268,   210,    83,    84,    85,
      86,    87,    88,    89,    90,   130,   201,   202,   203,   204,
     175,   326,   176,   215,    62,   144,   177,   178,   179,   180,
     234,   235,   238,   330,   247,   242,   335,   269,   270,   271,
     272,   336,   252,   338,   342,   259,   135,    93,    94,    95,
      96,   260,   345,   280,   285,   151,   349,   292,   293,   325,
     352,   297,   214,   353,   302,   136,     1,    69,    70,     2,
       3,    71,    72,    73,     4,   307,     5,     6,     7,    74,
      75,    76,     8,     9,    10,    11,    12,    77,    13,    14,
      78,    15,   314,    79,   317,   318,    16,    17,    18,    80,
      19,    20,    21,   319,   321,    81,   305,    50,    82,   331,
     328,    83,    84,    85,    86,    87,    88,    89,    90,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     340,   346,   348,   351,   275,    91,   350,   276,   311,   132,
     277,   312,   251,    68,   128,   296,   324,   290,    49,   282,
      92,    93,    94,    95,    96,     1,    69,    70,     2,     3,
      71,    72,    73,     4,     0,     5,     6,     7,    74,    75,
      76,     8,     9,    10,    11,    12,    77,    13,    14,    78,
      15,     0,    79,     0,     0,    16,    17,    18,    80,    19,
      20,    21,     0,     0,    81,     0,    50,     0,     0,     0,
      83,    84,    85,    86,    87,    88,    89,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,    69,    70,     0,     0,    71,    72,    73,    92,
      93,    94,    95,    96,    74,    75,    76,     0,     0,     0,
       0,     0,    77,     0,     0,    78,     0,     0,    79,     0,
       0,     0,     0,     0,    80,     0,     0,     0,     0,     0,
      81,     0,    50,     0,     0,     0,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,    95,    96,
       2,     3,     0,     0,     0,     4,     0,     5,     0,     7,
       0,     0,     0,     0,     9,    10,     0,    12,     0,    13,
      14,    78,     0,     0,     0,     0,     0,    16,    17,    18,
       0,    19,    20,    21,     0,     0,    81,     0,     0,     0,
       0,     0,    83,    84,    85,    86,    87,    88,    89,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,    93,    94,    95,    96,     1,     0,     0,     2,
       3,     0,     0,     0,     4,     0,     5,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,     0,    13,    14,
       0,    15,     0,     0,     0,     0,    16,    17,    18,     0,
      19,    20,    21,     1,     0,     0,     2,     3,     0,     0,
       0,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,     0,    13,    14,     0,    15,     0,
       0,     0,     0,    16,    17,    18,     0,    19,    20,    21,
       0,     0,     0,     0,  -205,     1,     0,     0,     2,     3,
     143,     0,     0,     4,     0,     5,     6,     7,     0,     0,
       0,     8,     9,    10,    11,    12,     0,    13,    14,     0,
      15,    78,     0,     0,    62,    16,    17,    18,     0,    19,
      20,    21,     0,     0,     0,    78,    81,     0,   134,     0,
       0,     0,    83,    84,    85,    86,    87,    88,    89,    90,
      81,     0,     0,     0,     0,     0,    83,    84,    85,    86,
      87,    88,    89,    90,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
     160,   135,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,     0,   229,    81,   135,    93,    94,    95,    96,
      83,    84,    85,   230,    87,    88,    89,    90,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,     0,     0,     0,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,   135,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,    93,
      94,    95,    96,    81,   256,    78,     0,     0,     0,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,    78,
      81,     0,   305,     0,     0,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    81,     0,     0,     0,     0,     0,
      83,    84,    85,    86,    87,    88,    89,    90,   135,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,   135,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,    78,   162,   135,
      93,    94,    95,    96,    83,    84,    85,    86,    87,    88,
      89,    90,   171,     0,     0,     0,     0,     0,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   135,    93,    94,    95,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,    93,    94,
      95,    96,     1,     0,     0,     2,     3,     0,     0,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,    48,
       0,     0,     1,    50,     0,     2,     3,     0,     0,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,     1,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       6,     7,     0,     0,     0,     8,     9,    10,    11,    12,
       0,    13,    14,     0,    15,     0,     0,     0,     0,    16,
      17,    18,     0,    19,    20,    21,     2,     3,     0,     0,
       0,     4,     0,     5,     0,     7,     0,     0,     0,     0,
       9,    10,     0,    12,     0,    13,    14,     0,     0,     0,
       0,     0,     0,    16,    17,    18,     0,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      70,    70,   155,   156,   127,    77,   100,    66,    78,    81,
       0,   157,    80,    83,    84,   125,    41,   224,   287,    41,
      23,   174,    42,    40,    42,    50,    81,    42,    44,    46,
     100,    62,    35,    51,    24,    25,    51,    27,    28,    29,
      65,    43,     7,    36,    45,    32,     7,    43,    72,    43,
     162,   119,    43,    45,    72,   125,   125,    74,    23,   171,
      44,    85,    23,    85,   333,    45,    59,    87,    45,    87,
      35,    87,    87,    66,    35,    45,    40,    67,    65,    52,
      53,   140,    46,    85,    85,   238,    51,   159,    81,    85,
     162,    85,   164,    72,    85,    87,    36,   220,    87,   171,
     194,   195,   196,   175,   243,    85,    85,   162,    85,   316,
     141,   221,   167,    44,   169,    85,   171,    51,    40,    59,
      42,    74,    56,    57,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      72,   144,   210,   211,   167,   176,   169,   140,    43,   142,
     303,   221,   221,    85,   300,    58,    59,    40,   252,    64,
      65,   192,    45,    46,    72,   304,    72,    69,    70,   162,
     197,   198,   240,   241,   167,   247,   169,   330,   171,   205,
     206,   320,   252,   214,    71,   338,     7,   326,    42,     7,
      87,   216,    42,   224,    42,     7,   335,   228,   337,   352,
     353,   232,    23,   342,    71,    23,    27,    50,   278,   279,
      28,    23,   280,    40,    35,   354,    28,    35,    45,    46,
      66,    42,    67,    35,   199,   200,    68,    48,    49,    50,
      51,    52,    53,    54,    55,   228,    60,    61,    62,    63,
      40,   313,    42,    45,    74,   235,    46,    47,    48,    49,
      43,    85,    71,   321,    42,    72,   328,   201,   202,   203,
     204,   329,    43,   331,   336,    87,    87,    88,    89,    90,
      91,    87,   340,    70,    87,   345,   345,    41,    41,   310,
     348,    87,    85,   351,    43,   316,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    43,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    41,    30,    41,    41,    33,    34,    35,    36,
      37,    38,    39,    36,    43,    42,    44,    44,    45,    43,
      42,    48,    49,    50,    51,    52,    53,    54,    55,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      71,    43,    12,    43,   207,    72,    72,   208,   278,    61,
     209,   279,   169,    43,    55,   235,   305,   226,    29,   216,
      87,    88,    89,    90,    91,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    44,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,     8,     9,    10,    87,
      88,    89,    90,    91,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,
       6,     7,    -1,    -1,    -1,    11,    -1,    13,    -1,    15,
      -1,    -1,    -1,    -1,    20,    21,    -1,    23,    -1,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    89,    90,    91,     3,    -1,    -1,     6,
       7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    -1,    25,    26,
      -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,
      37,    38,    39,     3,    -1,    -1,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39,
      -1,    -1,    -1,    -1,    44,     3,    -1,    -1,     6,     7,
      87,    -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    -1,    25,    26,    -1,
      28,    27,    -1,    -1,    74,    33,    34,    35,    -1,    37,
      38,    39,    -1,    -1,    -1,    27,    42,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      72,    87,    88,    89,    90,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    87,    88,    89,    90,    91,
      48,    49,    50,    51,    52,    53,    54,    55,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    87,
      88,    89,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    42,    43,    27,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    27,
      42,    -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    87,    88,
      89,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    42,    87,
      88,    89,    90,    91,    48,    49,    50,    51,    52,    53,
      54,    55,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39,     0,
      -1,    -1,     3,    44,    -1,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39,     3,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      -1,    25,    26,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    -1,    37,    38,    39,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,
      20,    21,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,   116,   117,   120,   121,   124,   127,   128,   155,
     156,   157,   158,    44,    87,    42,    51,    72,    87,   118,
     119,   129,   130,   133,   117,   117,   117,   117,     0,   156,
      44,   148,    87,   125,   126,    44,   129,   127,   133,   134,
      72,    85,    74,   116,   117,   159,    40,    42,   130,     4,
       5,     8,     9,    10,    16,    17,    18,    24,    27,    30,
      36,    42,    45,    48,    49,    50,    51,    52,    53,    54,
      55,    72,    87,    88,    89,    90,    91,    93,    94,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   112,   114,   116,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    74,    45,    85,   125,    43,
     127,   133,   119,   129,    44,    87,   112,   140,   116,   148,
      28,   132,   134,    87,   117,   131,   135,   136,   137,   138,
      72,    96,   109,   115,    72,    71,   110,    42,    87,    42,
      72,   114,    42,    96,    42,   110,   114,   121,   122,   127,
     139,    42,    96,    96,    71,    40,    42,    46,    47,    48,
      49,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   113,    98,    51,    56,    57,    52,    53,    58,
      59,    60,    61,    62,    63,    64,    65,    50,    66,    67,
      68,    69,   111,    72,    85,    45,   110,   115,   126,    45,
      85,    40,    46,   141,   142,   143,   144,   145,   134,    41,
      51,   112,    28,   129,    43,    85,    43,    85,    71,   146,
     146,   151,    72,   114,    72,   139,   114,    42,    43,   122,
     123,   123,    43,   139,   146,   114,    43,    95,   112,    87,
      87,   112,    98,    98,    98,    99,    99,   100,   100,   101,
     101,   101,   101,   102,   102,   103,   104,   105,   110,   110,
      70,   112,   150,    45,   115,    87,    45,    85,   140,    74,
     145,   112,    41,    41,   112,    73,   137,    87,   146,   110,
     110,   111,    43,    43,   114,    44,    98,    43,    41,    43,
      85,   106,   107,   110,    41,    45,   142,    41,    41,    36,
     151,    43,   146,   111,   141,   112,   114,   140,    42,   111,
     110,    43,    45,    85,   111,   114,   110,   146,   110,    45,
      71,   111,   114,   111,   146,   110,    43,   111,    12,   109,
      72,    43,   110,   110,   146,   146,   111
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    93,    93,    93,    93,    93,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    95,    95,
      96,    96,    96,    96,    96,    96,    97,    97,    97,    97,
      97,    97,    98,    98,    99,    99,    99,    99,   100,   100,
     100,   101,   101,   101,   102,   102,   102,   102,   102,   103,
     103,   103,   104,   104,   105,   105,   106,   106,   107,   107,
     108,   108,   109,   109,   110,   111,   112,   112,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   114,
     114,   115,   116,   116,   117,   117,   117,   117,   117,   117,
     117,   117,   118,   118,   119,   119,   120,   120,   120,   120,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   122,   122,   123,   123,   124,   124,   124,
     124,   125,   125,   126,   126,   127,   127,   127,   128,   129,
     129,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   131,   132,   132,   133,   133,   133,   133,   134,   134,
     135,   135,   136,   136,   137,   137,   138,   138,   139,   140,
     140,   140,   141,   141,   142,   142,   143,   144,   144,   145,
     145,   146,   146,   146,   146,   146,   146,   147,   147,   147,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   152,
     152,   153,   153,   153,   154,   154,   154,   154,   154,   155,
     155,   156,   156,   157,   157,   158,   159,   159
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     6,     7,     1,     3,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     4,
       1,     4,     1,     9,     0,     0,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     2,     2,     1,     2,     1,     2,     1,
       2,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     0,     4,     5,     6,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     1,     3,     4,     5,     6,     6,     5,     4,     4,
       1,     0,     1,     0,     2,     1,     3,     2,     1,     2,
       1,     3,     1,     3,     2,     1,     1,     3,     1,     1,
       3,     4,     2,     4,     1,     0,     2,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     3,     1,     3,     1,     1,     2,     1,     8,    12,
       5,     8,    10,    12,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     4,     2,     2,     1,     2
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
#line 135 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();                      // Create new expression

            string str = *((yyvsp[0].strval));
            SymTbl->lookup(str);                        // Look up the entry in the symbol table; if not found, add it
            (yyval.expr)->addr = str;                             // Store pointer to string identifier name
        }
#line 1890 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 3:
#line 143 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();                      // Create new expression

            (yyval.expr)->addr = SymTbl->gentemp(INT);            // Generate a new temporary variable
            string tmp_var = (yyval.expr)->addr;
            emit(tmp_var, (yyvsp[0].intval), ASSIGN);                  // emit the corresponding quad

            SymbolValue* val = new SymbolValue();
            val->init((yyvsp[0].intval));                              // Initialize value with integer constant

            Symbol* var = SymTbl->lookup(tmp_var);
            var->init_val = val;                        // Store in symbol table
        }
#line 1908 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 4:
#line 157 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();                      // Create new expression
            (yyval.expr)->addr = SymTbl->gentemp(FLOAT);          // Generate a new temporary variable
            emit((yyval.expr)->addr, (yyvsp[0].floatval), ASSIGN);
            SymbolValue* val = new SymbolValue();
            val->init((yyvsp[0].floatval));                              // Set the initial value
            SymTbl->lookup((yyval.expr)->addr)->init_val = val;   // Store in symbol table
        }
#line 1921 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 5:
#line 166 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();                      // Create new expression

            (yyval.expr)->addr = SymTbl->gentemp(CHAR);           // Generate a new temporary variable
            emit((yyval.expr)->addr, (yyvsp[0].charval), ASSIGN);

            SymbolValue* val = new SymbolValue();
            val->init((yyvsp[0].charval));                              // Set the initial value
            SymTbl->lookup((yyval.expr)->addr)->init_val = val;   // Store in symbol table
        }
#line 1936 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 6:
#line 177 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();                      // Create new expression

            (yyval.expr)->addr = ".LC" + to_string(str_count++);
            const_strs.push_back(*((yyvsp[0].strval)));                // Add to the list of string constants
        }
#line 1947 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 7:
#line 184 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = (yyvsp[-1].expr);                                    // Simple assignment
        }
#line 1955 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 8:
#line 191 "assn6_20CS30037_20CS30049.y"
        {
            // ignore this production
        }
#line 1963 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 9:
#line 195 "assn6_20CS30037_20CS30049.y"
        {
            SymbolType to = SymTbl->lookup((yyvsp[-3].expr)->addr)->type;      // Get the type of the expression
            string f = "";

            if(!((yyvsp[-3].expr)->dim)) 
            {
                f = SymTbl->gentemp(INT);                       // Generate a new temporary variable
                emit(f, 0, ASSIGN);                             // Emit the corresponding quad
                (yyvsp[-3].expr)->name = new string(f);
            }

            string temp = SymTbl->gentemp(INT);

            // Emit the necessary quads
            emit(temp, (yyvsp[-1].expr)->addr, "", ASSIGN);
            emit(temp, temp, "4", MULT);
            emit(f, temp, "", ASSIGN);
            (yyval.expr) = (yyvsp[-3].expr);
        }
#line 1987 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 10:
#line 215 "assn6_20CS30037_20CS30049.y"
        {   
            // Corresponds to calling a function with the function name but without any arguments
            SymbolTable* funcTable = SymTbl_Global.lookup((yyvsp[-2].expr)->addr)->nested_table;
            emit((yyvsp[-2].expr)->addr, "0", "", CALL);
        }
#line 1997 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 11:
#line 221 "assn6_20CS30037_20CS30049.y"
        {   
            // Corresponds to calling a function with the function name and the appropriate number of arguments
            SymbolTable* funcTable = SymTbl_Global.lookup((yyvsp[-3].expr)->addr)->nested_table;
            vector<Parameter*> parameters = *((yyvsp[-1].param_list));                          // Get the list of parameters
            vector<Symbol*> paramsList = funcTable->symbols;

            for (int i = 0; i < (int)parameters.size(); i++) 
            {
                emit(parameters[i]->name, "", "", PARAM);               // Emit the parameters
            }

            data_type retType = funcTable->lookup("RETVAL")->type.type;  // Add an entry in the symbol table for the return value
            
            if(retType == VOID)                                         // If the function returns void
                emit((yyvsp[-3].expr)->addr, (int)parameters.size(), CALL);
            else {                                                      // If the function returns a value
                string retVal = SymTbl->gentemp(retType);
                emit((yyvsp[-3].expr)->addr, to_string(parameters.size()), retVal, CALL);
                (yyval.expr) = new Expression();
                (yyval.expr)->addr = retVal;
            }
        }
#line 2024 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 12:
#line 244 "assn6_20CS30037_20CS30049.y"
        {
            // ignore this production
        }
#line 2032 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 13:
#line 248 "assn6_20CS30037_20CS30049.y"
        {
            // ignore this production
        }
#line 2040 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 14:
#line 252 "assn6_20CS30037_20CS30049.y"
        {   
            (yyval.expr) = new Expression();                                          // Create new expression
            SymbolType t = SymTbl->lookup((yyvsp[-1].expr)->addr)->type;                       // Get the type of the expression and generate a temporary variable
            if(t.type == ARRAY) {
                (yyval.expr)->addr = SymTbl->gentemp(SymTbl->lookup((yyvsp[-1].expr)->addr)->type.base_type);
                emit((yyval.expr)->addr, (yyvsp[-1].expr)->addr, *((yyvsp[-1].expr)->name), ARR_IDX_ARG);
                string temp = SymTbl->gentemp(t.base_type);
                emit(temp, (yyvsp[-1].expr)->addr, *((yyvsp[-1].expr)->name), ARR_IDX_ARG);
                emit(temp, temp, "1", ADD);
                emit((yyvsp[-1].expr)->addr, temp, *((yyvsp[-1].expr)->name), ARR_IDX_RES);
            }
            else {
                (yyval.expr)->addr = SymTbl->gentemp(SymTbl->lookup((yyvsp[-1].expr)->addr)->type.type);
                emit((yyval.expr)->addr, (yyvsp[-1].expr)->addr, "", ASSIGN);                         // Assign the old value 
                emit((yyvsp[-1].expr)->addr, (yyvsp[-1].expr)->addr, "1", ADD);                           // Increment the value
            }
        }
#line 2062 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 15:
#line 270 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();                                          // Create new expression
            (yyval.expr)->addr = SymTbl->gentemp(SymTbl->lookup((yyvsp[-1].expr)->addr)->type.type);          // Generate a new temporary variable
            SymbolType t = SymTbl->lookup((yyvsp[-1].expr)->addr)->type;
            if(t.type == ARRAY) {
                (yyval.expr)->addr = SymTbl->gentemp(SymTbl->lookup((yyvsp[-1].expr)->addr)->type.base_type);
                string temp = SymTbl->gentemp(t.base_type);
                emit(temp, (yyvsp[-1].expr)->addr, *((yyvsp[-1].expr)->name), ARR_IDX_ARG);
                emit((yyval.expr)->addr, temp, "", ASSIGN);
                emit(temp, temp, "1", SUB);
                emit((yyvsp[-1].expr)->addr, temp, *((yyvsp[-1].expr)->name), ARR_IDX_RES);
            }
            else {
                (yyval.expr)->addr = SymTbl->gentemp(SymTbl->lookup((yyvsp[-1].expr)->addr)->type.type);
                emit((yyval.expr)->addr, (yyvsp[-1].expr)->addr, "", ASSIGN);                         // Assign the old value
                emit((yyvsp[-1].expr)->addr, (yyvsp[-1].expr)->addr, "1", SUB);                           // Decrement the value
            }
        }
#line 2085 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 16:
#line 289 "assn6_20CS30037_20CS30049.y"
        {
            // ignore this production
        }
#line 2093 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 17:
#line 293 "assn6_20CS30037_20CS30049.y"
        {
            // ignore this production
        }
#line 2101 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 18:
#line 300 "assn6_20CS30037_20CS30049.y"
        {
            Parameter* first = new Parameter();                 // Create a new parameter
            first->name = (yyvsp[0].expr)->addr;
            first->type = SymTbl->lookup((yyvsp[0].expr)->addr)->type;
            (yyval.param_list) = new vector<Parameter*>;
            (yyval.param_list)->push_back(first);                       // Add the parameter to the list
        }
#line 2113 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 19:
#line 308 "assn6_20CS30037_20CS30049.y"
        {
            Parameter* next = new Parameter();                  // Create a new parameter
            next->name = (yyvsp[0].expr)->addr;
            next->type = SymTbl->lookup(next->name)->type;
            (yyval.param_list) = (yyvsp[-2].param_list);
            (yyval.param_list)->push_back(next);                        // Add the parameter to the list
        }
#line 2125 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 20:
#line 319 "assn6_20CS30037_20CS30049.y"
        {
            // ignore this production
        }
#line 2133 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 21:
#line 323 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();
            SymbolType type = SymTbl->lookup((yyvsp[0].expr)->addr)->type;
            if(type.type == ARRAY) {
                string t = SymTbl->gentemp(type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                emit(t, t, "1", ADD);
                emit((yyvsp[0].expr)->addr, t, *((yyvsp[0].expr)->name), ARR_IDX_RES);
                (yyval.expr)->addr = SymTbl->gentemp(SymTbl->lookup((yyvsp[0].expr)->addr)->type.base_type);
            }
            else {
                emit((yyvsp[0].expr)->addr, (yyvsp[0].expr)->addr, "1", ADD);                       // Increment the value
                (yyval.expr)->addr = SymTbl->gentemp(SymTbl->lookup((yyvsp[0].expr)->addr)->type.type);
            }
            (yyval.expr)->addr = SymTbl->gentemp(SymTbl->lookup((yyvsp[0].expr)->addr)->type.type);
            emit((yyval.expr)->addr, (yyvsp[0].expr)->addr, "", ASSIGN);                         // Assign the value
        }
#line 2155 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 22:
#line 341 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();
            SymbolType type = SymTbl->lookup((yyvsp[0].expr)->addr)->type;
            if(type.type == ARRAY) {
                string t = SymTbl->gentemp(type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                emit(t, t, "1", SUB);
                emit((yyvsp[0].expr)->addr, t, *((yyvsp[0].expr)->name), ARR_IDX_RES);
                (yyval.expr)->addr = SymTbl->gentemp(SymTbl->lookup((yyvsp[0].expr)->addr)->type.base_type);
            }
            else {
                emit((yyvsp[0].expr)->addr, (yyvsp[0].expr)->addr, "1", SUB);                       // Decrement the value
                (yyval.expr)->addr = SymTbl->gentemp(SymTbl->lookup((yyvsp[0].expr)->addr)->type.type);
            }
            emit((yyval.expr)->addr, (yyvsp[0].expr)->addr, "", ASSIGN);                         // Assign the value
        }
#line 2176 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 23:
#line 358 "assn6_20CS30037_20CS30049.y"
        {
            // Case of unary operator
            switch((yyvsp[-1].charval)) {
                case '&':   // Address
                    (yyval.expr) = new Expression();
                    (yyval.expr)->addr = SymTbl->gentemp(POINTER);                 // Generate temporary of the same base type
                    emit((yyval.expr)->addr, (yyvsp[0].expr)->addr, "", REFERENCE);          // Emit the quad
                    break;
                case '*':   // De-referencing
                    (yyval.expr) = new Expression();
                    (yyval.expr)->addr = SymTbl->gentemp(INT);                     // Generate temporary of the same base type
                    (yyval.expr)->dim = 1;
                    (yyval.expr)->name = new string((yyvsp[0].expr)->addr);
                    emit((yyval.expr)->addr, (yyvsp[0].expr)->addr, "", DEREFERENCE);        // Emit the quad
                    break;
                case '-':   // Unary minus
                    (yyval.expr) = new Expression();
                    (yyval.expr)->addr = SymTbl->gentemp();                        // Generate temporary of the same base type
                    emit((yyval.expr)->addr, (yyvsp[0].expr)->addr, "", U_MINUS);            // Emit the quad
                    break;
                case '!':   // Logical not 
                    (yyval.expr) = new Expression();
                    (yyval.expr)->addr = SymTbl->gentemp(INT);                     // Generate temporary of the same base type
                    int temp = nextinstr + 2;
                    emit(to_string(temp), (yyvsp[0].expr)->addr, "0", GOTO_EQ);   // Emit the quads
                    temp = nextinstr + 3;
                    emit(to_string(temp), "", "", GOTO);
                    emit((yyval.expr)->addr, "1", "", ASSIGN);
                    temp = nextinstr + 2;
                    emit(to_string(temp), "", "", GOTO);
                    emit((yyval.expr)->addr, "0", "", ASSIGN);
                    break;
            }
        }
#line 2215 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 24:
#line 393 "assn6_20CS30037_20CS30049.y"
        {}
#line 2221 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 25:
#line 395 "assn6_20CS30037_20CS30049.y"
        {}
#line 2227 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 26:
#line 400 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.charval) = '&';
        }
#line 2235 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 27:
#line 404 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.charval) = '*';
        }
#line 2243 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 28:
#line 408 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.charval) = '+';
        }
#line 2251 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 29:
#line 412 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.charval) = '-';
        }
#line 2259 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 30:
#line 416 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.charval) = '~';
        }
#line 2267 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 31:
#line 420 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.charval) = '!';
        }
#line 2275 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 32:
#line 427 "assn6_20CS30037_20CS30049.y"
        {}
#line 2281 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 33:
#line 429 "assn6_20CS30037_20CS30049.y"
        {}
#line 2287 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 34:
#line 434 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();                                  // Generate new expression
            SymbolType tp = SymTbl->lookup((yyvsp[0].expr)->addr)->type;
            if(tp.type == ARRAY) {                                  // If the type is an array
                string t = SymTbl->gentemp(tp.base_type);                // Generate a temporary
                if((yyvsp[0].expr)->name != NULL) {
                    emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);   // Emit the necessary quad
                    (yyvsp[0].expr)->addr = t;
                    (yyvsp[0].expr)->type = tp.base_type;
                    (yyval.expr) = (yyvsp[0].expr);
                }
                else
                    (yyval.expr) = (yyvsp[0].expr);        // Simple assignment
            }
            else
                (yyval.expr) = (yyvsp[0].expr);            // Simple assignment
        }
#line 2309 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 35:
#line 452 "assn6_20CS30037_20CS30049.y"
        {   
            // Indicates multiplication
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }

            // Assign the result of the multiplication to the higher data type
            data_type final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            (yyval.expr)->addr = SymTbl->gentemp(final);                       // Store the final result in a temporary
            emit((yyval.expr)->addr, (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, MULT);
        }
#line 2337 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 36:
#line 476 "assn6_20CS30037_20CS30049.y"
        {
            // Indicates division
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }

            // Assign the result of the division to the higher data type
            data_type final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            (yyval.expr)->addr = SymTbl->gentemp(final);                       // Store the final result in a temporary
            emit((yyval.expr)->addr, (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, DIV);
        }
#line 2365 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 37:
#line 500 "assn6_20CS30037_20CS30049.y"
        {
            // Indicates modulo
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }

            // Assign the result of the modulo to the higher data type
            data_type final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            (yyval.expr)->addr = SymTbl->gentemp(final);                       // Store the final result in a temporary
            emit((yyval.expr)->addr, (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, MOD);
        }
#line 2393 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 38:
#line 527 "assn6_20CS30037_20CS30049.y"
        {}
#line 2399 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 39:
#line 529 "assn6_20CS30037_20CS30049.y"
        {   
            // Indicates addition
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }

            // Assign the result of the addition to the higher data type
            data_type final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            (yyval.expr)->addr = SymTbl->gentemp(final);                       // Store the final result in a temporary
            emit((yyval.expr)->addr, (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, ADD);
        }
#line 2427 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 40:
#line 553 "assn6_20CS30037_20CS30049.y"
        {
            // Indicates subtraction
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }

            // Assign the result of the subtraction to the higher data type
            data_type final = ((one->type.type > two->type.type) ? (one->type.type) : (two->type.type));
            (yyval.expr)->addr = SymTbl->gentemp(final);                       // Store the final result in a temporary
            emit((yyval.expr)->addr, (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, SUB);
        }
#line 2455 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 41:
#line 580 "assn6_20CS30037_20CS30049.y"
        {}
#line 2461 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 42:
#line 582 "assn6_20CS30037_20CS30049.y"
        {
            // Indicates left shift
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }
            (yyval.expr)->addr = SymTbl->gentemp(one->type.type);              // Assign the result of the left shift to the data type of the left operand
            emit((yyval.expr)->addr, (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, SL);
        }
#line 2486 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 43:
#line 603 "assn6_20CS30037_20CS30049.y"
        {
            // Indicates right shift
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }
            (yyval.expr)->addr = SymTbl->gentemp(one->type.type);              // Assign the result of the right shift to the data type of the left operand
            emit((yyval.expr)->addr, (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, SR);
        }
#line 2511 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 44:
#line 627 "assn6_20CS30037_20CS30049.y"
        {}
#line 2517 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 45:
#line 629 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }
            (yyval.expr) = new Expression();
            (yyval.expr)->addr = SymTbl->gentemp();
            (yyval.expr)->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit((yyval.expr)->addr, "1", "", ASSIGN);
            (yyval.expr)->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, GOTO_LT);                // Emit "if x < y goto ..."
            emit((yyval.expr)->addr, "0", "", ASSIGN);
            (yyval.expr)->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
#line 2548 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 46:
#line 656 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }
            (yyval.expr) = new Expression();
            (yyval.expr)->addr = SymTbl->gentemp();
            (yyval.expr)->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit((yyval.expr)->addr, "1", "", ASSIGN);
            (yyval.expr)->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, GOTO_GT);                // Emit "if x > y goto ..."
            emit((yyval.expr)->addr, "0", "", ASSIGN);
            (yyval.expr)->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
#line 2579 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 47:
#line 683 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }
            (yyval.expr) = new Expression();
            (yyval.expr)->addr = SymTbl->gentemp();
            (yyval.expr)->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit((yyval.expr)->addr, "1", "", ASSIGN);
            (yyval.expr)->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, GOTO_LTE);               // Emit "if x <= y goto ..."
            emit((yyval.expr)->addr, "0", "", ASSIGN);
            (yyval.expr)->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
#line 2610 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 48:
#line 710 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }
            (yyval.expr) = new Expression();
            (yyval.expr)->addr = SymTbl->gentemp();
            (yyval.expr)->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit((yyval.expr)->addr, "1", "", ASSIGN);
            (yyval.expr)->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, GOTO_GTE);               // Emit "if x >= y goto ..."
            emit((yyval.expr)->addr, "0", "", ASSIGN);
            (yyval.expr)->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
#line 2641 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 49:
#line 740 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();
            (yyval.expr) = (yyvsp[0].expr);                // Simple assignment
        }
#line 2650 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 50:
#line 745 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }
            (yyval.expr) = new Expression();
            (yyval.expr)->addr = SymTbl->gentemp();
            (yyval.expr)->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit((yyval.expr)->addr, "1", "", ASSIGN);
            (yyval.expr)->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, GOTO_EQ);                // Emit "if x == y goto ..."
            emit((yyval.expr)->addr, "0", "", ASSIGN);
            (yyval.expr)->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
#line 2681 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 51:
#line 772 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }
            (yyval.expr) = new Expression();
            (yyval.expr)->addr = SymTbl->gentemp();
            (yyval.expr)->type = BOOL;                                    // Assign the result of the relational expression to a boolean
            emit((yyval.expr)->addr, "1", "", ASSIGN);
            (yyval.expr)->truelist = makelist(nextinstr);                 // Set the truelist to the next instruction
            emit("", (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, GOTO_NEQ);               // Emit "if x != y goto ..."
            emit((yyval.expr)->addr, "0", "", ASSIGN);
            (yyval.expr)->falselist = makelist(nextinstr);                // Set the falselist to the next instruction
            emit("", "", "", GOTO);                             // Emit "goto ..."
        }
#line 2712 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 52:
#line 802 "assn6_20CS30037_20CS30049.y"
        {}
#line 2718 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 53:
#line 804 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }
            (yyval.expr) = new Expression();
            (yyval.expr)->addr = SymTbl->gentemp();                            // Create a temporary variable to store the result
            emit((yyval.expr)->addr, (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, BW_AND);            // Emit the quad
        }
#line 2743 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 54:
#line 828 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = (yyvsp[0].expr);    // Simple assignment
        }
#line 2751 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 55:
#line 832 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }
            (yyval.expr) = new Expression();
            (yyval.expr)->addr = SymTbl->gentemp();                            // Create a temporary variable to store the result
            emit((yyval.expr)->addr, (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, BW_XOR);            // Emit the quad
        }
#line 2776 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 56:
#line 856 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();
            (yyval.expr) = (yyvsp[0].expr);                // Simple assignment
        }
#line 2785 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 57:
#line 861 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();
            Symbol* one = SymTbl->lookup((yyvsp[-2].expr)->addr);                  // Get the first operand from the symbol table
            Symbol* two = SymTbl->lookup((yyvsp[0].expr)->addr);                  // Get the second operand from the symbol table
            if(two->type.type == ARRAY) {                       // If the second operand is an array, perform necessary operations
                string t = SymTbl->gentemp(two->type.base_type);
                emit(t, (yyvsp[0].expr)->addr, *((yyvsp[0].expr)->name), ARR_IDX_ARG);
                (yyvsp[0].expr)->addr = t;
                (yyvsp[0].expr)->type = two->type.base_type;
            }
            if(one->type.type == ARRAY) {                       // If the first operand is an array, perform necessary operations
                string t = SymTbl->gentemp(one->type.base_type);
                emit(t, (yyvsp[-2].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_ARG);
                (yyvsp[-2].expr)->addr = t;
                (yyvsp[-2].expr)->type = one->type.base_type;
            }
            (yyval.expr) = new Expression();
            (yyval.expr)->addr = SymTbl->gentemp();                            // Create a temporary variable to store the result
            emit((yyval.expr)->addr, (yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, BW_OR);             // Emit the quad
        }
#line 2810 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 58:
#line 885 "assn6_20CS30037_20CS30049.y"
        {}
#line 2816 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 59:
#line 887 "assn6_20CS30037_20CS30049.y"
        {
            /*
                Here, we have augmented the grammar with the non-terminal M to facilitate backpatching
            */
            backpatch((yyvsp[-3].expr)->truelist, (yyvsp[-1].expr)->instr);                     // Backpatching
            (yyval.expr)->falselist = merge((yyvsp[-3].expr)->falselist, (yyvsp[0].expr)->falselist);    // Generate falselist by merging the falselists of $1 and $4
            (yyval.expr)->truelist = (yyvsp[0].expr)->truelist;                            // Generate truelist from truelist of $4
            (yyval.expr)->type = BOOL;                                        // Set the type of the expression to boolean
        }
#line 2830 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 60:
#line 900 "assn6_20CS30037_20CS30049.y"
        {}
#line 2836 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 61:
#line 902 "assn6_20CS30037_20CS30049.y"
        {
            backpatch((yyvsp[-3].expr)->falselist, (yyvsp[-1].expr)->instr);                    // Backpatching
            (yyval.expr)->truelist = merge((yyvsp[-3].expr)->truelist, (yyvsp[0].expr)->truelist);       // Generate falselist by merging the falselists of $1 and $4
            (yyval.expr)->falselist = (yyvsp[0].expr)->falselist;                          // Generate truelist from truelist of $4
            (yyval.expr)->type = BOOL;                                        // Set the type of the expression to boolean
        }
#line 2847 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 62:
#line 912 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = (yyvsp[0].expr);    // Simple assignment
        }
#line 2855 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 63:
#line 916 "assn6_20CS30037_20CS30049.y"
        {   
            /*
                Note the augmented grammar with the non-terminals M and N
            */
            Symbol* one = SymTbl->lookup((yyvsp[-4].expr)->addr);
            (yyval.expr)->addr = SymTbl->gentemp(one->type.type);      // Create a temporary for the expression
            (yyval.expr)->type = one->type.type;
            emit((yyval.expr)->addr, (yyvsp[0].expr)->addr, "", ASSIGN);         // Assign the conditional expression
            list<int> temp = makelist(nextinstr);
            emit("", "", "", GOTO);                     // Prevent fall-through
            backpatch((yyvsp[-3].expr)->nextlist, nextinstr);         // Backpatch with nextinstr
            emit((yyval.expr)->addr, (yyvsp[-4].expr)->addr, "", ASSIGN);
            temp = merge(temp, makelist(nextinstr));
            emit("", "", "", GOTO);                     // Prevent fall-through
            backpatch((yyvsp[-7].expr)->nextlist, nextinstr);         // Backpatch with nextinstr
            convertIntToBool((yyvsp[-8].expr));                       // Convert the expression to boolean
            backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-5].expr)->instr);         // When $1 is true, control goes to $4 (expression)
            backpatch((yyvsp[-8].expr)->falselist, (yyvsp[-1].expr)->instr);        // When $1 is false, control goes to $8 (conditional_expression)
            backpatch((yyvsp[-7].expr)->nextlist, nextinstr);         // Backpatch with nextinstr
        }
#line 2880 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 64:
#line 939 "assn6_20CS30037_20CS30049.y"
        {   
            // Stores the next instruction value, and helps in backpatching
            (yyval.expr) = new Expression();
            (yyval.expr)->instr = nextinstr;
        }
#line 2890 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 65:
#line 947 "assn6_20CS30037_20CS30049.y"
        {
            // Helps in control flow
            (yyval.expr) = new Expression();
            (yyval.expr)->nextlist = makelist(nextinstr);
            emit("", "", "", GOTO);
        }
#line 2901 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 66:
#line 957 "assn6_20CS30037_20CS30049.y"
        {}
#line 2907 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 67:
#line 959 "assn6_20CS30037_20CS30049.y"
        {
            Symbol* sym1 = SymTbl->lookup((yyvsp[-2].expr)->addr);         // Get the first operand from the symbol table
            Symbol* sym2 = SymTbl->lookup((yyvsp[0].expr)->addr);         // Get the second operand from the symbol table
            if((yyvsp[-2].expr)->dim == 0) {
                if(sym1->type.type != ARRAY)
                    emit((yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, "", ASSIGN);
                else
                    emit((yyvsp[-2].expr)->addr, (yyvsp[0].expr)->addr, *((yyvsp[-2].expr)->name), ARR_IDX_RES);
            }
            else
                emit(*((yyvsp[-2].expr)->name), (yyvsp[0].expr)->addr, "", L_DEREF);
            (yyval.expr) = (yyvsp[-2].expr);        // Assignment 
        }
#line 2925 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 68:
#line 976 "assn6_20CS30037_20CS30049.y"
        {}
#line 2931 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 69:
#line 978 "assn6_20CS30037_20CS30049.y"
        {}
#line 2937 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 70:
#line 980 "assn6_20CS30037_20CS30049.y"
        {}
#line 2943 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 71:
#line 982 "assn6_20CS30037_20CS30049.y"
        {}
#line 2949 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 72:
#line 984 "assn6_20CS30037_20CS30049.y"
        {}
#line 2955 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 73:
#line 986 "assn6_20CS30037_20CS30049.y"
        {}
#line 2961 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 74:
#line 988 "assn6_20CS30037_20CS30049.y"
        {}
#line 2967 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 75:
#line 990 "assn6_20CS30037_20CS30049.y"
        {}
#line 2973 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 76:
#line 992 "assn6_20CS30037_20CS30049.y"
        {}
#line 2979 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 77:
#line 994 "assn6_20CS30037_20CS30049.y"
        {}
#line 2985 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 78:
#line 996 "assn6_20CS30037_20CS30049.y"
        {}
#line 2991 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 79:
#line 1001 "assn6_20CS30037_20CS30049.y"
        {}
#line 2997 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 80:
#line 1003 "assn6_20CS30037_20CS30049.y"
        {}
#line 3003 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 81:
#line 1008 "assn6_20CS30037_20CS30049.y"
        {}
#line 3009 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 82:
#line 1013 "assn6_20CS30037_20CS30049.y"
        {
            data_type currType = (yyvsp[-2].types);
            int currSize = -1;
            // Assign correct size for the data type
            if(currType == INT)
                currSize = _SIZE_INT;
            else if(currType == CHAR)
                currSize = _SIZE_CHAR;
            else if(currType == FLOAT)
                currSize = _SIZE_FLOAT;
            vector<Declaration*> decs = *((yyvsp[-1].dec_list));
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
#line 3071 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 83:
#line 1071 "assn6_20CS30037_20CS30049.y"
        {}
#line 3077 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 84:
#line 1076 "assn6_20CS30037_20CS30049.y"
        {}
#line 3083 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 85:
#line 1078 "assn6_20CS30037_20CS30049.y"
        {}
#line 3089 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 86:
#line 1080 "assn6_20CS30037_20CS30049.y"
        {}
#line 3095 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 87:
#line 1082 "assn6_20CS30037_20CS30049.y"
        {}
#line 3101 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 88:
#line 1084 "assn6_20CS30037_20CS30049.y"
        {}
#line 3107 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 89:
#line 1086 "assn6_20CS30037_20CS30049.y"
        {}
#line 3113 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 90:
#line 1088 "assn6_20CS30037_20CS30049.y"
        {}
#line 3119 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 91:
#line 1090 "assn6_20CS30037_20CS30049.y"
        {}
#line 3125 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 92:
#line 1095 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.dec_list) = new vector<Declaration*>;      // Create a vector of declarations and add $1 to it
            (yyval.dec_list)->push_back((yyvsp[0].dec));
        }
#line 3134 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 93:
#line 1100 "assn6_20CS30037_20CS30049.y"
        {
            (yyvsp[-2].dec_list)->push_back((yyvsp[0].dec));                  // Add $3 to the vector of declarations
            (yyval.dec_list) = (yyvsp[-2].dec_list);
        }
#line 3143 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 94:
#line 1108 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.dec) = (yyvsp[0].dec);
            (yyval.dec)->init_val = NULL;         // Initialize the init_val to NULL as no initialization is done
        }
#line 3152 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 95:
#line 1113 "assn6_20CS30037_20CS30049.y"
        {   
            (yyval.dec) = (yyvsp[-2].dec);
            (yyval.dec)->init_val = (yyvsp[0].expr);           // Initialize the init_val to the value provided
        }
#line 3161 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 96:
#line 1121 "assn6_20CS30037_20CS30049.y"
        {}
#line 3167 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 97:
#line 1123 "assn6_20CS30037_20CS30049.y"
        {}
#line 3173 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 98:
#line 1125 "assn6_20CS30037_20CS30049.y"
        {}
#line 3179 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 99:
#line 1127 "assn6_20CS30037_20CS30049.y"
        {}
#line 3185 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 100:
#line 1132 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.types) = VOID;
        }
#line 3193 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 101:
#line 1136 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.types) = CHAR;
        }
#line 3201 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 102:
#line 1140 "assn6_20CS30037_20CS30049.y"
        {}
#line 3207 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 103:
#line 1142 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.types) = INT; 
        }
#line 3215 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 104:
#line 1146 "assn6_20CS30037_20CS30049.y"
        {}
#line 3221 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 105:
#line 1148 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.types) = FLOAT;
        }
#line 3229 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 106:
#line 1152 "assn6_20CS30037_20CS30049.y"
        {}
#line 3235 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 107:
#line 1154 "assn6_20CS30037_20CS30049.y"
        {}
#line 3241 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 108:
#line 1156 "assn6_20CS30037_20CS30049.y"
        {}
#line 3247 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 109:
#line 1158 "assn6_20CS30037_20CS30049.y"
        {}
#line 3253 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 110:
#line 1160 "assn6_20CS30037_20CS30049.y"
        {}
#line 3259 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 111:
#line 1162 "assn6_20CS30037_20CS30049.y"
        {}
#line 3265 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 112:
#line 1164 "assn6_20CS30037_20CS30049.y"
        {}
#line 3271 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 113:
#line 1169 "assn6_20CS30037_20CS30049.y"
        {}
#line 3277 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 114:
#line 1171 "assn6_20CS30037_20CS30049.y"
        {}
#line 3283 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 115:
#line 1176 "assn6_20CS30037_20CS30049.y"
        {}
#line 3289 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 116:
#line 1178 "assn6_20CS30037_20CS30049.y"
        {}
#line 3295 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 117:
#line 1183 "assn6_20CS30037_20CS30049.y"
        {}
#line 3301 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 118:
#line 1185 "assn6_20CS30037_20CS30049.y"
        {}
#line 3307 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 119:
#line 1187 "assn6_20CS30037_20CS30049.y"
        {}
#line 3313 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 120:
#line 1189 "assn6_20CS30037_20CS30049.y"
        {}
#line 3319 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 121:
#line 1194 "assn6_20CS30037_20CS30049.y"
        {}
#line 3325 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 122:
#line 1196 "assn6_20CS30037_20CS30049.y"
        {}
#line 3331 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 123:
#line 1201 "assn6_20CS30037_20CS30049.y"
        {}
#line 3337 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 124:
#line 1203 "assn6_20CS30037_20CS30049.y"
        {}
#line 3343 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 125:
#line 1208 "assn6_20CS30037_20CS30049.y"
        {}
#line 3349 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 126:
#line 1210 "assn6_20CS30037_20CS30049.y"
        {}
#line 3355 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 127:
#line 1212 "assn6_20CS30037_20CS30049.y"
        {}
#line 3361 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 128:
#line 1217 "assn6_20CS30037_20CS30049.y"
        {}
#line 3367 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 129:
#line 1222 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.dec) = (yyvsp[0].dec);
            (yyval.dec)->num_ptrs = (yyvsp[-1].intval);
        }
#line 3376 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 130:
#line 1227 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.dec) = (yyvsp[0].dec);
            (yyval.dec)->num_ptrs = 0;
        }
#line 3385 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 131:
#line 1235 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.dec) = new Declaration();
            (yyval.dec)->name = *((yyvsp[0].strval));
        }
#line 3394 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 132:
#line 1240 "assn6_20CS30037_20CS30049.y"
        {}
#line 3400 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 133:
#line 1242 "assn6_20CS30037_20CS30049.y"
        {
            (yyvsp[-3].dec)->type = ARRAY;       // Array type
            (yyvsp[-3].dec)->nextType = INT;     // Array of ints
            (yyval.dec) = (yyvsp[-3].dec);
            (yyval.dec)->li.push_back(0);
        }
#line 3411 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 134:
#line 1249 "assn6_20CS30037_20CS30049.y"
        {
            (yyvsp[-4].dec)->type = ARRAY;       // Array type
            (yyvsp[-4].dec)->nextType = INT;     // Array of ints
            (yyval.dec) = (yyvsp[-4].dec);
            int index = SymTbl->lookup((yyvsp[-1].expr)->addr)->init_val->int_;
            (yyval.dec)->li.push_back(index);
        }
#line 3423 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 135:
#line 1257 "assn6_20CS30037_20CS30049.y"
        {}
#line 3429 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 136:
#line 1259 "assn6_20CS30037_20CS30049.y"
        {}
#line 3435 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 137:
#line 1261 "assn6_20CS30037_20CS30049.y"
        {
            (yyvsp[-4].dec)->type = POINTER;     // Pointer type
            (yyvsp[-4].dec)->nextType = INT;
            (yyval.dec) = (yyvsp[-4].dec);
        }
#line 3445 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 138:
#line 1267 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.dec) = (yyvsp[-3].dec);
            (yyval.dec)->type = FUNCTION;    // Function type
            Symbol* funcData = SymTbl->lookup((yyval.dec)->name, (yyval.dec)->type);
            SymbolTable* funcTable = new SymbolTable();
            funcData->nested_table = funcTable;
            vector<Parameter*> paramList = *((yyvsp[-1].param_list));   // Get the parameter list

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
            emit((yyval.dec)->name, "", "", FUNC_BEG);
        }
#line 3482 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 139:
#line 1300 "assn6_20CS30037_20CS30049.y"
        {}
#line 3488 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 140:
#line 1305 "assn6_20CS30037_20CS30049.y"
        {}
#line 3494 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 141:
#line 1307 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.param_list) = new vector<Parameter*>;
        }
#line 3502 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 142:
#line 1314 "assn6_20CS30037_20CS30049.y"
        {}
#line 3508 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 143:
#line 1316 "assn6_20CS30037_20CS30049.y"
        {}
#line 3514 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 144:
#line 1321 "assn6_20CS30037_20CS30049.y"
        {}
#line 3520 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 145:
#line 1323 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.intval) = 1;
        }
#line 3528 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 146:
#line 1327 "assn6_20CS30037_20CS30049.y"
        {}
#line 3534 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 147:
#line 1329 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.intval) = 1 + (yyvsp[0].intval);
        }
#line 3542 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 148:
#line 1336 "assn6_20CS30037_20CS30049.y"
        {}
#line 3548 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 149:
#line 1338 "assn6_20CS30037_20CS30049.y"
        {}
#line 3554 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 152:
#line 1348 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.param_list) = new vector<Parameter*>;         // Create a new vector of parameters
            (yyval.param_list)->push_back((yyvsp[0].param));              // Add the parameter to the vector
        }
#line 3563 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 153:
#line 1353 "assn6_20CS30037_20CS30049.y"
        {
            (yyvsp[-2].param_list)->push_back((yyvsp[0].param));              // Add the parameter to the vector
            (yyval.param_list) = (yyvsp[-2].param_list);
        }
#line 3572 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 154:
#line 1361 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.param) = new Parameter();
            (yyval.param)->name = (yyvsp[0].dec)->name;
            if((yyvsp[0].dec)->type == ARRAY) {
                (yyval.param)->type.type = ARRAY;
                (yyval.param)->type.base_type = (yyvsp[-1].types);
            }
            else if((yyvsp[0].dec)->pc != 0) {
                (yyval.param)->type.type = POINTER;
                (yyval.param)->type.base_type = (yyvsp[-1].types);
            }
            else
                (yyval.param)->type.type = (yyvsp[-1].types);
        }
#line 3591 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 155:
#line 1376 "assn6_20CS30037_20CS30049.y"
        {}
#line 3597 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 156:
#line 1381 "assn6_20CS30037_20CS30049.y"
        {}
#line 3603 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 157:
#line 1383 "assn6_20CS30037_20CS30049.y"
        {}
#line 3609 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 158:
#line 1388 "assn6_20CS30037_20CS30049.y"
        {}
#line 3615 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 159:
#line 1393 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = (yyvsp[0].expr);   // Simple assignment
        }
#line 3623 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 160:
#line 1397 "assn6_20CS30037_20CS30049.y"
        {}
#line 3629 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 161:
#line 1399 "assn6_20CS30037_20CS30049.y"
        {}
#line 3635 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 162:
#line 1404 "assn6_20CS30037_20CS30049.y"
        {}
#line 3641 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 163:
#line 1406 "assn6_20CS30037_20CS30049.y"
        {}
#line 3647 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 164:
#line 1411 "assn6_20CS30037_20CS30049.y"
        {}
#line 3653 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 165:
#line 1413 "assn6_20CS30037_20CS30049.y"
        {}
#line 3659 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 166:
#line 1418 "assn6_20CS30037_20CS30049.y"
        {}
#line 3665 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 167:
#line 1423 "assn6_20CS30037_20CS30049.y"
        {}
#line 3671 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 168:
#line 1425 "assn6_20CS30037_20CS30049.y"
        {}
#line 3677 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 169:
#line 1430 "assn6_20CS30037_20CS30049.y"
        {}
#line 3683 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 170:
#line 1432 "assn6_20CS30037_20CS30049.y"
        {}
#line 3689 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 171:
#line 1437 "assn6_20CS30037_20CS30049.y"
        {}
#line 3695 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 177:
#line 1447 "assn6_20CS30037_20CS30049.y"
        {}
#line 3701 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 178:
#line 1449 "assn6_20CS30037_20CS30049.y"
        {}
#line 3707 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 179:
#line 1451 "assn6_20CS30037_20CS30049.y"
        {}
#line 3713 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 180:
#line 1456 "assn6_20CS30037_20CS30049.y"
        {}
#line 3719 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 181:
#line 1458 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = (yyvsp[-1].expr);
        }
#line 3727 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 182:
#line 1465 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = (yyvsp[0].expr);    // Simple assignment
            backpatch((yyvsp[0].expr)->nextlist, nextinstr);
        }
#line 3736 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 183:
#line 1470 "assn6_20CS30037_20CS30049.y"
        {   
            /*
                This production rule has been augmented with the non-terminal M
            */
            (yyval.expr) = new Expression();
            backpatch((yyvsp[-2].expr)->nextlist, (yyvsp[-1].expr)->instr);    // After $1, move to block_item via $2
            (yyval.expr)->nextlist = (yyvsp[0].expr)->nextlist;
        }
#line 3749 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 184:
#line 1482 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();   // Create new expression
        }
#line 3757 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 186:
#line 1490 "assn6_20CS30037_20CS30049.y"
        {}
#line 3763 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 187:
#line 1492 "assn6_20CS30037_20CS30049.y"
        {
            (yyval.expr) = new Expression();  // Create new expression
        }
#line 3771 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 188:
#line 1499 "assn6_20CS30037_20CS30049.y"
        {
            /*
                This production rule has been augmented for control flow
            */
            backpatch((yyvsp[-4].expr)->nextlist, nextinstr);         // nextlist of N now has nextinstr
            convertIntToBool((yyvsp[-5].expr));                       // Convert expression to bool
            backpatch((yyvsp[-5].expr)->truelist, (yyvsp[-2].expr)->instr);         // Backpatching - if expression is true, go to M
            (yyval.expr) = new Expression();                      // Create new expression
            // Merge falselist of expression, nextlist of statement and nextlist of the last N
            (yyvsp[-1].expr)->nextlist = merge((yyvsp[0].expr)->nextlist, (yyvsp[-1].expr)->nextlist);
            (yyval.expr)->nextlist = merge((yyvsp[-5].expr)->falselist, (yyvsp[-1].expr)->nextlist);
        }
#line 3788 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 189:
#line 1512 "assn6_20CS30037_20CS30049.y"
        {
            /*
                This production rule has been augmented for control flow
            */
            backpatch((yyvsp[-8].expr)->nextlist, nextinstr);         // nextlist of N now has nextinstr
            convertIntToBool((yyvsp[-9].expr));                       // Convert expression to bool
            backpatch((yyvsp[-9].expr)->truelist, (yyvsp[-6].expr)->instr);         // Backpatching - if expression is true, go to first M, else go to second M
            backpatch((yyvsp[-9].expr)->falselist, (yyvsp[-2].expr)->instr);
            (yyval.expr) = new Expression();                      // Create new expression
            // Merge nextlist of statement, nextlist of N and nextlist of the last statement
            (yyval.expr)->nextlist = merge((yyvsp[-5].expr)->nextlist, (yyvsp[-4].expr)->nextlist);
            (yyval.expr)->nextlist = merge((yyval.expr)->nextlist, (yyvsp[-1].expr)->nextlist);
            (yyval.expr)->nextlist = merge((yyval.expr)->nextlist, (yyvsp[0].expr)->nextlist);
        }
#line 3807 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 190:
#line 1527 "assn6_20CS30037_20CS30049.y"
        {}
#line 3813 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 191:
#line 1532 "assn6_20CS30037_20CS30049.y"
        {   
            /*
                This production rule has been augmented with non-terminals like M and N to handle the control flow and backpatching
            */
            (yyval.expr) = new Expression();                   // Create a new expression
            emit("", "", "", GOTO);
            backpatch(makelist(nextinstr - 1), (yyvsp[-6].expr)->instr);
            backpatch((yyvsp[-3].expr)->nextlist, nextinstr);
            convertIntToBool((yyvsp[-4].expr));                   // Convert expression to bool
            (yyval.expr)->nextlist = (yyvsp[-4].expr)->falselist;           // Exit loop if expression is false
            backpatch((yyvsp[-4].expr)->truelist, (yyvsp[-1].expr)->instr);     // Backpatching - if expression is true, go to M
            backpatch((yyvsp[0].expr)->nextlist, (yyvsp[-6].expr)->instr);     // Backpatching - go to the beginning of the loop
        }
#line 3831 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 192:
#line 1546 "assn6_20CS30037_20CS30049.y"
        {
            /*
                This production rule has been augmented with non-terminals like M and N to handle the control flow and backpatching
            */
            (yyval.expr) = new Expression();                  // Create a new expression  
            backpatch((yyvsp[-2].expr)->nextlist, nextinstr);     // Backpatching 
            convertIntToBool((yyvsp[-3].expr));                   // Convert expression to bool
            backpatch((yyvsp[-3].expr)->truelist, (yyvsp[-8].expr)->instr);     // Backpatching - if expression is true, go to M
            backpatch((yyvsp[-7].expr)->nextlist, (yyvsp[-6].expr)->instr);     // Backpatching - go to the beginning of the loop
            (yyval.expr)->nextlist = (yyvsp[-3].expr)->falselist;
        }
#line 3847 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 193:
#line 1558 "assn6_20CS30037_20CS30049.y"
        {
            /*
                This production rule has been augmented with non-terminals like M and N to handle the control flow and backpatching
            */
            (yyval.expr) = new Expression();                   // Create a new expression
            emit("", "", "", GOTO);
            (yyvsp[0].expr)->nextlist = merge((yyvsp[0].expr)->nextlist, makelist(nextinstr - 1));
            backpatch((yyvsp[0].expr)->nextlist, (yyvsp[-5].expr)->instr);    // Backpatching - go to the beginning of the loop
            backpatch((yyvsp[-3].expr)->nextlist, (yyvsp[-8].expr)->instr);     
            backpatch((yyvsp[-6].expr)->nextlist, nextinstr);     
            convertIntToBool((yyvsp[-7].expr));                   // Convert expression to bool
            backpatch((yyvsp[-7].expr)->truelist, (yyvsp[-1].expr)->instr);    // Backpatching - if expression is true, go to M
            (yyval.expr)->nextlist = (yyvsp[-7].expr)->falselist;           // Exit loop if expression is false
        }
#line 3866 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 194:
#line 1576 "assn6_20CS30037_20CS30049.y"
        {}
#line 3872 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 195:
#line 1578 "assn6_20CS30037_20CS30049.y"
        {}
#line 3878 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 196:
#line 1580 "assn6_20CS30037_20CS30049.y"
        {}
#line 3884 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 197:
#line 1582 "assn6_20CS30037_20CS30049.y"
        {
            if(SymTbl->lookup("RETVAL")->type.type == VOID) {
                emit("", "", "", RETURN);           // Emit the quad when return type is void
            }
            (yyval.expr) = new Expression();
        }
#line 3895 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 198:
#line 1589 "assn6_20CS30037_20CS30049.y"
        {
            if(SymTbl->lookup("RETVAL")->type.type == SymTbl->lookup((yyvsp[-1].expr)->addr)->type.type) {
                emit((yyvsp[-1].expr)->addr, "", "", RETURN);      // Emit the quad when return type is not void
            }
            (yyval.expr) = new Expression();
        }
#line 3906 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 199:
#line 1599 "assn6_20CS30037_20CS30049.y"
        {}
#line 3912 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 200:
#line 1601 "assn6_20CS30037_20CS30049.y"
        {}
#line 3918 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 201:
#line 1606 "assn6_20CS30037_20CS30049.y"
        {}
#line 3924 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 202:
#line 1608 "assn6_20CS30037_20CS30049.y"
        {}
#line 3930 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 203:
#line 1613 "assn6_20CS30037_20CS30049.y"
        {}
#line 3936 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 204:
#line 1615 "assn6_20CS30037_20CS30049.y"
        {
            SymTbl = &SymTbl_Global;                     // Reset the symbol table to global symbol table
            emit((yyvsp[-1].dec)->name, "", "", FUNC_END);
        }
#line 3945 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 205:
#line 1623 "assn6_20CS30037_20CS30049.y"
        {
            data_type currType = (yyvsp[-1].types);
            int currSize = -1;
            if(currType == CHAR)
                currSize = _SIZE_CHAR;
            if(currType == INT)
                currSize = _SIZE_INT;
            if(currType == FLOAT)
                currSize = _SIZE_FLOAT;
            Declaration* currDec = (yyvsp[0].dec);
            Symbol* sym = SymTbl_Global.lookup(currDec->name);
            if(currDec->type == FUNCTION) {
                Symbol* retval = sym->nested_table->lookup("RETVAL", currType, currDec->num_ptrs);   // Create entry for return value
                sym->size = 0;
                sym->init_val = NULL;
            }
            (yyval.dec) = (yyvsp[0].dec);
        }
#line 3968 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 206:
#line 1645 "assn6_20CS30037_20CS30049.y"
        {}
#line 3974 "assn6_20CS30037_20CS30049.tab.c"
    break;

  case 207:
#line 1647 "assn6_20CS30037_20CS30049.y"
        {}
#line 3980 "assn6_20CS30037_20CS30049.tab.c"
    break;


#line 3984 "assn6_20CS30037_20CS30049.tab.c"

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
#line 1650 "assn6_20CS30037_20CS30049.y"


void yyerror(string s) {
    /*
        This function prints any error encountered while parsing
    */
    cout << "Error occurred: " << s << endl;
    cout << "Line no.: " << yylineno << endl;
    cout << "Unable to parse: " << yytext << endl; 
}
