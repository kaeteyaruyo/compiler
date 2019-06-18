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
#line 1 "compiler_hw3.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int scope;
    int index;
	char *name;
	char *entry_type;
	char *data_type;
	char *parameter;
} symbol;

symbol *table[50][50];
int symbolCount[50] = { 0 };
int currentScope = 0;
int errorFlag = 0;
char errorMsg[256] = "";
FILE *file;

extern int yylineno;
extern int yylex();
extern char* yytext;
extern char buf[256];
void yyerror(char *s);

void create_symbol_variable(int scope, char *name, char *type);
void create_symbol_function(char *name, char *return_type, char *parameter_type);
symbol *lookup_symbol(char *name, int scope);
void dump_symbol(int scope);

void gencode_global_variable(char *name, char *type, char *initial_value);
void gencode_function(char *name, char *return_type, char *parameter_type);
void gencode_load_store(const char *instruction, const char *type, int index);
void gencode_arithmetic(const char *instruction, const char *type);
const char *get_type_descriptors(char *type);
const char *get_type_initial_value(char *type);


#line 107 "y.tab.c" /* yacc.c:339  */

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
    LOWER_THAN_ELSE = 277,
    VOID = 278,
    INT = 279,
    FLOAT = 280,
    STRING = 281,
    BOOL = 282,
    ID = 283,
    I_CONST = 284,
    F_CONST = 285,
    STRING_LITERAL = 286,
    TRUE = 287,
    FALSE = 288
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
#define LOWER_THAN_ELSE 277
#define VOID 278
#define INT 279
#define FLOAT 280
#define STRING 281
#define BOOL 282
#define ID 283
#define I_CONST 284
#define F_CONST 285
#define STRING_LITERAL 286
#define TRUE 287
#define FALSE 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 42 "compiler_hw3.y" /* yacc.c:355  */

    struct{
        char *type;
        char *value;
    } token;
    char *string;

#line 221 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 238 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

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
       2,     2,     2,     2,     2,     2,     2,    45,     2,     2,
      36,    37,    43,    41,    38,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      46,    34,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
       0,    68,    68,    70,    74,    79,    84,    88,    94,   104,
     116,   123,   132,   134,   136,   138,   140,   144,   149,   156,
     158,   162,   164,   168,   174,   185,   189,   193,   209,   224,
     240,   256,   272,   290,   292,   312,   334,   336,   356,   382,
     401,   403,   405,   409,   430,   434,   436,   438,   451,   470,
     476,   480,   486,   488,   490,   492,   494,   498,   500,   502,
     504,   506,   508,   512,   514,   518,   520,   524,   528,   530,
     532,   534,   536,   538,   542,   553,   571
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
  "MOD_ASSIGN", "LOWER_THAN_ELSE", "VOID", "INT", "FLOAT", "STRING",
  "BOOL", "ID", "I_CONST", "F_CONST", "STRING_LITERAL", "TRUE", "FALSE",
  "'='", "';'", "'('", "')'", "','", "'{'", "'}'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'<'", "'>'", "$accept", "translation_unit",
  "external_declaration", "function_declaration", "function_definition",
  "type_specifier", "parameter_list", "compound_statement",
  "block_item_list", "block_item", "expression", "assignment_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "argument_expression_list", "constant",
  "statement", "expression_statement", "selection_statement",
  "iteration_statement", "relational_expression", "return_statement",
  "print_statement", YY_NULLPTR
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
     285,   286,   287,   288,    61,    59,    40,    41,    44,   123,
     125,    43,    45,    42,    47,    37,    60,    62
};
# endif

#define YYPACT_NINF -87

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define YYTABLE_NINF -12

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     103,   -87,   -87,   -87,   -87,   -87,    24,   -87,   -34,   -30,
      -3,   -87,   -87,   -87,    30,   -87,    25,    -9,     3,   130,
       6,    98,   -87,   -87,     2,   -87,    60,   -87,    27,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   147,   -87,    -8,   139,
     139,    -5,   -87,   -87,   -87,   -87,   -87,   -87,   105,    29,
     -87,   139,   105,   105,   105,   105,   105,   105,    56,   -87,
     -87,   -87,    66,    74,    92,   -15,    -6,    85,    87,   -87,
     -87,   120,   105,   105,    61,    37,   -87,   -87,   -87,    94,
      55,    55,    55,    55,    55,    55,   105,   -87,   -87,   -87,
      84,   103,   139,   139,   139,   139,   139,   139,    86,    86,
     -87,   -87,    34,   -87,   -87,   -87,   105,   105,   105,   105,
     105,   107,    -7,   112,   -87,   -87,   -87,   -87,   -87,   -87,
     140,   -87,   -87,   139,    37,    37,   -87,   -87,   -87,   -87,
     -87,   -87,    86,   -87,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,    14,    15,    16,     0,     2,     0,     0,
       0,     1,     3,     6,     0,     7,     0,     0,     0,     0,
       0,     0,    63,    19,     0,    57,     0,    21,     0,    26,
      25,    58,    59,    60,    61,    62,     0,     5,     0,     0,
       0,    43,    52,    53,    56,    54,    55,    74,     0,     0,
      44,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      22,    64,     0,     8,     0,     0,     0,     0,     0,    45,
      46,     0,     0,     0,     0,    33,    36,    40,    75,     0,
      28,    29,    30,    31,    32,    27,     0,    23,     4,    17,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,    50,     0,    41,    42,    49,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    72,    68,    69,    70,    71,
      65,    67,    48,     0,    34,    35,    37,    38,    39,    76,
      24,    18,     0,    51,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   137,   -87,   -87,   -12,   -87,   136,   -87,   128,
     -87,   -87,    53,     5,   -65,   -19,   -87,   119,   -86,   -87,
     -87,   -87,   124,   -87,   -87
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    10,    65,    25,    26,    27,
      28,    29,    74,    75,    76,    77,   102,    50,    30,    31,
      32,    33,    67,    34,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    13,    24,    92,    93,    94,    95,   103,   104,    14,
      69,    70,   120,   121,    24,     1,     2,     3,     4,     5,
      66,    66,    90,    91,    11,    16,    64,    39,   130,    63,
      58,    71,    79,    17,   106,   107,    18,    19,    20,    40,
      96,    97,    51,   126,   127,   128,   134,     1,     2,     3,
       4,     5,   101,     1,     2,     3,     4,     5,    21,    36,
      37,    38,    61,    17,    78,    22,    18,    19,    20,    14,
      23,   122,   123,   114,   115,   116,   117,   118,   119,   113,
     108,   109,   110,     1,     2,     3,     4,     5,    21,    17,
      86,    87,    18,    19,    20,    22,   106,   107,   105,    14,
      59,    88,   106,   107,   133,    80,    81,    82,    83,    84,
      85,   124,   125,   -10,    21,    52,    53,    54,    55,    56,
      89,    22,    98,   -11,    99,    14,     1,     2,     3,     4,
       5,   111,    57,    41,    42,    43,    44,    45,    46,   112,
     131,    48,   129,    12,   132,    15,    72,    73,    41,    42,
      43,    44,    45,    46,    60,    62,    48,   100,    41,    42,
      43,    44,    45,    46,    68,    47,    48,    41,    42,    43,
      44,    45,    46,     0,     0,    48,    42,    43,    44,    45,
      46
};

static const yytype_int16 yycheck[] =
{
      19,    35,    14,     9,    10,    11,    12,    72,    73,    39,
      15,    16,    98,    99,    26,    23,    24,    25,    26,    27,
      39,    40,    37,    38,     0,    28,    38,    36,    35,    37,
      28,    36,    51,     3,    41,    42,     6,     7,     8,    36,
      46,    47,    36,   108,   109,   110,   132,    23,    24,    25,
      26,    27,    71,    23,    24,    25,    26,    27,    28,    34,
      35,    36,    35,     3,    35,    35,     6,     7,     8,    39,
      40,    37,    38,    92,    93,    94,    95,    96,    97,    91,
      43,    44,    45,    23,    24,    25,    26,    27,    28,     3,
      34,    35,     6,     7,     8,    35,    41,    42,    37,    39,
      40,    35,    41,    42,   123,    52,    53,    54,    55,    56,
      57,   106,   107,    39,    28,    17,    18,    19,    20,    21,
      28,    35,    37,    39,    37,    39,    23,    24,    25,    26,
      27,    37,    34,    28,    29,    30,    31,    32,    33,    86,
      28,    36,    35,     6,     4,     9,    41,    42,    28,    29,
      30,    31,    32,    33,    26,    36,    36,    37,    28,    29,
      30,    31,    32,    33,    40,    35,    36,    28,    29,    30,
      31,    32,    33,    -1,    -1,    36,    29,    30,    31,    32,
      33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    24,    25,    26,    27,    49,    50,    51,    52,
      53,     0,    50,    35,    39,    55,    28,     3,     6,     7,
       8,    28,    35,    40,    53,    55,    56,    57,    58,    59,
      66,    67,    68,    69,    71,    72,    34,    35,    36,    36,
      36,    28,    29,    30,    31,    32,    33,    35,    36,    63,
      65,    36,    17,    18,    19,    20,    21,    34,    28,    40,
      57,    35,    65,    37,    53,    54,    63,    70,    70,    15,
      16,    36,    41,    42,    60,    61,    62,    63,    35,    63,
      60,    60,    60,    60,    60,    60,    34,    35,    35,    28,
      37,    38,     9,    10,    11,    12,    46,    47,    37,    37,
      37,    63,    64,    62,    62,    37,    41,    42,    43,    44,
      45,    37,    60,    53,    63,    63,    63,    63,    63,    63,
      66,    66,    37,    38,    61,    61,    62,    62,    62,    35,
      35,    28,     4,    63,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    50,    50,    51,    51,
      52,    52,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    57,    58,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    61,    61,    61,    61,
      62,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      64,    64,    65,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    67,    67,    68,    68,    69,    70,    70,
      70,    70,    70,    70,    71,    71,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     5,     3,     2,     2,     4,     5,
       4,     5,     1,     1,     1,     1,     1,     2,     4,     2,
       3,     1,     2,     3,     5,     1,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     1,     1,     2,     2,     3,     4,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     7,     5,     3,     3,
       3,     3,     3,     3,     2,     3,     5
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
#line 68 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 70 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 74 "compiler_hw3.y" /* yacc.c:1646  */
    { // global variable declaration with initial value
        create_symbol_variable(0, (yyvsp[-3].string), (yyvsp[-4].string));
        gencode_global_variable((yyvsp[-3].string), (yyvsp[-4].string), (yyvsp[-1].token).value);
    }
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "compiler_hw3.y" /* yacc.c:1646  */
    { // global variable declaration
        create_symbol_variable(0, (yyvsp[-1].string), (yyvsp[-2].string));
        gencode_global_variable((yyvsp[-1].string), (yyvsp[-2].string), "");
    }
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 84 "compiler_hw3.y" /* yacc.c:1646  */
    { // function declaration

    }
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 88 "compiler_hw3.y" /* yacc.c:1646  */
    { // (end of) function definition
        fprintf(file, ".end method\n");
    }
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 94 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[-2].string), 0)){
            errorFlag = 1;
            sprintf(errorMsg, "Redeclared function %s", (yyvsp[-2].string));
        }
        else{
            create_symbol_function((yyvsp[-2].string), (yyvsp[-3].string), "");
        }
    }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 104 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[-3].string), 0)){
            errorFlag = 1;
            sprintf(errorMsg, "Redeclared function %s", (yyvsp[-3].string));
        }
        else{
            create_symbol_function((yyvsp[-3].string), (yyvsp[-4].string), (yyvsp[-1].string));
        }
    }
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 116 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(!lookup_symbol((yyvsp[-2].string), 0)){
            create_symbol_function((yyvsp[-2].string), (yyvsp[-3].string), "");
        }
        gencode_function((yyvsp[-2].string), (yyvsp[-3].string), "");
    }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 123 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(!lookup_symbol((yyvsp[-3].string), 0)){
            create_symbol_function((yyvsp[-3].string), (yyvsp[-4].string), (yyvsp[-1].string));
        }
        gencode_function((yyvsp[-3].string), (yyvsp[-4].string), (yyvsp[-1].string));
    }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 132 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 134 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 136 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 138 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 140 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 144 "compiler_hw3.y" /* yacc.c:1646  */
    {
        create_symbol_variable(1, (yyvsp[0].string), (yyvsp[-1].string));
        sprintf((yyval.string), "%s", get_type_descriptors((yyvsp[-1].string)));
    }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 149 "compiler_hw3.y" /* yacc.c:1646  */
    {
        create_symbol_variable(1, (yyvsp[0].string), (yyvsp[-1].string));
        sprintf((yyval.string), "%s%s", (yyvsp[-3].string), get_type_descriptors((yyvsp[-1].string)));
    }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 156 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 158 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 162 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 164 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 168 "compiler_hw3.y" /* yacc.c:1646  */
    {
        create_symbol_variable(currentScope, (yyvsp[-1].string), (yyvsp[-2].string));
        fprintf(file, "\tldc %s\n", get_type_initial_value((yyvsp[-2].string)));
        gencode_load_store("store", (yyvsp[-2].string), lookup_symbol((yyvsp[-1].string), currentScope)->index);
    }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 174 "compiler_hw3.y" /* yacc.c:1646  */
    {
        create_symbol_variable(currentScope, (yyvsp[-3].string), (yyvsp[-4].string));
        if(!strcmp((yyvsp[-4].string), "int") && !strcmp((yyvsp[-1].token).type, "float")){
            fprintf(file, "\tf2i\n");
        }
        else if(!strcmp((yyvsp[-4].string), "float") && !strcmp((yyvsp[-1].token).type, "int")){
            fprintf(file, "\ti2f\n");
        }
        gencode_load_store("store", (yyvsp[-4].string), lookup_symbol((yyvsp[-3].string), currentScope)->index);
    }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 185 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 189 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 193 "compiler_hw3.y" /* yacc.c:1646  */
    {
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol((yyvsp[-2].string), i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", (yyvsp[-2].string));
        }
        else{
            gencode_load_store("store", variable->data_type, variable->index);
        }
    }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 209 "compiler_hw3.y" /* yacc.c:1646  */
    {
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol((yyvsp[-2].string), i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", (yyvsp[-2].string));
        }
        else{
        }
    }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 224 "compiler_hw3.y" /* yacc.c:1646  */
    {
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol((yyvsp[-2].string), i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", (yyvsp[-2].string));
        }
        else{
            gencode_load_store("store", variable->data_type, variable->index);
        }
    }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 240 "compiler_hw3.y" /* yacc.c:1646  */
    {
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol((yyvsp[-2].string), i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", (yyvsp[-2].string));
        }
        else{
            gencode_load_store("store", variable->data_type, variable->index);
        }
    }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 256 "compiler_hw3.y" /* yacc.c:1646  */
    {
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol((yyvsp[-2].string), i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", (yyvsp[-2].string));
        }
        else{
            gencode_load_store("store", variable->data_type, variable->index);
        }
    }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 272 "compiler_hw3.y" /* yacc.c:1646  */
    {
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol((yyvsp[-2].string), i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", (yyvsp[-2].string));
        }
        else{
            gencode_load_store("store", variable->data_type, variable->index);
        }
    }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 290 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 292 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file, "%s(%s) + %s(%s)\n", (yyvsp[-2].token).value, (yyvsp[-2].token).type, (yyvsp[0].token).value, (yyvsp[0].token).type);
        if(!strcmp((yyvsp[-2].token).type, "int") && !strcmp((yyvsp[0].token).type, "int")){
            sprintf((yyval.token).type, "int");
            sprintf((yyval.token).value, "%d", atoi((yyvsp[-2].token).value) + atoi((yyvsp[0].token).value));
            gencode_arithmetic("add", "int");
        }
        else{
            if(!strcmp((yyvsp[-2].token).type, "float") && !strcmp((yyvsp[0].token).type, "int")){
                fprintf(file, "\ti2f\n");
            }
            else if(!strcmp((yyvsp[-2].token).type, "int") && !strcmp((yyvsp[0].token).type, "float")){
                fprintf(file, "\tswap\n");
                fprintf(file, "\ti2f\n");
            }
            sprintf((yyval.token).type, "float");
            gencode_arithmetic("add", "float");
        }
    }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 312 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file, "%s(%s) - %s(%s)\n", (yyvsp[-2].token).value, (yyvsp[-2].token).type, (yyvsp[0].token).value, (yyvsp[0].token).type);
        if(!strcmp((yyvsp[-2].token).type, "int") && !strcmp((yyvsp[0].token).type, "int")){
            sprintf((yyval.token).type, "int");
            sprintf((yyval.token).value, "%d", atoi((yyvsp[-2].token).value) - atoi((yyvsp[0].token).value));
            gencode_arithmetic("sub", "int");
        }
        else{
            if(!strcmp((yyvsp[-2].token).type, "float") && !strcmp((yyvsp[0].token).type, "int")){
                fprintf(file, "\ti2f\n");
            }
            else if(!strcmp((yyvsp[-2].token).type, "int") && !strcmp((yyvsp[0].token).type, "float")){
                fprintf(file, "\tswap\n");
                fprintf(file, "\ti2f\n");
            }
            sprintf((yyval.token).type, "float");
            gencode_arithmetic("sub", "float");
        }
    }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 334 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 336 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file, "%s(%s) * %s(%s)\n", (yyvsp[-2].token).value, (yyvsp[-2].token).type, (yyvsp[0].token).value, (yyvsp[0].token).type);
        if(!strcmp((yyvsp[-2].token).type, "int") && !strcmp((yyvsp[0].token).type, "int")){
            sprintf((yyval.token).type, "int");
            sprintf((yyval.token).value, "%d", atoi((yyvsp[-2].token).value) * atoi((yyvsp[0].token).value));
            gencode_arithmetic("mul", "int");
        }
        else{
            if(!strcmp((yyvsp[-2].token).type, "float") && !strcmp((yyvsp[0].token).type, "int")){
                fprintf(file, "\ti2f\n");
            }
            else if(!strcmp((yyvsp[-2].token).type, "int") && !strcmp((yyvsp[0].token).type, "float")){
                fprintf(file, "\tswap\n");
                fprintf(file, "\ti2f\n");
            }
            sprintf((yyval.token).type, "float");
            gencode_arithmetic("mul", "float");
        }
    }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 356 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file, "%s(%s) / %s(%s)\n", (yyvsp[-2].token).value, (yyvsp[-2].token).type, (yyvsp[0].token).value, (yyvsp[0].token).type);
        if(!strcmp((yyvsp[0].token).value, "0") || !strcmp((yyvsp[0].token).value, "0.0")){
            errorFlag = 1;
            sprintf(errorMsg, "Divided by zero");
        }
        else{
            if(!strcmp((yyvsp[-2].token).type, "int") && !strcmp((yyvsp[0].token).type, "int")){
                sprintf((yyval.token).type, "int");
                sprintf((yyval.token).value, "%d", atoi((yyvsp[-2].token).value) / atoi((yyvsp[0].token).value));
                gencode_arithmetic("div", "int");
            }
            else{
                if(!strcmp((yyvsp[-2].token).type, "float") && !strcmp((yyvsp[0].token).type, "int")){
                    fprintf(file, "\ti2f\n");
                }
                else if(!strcmp((yyvsp[-2].token).type, "int") && !strcmp((yyvsp[0].token).type, "float")){
                    fprintf(file, "\tswap\n");
                    fprintf(file, "\ti2f\n");
                }
                sprintf((yyval.token).type, "float");
                gencode_arithmetic("div", "float");
            }
        }
    }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 382 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(!strcmp((yyvsp[0].token).value, "0") || !strcmp((yyvsp[0].token).value, "0.0")){
            errorFlag = 1;
            sprintf(errorMsg, "Divided by zero");
        }
        else{
            if(!strcmp((yyvsp[-2].token).type, "int") && !strcmp((yyvsp[0].token).type, "int")){
                sprintf((yyval.token).type, "int");
                gencode_arithmetic("rem", "int");
            }
            else{
                errorFlag = 1;
                sprintf(errorMsg, "Modulo operator with floating point operands");
            }
        }
    }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 401 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 403 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 405 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 409 "compiler_hw3.y" /* yacc.c:1646  */
    { // variable at RHS
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol((yyvsp[0].string), i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", (yyvsp[0].string));
        }
        else{
            sprintf((yyval.token).type, "%s", variable->data_type);
            sprintf((yyval.token).value, "%s", variable->name);
            if(i == 0)
                fprintf(file, "\tgetstatic compiler_hw3/%s %s\n", variable->name, get_type_descriptors(variable->data_type));
            else
                gencode_load_store("load", variable->data_type, variable->index);
        }
    }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 430 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file, "\tldc %s\n", (yyvsp[0].token).value);
    }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 434 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 436 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 438 "compiler_hw3.y" /* yacc.c:1646  */
    { // function call
        symbol *function = lookup_symbol((yyvsp[-2].string), 0);
        if(!function){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared function %s", (yyvsp[-2].string));
        }
        else{
            sprintf((yyval.token).type, "%s", function->data_type);
            sprintf((yyval.token).value, "%s", function->name);
            fprintf(file, "\tinvokestatic compiler_hw3/%s()%s\n", function->name, get_type_descriptors(function->data_type));
        }
    }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 451 "compiler_hw3.y" /* yacc.c:1646  */
    { // function call with argument
        symbol *function = lookup_symbol((yyvsp[-3].string), 0);
        if(!function){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared function %s", (yyvsp[-3].string));
        }
        else{
            if(strcmp((yyvsp[-1].string), function->parameter)){
                errorFlag = 1;
                sprintf(errorMsg, "Function formal parameter is not the same");
            }
            else{
                sprintf((yyval.token).type, "%s", function->data_type);
                sprintf((yyval.token).value, "%s", function->name);
                fprintf(file, "\tinvokestatic compiler_hw3/%s(%s)%s\n", function->name, function->parameter, get_type_descriptors(function->data_type));
            }
        }
    }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 470 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file, "( %s(%s) )\n", (yyvsp[-1].token).value, (yyvsp[-1].token).type);
    }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 476 "compiler_hw3.y" /* yacc.c:1646  */
    {
        sprintf((yyval.string), "%s", get_type_descriptors((yyvsp[0].token).type));
    }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 480 "compiler_hw3.y" /* yacc.c:1646  */
    {
        sprintf((yyval.string), "%s%s", (yyvsp[-2].string), get_type_descriptors((yyvsp[0].token).type));
    }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 486 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 488 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 490 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 492 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 494 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 498 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 500 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 502 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 504 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 506 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 508 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 512 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 514 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 518 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 520 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 524 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 528 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 530 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 532 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 534 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 536 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 538 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 542 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char *return_type = table[0][symbolCount[0] - 1]->data_type;
        if(!strcmp(return_type, "void")){
            fprintf(file, "\treturn\n");
        }
        else{
            errorFlag = 1;
            sprintf(errorMsg, "Function return type is not the same");
        }
    }
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 553 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char *return_type = table[0][symbolCount[0] - 1]->data_type;
        if(!strcmp(return_type, (yyvsp[-1].token).type)){
            if(!strcmp(return_type, "int") || !strcmp(return_type, "bool")){
                fprintf(file, "\tireturn\n");
            }
            else if(!strcmp(return_type, "float")){
                fprintf(file, "\tfreturn\n");
            }
        }
        else{
            errorFlag = 1;
            sprintf(errorMsg, "Function return type is not the same");
        }
    }
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 571 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
        fprintf(file, "\tswap\n");
        fprintf(file, "\tinvokevirtual java/io/PrintStream/println(%s)V\n", get_type_descriptors((yyvsp[-2].token).type));
    }
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2184 "y.tab.c" /* yacc.c:1646  */
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
#line 578 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char **argv)
{
    yylineno = 0;

    file = fopen("compiler_hw3.j", "w");
    fprintf(file, ".class public compiler_hw3\n"
                  ".super java/lang/Object\n");

    yyparse();

    fclose(file);

    return 0;
}

void yyerror(char *s)
{
    if(!strcmp(s, "syntax error")){
        if(strlen(buf) != 0){
            printf("%d: %s\n", yylineno + 1, buf);
        }
        else{
            printf("%d:\n", yylineno + 1);
        }
        if(errorFlag > 0){
            printf("\n|-----------------------------------------------|\n");
            printf("| Error found in line %d: %s\n", yylineno + 1, buf);
            printf("| %s", errorMsg);
            printf("\n|-----------------------------------------------|\n\n");
            errorFlag = 0;
        }
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno + 1, buf);
        printf("| %s", s);
        printf("\n|-----------------------------------------------|\n\n");
    }
    else{
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno, buf);
        printf("| %s", s);
        printf("\n|-----------------------------------------------|\n\n");

    }
}

void create_symbol_variable(int scope, char *name, char *type){
    if(lookup_symbol(name, scope)){
        errorFlag = 1;
        sprintf(errorMsg, "Redeclared variable %s", name);
        return;
    }

    symbol *tmp = malloc(sizeof(symbol));
    tmp->name = strdup(name);
    tmp->entry_type = strdup("variable");
    tmp->data_type = strdup(type);
    tmp->scope = scope;
    tmp->parameter = strdup("");
    tmp->index = symbolCount[scope];
    for(int i = 1; i < scope; ++i)
        tmp->index += symbolCount[i];
    table[scope][symbolCount[scope]++] = tmp;
}

void create_symbol_function(char *name, char *return_type, char *parameter_type){
    symbol *tmp = malloc(sizeof(symbol));
    tmp->name = strdup(name);
    tmp->entry_type = strdup("function");
    tmp->data_type = strdup(return_type);
    tmp->scope = 0;
    tmp->parameter = strdup(parameter_type);
    tmp->index = symbolCount[0]++;
    table[0][tmp->index] = tmp;
}

symbol *lookup_symbol(char *name, int scope){
    for(int i = 0; i < symbolCount[scope]; ++i){
        if(!strcmp(table[scope][i]->name, name))
            return table[scope][i];
    }
    return NULL;
}

void dump_symbol(int scope) {
    if(symbolCount[scope] > 0){
        printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n", "Index", "Name", "Kind", "Type", "Scope", "Attribute");
        for(int i = 0; i < symbolCount[scope]; ++i){
            printf("%-10d%-10s%-12s%-10s%-10d%s\n", i, table[scope][i]->name, table[scope][i]->entry_type, table[scope][i]->data_type, table[scope][i]->scope, table[scope][i]->parameter);
        }
        printf("\n");
        for(int i = 0; i < symbolCount[scope]; ++i){
            free(table[scope][i]);
            table[scope][i] = NULL;
        }
        symbolCount[scope] = 0;
    }
}

void gencode_global_variable(char *name, char *type, char *initial_value) {
    if(strcmp(initial_value, "")){
        fprintf(file, ".field public static %s %s = %s\n", name, get_type_descriptors(type), initial_value);
    }
    else
        fprintf(file, ".field public static %s %s\n", name, get_type_descriptors(type));
}

void gencode_function(char *name, char *return_type, char *parameter_type){
    if(!strcmp(name, "main"))
        fprintf(file, ".method public static main([Ljava/lang/String;)V\n");
    else
        fprintf(file, ".method public static %s(%s)%s\n", name, parameter_type, get_type_descriptors(return_type));
    fprintf(file, ".limit stack 50\n");
    fprintf(file, ".limit locals 50\n");
}

void gencode_load_store(const char *instruction, const char *type, int index){
    if(!strcmp(instruction, "store")){
        if(!strcmp(type, "int") || !strcmp(type, "bool"))
            fprintf(file, "\tistore %d\n", index);
        else if(!strcmp(type, "float"))
            fprintf(file, "\tfstore %d\n", index);
        else if(!strcmp(type, "string"))
            fprintf(file, "\tastore %d\n", index);
    }
    else if(!strcmp(instruction, "load")){
        if(!strcmp(type, "int") || !strcmp(type, "bool"))
            fprintf(file, "\tiload %d\n", index);
        else if(!strcmp(type, "float"))
            fprintf(file, "\tfload %d\n", index);
        else if(!strcmp(type, "string"))
            fprintf(file, "\taload %d\n", index);
    }
}

void gencode_arithmetic(const char *instruction, const char *type){
    if(!strcmp(instruction, "add")){
        if(!strcmp(type, "int")){
            fprintf(file, "\tiadd\n");
        }
        else if(!strcmp(type, "float")){
            fprintf(file, "\tfadd\n");
        }
    }
    else if(!strcmp(instruction, "sub")){
        if(!strcmp(type, "int")){
            fprintf(file, "\tisub\n");
        }
        else if(!strcmp(type, "float")){
            fprintf(file, "\tfsub\n");
        }
    }
    else if(!strcmp(instruction, "mul")){
        if(!strcmp(type, "int")){
            fprintf(file, "\timul\n");
        }
        else if(!strcmp(type, "float")){
            fprintf(file, "\tfmul\n");
        }
    }
    else if(!strcmp(instruction, "div")){
        if(!strcmp(type, "int")){
            fprintf(file, "\tidiv\n");
        }
        else if(!strcmp(type, "float")){
            fprintf(file, "\tfdiv\n");
        }
    }
    else if(!strcmp(instruction, "rem")){
        if(!strcmp(type, "int")){
            fprintf(file, "\tirem\n");
        }
    }
    else if(!strcmp(instruction, "neg")){
        if(!strcmp(type, "int")){
            fprintf(file, "\tineg\n");
        }
        else if(!strcmp(type, "float")){
            fprintf(file, "\tfneg\n");
        }
    }
}

const char *get_type_descriptors(char *type){
    if(!strcmp(type, "int"))
        return "I";
    else if(!strcmp(type, "bool"))
        return "Z";
    else if(!strcmp(type, "float"))
        return "F";
    else if(!strcmp(type, "void"))
        return "V";
    else if(!strcmp(type, "string"))
        return "Ljava/lang/String;";
}

const char *get_type_initial_value(char *type){
    if(!strcmp(type, "int"))
        return "0";
    else if(!strcmp(type, "bool"))
        return "0";
    else if(!strcmp(type, "float"))
        return "0.0";
}
