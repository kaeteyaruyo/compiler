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
	char *entryType;
	char *dataType;
	int scope;
	char *parameter;
} symbol;

symbol *table[10][30];
int symbolCount[10] = { 0 };
int currentScope = 0;

extern int yylineno;
extern int yylex();
void yyerror(char *s);
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
void create_symbol(char *signature);
void insert_symbol(symbol *s);
int lookup_symbol(char *name, int scope);
void dump_symbol(int scope);

#line 96 "y.tab.c" /* yacc.c:339  */

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
#line 35 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* string;
	int boolean;

#line 209 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 226 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   352

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

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
       0,    67,    67,    69,    73,    75,    77,    81,    83,    87,
      91,    93,    95,    97,    99,   103,   105,   107,   111,   113,
     117,   119,   123,   127,   129,   133,   135,   137,   139,   143,
     145,   147,   149,   151,   155,   157,   159,   163,   165,   167,
     169,   171,   175,   177,   181,   183,   187,   189,   191,   195,
     197,   199,   201,   203,   205,   209,   211,   215,   217,   221,
     223,   227,   229,   231,   235,   237,   239,   241,   243,   247,
     249,   251,   255,   257,   259,   261,   265,   269,   271,   275,
     277,   281,   283,   287,   289,   291,   293,   295,   297,   301,
     303,   307,   309,   313,   315,   317,   319,   321,   325,   327,
     331,   333
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
  "translation_unit", "external_declaration", "variable_declaration",
  "function_declaration", "type_specifier", "function_declarator",
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

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      36,   -92,   -92,   -92,   -92,   -92,   204,   -92,   -92,   -92,
     -23,   -92,   -92,   -92,    18,   -22,   -92,   282,   315,   -92,
     118,   -92,   282,   282,   -92,   -92,   -92,   -92,   -92,   -92,
     282,   -92,   -92,   -92,   -16,   249,    -7,   -92,   -92,   282,
     -92,    -8,    13,    79,    11,    75,    39,   -92,   -92,     3,
      82,    98,   -92,    27,    29,    31,   184,    47,   -92,   -92,
     -92,    58,   -92,    -6,   -92,   157,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   100,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   282,   -92,   -92,   206,   -92,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   -92,   -92,    92,   -92,    36,   282,    77,   282,
     -92,     7,   126,   135,   -92,   282,   -92,   -92,   -92,   -92,
     -92,   -92,   137,   -92,    13,   -13,    79,    11,    11,    75,
      75,    75,    75,    39,    39,   -92,   -92,   -92,   -92,   -92,
     139,   224,   224,   164,   -92,     6,    94,   -92,   -92,   282,
     282,     8,   246,   264,     8,    78,    95,   -92,   -92,   147,
       8,   171,     8,   194,   -92,   -92,   -92,     8,   -92,     8,
     -92,     8,   -92,   -92,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    11,    12,    13,    14,     0,     2,     4,     5,
       0,     6,     1,     3,     0,     0,     7,     0,     0,     9,
       0,    76,     0,     0,    37,    38,    41,    34,    39,    40,
       0,    46,    47,    48,     0,    72,    25,    29,    35,     0,
      24,    55,    57,    59,    61,    64,    69,    18,    15,     0,
       0,     0,    20,     0,     0,     0,     0,     0,    89,    77,
      81,     0,    42,     0,    83,     0,    79,    82,    84,    85,
      86,    87,    88,    26,    27,     0,     8,    53,    54,    50,
      51,    52,    49,     0,    32,    33,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    16,     0,    17,     0,     0,     0,     0,
      98,     0,     0,     0,    90,     0,    78,    80,    36,    23,
      30,    44,     0,    72,    58,     0,    60,    62,    63,    68,
      67,    65,    66,    70,    71,    73,    74,    75,    19,    21,
       0,     0,     0,     0,    99,     0,     0,    43,    31,     0,
       0,     0,     0,     0,     0,     0,     0,    45,    56,    91,
       0,     0,     0,     0,    93,   101,   100,     0,    96,     0,
      94,     0,    92,    97,    95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   133,   -19,   -92,     4,   -92,   -92,   -92,    55,
     -17,   -20,   -92,   -92,   -92,   -25,   -92,   -92,   -92,    16,
     -92,    65,    81,   103,     1,   151,   -92,   163,   -92,   125,
     165,   -91,   -92,   -92,   -92,   -92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    61,    15,    50,    51,    52,
      62,    35,    36,    37,    38,    63,   122,    39,    83,    40,
      41,    42,    43,    44,    45,    46,    11,    64,    65,    66,
      67,    68,    69,    70,    71,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    60,    73,    74,    10,    75,    88,    14,    84,    85,
      10,    53,    19,    54,    55,    56,    57,   142,    76,    87,
      93,    94,    49,    22,    23,   115,    90,    20,   114,    86,
     150,   111,   115,   102,    89,    24,    25,    26,    27,    28,
      29,   144,    58,   155,    30,   115,    60,    31,    32,    33,
     152,   153,    16,    17,    18,    95,    96,    20,     1,     2,
       3,     4,     5,   107,   125,   108,   119,   109,   123,   121,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   135,
     136,   137,   140,   112,   143,    99,   100,   101,   113,   141,
      91,    92,    22,    23,   129,   130,   131,   132,   147,     1,
       2,     3,     4,     5,    24,    25,    26,    27,    28,    29,
      49,    58,   165,    30,    97,    98,    31,    32,    33,   103,
     104,    53,   138,    54,    55,    56,    57,   161,   163,   166,
     123,   156,   157,    22,    23,   105,   106,   118,   115,    13,
       1,     2,     3,     4,     5,    24,    25,    26,    27,    28,
      29,   167,    58,   124,    30,   145,   146,    31,    32,    33,
      53,   139,    54,    55,    56,    57,   158,    20,    59,    16,
      17,   126,    22,    23,   148,   149,   151,   115,    21,     1,
       2,     3,     4,     5,    24,    25,    26,    27,    28,    29,
     117,    58,     0,    30,   127,   128,    31,    32,    33,    22,
      23,   154,   115,     0,    12,     0,    20,   116,   169,   115,
       0,    24,    25,    26,    27,    28,    29,     0,   110,     0,
      30,    22,    23,    31,    32,    33,     1,     2,     3,     4,
       5,   171,   115,    24,    25,    26,    27,    28,    29,    22,
      23,     0,    30,   120,     0,    31,    32,    33,   133,   134,
       0,    24,    25,    26,    27,    28,    29,     0,    58,     0,
      30,    22,    23,    31,    32,    33,    77,    78,    79,    80,
      81,     0,     0,    24,    25,    26,    27,    28,    29,    22,
      23,     0,    30,   160,    82,    31,    32,    33,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    22,    23,     0,
      30,   162,     0,    31,    32,    33,     0,     0,     0,    24,
      25,    26,    27,    28,    29,     0,   159,     0,    30,   164,
       0,    31,    32,    33,     0,   168,     0,   170,     0,     0,
       0,     0,   172,     0,   173,     0,   174,     1,     2,     3,
       4,     5,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,    48
};

static const yytype_int16 yycheck[] =
{
      17,    20,    22,    23,     0,    30,    14,    30,    15,    16,
       6,     3,    34,     5,     6,     7,     8,   108,    34,    39,
       9,    10,    18,    15,    16,    38,    13,    49,    34,    36,
      43,    56,    38,    30,    42,    27,    28,    29,    30,    31,
      32,    34,    34,    37,    36,    38,    65,    39,    40,    41,
     141,   142,    34,    35,    36,    44,    45,    49,    22,    23,
      24,    25,    26,    36,    89,    36,    83,    36,    88,    86,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   107,    36,   109,    46,    47,    48,    30,   108,
      11,    12,    15,    16,    93,    94,    95,    96,   115,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
     106,    34,    34,    36,    39,    40,    39,    40,    41,    37,
      38,     3,    30,     5,     6,     7,     8,   152,   153,    34,
     150,    37,   149,    15,    16,    37,    38,    37,    38,     6,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     4,    34,    88,    36,    29,    30,    39,    40,    41,
       3,   106,     5,     6,     7,     8,   150,    49,    50,    34,
      35,    90,    15,    16,    37,    38,    37,    38,    15,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      65,    34,    -1,    36,    91,    92,    39,    40,    41,    15,
      16,    37,    38,    -1,     0,    -1,    49,    50,    37,    38,
      -1,    27,    28,    29,    30,    31,    32,    -1,    34,    -1,
      36,    15,    16,    39,    40,    41,    22,    23,    24,    25,
      26,    37,    38,    27,    28,    29,    30,    31,    32,    15,
      16,    -1,    36,    37,    -1,    39,    40,    41,    97,    98,
      -1,    27,    28,    29,    30,    31,    32,    -1,    34,    -1,
      36,    15,    16,    39,    40,    41,    17,    18,    19,    20,
      21,    -1,    -1,    27,    28,    29,    30,    31,    32,    15,
      16,    -1,    36,    37,    35,    39,    40,    41,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    15,    16,    -1,
      36,    37,    -1,    39,    40,    41,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,   151,    -1,    36,   154,
      -1,    39,    40,    41,    -1,   160,    -1,   162,    -1,    -1,
      -1,    -1,   167,    -1,   169,    -1,   171,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    23,    24,    25,    26,    52,    53,    54,    55,
      56,    77,     0,    53,    30,    57,    34,    35,    36,    34,
      49,    78,    15,    16,    27,    28,    29,    30,    31,    32,
      36,    39,    40,    41,    61,    62,    63,    64,    65,    68,
      70,    71,    72,    73,    74,    75,    76,    30,    37,    56,
      58,    59,    60,     3,     5,     6,     7,     8,    34,    50,
      54,    56,    61,    66,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    62,    62,    66,    34,    17,    18,    19,
      20,    21,    35,    69,    15,    16,    36,    62,    14,    42,
      13,    11,    12,     9,    10,    44,    45,    39,    40,    46,
      47,    48,    30,    37,    38,    37,    38,    36,    36,    36,
      34,    66,    36,    30,    34,    38,    50,    80,    37,    61,
      37,    61,    67,    62,    72,    66,    73,    74,    74,    75,
      75,    75,    75,    76,    76,    62,    62,    62,    30,    60,
      66,    54,    82,    66,    34,    29,    30,    61,    37,    38,
      43,    37,    82,    82,    37,    37,    37,    61,    70,    81,
      37,    66,    37,    66,    81,    34,    34,     4,    81,    37,
      81,    37,    81,    81,    81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    54,    54,    55,
      56,    56,    56,    56,    56,    57,    57,    57,    58,    58,
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
       0,     2,     1,     2,     1,     1,     1,     3,     5,     3,
       1,     1,     1,     1,     1,     3,     4,     4,     1,     3,
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
#line 67 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 69 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "compiler_hw2.y" /* yacc.c:1646  */
    { create_symbol((yyvsp[0].string)); }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 75 "compiler_hw2.y" /* yacc.c:1646  */
    { create_symbol((yyvsp[0].string)); }
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "compiler_hw2.y" /* yacc.c:1646  */
    { create_symbol((yyvsp[0].string)); }
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 81 "compiler_hw2.y" /* yacc.c:1646  */
    { sprintf((yyval.string), "%s %s variable %d", (yyvsp[-2].string), (yyvsp[-1].string), currentScope); }
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 83 "compiler_hw2.y" /* yacc.c:1646  */
    { sprintf((yyval.string), "%s %s variable %d", (yyvsp[-4].string), (yyvsp[-3].string), currentScope); }
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 87 "compiler_hw2.y" /* yacc.c:1646  */
    { sprintf((yyval.string), "%s %s", (yyvsp[-2].string), (yyvsp[-1].string)); }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 91 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 93 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 95 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 97 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 99 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 103 "compiler_hw2.y" /* yacc.c:1646  */
    { sprintf((yyval.string), "%s function", (yyvsp[-2].string)); }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 105 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 107 "compiler_hw2.y" /* yacc.c:1646  */
    { sprintf((yyval.string), "%s function parameter %s", (yyvsp[-3].string), (yyvsp[-1].string)); }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 111 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 113 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 117 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 119 "compiler_hw2.y" /* yacc.c:1646  */
    { sprintf((yyval.string), "%s %s", (yyvsp[-2].string), (yyvsp[0].string)); }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 123 "compiler_hw2.y" /* yacc.c:1646  */
    { sprintf((yyval.string), "%s %s", (yyvsp[-1].string), (yyvsp[0].string)); }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 127 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 129 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 133 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 135 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 137 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 139 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 143 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 145 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 147 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 149 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 151 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 155 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 157 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 159 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 163 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 165 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 167 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 169 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 171 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 175 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 177 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 181 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 183 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 187 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 189 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 191 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 195 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 197 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 199 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 201 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 203 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 205 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 209 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 211 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 215 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 217 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 221 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 223 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 227 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 229 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 231 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 235 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 237 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 239 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 241 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 243 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 247 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 249 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 251 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 255 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 257 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 259 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 261 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 265 "compiler_hw2.y" /* yacc.c:1646  */
    { sprintf((yyval.string), "%s %s", (yyvsp[-2].string), (yyvsp[-1].string)); }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 269 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 271 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 275 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 277 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 281 "compiler_hw2.y" /* yacc.c:1646  */
    { create_symbol((yyvsp[0].string)); }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 283 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 287 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 289 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 291 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 293 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 295 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 297 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 301 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 303 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 307 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 309 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 313 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 315 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 317 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 319 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 321 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 325 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 327 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 331 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 333 "compiler_hw2.y" /* yacc.c:1646  */
    {  }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2071 "y.tab.c" /* yacc.c:1646  */
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
#line 336 "compiler_hw2.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;

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

void create_symbol(char *signature){
	char name[64];
	char entryType[20];
	char dataType[10];
	int scope = 0;
	char parameter[128] = "";

    if(strstr(signature, "variable") != NULL){
        sscanf(signature, "%s %s %s %d", dataType, name, entryType, &scope);
    	symbol *tmp = malloc(sizeof(symbol));
        tmp->name = strdup(name);
        tmp->entryType = strdup(entryType);
        tmp->dataType = strdup(dataType);
        tmp->scope = scope;
        tmp->parameter = strdup("");
        insert_symbol(tmp);
    }
    else if(strstr(signature, "function") != NULL){
        sscanf(signature, "%s %s %s", dataType, name, entryType);
        if(lookup_symbol(name, 0)) return;
    	symbol *tmp = malloc(sizeof(symbol));
        tmp->name = strdup(name);
        tmp->entryType = strdup(entryType);
        tmp->dataType = strdup(dataType);
        tmp->scope = 0;
        if(strstr(signature, "parameter") != NULL){
            char *token = strtok(strstr(signature, "parameter"), " ");
            symbol *paraTmp = malloc(sizeof(symbol));
            paraTmp->dataType = strdup(strtok(NULL, " "));
            strcat(parameter, paraTmp->dataType);
            paraTmp->name = strdup(strtok(NULL, " "));
            paraTmp->entryType = strdup("parameter");
            paraTmp->parameter = strdup("");
            paraTmp->scope = 1;
            insert_symbol(paraTmp);
            token = strtok(NULL, " ");
            while(token != NULL){
                symbol *paraTmp = malloc(sizeof(symbol));
                paraTmp->dataType = strdup(token);
                strcat(parameter, ", ");
                strcat(parameter, paraTmp->dataType);
                paraTmp->name = strdup(strtok(NULL, " "));
                paraTmp->entryType = strdup("parameter");
                paraTmp->scope = 1;
                paraTmp->parameter = strdup("");
                insert_symbol(paraTmp);
                token = strtok(NULL, " ");
            }
            tmp->parameter = strdup(parameter);
        }
        else{
            tmp->parameter = strdup("");
        }
        insert_symbol(tmp);
    }
}

void insert_symbol(symbol *s){
    table[s->scope][symbolCount[s->scope]++] = s;
}

int lookup_symbol(char *name, int scope){
    for(int i = 0; i < symbolCount[scope]; ++i){
        if(!strcmp(table[scope][i]->name, name))
            return 1;
    }
    return 0;
}

void dump_symbol(int scope) {
    if(symbolCount[scope] > 0){
        printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n", "Index", "Name", "Kind", "Type", "Scope", "Attribute");
        for(int i = 0; i < symbolCount[scope]; ++i){
            printf("%-10d%-10s%-12s%-10s%-10d%s\n", i, table[scope][i]->name, table[scope][i]->entryType, table[scope][i]->dataType, table[scope][i]->scope, table[scope][i]->parameter);
        }
        printf("\n");
        for(int i = 0; i < symbolCount[scope]; ++i){
            free(table[scope][i]);
            table[scope][i] = NULL;
        }
        symbolCount[scope] = 0;
    }
}
