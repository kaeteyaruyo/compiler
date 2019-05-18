/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw2.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *name;
	char *kind;
	char *type;
	int scope;
	char *attribute;
} symbol;

symbol *table[10][30];
int tableHead[10] = {0};
int currentScope = 0;
char symbolBuf[512];

extern int yylineno;
extern int yylex();
void yyerror(char *s);
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
int lookup_symbol();
symbol *create_symbol(char *name, char *kind, char *type, int scope, char *attribute);
void insert_symbol();
void dump_symbol();


#line 98 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    RETURN = 262,
    PRINT = 263,
    GE_OP = 264,
    LE_OP = 265,
    EQ_OP = 266,
    NE_OP = 267,
    AND_OP = 268,
    OR_OP = 269,
    INC_OP = 270,
    DEC_OP = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    MUL_ASSIGN = 274,
    DIV_ASSIGN = 275,
    MOD_ASSIGN = 276,
    VOID = 277,
    INT = 278,
    FLOAT = 279,
    STRING = 280,
    BOOL = 281,
    I_CONST = 282,
    F_CONST = 283,
    STRING_LITERAL = 284,
    ID = 285,
    TRUE = 286,
    FALSE = 287,
    LOWER_THAN_ELSE = 288
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define RETURN 262
#define PRINT 263
#define GE_OP 264
#define LE_OP 265
#define EQ_OP 266
#define NE_OP 267
#define AND_OP 268
#define OR_OP 269
#define INC_OP 270
#define DEC_OP 271
#define ADD_ASSIGN 272
#define SUB_ASSIGN 273
#define MUL_ASSIGN 274
#define DIV_ASSIGN 275
#define MOD_ASSIGN 276
#define VOID 277
#define INT 278
#define FLOAT 279
#define STRING 280
#define BOOL 281
#define I_CONST 282
#define F_CONST 283
#define STRING_LITERAL 284
#define ID 285
#define TRUE 286
#define FALSE 287
#define LOWER_THAN_ELSE 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 37 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* string;
	int boolean;

#line 211 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 228 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,     2,     2,    48,     2,     2,
      36,    37,    46,    39,    38,    40,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    34,
      44,    35,    45,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    70,    74,    76,    80,    84,    86,    88,
      90,    92,    96,    98,   100,   104,   106,   108,   112,   114,
     118,   120,   124,   128,   130,   134,   136,   138,   140,   144,
     146,   148,   150,   152,   156,   158,   160,   164,   166,   168,
     170,   172,   176,   178,   182,   184,   188,   190,   192,   196,
     198,   200,   202,   204,   206,   210,   212,   216,   218,   222,
     224,   228,   230,   232,   236,   238,   240,   242,   244,   248,
     250,   252,   256,   258,   260,   262,   266,   270,   272,   276,
     278,   282,   284,   288,   290,   292,   294,   296,   298,   302,
     304,   308,   310,   314,   316,   318,   320,   322,   326,   328,
     332,   334
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "RETURN",
  "PRINT", "GE_OP", "LE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "INC_OP",
  "DEC_OP", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "VOID", "INT", "FLOAT", "STRING", "BOOL", "I_CONST",
  "F_CONST", "STRING_LITERAL", "ID", "TRUE", "FALSE", "LOWER_THAN_ELSE",
  "';'", "'='", "'('", "')'", "','", "'+'", "'-'", "'!'", "'?'", "':'",
  "'<'", "'>'", "'*'", "'/'", "'%'", "'{'", "'}'", "$accept",
  "translation_unit", "external_declaration", "declaration",
  "type_specifier", "init_declarator", "function_declarator",
  "identifier_list", "parameter_list", "parameter_declarator",
  "assignment_expression", "unary_expression", "postfix_expression",
  "primary_expression", "constant", "expression",
  "argument_expression_list", "unary_operator", "assignment_operator",
  "conditional_expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression",
  "function_definition", "compound_statement", "block_item_list",
  "block_item", "statement", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "print_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    59,    61,    40,    41,    44,    43,
      45,    33,    63,    58,    60,    62,    42,    47,    37,   123,
     125
};
# endif

#define YYPACT_NINF -98

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-98)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,   -98,   -98,   -98,   -98,   -98,    92,   -98,   -98,    -7,
     -98,   -98,   -98,    54,   -28,   -35,   283,   316,   -98,   117,
     -98,   283,   283,   -98,   -98,   -98,   -98,   -98,   -98,   283,
     -98,   -98,   -98,   -98,   210,    11,   -98,   -98,   283,   -98,
      10,    15,    50,     6,    70,    38,   -98,   -98,     0,    97,
      99,   -98,     4,    12,    17,    72,    30,   -98,   -98,   -98,
      -7,   -98,    -9,   -98,   156,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   131,   -98,   -98,   -98,   -98,   -98,
     -98,   283,   -98,   -98,   207,   -98,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     -98,   -98,     8,   -98,    33,   283,   185,   283,   -98,    26,
     125,   -98,   -98,   283,   -98,   -98,   -98,   -98,   -98,   -98,
     136,   -98,    15,   -21,    50,     6,     6,    70,    70,    70,
      70,    38,    38,   -98,   -98,   -98,   -98,   -98,   138,   225,
     225,   161,   -98,    45,    61,   -98,   -98,   283,   283,     5,
     247,   265,     5,    73,    85,   -98,   -98,   124,     5,   165,
       5,   195,   -98,   -98,   -98,     5,   -98,     5,   -98,     5,
     -98,   -98,   -98
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     8,     9,    10,    11,     0,     2,     4,     0,
       5,     1,     3,    12,     0,    14,     0,     0,     6,     0,
      76,     0,     0,    37,    38,    41,    34,    39,    40,     0,
      46,    47,    48,    13,    72,    25,    29,    35,     0,    24,
      55,    57,    59,    61,    64,    69,    18,    15,     0,     0,
       0,    20,     0,     0,     0,     0,     0,    89,    77,    81,
       0,    42,     0,    83,     0,    79,    82,    84,    85,    86,
      87,    88,    26,    27,     0,    53,    54,    50,    51,    52,
      49,     0,    32,    33,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    16,     0,    17,     0,     0,     0,     0,    98,     0,
       0,    14,    90,     0,    78,    80,    36,    23,    30,    44,
       0,    72,    58,     0,    60,    62,    63,    68,    67,    65,
      66,    70,    71,    73,    74,    75,    19,    21,     0,     0,
       0,     0,    99,     0,     0,    43,    31,     0,     0,     0,
       0,     0,     0,     0,     0,    45,    56,    91,     0,     0,
       0,     0,    93,   101,   100,     0,    96,     0,    94,     0,
      92,    97,    95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,   115,   -15,     1,   -98,    78,   -98,   -98,    46,
     -16,   -19,   -98,   -98,   -98,   -24,   -98,   -98,   -98,   -18,
     -98,    66,    77,   104,     2,   154,   -98,   145,   -98,   106,
     168,   -97,   -98,   -98,   -98,   -98
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,    60,    14,    15,    49,    50,    51,
      61,    34,    35,    36,    37,    62,   120,    38,    81,    39,
      40,    41,    42,    43,    44,    45,    10,    63,    64,    65,
      66,    67,    68,    69,    70,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,     9,    72,    73,    59,    74,    18,     9,    52,   140,
      53,    54,    55,    56,    19,    91,    92,   113,    48,    85,
      21,    22,   148,    13,    86,   112,    82,    83,    88,   113,
     100,   109,    23,    24,    25,    26,    27,    28,   136,    57,
     105,    29,   150,   151,    30,    31,    32,    84,   106,    59,
      93,    94,    87,   107,    19,     1,     2,     3,     4,     5,
     142,    89,    90,   123,   113,   117,   110,   121,   119,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   133,   134,
     135,   138,   153,   141,    97,    98,    99,    21,    22,    16,
      17,   139,    11,   127,   128,   129,   130,   145,   154,    23,
      24,    25,    26,    27,    28,    48,   108,   163,    29,    95,
      96,    30,    31,    32,     1,     2,     3,     4,     5,   164,
      52,    12,    53,    54,    55,    56,   159,   161,   165,   121,
     156,   155,    21,    22,   101,   102,   103,   104,   111,     1,
       2,     3,     4,     5,    23,    24,    25,    26,    27,    28,
     137,    57,   122,    29,   143,   144,    30,    31,    32,    52,
      20,    53,    54,    55,    56,   124,    19,    58,   116,   113,
     115,    21,    22,   146,   147,   149,   113,     0,     1,     2,
       3,     4,     5,    23,    24,    25,    26,    27,    28,     0,
      57,     0,    29,   125,   126,    30,    31,    32,   152,   113,
      21,    22,   167,   113,     0,    19,   114,     1,     2,     3,
       4,     5,    23,    24,    25,    26,    27,    28,     0,    57,
       0,    29,    21,    22,    30,    31,    32,    75,    76,    77,
      78,    79,   169,   113,    23,    24,    25,    26,    27,    28,
      21,    22,     0,    29,   118,    80,    30,    31,    32,   131,
     132,     0,    23,    24,    25,    26,    27,    28,     0,    57,
       0,    29,    21,    22,    30,    31,    32,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,    27,    28,
      21,    22,     0,    29,   158,     0,    30,    31,    32,     0,
       0,     0,    23,    24,    25,    26,    27,    28,    21,    22,
       0,    29,   160,     0,    30,    31,    32,     0,     0,     0,
      23,    24,    25,    26,    27,    28,     0,   157,     0,    29,
     162,     0,    30,    31,    32,     0,   166,     0,   168,     0,
       0,     0,     0,   170,     0,   171,     0,   172,     1,     2,
       3,     4,     5,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,    47
};

static const yytype_int16 yycheck[] =
{
      16,     0,    21,    22,    19,    29,    34,     6,     3,   106,
       5,     6,     7,     8,    49,     9,    10,    38,    17,    38,
      15,    16,    43,    30,    14,    34,    15,    16,    13,    38,
      30,    55,    27,    28,    29,    30,    31,    32,    30,    34,
      36,    36,   139,   140,    39,    40,    41,    36,    36,    64,
      44,    45,    42,    36,    49,    22,    23,    24,    25,    26,
      34,    11,    12,    87,    38,    81,    36,    86,    84,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   105,    37,   107,    46,    47,    48,    15,    16,    35,
      36,   106,     0,    91,    92,    93,    94,   113,    37,    27,
      28,    29,    30,    31,    32,   104,    34,    34,    36,    39,
      40,    39,    40,    41,    22,    23,    24,    25,    26,    34,
       3,     6,     5,     6,     7,     8,   150,   151,     4,   148,
     148,   147,    15,    16,    37,    38,    37,    38,    60,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
     104,    34,    86,    36,    29,    30,    39,    40,    41,     3,
      15,     5,     6,     7,     8,    88,    49,    50,    37,    38,
      64,    15,    16,    37,    38,    37,    38,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    -1,    36,    89,    90,    39,    40,    41,    37,    38,
      15,    16,    37,    38,    -1,    49,    50,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      -1,    36,    15,    16,    39,    40,    41,    17,    18,    19,
      20,    21,    37,    38,    27,    28,    29,    30,    31,    32,
      15,    16,    -1,    36,    37,    35,    39,    40,    41,    95,
      96,    -1,    27,    28,    29,    30,    31,    32,    -1,    34,
      -1,    36,    15,    16,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      15,    16,    -1,    36,    37,    -1,    39,    40,    41,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    15,    16,
      -1,    36,    37,    -1,    39,    40,    41,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,   149,    -1,    36,
     152,    -1,    39,    40,    41,    -1,   158,    -1,   160,    -1,
      -1,    -1,    -1,   165,    -1,   167,    -1,   169,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    23,    24,    25,    26,    52,    53,    54,    55,
      77,     0,    53,    30,    56,    57,    35,    36,    34,    49,
      78,    15,    16,    27,    28,    29,    30,    31,    32,    36,
      39,    40,    41,    61,    62,    63,    64,    65,    68,    70,
      71,    72,    73,    74,    75,    76,    30,    37,    55,    58,
      59,    60,     3,     5,     6,     7,     8,    34,    50,    54,
      55,    61,    66,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    62,    62,    66,    17,    18,    19,    20,    21,
      35,    69,    15,    16,    36,    62,    14,    42,    13,    11,
      12,     9,    10,    44,    45,    39,    40,    46,    47,    48,
      30,    37,    38,    37,    38,    36,    36,    36,    34,    66,
      36,    57,    34,    38,    50,    80,    37,    61,    37,    61,
      67,    62,    72,    66,    73,    74,    74,    75,    75,    75,
      75,    76,    76,    62,    62,    62,    30,    60,    66,    54,
      82,    66,    34,    29,    30,    61,    37,    38,    43,    37,
      82,    82,    37,    37,    37,    61,    70,    81,    37,    66,
      37,    66,    81,    34,    34,     4,    81,    37,    81,    37,
      81,    81,    81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    55,    55,    55,
      55,    55,    56,    56,    56,    57,    57,    57,    58,    58,
      59,    59,    60,    61,    61,    62,    62,    62,    62,    63,
      63,    63,    63,    63,    64,    64,    64,    65,    65,    65,
      65,    65,    66,    66,    67,    67,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    74,    74,    74,    74,    74,    75,
      75,    75,    76,    76,    76,    76,    77,    78,    78,    79,
      79,    80,    80,    81,    81,    81,    81,    81,    81,    82,
      82,    83,    83,    84,    84,    84,    84,    84,    85,    85,
      86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     4,     4,     1,     3,
       1,     3,     2,     3,     1,     1,     2,     2,     2,     1,
       3,     4,     2,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     2,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     5,     7,     5,     6,     7,     6,     7,     2,     3,
       5,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 68 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("external_declaration\n"); }
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 70 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("translation_unit external_declaration\n"); }
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 74 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("!!!%s!!!\n", (yyvsp[0].string)); printf("declaration\n"); }
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("!!!%s!!!\n", (yyvsp[0].string)); printf("function_definition\n"); }
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 80 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[-2].string); strcat((yyval.string), " "); strcat((yyval.string), (yyvsp[-1].string)); printf("type_specifier init_declarator ';'\n"); }
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 84 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); printf("VOID\n"); }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 86 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); printf("INT\n"); }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 88 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); printf("FLOAT\n"); }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 90 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); printf("STRING\n"); }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 92 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); printf("BOOL\n"); }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 96 "compiler_hw2.y" /* yacc.c:1646  */
    { sprintf((yyval.string), "%s variable %d", (yyvsp[0].string), currentScope); printf("ID\n"); }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 98 "compiler_hw2.y" /* yacc.c:1646  */
    { sprintf((yyval.string), "%s variable %d", (yyvsp[-2].string), currentScope); printf("ID '=' assignment_expression\n"); }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 100 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); printf("function_declarator\n"); }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 104 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[-2].string); strcat((yyval.string), " function"); printf("ID '(' ')'\n"); }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 106 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("ID '(' identifier_list ')'\n"); }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 108 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[-3].string); strcat((yyval.string), " funciton paramete "); strcat((yyval.string), (yyvsp[-1].string)); printf("ID '(' parameter_list ')'\n"); }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 112 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("ID\n"); }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 114 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("identifier_list ',' ID\n"); }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 118 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); printf("parameter_declarator\n"); }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 120 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); strcat((yyval.string), " "); strcat((yyval.string), (yyvsp[-2].string)); printf("parameter_list ',' parameter_declarator\n"); }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 124 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[-1].string);  strcat((yyval.string), " "); strcat((yyval.string), (yyvsp[0].string)); printf("type_specifier ID\n");}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 128 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("unary_expression assignment_operator assignment_expression\n"); }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 130 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("conditional_expression\n"); }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 134 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("postfix_expression\n"); }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 136 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("INC_OP unary_expression\n"); }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 138 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("DEC_OP unary_expression\n"); }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 140 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("unary_operator unary_expression\n"); }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 144 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("primary_expression\n"); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 146 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("postfix_expression '(' ')'\n"); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 148 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("postfix_expression '(' argument_expression_list ')'\n"); }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 150 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("postfix_expression INC_OP\n"); }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 152 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("postfix_expression DEC_OP\n"); }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 156 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("ID\n"); }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 158 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("constant\n"); }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 160 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("'(' expression ')'\n"); }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 164 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("I_CONST\n"); }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 166 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("F_CONST\n"); }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 168 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("TRUE\n"); }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 170 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("FALSE\n"); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 172 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("STRING_LITERAL\n"); }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 176 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("assignment_expression\n"); }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 178 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("expression ',' assignment_expression\n"); }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 182 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("assignment_expression\n"); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 184 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("argument_expression_list ',' assignment_expression\n"); }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 188 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("'+'\n"); }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 190 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("'-'\n"); }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 192 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("'!'\n"); }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 196 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("'='\n"); }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 198 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("MUL_ASSIGN\n"); }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 200 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("DIV_ASSIGN\n"); }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 202 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("MOD_ASSIGN\n"); }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 204 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("ADD_ASSIGN\n"); }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 206 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("SUB_ASSIGN\n"); }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 210 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("logical_or_expression\n"); }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 212 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("logical_or_expression '?' expression ':' conditional_expression\n"); }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 216 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("logical_and_expression\n"); }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 218 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("logical_or_expression OR_OP logical_and_expression\n"); }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 222 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("equality_expression\n"); }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 224 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("logical_and_expression AND_OP equality_expression\n"); }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 228 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("relational_expression\n"); }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 230 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("equality_expression EQ_OP relational_expression\n"); }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 232 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("equality_expression NE_OP relational_expression\n"); }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 236 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("additive_expression\n"); }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 238 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("relational_expression '<' additive_expression\n"); }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 240 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("relational_expression '>' additive_expression\n"); }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 242 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("relational_expression LE_OP additive_expression\n"); }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 244 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("relational_expression GE_OP additive_expression\n"); }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 248 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("multiplicative_expression\n"); }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 250 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("additive_expression '+' multiplicative_expression\n"); }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 252 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("additive_expression '-' multiplicative_expression\n"); }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 256 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("unary_expression\n"); }
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 258 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("multiplicative_expression '*' unary_expression\n"); }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 260 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("multiplicative_expression '/' unary_expression\n"); }
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 262 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("multiplicative_expression '%' unary_expression\n"); }
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 266 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[-2].string); strcat((yyval.string), " "); strcat((yyval.string), (yyvsp[-1].string)); printf("type_specifier function_declarator compound_statement\n"); }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 270 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("'{' '}'\n"); }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 272 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("'{'  block_item_list '}'\n"); }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 276 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("block_item\n"); }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 278 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("block_item_list block_item\n"); }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 282 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("!!!%s!!!\n", (yyvsp[0].string)); printf("declaration\n"); }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 284 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("statement\n"); }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 288 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("compound_statement\n"); }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 290 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("expression_statement\n"); }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 292 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("selection_statement\n"); }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 294 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("iteration_statement\n"); }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 296 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("jump_statement\n"); }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 298 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("print_statement\n"); }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 302 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("';'\n"); }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 304 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("expression ';'\n"); }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 308 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("IF '(' expression ')' statement %prec LOWER_THAN_ELSE\n"); }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 310 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("IF '(' expression ')' statement ELSE statement\n"); }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 314 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("WHILE '(' expression ')' statement\n"); }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 316 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("FOR '(' expression_statement expression_statement ')' statement\n"); }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 318 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("FOR '(' expression_statement expression_statement expression ')' statement\n"); }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 320 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("FOR '(' declaration expression_statement ')' statement\n"); }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 322 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("FOR '(' declaration expression_statement expression ')' statement\n"); }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 326 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("RETURN ';'\n"); }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 328 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("RETURN expression ';'\n"); }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 332 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("PRINT '(' ID ')' ';'\n"); }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 334 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("PRINT '(' STRING_LITERAL ')' ';'\n"); }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2073 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 337 "compiler_hw2.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    yylineno = 1;

    yyparse();
	printf("\nTotal lines: %d \n", yylineno);

    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

symbol *create_symbol(char *name, char *kind, char *type, int scope, char *attribute){
	symbol *tmp = malloc(sizeof(symbol));
	tmp->name = strdup(name);
	tmp->kind = strdup(kind);
	tmp->type = strdup(type);
	tmp->scope = scope;
	tmp->attribute = strdup(attribute);
	return tmp;
}

void insert_symbol() {}
int lookup_symbol() {}
void dump_symbol() {
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
}
