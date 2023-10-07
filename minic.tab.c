/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "minic.y"
	
    #include <stdio.h>
    #include <stdlib.h>
	#include <string.h>
	#include "listaSimbolos.h"
    extern int yylex();
    void yyerror (const char *msg);
	void liberarReg(char *s);
	char *obtenerReg();
	char *nuevaEtiqueta();
	

    extern int yylineno;
	extern char* yytext;
	extern int errores;
	extern int yynerrs;

	int cont_semantico = 0;
	int contador_etiq = 1;
	int contador_cadena = 0;

	int registros[10]={0,0,0,0,0,0,0,0,0,0};

	Lista tS;
	Tipo tipo;

#line 98 "minic.tab.c"

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

#include "minic.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PRI = 3,                        /* PRI  */
  YYSYMBOL_SUM = 4,                        /* SUM  */
  YYSYMBOL_RES = 5,                        /* RES  */
  YYSYMBOL_MUL = 6,                        /* MUL  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_ASI = 8,                        /* ASI  */
  YYSYMBOL_PAI = 9,                        /* PAI  */
  YYSYMBOL_PAD = 10,                       /* PAD  */
  YYSYMBOL_LLI = 11,                       /* LLI  */
  YYSYMBOL_LLD = 12,                       /* LLD  */
  YYSYMBOL_COM = 13,                       /* COM  */
  YYSYMBOL_PYC = 14,                       /* PYC  */
  YYSYMBOL_VAR = 15,                       /* VAR  */
  YYSYMBOL_ELS = 16,                       /* ELS  */
  YYSYMBOL_REA = 17,                       /* REA  */
  YYSYMBOL_IFF = 18,                       /* IFF  */
  YYSYMBOL_VOI = 19,                       /* VOI  */
  YYSYMBOL_CON = 20,                       /* CON  */
  YYSYMBOL_WHI = 21,                       /* WHI  */
  YYSYMBOL_IDE = 22,                       /* IDE  */
  YYSYMBOL_ENT = 23,                       /* ENT  */
  YYSYMBOL_CAD = 24,                       /* CAD  */
  YYSYMBOL_RES2 = 25,                      /* RES2  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_program = 27,                   /* program  */
  YYSYMBOL_28_1 = 28,                      /* $@1  */
  YYSYMBOL_declarations = 29,              /* declarations  */
  YYSYMBOL_30_2 = 30,                      /* $@2  */
  YYSYMBOL_31_3 = 31,                      /* $@3  */
  YYSYMBOL_identifier_list = 32,           /* identifier_list  */
  YYSYMBOL_asig = 33,                      /* asig  */
  YYSYMBOL_statement_list = 34,            /* statement_list  */
  YYSYMBOL_statement = 35,                 /* statement  */
  YYSYMBOL_print_list = 36,                /* print_list  */
  YYSYMBOL_print_item = 37,                /* print_item  */
  YYSYMBOL_read_list = 38,                 /* read_list  */
  YYSYMBOL_expression = 39                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  35
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  75

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    54,    81,    81,    86,    86,    91,    96,
      99,   106,   121,   149,   154,   159,   188,   192,   229,   250,
     288,   292,   297,   300,   307,   329,   366,   405,   445,   457,
     465,   473,   481,   492,   497,   518
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PRI", "SUM", "RES",
  "MUL", "DIV", "ASI", "PAI", "PAD", "LLI", "LLD", "COM", "PYC", "VAR",
  "ELS", "REA", "IFF", "VOI", "CON", "WHI", "IDE", "ENT", "CAD", "RES2",
  "$accept", "program", "$@1", "declarations", "$@2", "$@3",
  "identifier_list", "asig", "statement_list", "statement", "print_list",
  "print_item", "read_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -9,    -3,    30,    22,   -53,    59,    40,   -53,   -53,   -11,
     -53,   -53,    15,    27,    27,    38,   -53,   -53,    48,    67,
      74,    69,   -53,    76,    28,   -53,    31,    41,    41,   -53,
     -53,   -53,    39,   -53,    82,    17,   -53,    43,    41,    41,
      41,    41,    27,   -53,   -53,   -53,    61,    38,   -53,    41,
      41,    41,    41,   -53,    70,   -53,    68,    75,     1,    82,
     -53,   -53,   -53,    -4,    -4,   -53,   -53,   -53,    37,    37,
     -53,    77,   -53,    37,   -53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     2,     8,    14,
       4,     6,     0,     0,     0,     0,    14,     3,     0,     0,
       0,     0,    13,    11,     0,     9,     0,     0,     0,    34,
      35,    25,     0,    22,    24,     0,    26,     0,     0,     0,
       0,     0,     0,     5,     7,    32,     0,     0,    20,     0,
       0,     0,     0,    16,     0,    21,     0,     0,     0,    12,
      10,    33,    23,    28,    29,    30,    31,    27,     0,     0,
      15,    18,    19,     0,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,   -53,   -53,   -53,    80,    49,    79,   -52,
     -53,    50,   -53,   -27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     8,     9,    13,    14,    24,    25,    12,    22,
      32,    33,    37,    34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      45,    46,    51,    52,    10,    49,    50,    51,    52,    11,
       1,    56,    57,    58,    59,    70,    71,    72,    15,     3,
      15,    74,    63,    64,    65,    66,    16,    17,    16,    53,
       4,     5,    18,    19,    18,    19,    20,    21,    20,    21,
      15,    42,    43,    27,    42,    44,    27,    28,    16,    23,
      28,     7,    47,    48,    18,    19,    54,    55,    20,    21,
      29,    30,    31,    29,    30,    49,    50,    51,    52,     6,
      36,    61,    49,    50,    51,    52,    38,    40,    68,    49,
      50,    51,    52,    39,    41,    69,    49,    50,    51,    52,
       0,    60,    67,    73,    26,    35,     0,    62
};

static const yytype_int8 yycheck[] =
{
      27,    28,     6,     7,    15,     4,     5,     6,     7,    20,
      19,    38,    39,    40,    41,    14,    68,    69,     3,    22,
       3,    73,    49,    50,    51,    52,    11,    12,    11,    12,
       0,     9,    17,    18,    17,    18,    21,    22,    21,    22,
       3,    13,    14,     5,    13,    14,     5,     9,    11,    22,
       9,    11,    13,    14,    17,    18,    13,    14,    21,    22,
      22,    23,    24,    22,    23,     4,     5,     6,     7,    10,
      22,    10,     4,     5,     6,     7,     9,     8,    10,     4,
       5,     6,     7,     9,     8,    10,     4,     5,     6,     7,
      -1,    42,    22,    16,    14,    16,    -1,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    27,    22,     0,     9,    10,    11,    28,    29,
      15,    20,    34,    30,    31,     3,    11,    12,    17,    18,
      21,    22,    35,    22,    32,    33,    32,     5,     9,    22,
      23,    24,    36,    37,    39,    34,    22,    38,     9,     9,
       8,     8,    13,    14,    14,    39,    39,    13,    14,     4,
       5,     6,     7,    12,    13,    14,    39,    39,    39,    39,
      33,    10,    37,    39,    39,    39,    39,    22,    10,    10,
      14,    35,    35,    16,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    26,    28,    27,    30,    29,    31,    29,    29,    32,
      32,    33,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    36,    36,    37,    37,    38,    38,    39,    39,
      39,    39,    39,    39,    39,    39
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     9,     0,     5,     0,     5,     0,     1,
       3,     1,     3,     2,     0,     4,     3,     7,     5,     5,
       3,     3,     1,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     2,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* $@1: %empty  */
#line 54 "minic.y"
                                 { tS = creaLS(); }
#line 1167 "minic.tab.c"
    break;

  case 3: /* program: VOI IDE PAI PAD LLI $@1 declarations statement_list LLD  */
#line 54 "minic.y"
                                                                                    {
			/*Volcar lista de simbolos a salida para generar .data*/
			if(cont_semantico == 0 && errores == 0 && yynerrs==0){
				printf("\n");
				printf(".data\n\n");
				imprimirLS(tS);
				printf("\n");
				printf(".text\n.globl main\n\n");
				concatenaLC((yyvsp[-2].codigo),(yyvsp[-1].codigo));
				Operacion oper;
				oper.op = strdup("li");
				oper.res = strdup("$v0");
				oper.arg1 = strdup("10");
				oper.arg2 = NULL;
				insertaLC((yyvsp[-2].codigo), finalLC((yyvsp[-2].codigo)), oper);
				Operacion oper2;
				oper2.op = strdup("syscall");
				oper2.res = NULL;
				oper2.arg1 = NULL;
				oper2.arg2 = NULL;
				insertaLC((yyvsp[-2].codigo), finalLC((yyvsp[-2].codigo)), oper2);
				imprimirCodigo((yyvsp[-2].codigo));
				liberaLC((yyvsp[-1].codigo));
			} 
			}
#line 1197 "minic.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 81 "minic.y"
                                {tipo = VARIABLE; }
#line 1203 "minic.tab.c"
    break;

  case 5: /* declarations: declarations VAR $@2 identifier_list PYC  */
#line 81 "minic.y"
                                                                        {
				(yyval.codigo)=(yyvsp[-4].codigo);
				concatenaLC((yyval.codigo),(yyvsp[-1].codigo));
				liberaLC((yyvsp[-1].codigo));
			 }
#line 1213 "minic.tab.c"
    break;

  case 6: /* $@3: %empty  */
#line 86 "minic.y"
                                            {tipo = CONSTANTE; }
#line 1219 "minic.tab.c"
    break;

  case 7: /* declarations: declarations CON $@3 identifier_list PYC  */
#line 86 "minic.y"
                                                                                     {
				(yyval.codigo)=(yyvsp[-4].codigo);
				concatenaLC((yyval.codigo),(yyvsp[-1].codigo));
				liberaLC((yyvsp[-1].codigo));
			 }
#line 1229 "minic.tab.c"
    break;

  case 8: /* declarations: %empty  */
#line 91 "minic.y"
                           {
				 (yyval.codigo)=creaLC();
			 }
#line 1237 "minic.tab.c"
    break;

  case 9: /* identifier_list: asig  */
#line 96 "minic.y"
                        {
				(yyval.codigo)=(yyvsp[0].codigo);
}
#line 1245 "minic.tab.c"
    break;

  case 10: /* identifier_list: identifier_list COM asig  */
#line 99 "minic.y"
                                                    {
				(yyval.codigo)=(yyvsp[-2].codigo);
				concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				liberaLC((yyvsp[0].codigo));
			 }
#line 1255 "minic.tab.c"
    break;

  case 11: /* asig: IDE  */
#line 106 "minic.y"
                   {
				PosicionLista p1;
				p1 = buscaLS(tS, (yyvsp[0].cadena));
				if(p1 == finalLS(tS)){
					Simbolo s;
					s.nombre = strdup((yyvsp[0].cadena));
					s.tipo = tipo;
					insertaLS(tS, p1, s);
					(yyval.codigo)=creaLC();
				} else {
					cont_semantico++;
					yyerror("error semantico, identificador ya declarado");
				}

				}
#line 1275 "minic.tab.c"
    break;

  case 12: /* asig: IDE ASI expression  */
#line 121 "minic.y"
                                              {
				PosicionLista p1;
				p1 = buscaLS(tS, (yyvsp[-2].cadena));
				if(p1 == finalLS(tS)){
					Simbolo s;
					s.nombre = strdup((yyvsp[-2].cadena));
					s.tipo = tipo;
					insertaLS(tS, p1, s);
					
				} else {
					cont_semantico++;
					yyerror("error semantico, identificador ya declarado");
				}
					(yyval.codigo)=(yyvsp[0].codigo);
					Operacion oper;
					oper.op = strdup("sw");
					oper.res = recuperaResLC((yyvsp[0].codigo));
					char str[18];
					sprintf(str, "_%s", (yyvsp[-2].cadena));
					oper.arg1 = strdup(str);
					free((yyvsp[-2].cadena));
					oper.arg2 = NULL;
					liberarReg(oper.res);
					insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);

				}
#line 1306 "minic.tab.c"
    break;

  case 13: /* statement_list: statement_list statement  */
#line 149 "minic.y"
                                         {
				(yyval.codigo)=(yyvsp[-1].codigo);
				concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				liberaLC((yyvsp[0].codigo));
			}
#line 1316 "minic.tab.c"
    break;

  case 14: /* statement_list: %empty  */
#line 154 "minic.y"
                                {
				 (yyval.codigo)  = creaLC();
			 }
#line 1324 "minic.tab.c"
    break;

  case 15: /* statement: IDE ASI expression PYC  */
#line 159 "minic.y"
                                      {
				PosicionLista p2;
				p2 = buscaLS(tS, (yyvsp[-3].cadena));
				if(p2 != finalLS(tS)){	
					Simbolo s = recuperaLS(tS, p2);
					if(s.tipo != CONSTANTE){		
						(yyval.codigo)=(yyvsp[-1].codigo);
						Operacion oper;
						oper.op=strdup("sw");
						oper.res = recuperaResLC((yyvsp[-1].codigo));
						char c[18];
						sprintf(c, "_%s", (yyvsp[-3].cadena));
						free((yyvsp[-3].cadena));
						oper.arg1=strdup(c);
						oper.arg2=NULL;
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
						liberarReg(oper.res);
					} else {
						cont_semantico++;
						yyerror("error semantico, asignacion a una constante");
						(yyval.codigo)=(yyvsp[-1].codigo);
					}
				} else {
					cont_semantico++;
					yyerror("error semantico, no se encuentra en la lista");
					(yyval.codigo)=(yyvsp[-1].codigo);
				}

				}
#line 1358 "minic.tab.c"
    break;

  case 16: /* statement: LLI statement_list LLD  */
#line 188 "minic.y"
                                                  {
				 (yyval.codigo)=(yyvsp[-1].codigo);

			 }
#line 1367 "minic.tab.c"
    break;

  case 17: /* statement: IFF PAI expression PAD statement ELS statement  */
#line 192 "minic.y"
                                                                          {
				(yyval.codigo)=creaLC();
				concatenaLC((yyval.codigo),(yyvsp[-4].codigo));
				Operacion oper;
				oper.op=strdup("beqz");
				oper.res = recuperaResLC((yyvsp[-4].codigo));
				oper.arg1 = nuevaEtiqueta();
				oper.arg2 = NULL;
				insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
				concatenaLC((yyval.codigo),(yyvsp[-2].codigo));
				Operacion oper2;
				oper2.op=strdup("b");
				oper2.res = nuevaEtiqueta();
				oper2.arg1 = NULL;
				oper2.arg2 = NULL;
				insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper2);
				Operacion oper3;
				char c[18];
				sprintf(c, "%s:", oper.arg1);
				oper3.op=strdup(c);
				oper3.res = NULL;
				oper3.arg1 = NULL;
				oper3.arg2 = NULL;
				insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper3);
				concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				Operacion oper4;
				char d[18];
				sprintf(d, "%s:", oper2.res);
				oper4.op=strdup(d);
				oper4.res = NULL;
				oper4.arg1 = NULL;
				oper4.arg2 = NULL;
				insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper4);
				liberarReg(oper.res);


			 }
#line 1409 "minic.tab.c"
    break;

  case 18: /* statement: IFF PAI expression PAD statement  */
#line 229 "minic.y"
                                                            {
				(yyval.codigo)=creaLC();
				concatenaLC((yyval.codigo),(yyvsp[-2].codigo));
				Operacion oper;
				oper.op=strdup("beqz");
				oper.res = recuperaResLC((yyvsp[-2].codigo));
				oper.arg1 = nuevaEtiqueta();
				oper.arg2 = NULL;
				insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
				concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				Operacion oper2;
				char c[18];
				sprintf(c, "%s:", oper.arg1);
				oper2.op=strdup(c);
				oper2.res = NULL;
				oper2.arg1 = NULL;
				oper2.arg2 = NULL;
				insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper2);
				liberarReg(oper.res);

			 }
#line 1435 "minic.tab.c"
    break;

  case 19: /* statement: WHI PAI expression PAD statement  */
#line 250 "minic.y"
                                                    {
				(yyval.codigo)=creaLC();
				Operacion oper;
				char d[19];
				char a[18];
				sprintf(a, "%s", nuevaEtiqueta());
				sprintf(d, "%s:", a);
				oper.op=strdup(d);
				oper.res = NULL;
				oper.arg1 = NULL;
				oper.arg2 = NULL;
				insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
				concatenaLC((yyval.codigo),(yyvsp[-2].codigo));
				Operacion oper2;
				oper2.op=strdup("beqz");
				oper2.res = recuperaResLC((yyvsp[-2].codigo));
				oper2.arg1 = nuevaEtiqueta();
				oper2.arg2 = NULL;
				insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper2);
				concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				Operacion oper3;
				oper3.op=strdup("b");
				oper3.res = strdup(a); 
				oper3.arg1 = NULL;
				oper3.arg2 = NULL;
				insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper3);
				Operacion oper4;
				char c[18];
				sprintf(c, "%s:", oper2.arg1);
				oper4.op=strdup(c);
				oper4.res = NULL;
				oper4.arg1 = NULL;
				oper4.arg2 = NULL;
				insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper4);
				liberarReg(oper2.res);


			 }
#line 1478 "minic.tab.c"
    break;

  case 20: /* statement: PRI print_list PYC  */
#line 288 "minic.y"
                                              {
				 
					(yyval.codigo)=(yyvsp[-1].codigo);
			 }
#line 1487 "minic.tab.c"
    break;

  case 21: /* statement: REA read_list PYC  */
#line 292 "minic.y"
                                 {
					(yyval.codigo)=(yyvsp[-1].codigo);
			 }
#line 1495 "minic.tab.c"
    break;

  case 22: /* print_list: print_item  */
#line 297 "minic.y"
                          {
					(yyval.codigo)=(yyvsp[0].codigo);
			}
#line 1503 "minic.tab.c"
    break;

  case 23: /* print_list: print_list COM print_item  */
#line 300 "minic.y"
                                                     {
					(yyval.codigo)=(yyvsp[-2].codigo);
					concatenaLC((yyval.codigo),(yyvsp[0].codigo));
					liberaLC((yyvsp[0].codigo));
			 }
#line 1513 "minic.tab.c"
    break;

  case 24: /* print_item: expression  */
#line 307 "minic.y"
                         {
					(yyval.codigo)=(yyvsp[0].codigo);
					Operacion oper;
					oper.op=strdup("li");
					oper.res = strdup("$v0");
				 	oper.arg1=strdup("1");
					oper.arg2=NULL;
					insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
					Operacion oper2;
					oper2.op=strdup("move");
					oper2.res = strdup("$a0");
				 	oper2.arg1=recuperaResLC((yyvsp[0].codigo));
					oper2.arg2=NULL;
					insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper2);
					Operacion oper3;
					oper3.op=strdup("syscall");
					oper3.res = NULL;
				 	oper3.arg1=NULL;
					oper3.arg2=NULL;
					insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper3);
					liberarReg(oper2.arg1);
				}
#line 1540 "minic.tab.c"
    break;

  case 25: /* print_item: CAD  */
#line 329 "minic.y"
                               {
				 	(yyval.codigo)=creaLC(); 
					Operacion oper;
					oper.op=strdup("li");
					oper.res = strdup("$v0");
				 	oper.arg1=strdup("4");
				 	oper.arg2=NULL;
					insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
					Operacion oper2;
					oper2.op=strdup("la");
					oper2.res = strdup("$a0");
					PosicionLista p;
					p = buscaLS(tS, (yyvsp[0].cadena));
					Simbolo s;
					if(p==finalLS(tS)){
						s.nombre = (yyvsp[0].cadena);
						s.tipo = CADENA;
						s.valor = contador_cadena;
						insertaLS(tS, p, s);
						contador_cadena++;
					}else{
						s=recuperaLS(tS, p);
					}
					char c[18];
					sprintf(c, "$str%d", s.valor);
				 	oper2.arg1=strdup(c);
					oper2.arg2=NULL;
					insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper2);
					Operacion oper3;
					oper3.op=strdup("syscall");
					oper3.res = NULL;
				 	oper3.arg1=NULL;
					oper3.arg2=NULL;
					insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper3);
			 }
#line 1580 "minic.tab.c"
    break;

  case 26: /* read_list: IDE  */
#line 366 "minic.y"
                   {
				PosicionLista p2;
				p2 = buscaLS(tS, (yyvsp[0].cadena));
				if(p2 != finalLS(tS)){
					Simbolo s = recuperaLS(tS, p2);
					if(s.tipo != CONSTANTE){
						(yyval.codigo)=creaLC();
						Operacion oper;
						oper.op=strdup("li");
						oper.res = strdup("$v0");
						oper.arg1=strdup("5");
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
						Operacion oper2;
						oper2.op=strdup("syscall");
						oper2.res = NULL;
						oper2.arg1=NULL;
						oper2.arg2=NULL;
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper2);
						Operacion oper3;
						oper3.op = strdup("sw");
						oper3.res = strdup("$v0");
						char c[18];
						sprintf(c, "_%s", (yyvsp[0].cadena));
						free((yyvsp[0].cadena));
						oper3.arg1 = strdup(c);
						oper3.arg2=NULL;
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper3);					
					} else {
						cont_semantico++;
						yyerror("error semantico, asignacion a una constante");
						(yyval.codigo)=creaLC();
					}	
				} else {
					cont_semantico++;
					yyerror("error semantico, no se encuentra en la lista");
					(yyval.codigo)=creaLC();
					
				}
				}
#line 1624 "minic.tab.c"
    break;

  case 27: /* read_list: read_list COM IDE  */
#line 405 "minic.y"
                                             {
				PosicionLista p2;
				p2 = buscaLS(tS, (yyvsp[0].cadena));
				if(p2 != finalLS(tS)){
					Simbolo s = recuperaLS(tS, p2);
					if(s.tipo != CONSTANTE){
						(yyval.codigo)=(yyvsp[-2].codigo);
						Operacion oper;
						oper.op=strdup("li");
						oper.res = strdup("$v0");
						oper.arg1=strdup("5");
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
						Operacion oper2;
						oper2.op=strdup("syscall");
						oper2.res = NULL;
						oper2.arg1=NULL;
						oper2.arg2=NULL;
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper2);
						Operacion oper3;
						oper3.op = strdup("sw");
						oper3.res = strdup("$v0");
						char c[18];
						sprintf(c, "_%s", (yyvsp[0].cadena));
						free((yyvsp[0].cadena));
						oper3.arg1 = strdup(c);
						oper3.arg2=NULL;
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper3);		
					} else {
						cont_semantico++;
						yyerror("error semantico, asignacion a una constante");
						(yyval.codigo)=(yyvsp[-2].codigo);
					}
				} else {
					cont_semantico++;
					yyerror("error semantico, no pertenece a la lista");
					(yyval.codigo)=(yyvsp[-2].codigo);
				}	
				}
#line 1667 "minic.tab.c"
    break;

  case 28: /* expression: expression SUM expression  */
#line 446 "minic.y"
                           {
				   (yyval.codigo)=(yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				   Operacion oper;
				   oper.op=strdup("add");
				   oper.res = recuperaResLC((yyvsp[-2].codigo));
				   oper.arg1=recuperaResLC((yyvsp[-2].codigo));
				   oper.arg2 = recuperaResLC((yyvsp[0].codigo));
				   insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
				   liberaLC((yyvsp[0].codigo));
				   liberarReg(oper.arg2);
			   }
#line 1683 "minic.tab.c"
    break;

  case 29: /* expression: expression RES expression  */
#line 458 "minic.y"
                         {
				   (yyval.codigo)=(yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				   Operacion oper; oper.op=strdup("sub"); oper.res = recuperaResLC((yyvsp[-2].codigo));
				   oper.arg1=recuperaResLC((yyvsp[-2].codigo)); oper.arg2 = recuperaResLC((yyvsp[0].codigo));
				   insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); liberaLC((yyvsp[0].codigo));
				   liberarReg(oper.arg2);
			   }
#line 1695 "minic.tab.c"
    break;

  case 30: /* expression: expression MUL expression  */
#line 466 "minic.y"
                         {
				   (yyval.codigo)=(yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				   Operacion oper; oper.op=strdup("mul");; oper.res = recuperaResLC((yyvsp[-2].codigo));
				   oper.arg1=recuperaResLC((yyvsp[-2].codigo)); oper.arg2 = recuperaResLC((yyvsp[0].codigo));
				   insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); liberaLC((yyvsp[0].codigo));
				   liberarReg(oper.arg2);
			   }
#line 1707 "minic.tab.c"
    break;

  case 31: /* expression: expression DIV expression  */
#line 474 "minic.y"
                         {
				   (yyval.codigo)=(yyvsp[-2].codigo); concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				   Operacion oper; oper.op=strdup("div");; oper.res = recuperaResLC((yyvsp[-2].codigo));
				   oper.arg1=recuperaResLC((yyvsp[-2].codigo)); oper.arg2 = recuperaResLC((yyvsp[0].codigo));
				   insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper); liberaLC((yyvsp[0].codigo));
				   liberarReg(oper.arg2);
			   }
#line 1719 "minic.tab.c"
    break;

  case 32: /* expression: RES expression  */
#line 482 "minic.y"
                         {
				 (yyval.codigo)=(yyvsp[0].codigo);
				 Operacion oper;
				 oper.op=strdup("neg");
				 oper.res=recuperaResLC((yyvsp[0].codigo));
				 oper.arg1=recuperaResLC((yyvsp[0].codigo));
				 oper.arg2=NULL;
				 insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

			 }
#line 1734 "minic.tab.c"
    break;

  case 33: /* expression: PAI expression PAD  */
#line 493 "minic.y"
                         {
                (yyval.codigo) = (yyvsp[-1].codigo);

             }
#line 1743 "minic.tab.c"
    break;

  case 34: /* expression: IDE  */
#line 497 "minic.y"
                               {
				PosicionLista p2;
				p2 = buscaLS(tS, (yyvsp[0].cadena));
				if(p2 != finalLS(tS)){
					(yyval.codigo)=creaLC();
					
				} else {
					(yyval.codigo)=creaLC();
					cont_semantico++;
					yyerror("error semantico, identificador no declarado");
				}
				Operacion oper;
					oper.op=strdup("lw");
					oper.res=obtenerReg();
					char c[18];
					sprintf(c, "_%s", (yyvsp[0].cadena));
					oper.arg1=strdup(c);
					oper.arg2=NULL;
					insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
					guardaResLC((yyval.codigo),oper.res);
				}
#line 1769 "minic.tab.c"
    break;

  case 35: /* expression: ENT  */
#line 518 "minic.y"
                               {
				  (yyval.codigo) = creaLC();
				 Operacion oper;
				 oper.op=strdup("li");
				 oper.res = obtenerReg();
				 oper.arg1=(yyvsp[0].cadena);
				 oper.arg2=NULL;
				 insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper);
				 guardaResLC((yyval.codigo), oper.res);
				 
			 }
#line 1785 "minic.tab.c"
    break;


#line 1789 "minic.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 530 "minic.y"



void yyerror(const char *msg){
    fprintf(stderr, "Error en linea %d: %s, hay %d errores semanticos\n", yylineno, msg, cont_semantico);
}

char *obtenerReg(){
	int i=0; 
	while(registros[i]!=0){
		i++;
	}
	registros[i]=1;
	char str[10];
	sprintf(str, "$t%d", i);
	return strdup(str);
}

void liberarReg(char *s){
	registros[s[2]-'0']=0;
}

char *nuevaEtiqueta() {
	char aux[10];
	sprintf(aux,"$l%d",contador_etiq++);
	return strdup(aux);
}


