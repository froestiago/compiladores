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
#line 1 "parser.y"

#include<stdio.h>
#include<string.h>
#include "ast.h"
#include "table.h"
#include "utils.h"
#include "code.h"
extern void* arvore;
int yylex(void);
void yyerror (char const *s);
extern int yylineno;

extern Symbol *tabela_global;
extern Symbol *tabela_atual;
extern Tipo tipo_atual;
// extern List list;
extern List *nodo_inicial;
extern List *nodo_atual;

extern int current_temp;
extern int current_temp_dec;
extern int current_label;
extern int cbr_temp;

extern int disp_rfp;
extern int disp_rbss;

extern Code *code;
extern AssemblySymbol *ass_table;

// O codigo é gerado em um passagem só


#line 105 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_PR_INT = 3,                  /* TK_PR_INT  */
  YYSYMBOL_TK_PR_FLOAT = 4,                /* TK_PR_FLOAT  */
  YYSYMBOL_TK_PR_BOOL = 5,                 /* TK_PR_BOOL  */
  YYSYMBOL_TK_PR_IF = 6,                   /* TK_PR_IF  */
  YYSYMBOL_TK_PR_ELSE = 7,                 /* TK_PR_ELSE  */
  YYSYMBOL_TK_PR_WHILE = 8,                /* TK_PR_WHILE  */
  YYSYMBOL_TK_PR_RETURN = 9,               /* TK_PR_RETURN  */
  YYSYMBOL_TK_OC_LE = 10,                  /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 11,                  /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 12,                  /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 13,                  /* TK_OC_NE  */
  YYSYMBOL_TK_OC_AND = 14,                 /* TK_OC_AND  */
  YYSYMBOL_TK_OC_OR = 15,                  /* TK_OC_OR  */
  YYSYMBOL_TK_OC_MAP = 16,                 /* TK_OC_MAP  */
  YYSYMBOL_TK_IDENTIFICADOR = 17,          /* TK_IDENTIFICADOR  */
  YYSYMBOL_TK_LIT_INT = 18,                /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_FLOAT = 19,              /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_LIT_FALSE = 20,              /* TK_LIT_FALSE  */
  YYSYMBOL_TK_LIT_TRUE = 21,               /* TK_LIT_TRUE  */
  YYSYMBOL_TK_ERRO = 22,                   /* TK_ERRO  */
  YYSYMBOL_23_ = 23,                       /* '('  */
  YYSYMBOL_24_ = 24,                       /* ')'  */
  YYSYMBOL_25_ = 25,                       /* '!'  */
  YYSYMBOL_26_ = 26,                       /* '-'  */
  YYSYMBOL_27_ = 27,                       /* '*'  */
  YYSYMBOL_28_ = 28,                       /* '/'  */
  YYSYMBOL_29_ = 29,                       /* '%'  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '<'  */
  YYSYMBOL_32_ = 32,                       /* '>'  */
  YYSYMBOL_33_ = 33,                       /* '='  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_init = 39,                      /* init  */
  YYSYMBOL_40_1 = 40,                      /* $@1  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_list = 42,                      /* list  */
  YYSYMBOL_global_var = 43,                /* global_var  */
  YYSYMBOL_44_2 = 44,                      /* $@2  */
  YYSYMBOL_list_global_var = 45,           /* list_global_var  */
  YYSYMBOL_function = 46,                  /* function  */
  YYSYMBOL_new_node = 47,                  /* new_node  */
  YYSYMBOL_function_type = 48,             /* function_type  */
  YYSYMBOL_parameter_list = 49,            /* parameter_list  */
  YYSYMBOL_parameter = 50,                 /* parameter  */
  YYSYMBOL_type_aux = 51,                  /* type_aux  */
  YYSYMBOL_command_block = 52,             /* command_block  */
  YYSYMBOL_abre_escopo = 53,               /* abre_escopo  */
  YYSYMBOL_fecha_escopo = 54,              /* fecha_escopo  */
  YYSYMBOL_command_block_func = 55,        /* command_block_func  */
  YYSYMBOL_abre_escopo_func = 56,          /* abre_escopo_func  */
  YYSYMBOL_fecha_escopo_func = 57,         /* fecha_escopo_func  */
  YYSYMBOL_command_list = 58,              /* command_list  */
  YYSYMBOL_command = 59,                   /* command  */
  YYSYMBOL_var_declaration = 60,           /* var_declaration  */
  YYSYMBOL_var_in_func = 61,               /* var_in_func  */
  YYSYMBOL_assignment = 62,                /* assignment  */
  YYSYMBOL_function_call = 63,             /* function_call  */
  YYSYMBOL_args = 64,                      /* args  */
  YYSYMBOL_op_return = 65,                 /* op_return  */
  YYSYMBOL_flow_control = 66,              /* flow_control  */
  YYSYMBOL_add_label_to_code = 67,         /* add_label_to_code  */
  YYSYMBOL_add_cbr = 68,                   /* add_cbr  */
  YYSYMBOL_add_cbr_while = 69,             /* add_cbr_while  */
  YYSYMBOL_add_jumpI_else = 70,            /* add_jumpI_else  */
  YYSYMBOL_add_jumpI_end_while_block = 71, /* add_jumpI_end_while_block  */
  YYSYMBOL_conditional = 72,               /* conditional  */
  YYSYMBOL_iterative = 73,                 /* iterative  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_expression_7 = 75,              /* expression_7  */
  YYSYMBOL_expression_6 = 76,              /* expression_6  */
  YYSYMBOL_expression_5 = 77,              /* expression_5  */
  YYSYMBOL_expression_4 = 78,              /* expression_4  */
  YYSYMBOL_expression_3 = 79,              /* expression_3  */
  YYSYMBOL_expression_2 = 80,              /* expression_2  */
  YYSYMBOL_expression_1 = 81,              /* expression_1  */
  YYSYMBOL_literal = 82,                   /* literal  */
  YYSYMBOL_type = 83                       /* type  */
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
typedef yytype_uint8 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
       2,     2,     2,    25,     2,     2,     2,    29,     2,     2,
      23,    24,    27,    30,    35,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      31,    33,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   105,   105,   105,   107,   108,   118,   119,   120,   121,
     125,   125,   127,   132,   140,   146,   152,   154,   156,   157,
     159,   164,   166,   167,   169,   170,   172,   173,   175,   176,
     179,   180,   182,   183,   184,   185,   186,   187,   191,   194,
     202,   215,   220,   231,   241,   246,   247,   248,   250,   252,
     253,   255,   259,   263,   269,   273,   277,   283,   289,   297,
     306,   308,   317,   319,   328,   337,   339,   348,   359,   370,
     380,   382,   394,   405,   407,   418,   428,   431,   433,   434,
     435,   437,   449,   455,   456,   461,   467,   468,   469,   473,
     474,   475
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_PR_INT",
  "TK_PR_FLOAT", "TK_PR_BOOL", "TK_PR_IF", "TK_PR_ELSE", "TK_PR_WHILE",
  "TK_PR_RETURN", "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE",
  "TK_OC_AND", "TK_OC_OR", "TK_OC_MAP", "TK_IDENTIFICADOR", "TK_LIT_INT",
  "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE", "TK_ERRO", "'('", "')'",
  "'!'", "'-'", "'*'", "'/'", "'%'", "'+'", "'<'", "'>'", "'='", "';'",
  "','", "'{'", "'}'", "$accept", "init", "$@1", "program", "list",
  "global_var", "$@2", "list_global_var", "function", "new_node",
  "function_type", "parameter_list", "parameter", "type_aux",
  "command_block", "abre_escopo", "fecha_escopo", "command_block_func",
  "abre_escopo_func", "fecha_escopo_func", "command_list", "command",
  "var_declaration", "var_in_func", "assignment", "function_call", "args",
  "op_return", "flow_control", "add_label_to_code", "add_cbr",
  "add_cbr_while", "add_jumpI_else", "add_jumpI_end_while_block",
  "conditional", "iterative", "expression", "expression_7", "expression_6",
  "expression_5", "expression_4", "expression_3", "expression_2",
  "expression_1", "literal", "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-119)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -119,    13,    31,  -119,  -119,  -119,  -119,  -119,  -119,    31,
      31,     3,  -119,  -119,  -119,     5,    14,    22,    20,    24,
      65,    37,    38,    88,  -119,    14,  -119,    80,    74,    65,
      80,  -119,  -119,  -119,    76,  -119,     1,    74,  -119,  -119,
      91,  -119,    46,    29,    78,    99,  -119,     1,    81,    83,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    46,    96,
      97,  -119,  -119,  -119,  -119,    46,    57,    57,  -119,   106,
     108,    89,    11,    56,    68,  -119,  -119,  -119,    46,    46,
    -119,     4,  -119,    86,  -119,  -119,     1,    30,    46,    44,
    -119,  -119,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,   100,    -3,   106,    69,    99,
    -119,  -119,  -119,  -119,    55,  -119,   108,    89,    11,    11,
      56,    56,    56,    56,    68,    68,  -119,  -119,  -119,  -119,
      46,    90,  -119,  -119,  -119,  -119,    99,    92,  -119,  -119,
     119,    92,  -119,   120,  -119,  -119,  -119,    92,  -119,  -119,
    -119
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     1,    89,    90,    91,     3,     5,     9,
       8,     0,    10,     7,     6,     0,     0,     0,    13,     0,
       0,     0,    18,     0,    21,     0,    11,     0,     0,     0,
       0,    20,    12,    17,    28,    14,     0,     0,    19,    26,
       0,    51,     0,     0,    24,     0,    36,     0,     0,     0,
      32,    33,    37,    35,    34,    49,    50,    15,     0,     0,
      81,    85,    86,    88,    87,     0,     0,     0,    83,    48,
      60,    62,    65,    70,    73,    77,    80,    82,    45,     0,
      22,    42,    38,     0,    29,    27,    31,     0,     0,     0,
      79,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,    43,     0,     0,
      25,    23,    30,    52,     0,    84,    59,    61,    63,    64,
      68,    69,    66,    67,    72,    71,    74,    75,    76,    44,
      45,    40,    41,    51,    53,    46,     0,     0,    51,    39,
      51,     0,    57,     0,    55,    51,    51,     0,    58,    51,
      56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -119,  -119,  -119,  -119,    94,  -119,  -119,   104,  -119,  -119,
     101,   102,  -119,    23,  -118,  -119,  -119,    98,  -119,  -119,
     -45,  -119,  -119,  -106,  -119,   -36,     7,  -119,  -119,   -89,
    -119,  -119,  -119,  -119,  -119,  -119,   -41,    39,    40,    12,
      -5,     8,    -4,    45,    26,     6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,     8,     9,    16,    19,    10,    11,
      28,    21,    22,    45,    46,    47,   111,    35,    36,    85,
      48,    49,    50,    82,    51,    68,   105,    53,    54,    59,
     133,   138,   143,   146,    55,    56,   106,    70,    71,    72,
      73,    74,    75,    76,    77,    24
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    69,    83,   132,     4,     5,     6,    40,    12,    41,
      42,    52,    92,     3,   108,    12,    12,    87,    43,   140,
      15,    96,    97,   144,    89,     4,     5,     6,    17,   149,
     139,    18,   130,    33,     4,     5,     6,    44,   107,   109,
      23,   112,    98,    99,   137,    92,    20,   114,   -16,   141,
      52,   142,    78,    23,   113,    25,   147,   148,    26,    92,
     150,    29,    79,    60,    61,    62,    63,    64,   115,    65,
      92,    66,    67,    30,    60,    61,    62,    63,    64,   134,
      65,    27,   100,     4,     5,     6,   101,    61,    62,    63,
      64,   120,   121,   122,   123,   102,   103,   104,   126,   127,
     128,    94,    95,    13,    14,    31,   118,   119,   124,   125,
      34,    90,    91,    39,    58,    80,    81,    86,    84,    88,
      78,    92,    93,   110,   129,   136,   -54,   145,    44,    32,
      37,   116,    38,   117,   131,    57,     0,   135
};

static const yytype_int16 yycheck[] =
{
      36,    42,    47,   109,     3,     4,     5,     6,     2,     8,
       9,    47,    15,     0,    10,     9,    10,    58,    17,   137,
      17,    10,    11,   141,    65,     3,     4,     5,    23,   147,
     136,    17,    35,    27,     3,     4,     5,    36,    79,    35,
      17,    86,    31,    32,   133,    15,    24,    88,    17,   138,
      86,   140,    23,    30,    24,    35,   145,   146,    34,    15,
     149,    24,    33,    17,    18,    19,    20,    21,    24,    23,
      15,    25,    26,    35,    17,    18,    19,    20,    21,    24,
      23,    16,    26,     3,     4,     5,    30,    18,    19,    20,
      21,    96,    97,    98,    99,    27,    28,    29,   102,   103,
     104,    12,    13,     9,    10,    17,    94,    95,   100,   101,
      36,    66,    67,    37,    23,    37,    17,    34,    37,    23,
      23,    15,    14,    37,    24,    35,     7,     7,    36,    25,
      29,    92,    30,    93,   108,    37,    -1,   130
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    40,     0,     3,     4,     5,    41,    42,    43,
      46,    47,    83,    42,    42,    17,    44,    23,    17,    45,
      24,    49,    50,    51,    83,    35,    34,    16,    48,    24,
      35,    17,    45,    83,    36,    55,    56,    48,    49,    37,
       6,     8,     9,    17,    36,    51,    52,    53,    58,    59,
      60,    62,    63,    65,    66,    72,    73,    55,    23,    67,
      17,    18,    19,    20,    21,    23,    25,    26,    63,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    23,    33,
      37,    17,    61,    58,    37,    57,    34,    74,    23,    74,
      81,    81,    15,    14,    12,    13,    10,    11,    31,    32,
      26,    30,    27,    28,    29,    64,    74,    74,    10,    35,
      37,    54,    58,    24,    74,    24,    75,    76,    77,    77,
      78,    78,    78,    78,    79,    79,    80,    80,    80,    24,
      35,    82,    61,    68,    24,    64,    35,    67,    69,    61,
      52,    67,    67,    70,    52,     7,    71,    67,    67,    52,
      67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    40,    39,    41,    41,    42,    42,    42,    42,
      44,    43,    45,    45,    46,    46,    47,    48,    49,    49,
      50,    51,    52,    52,    53,    54,    55,    55,    56,    57,
      58,    58,    59,    59,    59,    59,    59,    59,    60,    61,
      61,    61,    61,    62,    63,    64,    64,    64,    65,    66,
      66,    67,    68,    69,    70,    71,    72,    72,    73,    74,
      74,    75,    75,    76,    76,    76,    77,    77,    77,    77,
      77,    78,    78,    78,    79,    79,    79,    79,    80,    80,
      80,    81,    81,    81,    81,    82,    82,    82,    82,    83,
      83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     1,     2,     2,     1,     1,
       0,     4,     3,     1,     6,     7,     0,     2,     1,     3,
       2,     1,     2,     3,     1,     1,     2,     3,     1,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     2,     5,
       3,     3,     1,     3,     4,     0,     3,     1,     2,     1,
       1,     0,     0,     0,     0,     0,    12,     8,    10,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
#line 105 "parser.y"
      {inicializarLista();}
#line 1554 "parser.tab.c"
    break;

  case 4: /* program: %empty  */
#line 107 "parser.y"
                {(yyval.node) = NULL; arvore = NULL; printf("arvore vazia");}
#line 1560 "parser.tab.c"
    break;

  case 5: /* program: list  */
#line 108 "parser.y"
               {(yyval.node) = (yyvsp[0].node);
                arvore = (yyval.node);
                // imprime_lista();
                // printf("\n\n\n\n");
                (yyval.node)->valor_lexico.code = code;
                printCodeList();
                printf("\n----------------\n"); 
                printAssemblyCode();
                }
#line 1574 "parser.tab.c"
    break;

  case 6: /* list: function list  */
#line 118 "parser.y"
                   { if((yyvsp[-1].node)!=NULL){add_children((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}else{(yyval.node)=(yyvsp[0].node);}}
#line 1580 "parser.tab.c"
    break;

  case 7: /* list: global_var list  */
#line 119 "parser.y"
                     { if((yyvsp[-1].node)!=NULL){add_children((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}else{(yyval.node)=(yyvsp[0].node);}}
#line 1586 "parser.tab.c"
    break;

  case 8: /* list: function  */
#line 120 "parser.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 1592 "parser.tab.c"
    break;

  case 9: /* list: global_var  */
#line 121 "parser.y"
                 {(yyval.node) = NULL;}
#line 1598 "parser.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 125 "parser.y"
                 {set_tipo_atual((yyvsp[0].valor_lexico));}
#line 1604 "parser.tab.c"
    break;

  case 11: /* global_var: type $@2 list_global_var ';'  */
#line 125 "parser.y"
                                                           {(yyval.node) = NULL; }
#line 1610 "parser.tab.c"
    break;

  case 12: /* list_global_var: TK_IDENTIFICADOR ',' list_global_var  */
#line 127 "parser.y"
                                                     {
                        (yyval.node) = NULL;
                        adicionarSymbol(nodo_atual, create_node((yyvsp[-2].valor_lexico)));
                        }
#line 1619 "parser.tab.c"
    break;

  case 13: /* list_global_var: TK_IDENTIFICADOR  */
#line 132 "parser.y"
                                   {
                        (yyval.node) = NULL;
                        adicionarSymbol(nodo_atual, create_node((yyvsp[0].valor_lexico)));
                        }
#line 1628 "parser.tab.c"
    break;

  case 14: /* function: new_node TK_IDENTIFICADOR '(' ')' function_type command_block_func  */
#line 140 "parser.y"
                                                                             {
                (yyval.node) = create_node((yyvsp[-4].valor_lexico));
                if((yyvsp[-1].node) != NULL){add_children((yyval.node), (yyvsp[0].node));}
                adicionarSymbol_DefFunc(nodo_atual, create_node((yyvsp[-4].valor_lexico)));
                }
#line 1638 "parser.tab.c"
    break;

  case 15: /* function: new_node TK_IDENTIFICADOR '(' parameter_list ')' function_type command_block_func  */
#line 146 "parser.y"
                                                                                            {
                (yyval.node) = create_node((yyvsp[-5].valor_lexico));
                if((yyvsp[-1].node) != NULL) {add_children((yyval.node), (yyvsp[0].node));}
                adicionarSymbol_DefFunc(nodo_atual, create_node((yyvsp[-5].valor_lexico)));
                }
#line 1648 "parser.tab.c"
    break;

  case 16: /* new_node: %empty  */
#line 152 "parser.y"
          {adicionarNodo();}
#line 1654 "parser.tab.c"
    break;

  case 17: /* function_type: TK_OC_MAP type  */
#line 154 "parser.y"
                             {set_tipo_atual((yyvsp[0].valor_lexico));}
#line 1660 "parser.tab.c"
    break;

  case 18: /* parameter_list: parameter  */
#line 156 "parser.y"
                          {(yyval.node) = NULL;}
#line 1666 "parser.tab.c"
    break;

  case 19: /* parameter_list: parameter ',' parameter_list  */
#line 157 "parser.y"
                                               {(yyval.node) = NULL;}
#line 1672 "parser.tab.c"
    break;

  case 20: /* parameter: type_aux TK_IDENTIFICADOR  */
#line 159 "parser.y"
                                     {
                (yyval.node) = NULL;
                adicionarSymbol(nodo_atual, create_node((yyvsp[0].valor_lexico)));
                }
#line 1681 "parser.tab.c"
    break;

  case 21: /* type_aux: type  */
#line 164 "parser.y"
               {set_tipo_atual((yyvsp[0].valor_lexico));}
#line 1687 "parser.tab.c"
    break;

  case 22: /* command_block: '{' '}'  */
#line 166 "parser.y"
                       {(yyval.node) = NULL;}
#line 1693 "parser.tab.c"
    break;

  case 23: /* command_block: abre_escopo command_list fecha_escopo  */
#line 167 "parser.y"
                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1699 "parser.tab.c"
    break;

  case 24: /* abre_escopo: '{'  */
#line 169 "parser.y"
                     {adicionarNodo();}
#line 1705 "parser.tab.c"
    break;

  case 25: /* fecha_escopo: '}'  */
#line 170 "parser.y"
                    {retrocederNodo();}
#line 1711 "parser.tab.c"
    break;

  case 26: /* command_block_func: '{' '}'  */
#line 172 "parser.y"
                            {(yyval.node) = NULL;}
#line 1717 "parser.tab.c"
    break;

  case 27: /* command_block_func: abre_escopo_func command_list fecha_escopo_func  */
#line 173 "parser.y"
                                                                  {(yyval.node) = (yyvsp[-1].node);}
#line 1723 "parser.tab.c"
    break;

  case 28: /* abre_escopo_func: '{'  */
#line 175 "parser.y"
                      {}
#line 1729 "parser.tab.c"
    break;

  case 29: /* fecha_escopo_func: '}'  */
#line 176 "parser.y"
                       {nodo_atual = nodo_inicial;}
#line 1735 "parser.tab.c"
    break;

  case 30: /* command_list: command ';' command_list  */
#line 179 "parser.y"
                                       {if((yyvsp[-2].node) == NULL) {(yyval.node) = (yyvsp[0].node);}else{add_children((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-2].node);}}
#line 1741 "parser.tab.c"
    break;

  case 31: /* command_list: command ';'  */
#line 180 "parser.y"
                          { (yyval.node) = (yyvsp[-1].node);}
#line 1747 "parser.tab.c"
    break;

  case 32: /* command: var_declaration  */
#line 182 "parser.y"
                         {(yyval.node) = (yyvsp[0].node);}
#line 1753 "parser.tab.c"
    break;

  case 33: /* command: assignment  */
#line 183 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1759 "parser.tab.c"
    break;

  case 34: /* command: flow_control  */
#line 184 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1765 "parser.tab.c"
    break;

  case 35: /* command: op_return  */
#line 185 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1771 "parser.tab.c"
    break;

  case 36: /* command: command_block  */
#line 186 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1777 "parser.tab.c"
    break;

  case 37: /* command: function_call  */
#line 187 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1783 "parser.tab.c"
    break;

  case 38: /* var_declaration: type_aux var_in_func  */
#line 191 "parser.y"
                                      {
                (yyval.node) = (yyvsp[0].node);}
#line 1790 "parser.tab.c"
    break;

  case 39: /* var_in_func: TK_IDENTIFICADOR TK_OC_LE literal ',' var_in_func  */
#line 194 "parser.y"
                                                               {
                (yyval.node) = create_node((yyvsp[-3].valor_lexico));
                add_children((yyval.node), create_node((yyvsp[-4].valor_lexico))); 
                add_children((yyval.node), (yyvsp[-2].node));
                add_children((yyval.node), (yyvsp[0].node));
                adicionarSymbol(nodo_atual, create_node((yyvsp[-4].valor_lexico)));
                }
#line 1802 "parser.tab.c"
    break;

  case 40: /* var_in_func: TK_IDENTIFICADOR TK_OC_LE literal  */
#line 202 "parser.y"
                                            {
                (yyval.node) = create_node((yyvsp[-1].valor_lexico));
                add_children((yyval.node), create_node((yyvsp[-2].valor_lexico)));
                add_children((yyval.node), (yyvsp[0].node));
                adicionarSymbol(nodo_atual, create_node((yyvsp[-2].valor_lexico)));
                Instruction *instruction_load = add_loadI((yyvsp[0].node)->valor_lexico.valor,(yyvsp[0].node)->valor_lexico.temp);
                (yyval.node)->valor_lexico.code = addInstruction(instruction_load);
                int disp = find_disp(nodo_atual, (yyvsp[-2].valor_lexico).valor);
                char *base = find_base(nodo_atual, (yyvsp[-2].valor_lexico).valor);
                Instruction *instruction_store = add_storeAI((yyvsp[0].node)->valor_lexico.temp, base, disp);
                (yyval.node)->valor_lexico.code = addInstruction(instruction_store);
                }
#line 1819 "parser.tab.c"
    break;

  case 41: /* var_in_func: TK_IDENTIFICADOR ',' var_in_func  */
#line 215 "parser.y"
                                           {
                (yyval.node) = (yyvsp[0].node);
                adicionarSymbol(nodo_atual, create_node((yyvsp[-2].valor_lexico)));
                }
#line 1828 "parser.tab.c"
    break;

  case 42: /* var_in_func: TK_IDENTIFICADOR  */
#line 220 "parser.y"
                           {
                (yyval.node) = NULL;
                adicionarSymbol(nodo_atual, create_node((yyvsp[0].valor_lexico)));
                createFullNode("NULL", //value
                               "NULL", //temp
                               "NULL", //base
                               "NULL", //disp
                               (yyvsp[0].valor_lexico).valor);  //var

                }
#line 1843 "parser.tab.c"
    break;

  case 43: /* assignment: TK_IDENTIFICADOR '=' expression  */
#line 231 "parser.y"
                                            {
                (yyval.node) = create_node((yyvsp[-1].valor_lexico));
                add_children((yyval.node), create_node((yyvsp[-2].valor_lexico)));
                add_children((yyval.node), (yyvsp[0].node));
                char *base = find_base(nodo_atual, (yyvsp[-2].valor_lexico).valor);
                int disp = find_disp(nodo_atual, (yyvsp[-2].valor_lexico).valor);
                Instruction *instruction = add_storeAI((yyvsp[0].node)->valor_lexico.temp, base, disp);
                (yyval.node)->valor_lexico.code = addInstruction(instruction);
                }
#line 1857 "parser.tab.c"
    break;

  case 44: /* function_call: TK_IDENTIFICADOR '(' args ')'  */
#line 241 "parser.y"
                                             {
                (yyval.node) = create_node((yyvsp[-3].valor_lexico));
                add_children((yyval.node), (yyvsp[-1].node));
                }
#line 1866 "parser.tab.c"
    break;

  case 45: /* args: %empty  */
#line 246 "parser.y"
             {(yyval.node) = NULL;}
#line 1872 "parser.tab.c"
    break;

  case 46: /* args: expression ',' args  */
#line 247 "parser.y"
                              {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), (yyvsp[0].node));}
#line 1878 "parser.tab.c"
    break;

  case 47: /* args: expression  */
#line 248 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1884 "parser.tab.c"
    break;

  case 48: /* op_return: TK_PR_RETURN expression  */
#line 250 "parser.y"
                                   {(yyval.node) = create_node((yyvsp[-1].valor_lexico)); add_children((yyval.node), (yyvsp[0].node));}
#line 1890 "parser.tab.c"
    break;

  case 49: /* flow_control: conditional  */
#line 252 "parser.y"
                          {(yyval.node) = (yyvsp[0].node);}
#line 1896 "parser.tab.c"
    break;

  case 50: /* flow_control: iterative  */
#line 253 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1902 "parser.tab.c"
    break;

  case 51: /* add_label_to_code: %empty  */
#line 255 "parser.y"
                   {
    add_label(current_label); current_label+=1;
    }
#line 1910 "parser.tab.c"
    break;

  case 52: /* add_cbr: %empty  */
#line 259 "parser.y"
         {
    add_cbr(cbr_temp, current_label, current_label+1);
    }
#line 1918 "parser.tab.c"
    break;

  case 53: /* add_cbr_while: %empty  */
#line 263 "parser.y"
               {
    add_cbr(cbr_temp, current_label, current_label+1);
    }
#line 1926 "parser.tab.c"
    break;

  case 54: /* add_jumpI_else: %empty  */
#line 269 "parser.y"
                {
    add_jumpI(current_label+1);
    }
#line 1934 "parser.tab.c"
    break;

  case 55: /* add_jumpI_end_while_block: %empty  */
#line 273 "parser.y"
                           {
    add_jumpI(current_label-2);
    }
#line 1942 "parser.tab.c"
    break;

  case 56: /* conditional: TK_PR_IF '(' expression ')' add_cbr add_label_to_code command_block add_jumpI_else TK_PR_ELSE add_label_to_code command_block add_label_to_code  */
#line 277 "parser.y"
                                                                                                                                                            {
                (yyval.node) = create_node((yyvsp[-11].valor_lexico)); 
                add_children((yyval.node), (yyvsp[-9].node));
                add_children((yyval.node), (yyvsp[-5].node));
                add_children((yyval.node), (yyvsp[-1].node));
                }
#line 1953 "parser.tab.c"
    break;

  case 57: /* conditional: TK_PR_IF '(' expression ')' add_cbr add_label_to_code command_block add_label_to_code  */
#line 283 "parser.y"
                                                                                                    {
                (yyval.node) = create_node((yyvsp[-7].valor_lexico));
                add_children((yyval.node), (yyvsp[-5].node));
                add_children((yyval.node), (yyvsp[-1].node));
                }
#line 1963 "parser.tab.c"
    break;

  case 58: /* iterative: TK_PR_WHILE add_label_to_code '(' expression ')' add_cbr_while add_label_to_code command_block add_jumpI_end_while_block add_label_to_code  */
#line 289 "parser.y"
                                                                                                                                                      {
                (yyval.node) = create_node((yyvsp[-9].valor_lexico));
                add_children((yyval.node), (yyvsp[-6].node));
                add_children((yyval.node), (yyvsp[-2].node));
                }
#line 1973 "parser.tab.c"
    break;

  case 59: /* expression: expression TK_OC_OR expression_7  */
#line 297 "parser.y"
                                             {
                (yyval.node) = create_node((yyvsp[-1].valor_lexico));add_children((yyval.node), (yyvsp[-2].node));add_children((yyval.node), (yyvsp[0].node));
                
                (yyval.node)->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("or", (yyvsp[-2].node)->valor_lexico.temp, (yyvsp[0].node)->valor_lexico.temp, (yyval.node)->valor_lexico.temp);
                (yyval.node)->valor_lexico.code = addInstruction(instruction);
                }
#line 1987 "parser.tab.c"
    break;

  case 60: /* expression: expression_7  */
#line 306 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 1993 "parser.tab.c"
    break;

  case 61: /* expression_7: expression_7 TK_OC_AND expression_6  */
#line 308 "parser.y"
                                                  {
                (yyval.node) = create_node((yyvsp[-1].valor_lexico));add_children((yyval.node), (yyvsp[-2].node));add_children((yyval.node), (yyvsp[0].node));
                
                (yyval.node)->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("and", (yyvsp[-2].node)->valor_lexico.temp, (yyvsp[0].node)->valor_lexico.temp, (yyval.node)->valor_lexico.temp);
                (yyval.node)->valor_lexico.code = addInstruction(instruction);
                }
#line 2007 "parser.tab.c"
    break;

  case 62: /* expression_7: expression_6  */
#line 317 "parser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2013 "parser.tab.c"
    break;

  case 63: /* expression_6: expression_6 TK_OC_EQ expression_5  */
#line 319 "parser.y"
                                                 {
                (yyval.node) = create_node((yyvsp[-1].valor_lexico));add_children((yyval.node), (yyvsp[-2].node));add_children((yyval.node), (yyvsp[0].node));
                
                (yyval.node)->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("cmp_EQ", (yyvsp[-2].node)->valor_lexico.temp, (yyvsp[0].node)->valor_lexico.temp, (yyval.node)->valor_lexico.temp);
                (yyval.node)->valor_lexico.code = addInstruction(instruction);
                }
#line 2027 "parser.tab.c"
    break;

  case 64: /* expression_6: expression_6 TK_OC_NE expression_5  */
#line 328 "parser.y"
                                                 {
                (yyval.node) = create_node((yyvsp[-1].valor_lexico));add_children((yyval.node), (yyvsp[-2].node));add_children((yyval.node), (yyvsp[0].node));
                
                (yyval.node)->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("cmp_NE", (yyvsp[-2].node)->valor_lexico.temp, (yyvsp[0].node)->valor_lexico.temp, (yyval.node)->valor_lexico.temp);
                (yyval.node)->valor_lexico.code = addInstruction(instruction);
                }
#line 2041 "parser.tab.c"
    break;

  case 65: /* expression_6: expression_5  */
#line 337 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2047 "parser.tab.c"
    break;

  case 66: /* expression_5: expression_5 '<' expression_4  */
#line 339 "parser.y"
                                            {
                (yyval.node) = create_node((yyvsp[-1].valor_lexico));add_children((yyval.node), (yyvsp[-2].node));add_children((yyval.node), (yyvsp[0].node));
                
                (yyval.node)->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("cmp_LT", (yyvsp[-2].node)->valor_lexico.temp, (yyvsp[0].node)->valor_lexico.temp, (yyval.node)->valor_lexico.temp);
                (yyval.node)->valor_lexico.code = addInstruction(instruction);
                }
#line 2061 "parser.tab.c"
    break;

  case 67: /* expression_5: expression_5 '>' expression_4  */
#line 348 "parser.y"
                                            {
                (yyval.node) = create_node((yyvsp[-1].valor_lexico));add_children((yyval.node), (yyvsp[-2].node));add_children((yyval.node), (yyvsp[0].node));
                
                (yyval.node)->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("cmp_GT", (yyvsp[-2].node)->valor_lexico.temp, (yyvsp[0].node)->valor_lexico.temp, (yyval.node)->valor_lexico.temp);
                (yyval.node)->valor_lexico.code = addInstruction(instruction);
                }
#line 2075 "parser.tab.c"
    break;

  case 68: /* expression_5: expression_5 TK_OC_LE expression_4  */
#line 359 "parser.y"
                                                 {
                (yyval.node) = create_node((yyvsp[-1].valor_lexico));add_children((yyval.node), (yyvsp[-2].node));add_children((yyval.node), (yyvsp[0].node));
                
                (yyval.node)->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("cmp_LE", (yyvsp[-2].node)->valor_lexico.temp, (yyvsp[0].node)->valor_lexico.temp, (yyval.node)->valor_lexico.temp);
                (yyval.node)->valor_lexico.code = addInstruction(instruction);
                }
#line 2089 "parser.tab.c"
    break;

  case 69: /* expression_5: expression_5 TK_OC_GE expression_4  */
#line 370 "parser.y"
                                                 {
                (yyval.node) = create_node((yyvsp[-1].valor_lexico));add_children((yyval.node), (yyvsp[-2].node));add_children((yyval.node), (yyvsp[0].node));
                
                (yyval.node)->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("cmp_GE", (yyvsp[-2].node)->valor_lexico.temp, (yyvsp[0].node)->valor_lexico.temp, (yyval.node)->valor_lexico.temp);
                (yyval.node)->valor_lexico.code = addInstruction(instruction);
                }
#line 2103 "parser.tab.c"
    break;

  case 70: /* expression_5: expression_4  */
#line 380 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2109 "parser.tab.c"
    break;

  case 71: /* expression_4: expression_4 '+' expression_3  */
#line 382 "parser.y"
                                            {
                        // add node
                        (yyval.node) = create_node((yyvsp[-1].valor_lexico));add_children((yyval.node), (yyvsp[-2].node));add_children((yyval.node), (yyvsp[0].node));
                        
                        // add code
                        (yyval.node)->valor_lexico.temp = current_temp;
                        cbr_temp = current_temp;
                        current_temp++;
                        Instruction *instruction = add_custom_instruction("add", (yyvsp[-2].node)->valor_lexico.temp, (yyvsp[0].node)->valor_lexico.temp, (yyval.node)->valor_lexico.temp);
                        (yyval.node)->valor_lexico.code = addInstruction(instruction);
                        }
#line 2125 "parser.tab.c"
    break;

  case 72: /* expression_4: expression_4 '-' expression_3  */
#line 394 "parser.y"
                                            {
                        (yyval.node) = create_node((yyvsp[-1].valor_lexico));add_children((yyval.node), (yyvsp[-2].node));add_children((yyval.node), (yyvsp[0].node));
                        
                        (yyval.node)->valor_lexico.temp = current_temp;
                        cbr_temp = current_temp;
                        current_temp++;
                        Instruction *instruction = add_custom_instruction("sub", (yyvsp[-2].node)->valor_lexico.temp, (yyvsp[0].node)->valor_lexico.temp, (yyval.node)->valor_lexico.temp);
                        (yyval.node)->valor_lexico.code = addInstruction(instruction);
                        }
#line 2139 "parser.tab.c"
    break;

  case 73: /* expression_4: expression_3  */
#line 405 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2145 "parser.tab.c"
    break;

  case 74: /* expression_3: expression_3 '*' expression_2  */
#line 407 "parser.y"
                                            {
                        (yyval.node) = create_node((yyvsp[-1].valor_lexico));add_children((yyval.node), (yyvsp[-2].node));add_children((yyval.node), (yyvsp[0].node));
                        
                        (yyval.node)->valor_lexico.temp = current_temp;
                        cbr_temp = current_temp;
                        current_temp++;
                        Instruction *instruction = add_custom_instruction("mult", (yyvsp[-2].node)->valor_lexico.temp, (yyvsp[0].node)->valor_lexico.temp, (yyval.node)->valor_lexico.temp);
                        (yyval.node)->valor_lexico.code = addInstruction(instruction);
                        
                        }
#line 2160 "parser.tab.c"
    break;

  case 75: /* expression_3: expression_3 '/' expression_2  */
#line 418 "parser.y"
                                            {
                        (yyval.node) = create_node((yyvsp[-1].valor_lexico));add_children((yyval.node), (yyvsp[-2].node));add_children((yyval.node), (yyvsp[0].node));
                        
                        (yyval.node)->valor_lexico.temp = current_temp;
                        cbr_temp = current_temp;
                        current_temp++;
                        Instruction *instruction = add_custom_instruction("div", (yyvsp[-2].node)->valor_lexico.temp, (yyvsp[0].node)->valor_lexico.temp, (yyval.node)->valor_lexico.temp);
                        (yyval.node)->valor_lexico.code = addInstruction(instruction);
                        }
#line 2174 "parser.tab.c"
    break;

  case 76: /* expression_3: expression_3 '%' expression_2  */
#line 428 "parser.y"
                                            {
                        (yyval.node) = create_node((yyvsp[-1].valor_lexico));add_children((yyval.node), (yyvsp[-2].node));add_children((yyval.node), (yyvsp[0].node));
                        }
#line 2182 "parser.tab.c"
    break;

  case 77: /* expression_3: expression_2  */
#line 431 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2188 "parser.tab.c"
    break;

  case 78: /* expression_2: '-' expression_1  */
#line 433 "parser.y"
                               {(yyval.node) = create_node((yyvsp[-1].valor_lexico)); add_children((yyval.node), (yyvsp[0].node));}
#line 2194 "parser.tab.c"
    break;

  case 79: /* expression_2: '!' expression_1  */
#line 434 "parser.y"
                              {(yyval.node) = create_node((yyvsp[-1].valor_lexico)); add_children((yyval.node), (yyvsp[0].node));}
#line 2200 "parser.tab.c"
    break;

  case 80: /* expression_2: expression_1  */
#line 435 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2206 "parser.tab.c"
    break;

  case 81: /* expression_1: TK_IDENTIFICADOR  */
#line 437 "parser.y"
                               {
                        Node *node = create_node((yyvsp[0].valor_lexico));
                        (yyval.node) = node;
                        (yyval.node)->valor_lexico.temp = current_temp;
                        cbr_temp = current_temp;
                        current_temp++;
                        // achar disp, percorer lista de tabelas da atual para tras
                        int disp = find_disp(nodo_atual, (yyval.node)->valor_lexico.valor);
                        char *base = find_base(nodo_atual, (yyval.node)->valor_lexico.valor);
                        Instruction *instruction = add_loadAI((yyval.node)->valor_lexico.temp, base, disp);
                        (yyval.node)->valor_lexico.code = addInstruction(instruction);
                        }
#line 2223 "parser.tab.c"
    break;

  case 82: /* expression_1: literal  */
#line 449 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);
                        Instruction *instruction_load = add_loadI((yyvsp[0].node)->valor_lexico.valor,(yyvsp[0].node)->valor_lexico.temp);
                        (yyval.node)->valor_lexico.code = addInstruction(instruction_load);
                        
                        
            }
#line 2234 "parser.tab.c"
    break;

  case 83: /* expression_1: function_call  */
#line 455 "parser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2240 "parser.tab.c"
    break;

  case 84: /* expression_1: '(' expression ')'  */
#line 456 "parser.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2246 "parser.tab.c"
    break;

  case 85: /* literal: TK_LIT_INT  */
#line 461 "parser.y"
                       {(yyval.node) = create_node((yyvsp[0].valor_lexico));
                        (yyval.node)->valor_lexico.temp = current_temp;
                        cbr_temp = current_temp;
                        current_temp = current_temp + 1;
                        
                        }
#line 2257 "parser.tab.c"
    break;

  case 86: /* literal: TK_LIT_FLOAT  */
#line 467 "parser.y"
                       {(yyval.node) = create_node((yyvsp[0].valor_lexico));}
#line 2263 "parser.tab.c"
    break;

  case 87: /* literal: TK_LIT_TRUE  */
#line 468 "parser.y"
                       {(yyval.node) = create_node((yyvsp[0].valor_lexico));}
#line 2269 "parser.tab.c"
    break;

  case 88: /* literal: TK_LIT_FALSE  */
#line 469 "parser.y"
                       {(yyval.node) = create_node((yyvsp[0].valor_lexico));}
#line 2275 "parser.tab.c"
    break;

  case 89: /* type: TK_PR_INT  */
#line 473 "parser.y"
                        { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2281 "parser.tab.c"
    break;

  case 90: /* type: TK_PR_FLOAT  */
#line 474 "parser.y"
                        { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2287 "parser.tab.c"
    break;

  case 91: /* type: TK_PR_BOOL  */
#line 475 "parser.y"
                        { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2293 "parser.tab.c"
    break;


#line 2297 "parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 477 "parser.y"


void yyerror (char const *s){
    fprintf(stderr, "Error on line %d: %s\n", yylineno, s);
}
