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
#line 1 "limbaj.y"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>
#include "structures.h"

using namespace std;

void yyerror(const char *s);
extern int yylex();
extern int yylineno;

//manager global de tabele de simboluri
SymbolTableManager manager;

//variabile ajutatoare pentru verificare parametrii functii

vector<string> declParams; //tipul parametrilor la declarare
vector<string> callArgs; // tipul argumentelor la apel

char* lastFuncName = nullptr; // retinem numele functiei curente pt a-i adauga parametrii



#line 100 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_VAL = 258,                 /* INT_VAL  */
    FLOAT_VAL = 259,               /* FLOAT_VAL  */
    STRING_VAL = 260,              /* STRING_VAL  */
    ID = 261,                      /* ID  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    STRING = 264,                  /* STRING  */
    BOOL = 265,                    /* BOOL  */
    CLASS = 266,                   /* CLASS  */
    VOID = 267,                    /* VOID  */
    RETURN = 268,                  /* RETURN  */
    MAIN = 269,                    /* MAIN  */
    PRINT = 270,                   /* PRINT  */
    IF = 271,                      /* IF  */
    ELSE = 272,                    /* ELSE  */
    WHILE = 273,                   /* WHILE  */
    BOOL_TRUE = 274,               /* BOOL_TRUE  */
    BOOL_FALSE = 275,              /* BOOL_FALSE  */
    ASSIGN = 276,                  /* ASSIGN  */
    EQ = 277,                      /* EQ  */
    NEQ = 278,                     /* NEQ  */
    LEQ = 279,                     /* LEQ  */
    GEQ = 280,                     /* GEQ  */
    AND = 281,                     /* AND  */
    OR = 282                       /* OR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT_VAL 258
#define FLOAT_VAL 259
#define STRING_VAL 260
#define ID 261
#define INT 262
#define FLOAT 263
#define STRING 264
#define BOOL 265
#define CLASS 266
#define VOID 267
#define RETURN 268
#define MAIN 269
#define PRINT 270
#define IF 271
#define ELSE 272
#define WHILE 273
#define BOOL_TRUE 274
#define BOOL_FALSE 275
#define ASSIGN 276
#define EQ 277
#define NEQ 278
#define LEQ 279
#define GEQ 280
#define AND 281
#define OR 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "limbaj.y"


    int int_val;
    float float_val;
    char* str_val;



#line 216 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_VAL = 3,                    /* INT_VAL  */
  YYSYMBOL_FLOAT_VAL = 4,                  /* FLOAT_VAL  */
  YYSYMBOL_STRING_VAL = 5,                 /* STRING_VAL  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_STRING = 9,                     /* STRING  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_CLASS = 11,                     /* CLASS  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_MAIN = 14,                      /* MAIN  */
  YYSYMBOL_PRINT = 15,                     /* PRINT  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_BOOL_TRUE = 19,                 /* BOOL_TRUE  */
  YYSYMBOL_BOOL_FALSE = 20,                /* BOOL_FALSE  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_NEQ = 23,                       /* NEQ  */
  YYSYMBOL_LEQ = 24,                       /* LEQ  */
  YYSYMBOL_GEQ = 25,                       /* GEQ  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '.'  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_progr = 42,                     /* progr  */
  YYSYMBOL_declarations = 43,              /* declarations  */
  YYSYMBOL_decl = 44,                      /* decl  */
  YYSYMBOL_type = 45,                      /* type  */
  YYSYMBOL_class_decl = 46,                /* class_decl  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_class_body = 48,                /* class_body  */
  YYSYMBOL_var_decl = 49,                  /* var_decl  */
  YYSYMBOL_func_decl = 50,                 /* func_decl  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_param_list = 53,                /* param_list  */
  YYSYMBOL_params = 54,                    /* params  */
  YYSYMBOL_func_body = 55,                 /* func_body  */
  YYSYMBOL_main_block = 56,                /* main_block  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_statement_list = 58,            /* statement_list  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_assignment = 60,                /* assignment  */
  YYSYMBOL_if_statement = 61,              /* if_statement  */
  YYSYMBOL_else_statement = 62,            /* else_statement  */
  YYSYMBOL_while_statement = 63,           /* while_statement  */
  YYSYMBOL_print_statement = 64,           /* print_statement  */
  YYSYMBOL_func_call = 65,                 /* func_call  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_args = 67,                      /* args  */
  YYSYMBOL_args_list = 68,                 /* args_list  */
  YYSYMBOL_expr = 69                       /* expr  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
      38,    39,    32,    30,    40,    31,    34,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      28,     2,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    92,    93,    98,    99,   100,   107,   108,
     109,   110,   111,   112,   117,   116,   136,   137,   138,   144,
     149,   158,   171,   157,   187,   188,   192,   200,   209,   210,
     211,   218,   217,   230,   231,   235,   236,   237,   238,   239,
     240,   241,   248,   253,   275,   315,   318,   321,   324,   330,
     329,   379,   384,   385,   390,   391,   394,   395,   396,   397,
     398,   399,   414,   426,   427,   437,   446,   455,   464,   473,
     482,   491,   500,   509,   518,   527,   536
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
  "\"end of file\"", "error", "\"invalid token\"", "INT_VAL", "FLOAT_VAL",
  "STRING_VAL", "ID", "INT", "FLOAT", "STRING", "BOOL", "CLASS", "VOID",
  "RETURN", "MAIN", "PRINT", "IF", "ELSE", "WHILE", "BOOL_TRUE",
  "BOOL_FALSE", "ASSIGN", "EQ", "NEQ", "LEQ", "GEQ", "AND", "OR", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'.'", "'{'", "'}'", "';'", "'('",
  "')'", "','", "$accept", "progr", "declarations", "decl", "type",
  "class_decl", "$@1", "class_body", "var_decl", "func_decl", "$@2", "$@3",
  "param_list", "params", "func_body", "main_block", "$@4",
  "statement_list", "statement", "assignment", "if_statement",
  "else_statement", "while_statement", "print_statement", "func_call",
  "$@5", "args", "args_list", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -41,     5,   271,   -41,   -41,   -41,   -41,   -41,   -41,     8,
     -41,   -41,   -41,     9,   -41,   -41,   -41,   -41,   -41,   -18,
      -8,    -5,   -41,    28,   -41,   -11,   -41,    71,   -41,   -41,
     -41,   -28,   -41,   -41,    28,   -41,   189,   280,    13,   -10,
      28,    17,    21,   103,    36,   -41,   -41,   -41,    38,   -41,
     -41,   -41,    39,    41,    73,   -41,   117,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,   -41,
      76,    44,    45,   -41,   -41,   -41,    28,    89,   205,    28,
      28,   -41,    28,    95,   -41,   -41,   -41,    61,    28,   -41,
     243,   243,    20,    20,   104,   233,    20,    20,   -25,   -25,
     -41,   -41,   -41,   -41,   280,   221,   -12,   -41,   135,   153,
     171,   -41,    28,    64,    60,   221,    69,   108,    28,   -41,
     103,   103,    78,   -41,    28,   -41,   -41,   221,   -41,   -41,
     -41,   221,    55,   -10,   -41,   109,   -41,   -41,    -8
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,    13,     8,     9,    11,    10,     0,
      12,    31,     4,     0,     6,     5,     7,     2,    14,     0,
      21,     0,    33,     0,    19,     0,    16,     0,    56,    57,
      58,    61,    59,    60,     0,    63,     0,    24,     0,     0,
       0,     0,     0,     0,     0,    33,    32,    34,     0,    36,
      37,    38,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,    25,    15,    17,    18,     0,     0,     0,     0,
       0,    46,     0,     0,    35,    39,    40,    62,    52,    76,
      72,    73,    70,    71,    74,    75,    68,    69,    64,    65,
      66,    67,    26,    22,     0,    43,     0,    41,     0,     0,
       0,    42,    52,     0,    53,    54,     0,     0,     0,    48,
       0,     0,     0,    50,     0,    28,    27,    44,    45,    47,
      51,    55,     0,    13,    23,     0,    29,    30,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -41,   -41,   -35,   -41,   -41,   -41,   -34,    84,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,    79,   -40,   -41,
     -41,   -41,   -41,   -41,   -27,   -41,    11,   -41,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    12,    13,    14,    21,    38,    15,    16,
      25,   116,    71,    72,   132,    17,    19,    27,    47,    48,
      49,    50,    51,    52,    35,    88,   113,   114,   115
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      53,    36,    70,    81,    74,     3,    54,    67,    68,   118,
      55,    76,    56,    23,    18,    20,    53,    22,    78,     4,
       5,     6,     7,     8,    77,    10,   112,    37,    55,    24,
      26,    28,    29,    30,    31,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    32,    33,    73,
      65,    66,    67,    68,   105,    79,    53,   108,   109,    80,
     110,   133,     5,     6,     7,     8,    34,    10,    40,   117,
      41,    42,    43,    44,    82,    84,    85,    39,    86,    87,
     128,   129,   102,   103,    40,   104,    41,    42,    43,    44,
      45,   134,   137,    53,    53,   106,   127,   135,   136,   112,
     124,    39,   131,   123,   125,    53,    45,    46,    40,    39,
      41,    42,    43,    44,   126,   138,    40,   130,    41,    42,
      43,    44,    75,   122,    83,     0,    57,    58,    59,    60,
      45,   111,    63,    64,    65,    66,    67,    68,    45,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,     0,     0,     0,     0,    89,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
       0,     0,     0,     0,   119,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,     0,     0,
       0,     0,   120,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,     0,     0,     0,     0,
     121,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,     0,     0,    69,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
       0,     0,   107,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    57,    58,    59,    60,    61,
       0,    63,    64,    65,    66,    67,    68,    59,    60,     0,
       0,    63,    64,    65,    66,    67,    68,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     4,     5,     6,     7,
       8,     0,    10
};

static const yytype_int16 yycheck[] =
{
      27,    23,    37,    43,    38,     0,    34,    32,    33,    21,
      38,    21,    34,    21,     6,     6,    43,    35,    40,     6,
       7,     8,     9,    10,    34,    12,    38,    38,    38,    37,
      35,     3,     4,     5,     6,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    19,    20,    36,
      30,    31,    32,    33,    76,    38,    83,    79,    80,    38,
      82,     6,     7,     8,     9,    10,    38,    12,    13,   104,
      15,    16,    17,    18,    38,    37,    37,     6,    37,     6,
     120,   121,     6,    39,    13,    40,    15,    16,    17,    18,
      35,    36,   132,   120,   121,     6,   118,   132,   132,    38,
      40,     6,   124,    39,    35,   132,    35,    36,    13,     6,
      15,    16,    17,    18,     6,     6,    13,    39,    15,    16,
      17,    18,    38,   112,    45,    -1,    22,    23,    24,    25,
      35,    36,    28,    29,    30,    31,    32,    33,    35,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    39,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    39,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    39,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      39,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    37,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    37,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    22,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    24,    25,    -1,
      -1,    28,    29,    30,    31,    32,    33,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,     6,     7,     8,     9,
      10,    -1,    12
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,     0,     6,     7,     8,     9,    10,    11,
      12,    14,    44,    45,    46,    49,    50,    56,     6,    57,
       6,    47,    35,    21,    37,    51,    35,    58,     3,     4,
       5,     6,    19,    20,    38,    65,    69,    38,    48,     6,
      13,    15,    16,    17,    18,    35,    36,    59,    60,    61,
      62,    63,    64,    65,    34,    38,    69,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    37,
      45,    53,    54,    36,    49,    50,    21,    34,    69,    38,
      38,    59,    38,    58,    37,    37,    37,     6,    66,    39,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,     6,    39,    40,    69,     6,    37,    69,    69,
      69,    36,    38,    67,    68,    69,    52,    45,    21,    39,
      39,    39,    67,    39,    40,    35,     6,    69,    59,    59,
      39,    69,    55,     6,    36,    45,    49,    59,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    45,    45,
      45,    45,    45,    45,    47,    46,    48,    48,    48,    49,
      49,    51,    52,    50,    53,    53,    54,    54,    55,    55,
      55,    57,    56,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    62,    63,    64,    66,
      65,    65,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     0,     2,     2,     3,
       5,     0,     0,    10,     0,     1,     2,     4,     0,     2,
       2,     0,     5,     0,     2,     2,     1,     1,     1,     2,
       2,     3,     3,     3,     5,     5,     2,     5,     4,     0,
       5,     6,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3
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
  case 2: /* progr: declarations main_block  */
#line 82 "limbaj.y"
      { 
        printf("Sintaxa corecta!\n"); 
        // La final printam tabelele
        manager.printAllTables("tables.txt");  
      }
#line 1388 "y.tab.c"
    break;

  case 8: /* type: INT  */
#line 107 "limbaj.y"
           { (yyval.str_val) = strdup("int"); }
#line 1394 "y.tab.c"
    break;

  case 9: /* type: FLOAT  */
#line 108 "limbaj.y"
             { (yyval.str_val) = strdup("float"); }
#line 1400 "y.tab.c"
    break;

  case 10: /* type: BOOL  */
#line 109 "limbaj.y"
            { (yyval.str_val) = strdup("bool"); }
#line 1406 "y.tab.c"
    break;

  case 11: /* type: STRING  */
#line 110 "limbaj.y"
              { (yyval.str_val) = strdup("string"); }
#line 1412 "y.tab.c"
    break;

  case 12: /* type: VOID  */
#line 111 "limbaj.y"
            { (yyval.str_val) = strdup("void"); }
#line 1418 "y.tab.c"
    break;

  case 13: /* type: ID  */
#line 112 "limbaj.y"
          { (yyval.str_val) = (yyvsp[0].str_val); }
#line 1424 "y.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 117 "limbaj.y"
            { 
                manager.addClass((yyvsp[0].str_val)); // adaugam simbolul clasei in Global
                manager.enterScope((yyvsp[0].str_val)); // intram in scope-ul clasei

                // Salvam scope-ul ca sa putem verifica obj.proprietate mai tarziu
                manager.saveClassScope((yyvsp[0].str_val));
            }
#line 1436 "y.tab.c"
    break;

  case 15: /* class_decl: CLASS ID $@1 '{' class_body '}'  */
#line 127 "limbaj.y"
            {
                manager.exitScope(); // iesim din scope-ul clasei

            }
#line 1445 "y.tab.c"
    break;

  case 19: /* var_decl: type ID ';'  */
#line 145 "limbaj.y"
           {
             manager.addVariable((yyvsp[-1].str_val),(yyvsp[-2].str_val));
           }
#line 1453 "y.tab.c"
    break;

  case 20: /* var_decl: type ID ASSIGN expr ';'  */
#line 150 "limbaj.y"
           {
            manager.addVariable((yyvsp[-3].str_val), (yyvsp[-4].str_val));
           }
#line 1461 "y.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 158 "limbaj.y"
          {

            manager.addFunction((yyvsp[0].str_val),(yyvsp[-1].str_val)); // adaugam functia in parinte
            manager.enterScope((yyvsp[0].str_val)); // intram in scope-ul functiei

            lastFuncName = strdup((yyvsp[0].str_val)); // tinem minte numele functiei

            declParams.clear(); // resetam lista de parametrii

          }
#line 1476 "y.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 171 "limbaj.y"
          {

            // dupa de am citit parametrii, actualizam semnatura functiei in SymbolTable
            manager.currentScope->parent->symbols.at(lastFuncName).paramTypes = declParams;

          }
#line 1487 "y.tab.c"
    break;

  case 23: /* func_decl: type ID $@2 '(' param_list ')' $@3 '{' func_body '}'  */
#line 180 "limbaj.y"
          {

            manager.exitScope(); //iesim din scope-ul functiei
          }
#line 1496 "y.tab.c"
    break;

  case 26: /* params: type ID  */
#line 193 "limbaj.y"
        {

            manager.addVariable((yyvsp[0].str_val),(yyvsp[-1].str_val));
            declParams.push_back((yyvsp[-1].str_val)); // adaugam tipul in lista

        }
#line 1507 "y.tab.c"
    break;

  case 27: /* params: params ',' type ID  */
#line 201 "limbaj.y"
       {
            manager.addVariable((yyvsp[0].str_val),(yyvsp[-1].str_val));
            declParams.push_back((yyvsp[-1].str_val));
       }
#line 1516 "y.tab.c"
    break;

  case 31: /* $@4: %empty  */
#line 218 "limbaj.y"
            {
                manager.enterScope("Main");
            }
#line 1524 "y.tab.c"
    break;

  case 32: /* main_block: MAIN $@4 '{' statement_list '}'  */
#line 222 "limbaj.y"
            {
                manager.exitScope();
            }
#line 1532 "y.tab.c"
    break;

  case 41: /* statement: RETURN expr ';'  */
#line 243 "limbaj.y"
            {
                // aici am putea verifica daca tipul returnat corespunde cu cel al functeii

            }
#line 1541 "y.tab.c"
    break;

  case 43: /* assignment: ID ASSIGN expr  */
#line 255 "limbaj.y"
             {
                
                string typeId = manager.getTypeOf((yyvsp[-2].str_val));
                if (typeId == "error") 
                {
                    char err[100]; 
                    sprintf(err,"Variabila '%s' nu este definita.", (yyvsp[-2].str_val));
                    yyerror(err);
                    exit(1);
                }

                if (typeId != string((yyvsp[0].str_val))) 
                {
                    char err[100]; 
                    sprintf(err,"Tipuri incompatibile la atribuire: '%s' vs '%s'", typeId.c_str(), (yyvsp[0].str_val));
                    yyerror(err);
                    exit(1);
                }

             }
#line 1566 "y.tab.c"
    break;

  case 44: /* assignment: ID '.' ID ASSIGN expr  */
#line 278 "limbaj.y"
           {
                // verificam obj.prop

                string typeObj = manager.getTypeOf((yyvsp[-4].str_val)); // ex: Dreptunghi
                string typeMember = manager.getClassMemberType(typeObj, (yyvsp[-2].str_val));

                if (typeMember == "error_no_class") 
                {
                    char err[100]; 
                    sprintf(err,"Variabila '%s' nu este un obiect sau clasa nu exista.", (yyvsp[-4].str_val));
                    yyerror(err);
                    exit(1);
                }

                if (typeMember == "error_no_member")
                {
                    char err[100]; 
                    sprintf(err,"Clasa '%s' nu are membrul '%s'.", typeObj.c_str(), (yyvsp[-2].str_val));
                    yyerror(err);
                    exit(1);
                }

                if (typeMember != string((yyvsp[0].str_val))) 
                {
                    char err[100]; 
                    sprintf(err,"Tip incorect la atribuirea membrului: '%s' vs '%s'", typeMember.c_str(), (yyvsp[0].str_val));
                    yyerror(err);
                    exit(1);


                }


           }
#line 1605 "y.tab.c"
    break;

  case 49: /* $@5: %empty  */
#line 330 "limbaj.y"
            {
                callArgs.clear(); // resetam argumentele inainte de a parsa
            }
#line 1613 "y.tab.c"
    break;

  case 50: /* func_call: ID '(' $@5 args ')'  */
#line 336 "limbaj.y"
            {

                SymbolInfo* func = manager.lookupSymbol((yyvsp[-4].str_val));

                if(!func || func->kind != "function")
                {
                    char err[100]; 
                    sprintf(err,"Functia '%s' nu este definita.", (yyvsp[-4].str_val));
                    yyerror(err);
                    exit(1);
                }

                // verificare nr parametri

                if(func->paramTypes.size() != callArgs.size())
                {
                    char err[100]; 
                    sprintf(err,"Functia '%s' asteapta %lu argumente, dar a primit %lu.", (yyvsp[-4].str_val), func->paramTypes.size(), callArgs.size());
                    yyerror(err);
                    exit(1);
                }

                // verificare tipuri parametrii 

                for(size_t i=0; i<callArgs.size(); ++i)
                {

                    if(func->paramTypes[i] != callArgs[i])
                    {

                        char err[100]; 
                        sprintf(err,"Argumentul %lu la functia '%s' are tip gresit (%s vs %s).", i+1, (yyvsp[-4].str_val), callArgs[i].c_str(), func->paramTypes[i].c_str());
                        yyerror(err);
                        exit(1);

                    }

                }

                // returnam tipul functiei (pentru a fi folosin in expresii)
                (yyval.str_val) = strdup(func->type.c_str());

            }
#line 1661 "y.tab.c"
    break;

  case 54: /* args_list: expr  */
#line 390 "limbaj.y"
                 { callArgs.push_back((yyvsp[0].str_val)); }
#line 1667 "y.tab.c"
    break;

  case 55: /* args_list: args_list ',' expr  */
#line 391 "limbaj.y"
                               { callArgs.push_back((yyvsp[0].str_val)); }
#line 1673 "y.tab.c"
    break;

  case 56: /* expr: INT_VAL  */
#line 394 "limbaj.y"
               { (yyval.str_val) = strdup("int"); }
#line 1679 "y.tab.c"
    break;

  case 57: /* expr: FLOAT_VAL  */
#line 395 "limbaj.y"
                 { (yyval.str_val) = strdup("float"); }
#line 1685 "y.tab.c"
    break;

  case 58: /* expr: STRING_VAL  */
#line 396 "limbaj.y"
                  { (yyval.str_val) = strdup("string"); }
#line 1691 "y.tab.c"
    break;

  case 59: /* expr: BOOL_TRUE  */
#line 397 "limbaj.y"
                 { (yyval.str_val) = strdup("bool"); }
#line 1697 "y.tab.c"
    break;

  case 60: /* expr: BOOL_FALSE  */
#line 398 "limbaj.y"
                  { (yyval.str_val) = strdup("bool"); }
#line 1703 "y.tab.c"
    break;

  case 61: /* expr: ID  */
#line 400 "limbaj.y"
       {

            string t = manager.getTypeOf((yyvsp[0].str_val));

            if(t == "error")
            {
                char err[100]; 
                sprintf(err,"Variabila '%s' folosita nedeclarata.", (yyvsp[0].str_val));
                yyerror(err);
                exit(1);
            }

            (yyval.str_val) = strdup(t.c_str());
       }
#line 1722 "y.tab.c"
    break;

  case 62: /* expr: ID '.' ID  */
#line 415 "limbaj.y"
       {
            string tObj = manager.getTypeOf((yyvsp[-2].str_val));
            string tMem = manager.getClassMemberType(tObj, (yyvsp[0].str_val));
            if (tMem.find("error") != string::npos )
            {
                yyerror("Acces invalid la membru de clasa.");
                exit(1);
            }

            (yyval.str_val) = strdup(tMem.c_str());
       }
#line 1738 "y.tab.c"
    break;

  case 63: /* expr: func_call  */
#line 426 "limbaj.y"
                 { (yyval.str_val) = (yyvsp[0].str_val); }
#line 1744 "y.tab.c"
    break;

  case 64: /* expr: expr '+' expr  */
#line 428 "limbaj.y"
        {
            if (strcmp((yyvsp[-2].str_val) , (yyvsp[0].str_val)) != 0)
            {
                yyerror("Tipuri diferite la adunare.");
                exit(1);
            }
            (yyval.str_val) = (yyvsp[-2].str_val);
        }
#line 1757 "y.tab.c"
    break;

  case 65: /* expr: expr '-' expr  */
#line 438 "limbaj.y"
        {
            if (strcmp((yyvsp[-2].str_val) , (yyvsp[0].str_val)) != 0)
            {
                yyerror("Tipuri diferite la scadere.");
                exit(1);
            }
            (yyval.str_val) = (yyvsp[-2].str_val);
        }
#line 1770 "y.tab.c"
    break;

  case 66: /* expr: expr '*' expr  */
#line 447 "limbaj.y"
        {
            if (strcmp((yyvsp[-2].str_val) , (yyvsp[0].str_val)) != 0)
            {
                yyerror("Tipuri diferite la inmultire.");
                exit(1);
            }
            (yyval.str_val) = (yyvsp[-2].str_val);
        }
#line 1783 "y.tab.c"
    break;

  case 67: /* expr: expr '/' expr  */
#line 456 "limbaj.y"
        {
            if (strcmp((yyvsp[-2].str_val) , (yyvsp[0].str_val)) != 0)
            {
                yyerror("Tipuri diferite la impartire.");
                exit(1);
            }
            (yyval.str_val) = (yyvsp[-2].str_val);
        }
#line 1796 "y.tab.c"
    break;

  case 68: /* expr: expr '<' expr  */
#line 465 "limbaj.y"
        {
            if (strcmp((yyvsp[-2].str_val) , (yyvsp[0].str_val)) != 0)
            {
                yyerror("Tipuri diferite la <.");
                exit(1);
            }
            (yyval.str_val) = (yyvsp[-2].str_val);
        }
#line 1809 "y.tab.c"
    break;

  case 69: /* expr: expr '>' expr  */
#line 474 "limbaj.y"
     {
            if (strcmp((yyvsp[-2].str_val) , (yyvsp[0].str_val)) != 0)
            {
                yyerror("Tipuri diferite la >.");
                exit(1);
            }
            (yyval.str_val) = (yyvsp[-2].str_val);
        }
#line 1822 "y.tab.c"
    break;

  case 70: /* expr: expr LEQ expr  */
#line 483 "limbaj.y"
     {
            if (strcmp((yyvsp[-2].str_val) , (yyvsp[0].str_val)) != 0)
            {
                yyerror("Tipuri diferite la LEQ.");
                exit(1);
            }
            (yyval.str_val) = (yyvsp[-2].str_val);
        }
#line 1835 "y.tab.c"
    break;

  case 71: /* expr: expr GEQ expr  */
#line 492 "limbaj.y"
        {
            if (strcmp((yyvsp[-2].str_val) , (yyvsp[0].str_val)) != 0)
            {
                yyerror("Tipuri diferite la GEQ.");
                exit(1);
            }
            (yyval.str_val) = (yyvsp[-2].str_val);
        }
#line 1848 "y.tab.c"
    break;

  case 72: /* expr: expr EQ expr  */
#line 501 "limbaj.y"
     {
            if (strcmp((yyvsp[-2].str_val) , (yyvsp[0].str_val)) != 0)
            {
                yyerror("Tipuri diferite la EQ.");
                exit(1);
            }
            (yyval.str_val) = (yyvsp[-2].str_val);
        }
#line 1861 "y.tab.c"
    break;

  case 73: /* expr: expr NEQ expr  */
#line 510 "limbaj.y"
        {
            if (strcmp((yyvsp[-2].str_val) , (yyvsp[0].str_val)) != 0)
            {
                yyerror("Tipuri diferite la NEQ.");
                exit(1);
            }
            (yyval.str_val) = (yyvsp[-2].str_val);
        }
#line 1874 "y.tab.c"
    break;

  case 74: /* expr: expr AND expr  */
#line 519 "limbaj.y"
     {
            if (strcmp((yyvsp[-2].str_val) , (yyvsp[0].str_val)) != 0)
            {
                yyerror("Tipuri diferite la AND.");
                exit(1);
            }
            (yyval.str_val) = (yyvsp[-2].str_val);
        }
#line 1887 "y.tab.c"
    break;

  case 75: /* expr: expr OR expr  */
#line 528 "limbaj.y"
     {
            if (strcmp((yyvsp[-2].str_val) , (yyvsp[0].str_val)) != 0)
            {
                yyerror("Tipuri diferite la OR.");
                exit(1);
            }
            (yyval.str_val) = (yyvsp[-2].str_val);
        }
#line 1900 "y.tab.c"
    break;

  case 76: /* expr: '(' expr ')'  */
#line 536 "limbaj.y"
                    { (yyval.str_val) = (yyvsp[-1].str_val); }
#line 1906 "y.tab.c"
    break;


#line 1910 "y.tab.c"

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

#line 539 "limbaj.y"


void yyerror(const char *s) {
    fprintf(stderr, "Eroare la linia %d: %s\n", yylineno, s);
}

int main (int argc, char* argv[]) {

    yyparse();
    return 0;


}


