/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     pub = 258,
     pri = 259,
     voi = 260,
     pl = 261,
     mi = 262,
     di = 263,
     mo = 264,
     cla = 265,
     identifier = 266,
     thi = 267,
     def = 268,
     boo = 269,
     flo = 270,
     lon = 271,
     sho = 272,
     ing = 273,
     cha = 274,
     byt = 275,
     dou = 276,
     equ = 277,
     sta = 278,
     new = 279,
     import = 280,
     comma = 281,
     cirbral = 282,
     cirbrar = 283,
     curbral = 284,
     curbrar = 285,
     dot = 286,
     colon = 287,
     semicolon = 288,
     star = 289,
     sqr = 290,
     sql = 291,
     ths = 292,
     protect = 293,
     abst = 294,
     fin = 295,
     imp = 296,
     pack = 297,
     ext = 298,
     inter = 299
   };
#endif
#define pub 258
#define pri 259
#define voi 260
#define pl 261
#define mi 262
#define di 263
#define mo 264
#define cla 265
#define identifier 266
#define thi 267
#define def 268
#define boo 269
#define flo 270
#define lon 271
#define sho 272
#define ing 273
#define cha 274
#define byt 275
#define dou 276
#define equ 277
#define sta 278
#define new 279
#define import 280
#define comma 281
#define cirbral 282
#define cirbrar 283
#define curbral 284
#define curbrar 285
#define dot 286
#define colon 287
#define semicolon 288
#define star 289
#define sqr 290
#define sql 291
#define ths 292
#define protect 293
#define abst 294
#define fin 295
#define imp 296
#define pack 297
#define ext 298
#define inter 299




/* Copy the first part of user declarations.  */
#line 3 "vv1.y"

 #include<stdio.h>
 #define  z 20    /*maximum size of identifier(userdefined)*/
 #define fz 30    /*maximum size of filename(java source)*/
 #define nvil 10  /* number of variables in line */
 #include <dirent.h>

 char javasource[20][100];               /*to store the absolute path of java source files in the given java project*/
 FILE *fop,*syt;                         /* File Pointers*/
 int js=0;                               /*for java source indexing*/
 char fname[fz];                         /*To store the extracted filename from java source absolute path*/
 char name[z];                           /*To store the name of variables,class names etc*/
 char access[10];                        /*To store the access specifier*/
 char isstatic[10];                      /*To store the Static status of instance*/
 char rettype[10],isstatic1[10];         /*To store the return type and static status of method*/
 int  ais=0i,ais1=0,l=0;                 /*for indexing the arrays*/
 char classname[z];                      /*To store the name of class*/
 char array[nvil][z];
 char array2[nvil][z];
 char array1[z];
 int flagm=1;
 int flagv=1;
 int flagp=1;
 int flagl=1;
 void function(char *a);
 void PrintAndProcess();

 	/* The Structures Employed are as listed below */

		struct cll  				/*structure for classes*/
				{
				char name[z];
				char access[10];
				char filename[fz];
				int cnt;
				struct cll *next;
				} *chead,*ctemp;
		struct mfll				/*structure for member functions*/
				{
				char name[z];
				char access[10];
                        	char isstatic[10];
				char rettype[z];
				int  iscon;
				char classname[z];
                        	char filename[fz];
                        	int  cnt;
				int flag;
                        	struct mfll *next;
				} *mfhead,*mftemp;
		struct fpll				/*structure for function parameters*/
				{
				char name[z];
				char type[z];
				char functionname[z];
				char classname[z];
                        	char filename[fz];
                        	int cnt;
				int flag;
                        	struct fpll *next;
				} *fphead,*fptemp;
		struct lvll				/*structure for local variables of function*/
				{
				char name[z];
				char isstatic[10];
				char type[z];
                        	char functionname[z];
                        	char classname[z];
                        	char filename[fz];
                        	int cnt;
				int flag;
                        	struct lvll *next;
				} *lvhead,*lvtemp;
		struct mvll				/*structure for member variables of class*/
				{
				char name[z];
                        	char access[10];
				char isstatic[10];
				char type[z];
                        	char classname[z];
                        	char filename[fz];
                        	int cnt;
				int flag;
                        	struct mvll *next;
				} *mvhead,*mvtemp;
		


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 262 "vv1.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   441

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  55
/* YYNRULES -- Number of rules. */
#define YYNRULES  165
/* YYNRULES -- Number of states. */
#define YYNSTATES  289

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     4,     8,    11,    14,    17,    19,    21,
      23,    27,    29,    33,    35,    38,    40,    42,    44,    46,
      50,    56,    63,    70,    72,    76,    78,    81,    87,    94,
      99,   105,   110,   116,   120,   125,   128,   133,   136,   138,
     142,   144,   146,   150,   153,   155,   158,   160,   162,   164,
     166,   168,   170,   172,   176,   179,   181,   184,   186,   188,
     190,   192,   194,   196,   198,   200,   202,   204,   206,   208,
     210,   212,   214,   216,   218,   222,   225,   230,   234,   238,
     248,   257,   266,   278,   289,   300,   302,   306,   308,   311,
     315,   319,   325,   330,   336,   343,   351,   356,   358,   362,
     365,   367,   370,   374,   378,   380,   382,   384,   386,   388,
     390,   395,   399,   409,   418,   430,   441,   443,   447,   448,
     450,   452,   456,   458,   461,   465,   469,   471,   473,   475,
     478,   482,   485,   488,   490,   492,   494,   496,   498,   500,
     502,   504,   506,   508,   510,   512,   514,   516,   518,   521,
     523,   525,   529,   531,   535,   539,   541,   543,   547,   549,
     552,   556,   559,   563,   566,   569
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      46,     0,    -1,    -1,    47,    49,    56,    -1,    49,    56,
      -1,    47,    56,    -1,    47,    49,    -1,    47,    -1,    49,
      -1,    56,    -1,    42,    48,    33,    -1,    11,    -1,    48,
      31,    11,    -1,    50,    -1,    49,    50,    -1,    51,    -1,
      52,    -1,    53,    -1,    54,    -1,    25,    55,    33,    -1,
      25,    55,    31,    34,    33,    -1,    25,    23,    55,    31,
      11,    33,    -1,    25,    23,    55,    31,    34,    33,    -1,
      11,    -1,    55,    31,    11,    -1,    57,    -1,    56,    57,
      -1,    60,     3,    10,    11,    61,    -1,    60,     3,    10,
      11,    58,    61,    -1,    60,    10,    11,    61,    -1,    60,
      10,    11,    58,    61,    -1,     3,    10,    11,    61,    -1,
       3,    10,    11,    58,    61,    -1,    10,    11,    61,    -1,
      10,    11,    58,    61,    -1,    43,    11,    -1,    43,    11,
      41,    59,    -1,    41,    59,    -1,    11,    -1,    59,    26,
      11,    -1,    39,    -1,    40,    -1,    29,    62,    30,    -1,
      29,    30,    -1,    63,    -1,    62,    63,    -1,    64,    -1,
      65,    -1,    98,    -1,    79,    -1,    99,    -1,    57,    -1,
      33,    -1,    29,    66,    30,    -1,    29,    30,    -1,    67,
      -1,    66,    67,    -1,    69,    -1,    57,    -1,    68,    -1,
      27,    -1,    28,    -1,    33,    -1,    22,    -1,    32,    -1,
      24,    -1,     6,    -1,     7,    -1,     8,    -1,     9,    -1,
      26,    -1,    31,    -1,    11,    -1,    34,    -1,    29,    66,
      30,    -1,    29,    30,    -1,    23,    76,    70,    33,    -1,
      76,    70,    33,    -1,    11,    70,    33,    -1,    23,    76,
      11,    22,    24,    11,    27,    80,    28,    -1,    76,    11,
      22,    24,    11,    27,    80,    28,    -1,    11,    11,    22,
      24,    11,    27,    80,    28,    -1,    23,    76,    11,    22,
      24,    11,    31,    11,    27,    80,    28,    -1,    76,    11,
      22,    24,    11,    31,    11,    27,    80,    28,    -1,    11,
      11,    22,    24,    11,    31,    11,    27,    80,    28,    -1,
      71,    -1,    70,    26,    71,    -1,    11,    -1,    11,    22,
      -1,    11,    22,    31,    -1,    71,    36,    35,    -1,    11,
      27,    73,    28,    33,    -1,    11,    27,    28,    65,    -1,
      11,    27,    73,    28,    65,    -1,    11,    27,    28,    37,
      11,    65,    -1,    11,    27,    73,    28,    37,    11,    65,
      -1,    11,    27,    28,    33,    -1,    74,    -1,    73,    26,
      74,    -1,    76,    75,    -1,    11,    -1,    11,    22,    -1,
      11,    22,    31,    -1,    75,    36,    35,    -1,    77,    -1,
      90,    -1,    78,    -1,    14,    -1,    88,    -1,    89,    -1,
      84,    76,    82,    33,    -1,    76,    82,    33,    -1,    84,
      76,    11,    22,    24,    11,    27,    80,    28,    -1,    76,
      11,    22,    24,    11,    27,    80,    28,    -1,    84,    76,
      11,    22,    24,    11,    31,    11,    27,    80,    28,    -1,
      76,    11,    22,    24,    11,    31,    11,    27,    80,    28,
      -1,    81,    -1,    80,    26,    81,    -1,    -1,    11,    -1,
      83,    -1,    82,    26,    83,    -1,    11,    -1,    11,    22,
      -1,    11,    22,    31,    -1,    83,    36,    35,    -1,    85,
      -1,    86,    -1,    87,    -1,    87,    86,    -1,    85,    87,
      86,    -1,    85,    86,    -1,    85,    87,    -1,    40,    -1,
      23,    -1,     3,    -1,     4,    -1,    38,    -1,    20,    -1,
      17,    -1,    16,    -1,    18,    -1,    19,    -1,    15,    -1,
      21,    -1,    91,    -1,    11,    -1,    94,    -1,    92,    95,
      -1,    92,    -1,    93,    -1,    91,    31,    11,    -1,    11,
      -1,    93,    31,    11,    -1,    76,    36,    35,    -1,    96,
      -1,    97,    -1,    96,    26,    97,    -1,    90,    -1,    23,
      65,    -1,    84,    76,    72,    -1,    76,    72,    -1,    84,
       5,    72,    -1,    84,    72,    -1,     5,    72,    -1,    72,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   113,   113,   114,   115,   116,   117,   118,   119,   120,
     123,   126,   127,   132,   133,   136,   137,   138,   139,   142,
     145,   148,   151,   154,   155,   160,   161,   167,   168,   169,
     170,   171,   172,   173,   174,   177,   178,   179,   182,   183,
     186,   187,   192,   193,   198,   199,   205,   206,   207,   211,
     232,   265,   266,   269,   270,   273,   274,   277,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   314,   315,   318,   319,   320,   321,
     325,   326,   330,   334,   335,   341,   342,   345,   346,   347,
     348,   351,   352,   353,   354,   355,   356,   359,   372,   387,
     390,   391,   392,   393,   396,   397,   400,   401,   404,   405,
     408,   409,   410,   411,   412,   413,   416,   417,   420,   421,
     424,   425,   428,   429,   430,   431,   436,   437,   438,   439,
     440,   441,   442,   445,   448,   451,   452,   453,   456,   457,
     458,   459,   460,   463,   464,   467,   468,   469,   472,   473,
     476,   477,   480,   481,   484,   487,   490,   491,   494,   497,
     500,   501,   502,   503,   504,   505
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "pub", "pri", "voi", "pl", "mi", "di", 
  "mo", "cla", "identifier", "thi", "def", "boo", "flo", "lon", "sho", 
  "ing", "cha", "byt", "dou", "equ", "sta", "new", "import", "comma", 
  "cirbral", "cirbrar", "curbral", "curbrar", "dot", "colon", "semicolon", 
  "star", "sqr", "sql", "ths", "protect", "abst", "fin", "imp", "pack", 
  "ext", "inter", "$accept", "S", "PDS", "PN", "IDS", "ID", "STID", 
  "TIODD", "SSID", "SIDD", "ITN", "TDS", "CD", "EXTN", "IMPS", "CBS", 
  "CB", "CBDS", "CBD", "CMD", "B", "BSS", "BS", "CRLP", "FD1", "VDS1", 
  "VDD2", "COM", "FPS", "FP", "VDD1", "T", "PT", "NT", "FD", "LL", "LL1", 
  "VDS", "VDD", "FMS", "FM2", "FM", "FM1", "IT", "FPT", "RT", "CT", 
  "TDS1", "TN", "AT", "TA", "ATAL", "ATA", "ST", "MD", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    45,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    48,    48,    49,    49,    50,    50,    50,    50,    51,
      52,    53,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    71,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    73,    73,    74,
      75,    75,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    79,    79,    79,    79,    79,    80,    80,    81,    81,
      82,    82,    83,    83,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    85,    86,    87,    87,    87,    88,    88,
      88,    88,    88,    89,    89,    90,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    95,    96,    96,    97,    98,
      99,    99,    99,    99,    99,    99
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     3,     2,     2,     2,     1,     1,     1,
       3,     1,     3,     1,     2,     1,     1,     1,     1,     3,
       5,     6,     6,     1,     3,     1,     2,     5,     6,     4,
       5,     4,     5,     3,     4,     2,     4,     2,     1,     3,
       1,     1,     3,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     4,     3,     3,     9,
       8,     8,    11,    10,    10,     1,     3,     1,     2,     3,
       3,     5,     4,     5,     6,     7,     4,     1,     3,     2,
       1,     2,     3,     3,     1,     1,     1,     1,     1,     1,
       4,     3,     9,     8,    11,    10,     1,     3,     0,     1,
       1,     3,     1,     2,     3,     3,     1,     1,     1,     2,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     3,     1,     3,     3,     1,     1,     3,     1,     2,
       3,     2,     3,     2,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     0,     0,     0,    40,    41,     0,     0,     7,     8,
      13,    15,    16,    17,    18,     9,    25,     0,     0,     0,
      23,     0,     0,    11,     0,     1,     6,     5,    14,     4,
      26,     0,     0,     0,     0,     0,     0,     0,    33,     0,
       0,    19,     0,    10,     3,     0,     0,     0,    31,   135,
     136,     0,   152,   107,   143,   140,   139,   141,   142,   138,
     144,   134,     0,    43,    52,   137,   133,    51,     0,    44,
      46,    47,   165,     0,   104,   106,    49,     0,   126,   127,
     128,   108,   109,   105,   145,   149,   150,   147,    48,    50,
      38,    37,    35,    34,     0,    24,     0,    12,     0,     0,
      29,    32,     0,   164,     0,   159,    66,    67,    68,    69,
      72,    63,     0,    65,    70,    60,    61,     0,    54,    71,
      64,    62,    73,    58,     0,    55,    59,    57,     0,    42,
      45,   122,     0,   161,     0,   120,     0,   163,     0,   135,
     134,   131,   132,   129,     0,   152,     0,   158,   148,   155,
     156,     0,     0,     0,    24,     0,    20,     0,    27,    30,
       0,     0,    97,     0,    87,     0,    85,     0,    75,     0,
      53,    56,    87,     0,   123,   154,     0,   111,     0,   162,
     122,   160,     0,   130,   151,     0,   153,    39,    36,    21,
      22,    28,    96,     0,    92,     0,     0,   100,    99,    88,
       0,    78,     0,    87,     0,    74,    88,    77,     0,   124,
     122,   121,   125,   123,   110,   157,     0,    98,    91,     0,
      93,   101,     0,     0,    89,    87,    86,    90,    88,    76,
       0,     0,   123,     0,    94,     0,   102,   103,     0,    88,
       0,     0,   118,     0,     0,    95,   118,     0,     0,   118,
       0,   119,     0,   116,     0,   118,     0,     0,     0,   118,
       0,     0,     0,   118,   113,   118,     0,     0,    81,   118,
       0,     0,    80,   118,   117,     0,   112,   118,     0,    79,
     118,     0,   115,     0,    84,     0,    83,   114,    82
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     7,     8,    24,     9,    10,    11,    12,    13,    14,
      22,    15,    16,    37,    91,    17,    38,    68,    69,    70,
      71,   124,   125,   126,   127,   165,   166,    72,   161,   162,
     198,   128,    74,    75,    76,   252,   253,   134,   135,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
     148,   149,   150,    88,    89
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -120
static const short yypact[] =
{
      20,    16,    25,    14,  -120,  -120,    86,   148,    36,    36,
    -120,  -120,  -120,  -120,  -120,    24,  -120,   102,   155,   -19,
    -120,   162,    56,  -120,   165,  -120,    36,    24,  -120,    24,
    -120,    76,   175,   -19,   103,   186,   197,   180,  -120,   190,
       8,  -120,   221,  -120,    24,   232,   -19,   180,  -120,    16,
    -120,   233,     2,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,   227,   161,  -120,  -120,  -120,   106,  -120,   298,  -120,
    -120,  -120,  -120,     4,  -120,  -120,  -120,   359,    44,  -120,
     244,  -120,  -120,  -120,   247,   370,   248,  -120,  -120,  -120,
    -120,   265,   263,  -120,    43,  -120,   277,  -120,   -19,   180,
    -120,  -120,   297,  -120,   341,  -120,  -120,  -120,  -120,  -120,
      22,  -120,   370,  -120,  -120,  -120,  -120,   196,  -120,  -120,
    -120,  -120,  -120,  -120,   231,  -120,  -120,  -120,    30,  -120,
    -120,    73,   290,  -120,   101,   299,   233,  -120,    32,  -120,
    -120,  -120,   244,  -120,   323,    54,   305,   309,  -120,   327,
    -120,   338,   356,   186,   339,   349,  -120,   180,  -120,  -120,
      59,   205,  -120,    42,   361,   104,   335,    45,  -120,   266,
    -120,  -120,   374,   105,   115,  -120,   387,  -120,   365,  -120,
      88,  -120,   114,  -120,  -120,   370,  -120,  -120,   265,  -120,
    -120,  -120,  -120,   390,  -120,   370,    65,   380,   368,   120,
     392,  -120,   372,   383,   124,  -120,   129,  -120,   395,  -120,
     386,   299,  -120,   130,  -120,  -120,   227,  -120,  -120,   398,
    -120,   379,   376,   401,  -120,   391,   335,  -120,   134,  -120,
     403,    98,   384,   405,  -120,   227,  -120,  -120,   118,   388,
     406,   132,   407,   409,   280,  -120,   407,   410,   295,   407,
     411,  -120,   240,  -120,   396,   407,   413,   304,   399,   407,
     414,   314,   400,   407,  -120,   407,   318,   402,  -120,   407,
     322,   404,  -120,   407,  -120,   337,  -120,   407,   340,  -120,
     407,   366,  -120,   367,  -120,   371,  -120,  -120,  -120
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -120,  -120,  -120,  -120,   420,    48,  -120,  -120,  -120,  -120,
     412,    75,   -13,   -26,   279,  -120,   -29,  -120,   362,  -120,
     -61,   317,  -119,  -120,  -120,  -116,   235,   -45,  -120,   241,
    -120,   -33,  -120,  -120,  -120,    74,   174,   300,   264,  -120,
    -120,   -69,   363,  -120,  -120,   -82,  -120,  -120,  -120,  -120,
    -120,  -120,   254,  -120,  -120
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -147
static const short yytable[] =
{
     105,    73,    30,   147,    48,   171,   103,    47,    93,   141,
      34,   143,   173,  -146,    30,   131,    30,   100,   101,    95,
      99,    67,    35,     1,    36,    20,    18,     1,   133,   104,
       2,    30,   137,   164,     2,    73,    19,    21,  -146,     1,
     132,   172,    96,   180,   138,     3,     2,   139,    50,   123,
     171,   204,   146,   197,   154,    67,   203,    28,  -146,     4,
       5,     3,     6,     4,     5,  -146,   132,   140,   132,   158,
     159,   163,   157,   183,    28,     4,     5,   155,   132,   167,
    -146,   132,    65,    27,    29,  -146,    45,    40,    62,    41,
    -146,   179,   192,   181,    62,   174,   193,    23,   218,   194,
     104,    44,   219,   147,   123,    31,    49,    50,    51,   -41,
     213,   123,    32,     2,    52,   104,   -41,    53,    54,    55,
      56,    57,    58,    59,    60,   242,    61,   176,   191,   243,
     200,   200,    62,    63,   177,   220,    64,   201,   207,   208,
     176,    65,     4,    66,   223,   246,   209,   214,    25,   247,
     200,   224,   146,   230,   233,   234,   123,   229,   240,   249,
     224,   209,   163,   250,     1,   224,    33,   106,   107,   108,
     109,     2,   110,    20,   245,    53,    54,    55,    56,    57,
      58,    59,    60,   111,   112,   113,    46,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    42,    90,    43,     1,
       4,     5,   106,   107,   108,   109,     2,   110,    92,    34,
      53,    54,    55,    56,    57,    58,    59,    60,   111,   112,
     113,    94,   114,   115,   116,   117,   168,   119,   120,   121,
     122,   195,    97,   196,     1,     4,     5,   106,   107,   108,
     109,     2,   110,    98,   102,    53,    54,    55,    56,    57,
      58,    59,    60,   111,   112,   113,    62,   114,   115,   116,
     117,   170,   119,   120,   121,   122,   263,   140,   264,     1,
       4,     5,   106,   107,   108,   109,     2,   110,   144,   151,
      53,    54,    55,    56,    57,    58,    59,    60,   111,   112,
     113,   152,   114,   115,   116,   117,   205,   119,   120,   121,
     122,    49,    50,    51,   153,     4,     5,   255,     2,    52,
     156,   256,    53,    54,    55,    56,    57,    58,    59,    60,
     257,    61,   259,   261,   104,   175,   260,    62,   129,   266,
     263,    64,   268,   270,   184,   178,    65,     4,    66,   275,
     263,   132,   272,   278,   263,  -105,   276,   281,   263,   186,
     279,   283,   145,   185,   285,    53,    54,    55,    56,    57,
      58,    59,    60,   263,   136,   282,   263,   187,   284,   160,
      52,   202,   189,    53,    54,    55,    56,    57,    58,    59,
      60,   145,   190,   199,    53,    54,    55,    56,    57,    58,
      59,    60,   263,   263,   286,   287,   206,   263,   210,   288,
     212,   216,   221,   225,   222,   228,   231,   227,   232,   235,
     236,   237,   238,   239,   241,   209,   244,   248,   251,   224,
     254,   258,   262,   265,   267,   271,   269,   273,    26,   277,
     130,   280,   188,    39,   169,   226,   217,   274,   182,   215,
     211,   142
};

static const unsigned short yycheck[] =
{
      61,    34,    15,    85,    33,   124,    51,    33,    37,    78,
      29,    80,   128,    11,    27,    11,    29,    46,    47,    11,
      46,    34,    41,     3,    43,    11,    10,     3,    73,    27,
      10,    44,    77,    11,    10,    68,    11,    23,    36,     3,
      36,    11,    34,    11,    77,    25,    10,     3,     4,    62,
     169,   167,    85,    11,    11,    68,    11,     9,    36,    39,
      40,    25,    42,    39,    40,    11,    36,    23,    36,    98,
      99,   104,    98,   142,    26,    39,    40,    34,    36,   112,
      26,    36,    38,     8,     9,    31,    10,    31,    29,    33,
      36,   136,    33,   138,    29,    22,    37,    11,    33,   160,
      27,    26,    37,   185,   117,     3,     3,     4,     5,     3,
      22,   124,    10,    10,    11,    27,    10,    14,    15,    16,
      17,    18,    19,    20,    21,    27,    23,    26,   157,    31,
      26,    26,    29,    30,    33,   196,    33,    33,    33,    24,
      26,    38,    39,    40,    24,    27,    31,    33,     0,    31,
      26,    31,   185,    24,    24,   216,   169,    33,    24,    27,
      31,    31,   195,    31,     3,    31,    11,     6,     7,     8,
       9,    10,    11,    11,   235,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    11,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    31,    11,    33,     3,
      39,    40,     6,     7,     8,     9,    10,    11,    11,    29,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    31,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    26,    11,    28,     3,    39,    40,     6,     7,     8,
       9,    10,    11,    11,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    29,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    26,    23,    28,     3,
      39,    40,     6,     7,     8,     9,    10,    11,    31,    31,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    26,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     3,     4,     5,    41,    39,    40,    27,    10,    11,
      33,    31,    14,    15,    16,    17,    18,    19,    20,    21,
     246,    23,    27,   249,    27,    35,    31,    29,    30,   255,
      26,    33,    28,   259,    11,    36,    38,    39,    40,   265,
      26,    36,    28,   269,    26,    36,    28,   273,    26,    11,
      28,   277,    11,    26,   280,    14,    15,    16,    17,    18,
      19,    20,    21,    26,     5,    28,    26,    11,    28,    28,
      11,    36,    33,    14,    15,    16,    17,    18,    19,    20,
      21,    11,    33,    22,    14,    15,    16,    17,    18,    19,
      20,    21,    26,    26,    28,    28,    22,    26,    11,    28,
      35,    11,    22,    11,    36,    22,    11,    35,    22,    11,
      31,    35,    11,    22,    11,    31,    11,    11,    11,    31,
      11,    11,    11,    27,    11,    11,    27,    27,     8,    27,
      68,    27,   153,    21,   117,   200,   195,   263,   138,   185,
     176,    78
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,    10,    25,    39,    40,    42,    46,    47,    49,
      50,    51,    52,    53,    54,    56,    57,    60,    10,    11,
      11,    23,    55,    11,    48,     0,    49,    56,    50,    56,
      57,     3,    10,    11,    29,    41,    43,    58,    61,    55,
      31,    33,    31,    33,    56,    10,    11,    58,    61,     3,
       4,     5,    11,    14,    15,    16,    17,    18,    19,    20,
      21,    23,    29,    30,    33,    38,    40,    57,    62,    63,
      64,    65,    72,    76,    77,    78,    79,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    98,    99,
      11,    59,    11,    61,    31,    11,    34,    11,    11,    58,
      61,    61,    11,    72,    27,    65,     6,     7,     8,     9,
      11,    22,    23,    24,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    57,    66,    67,    68,    69,    76,    30,
      63,    11,    36,    72,    82,    83,     5,    72,    76,     3,
      23,    86,    87,    86,    31,    11,    76,    90,    95,    96,
      97,    31,    26,    41,    11,    34,    33,    58,    61,    61,
      28,    73,    74,    76,    11,    70,    71,    76,    30,    66,
      30,    67,    11,    70,    22,    35,    26,    33,    36,    72,
      11,    72,    82,    86,    11,    26,    11,    11,    59,    33,
      33,    61,    33,    37,    65,    26,    28,    11,    75,    22,
      26,    33,    36,    11,    70,    30,    22,    33,    24,    31,
      11,    83,    35,    22,    33,    97,    11,    74,    33,    37,
      65,    22,    36,    24,    31,    11,    71,    35,    22,    33,
      24,    11,    22,    24,    65,    11,    31,    35,    11,    22,
      24,    11,    27,    31,    11,    65,    27,    31,    11,    27,
      31,    11,    80,    81,    11,    27,    31,    80,    11,    27,
      31,    80,    11,    26,    28,    27,    80,    11,    28,    27,
      80,    11,    28,    27,    81,    80,    28,    27,    80,    28,
      27,    80,    28,    80,    28,    80,    28,    28,    28
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 27:
#line 167 "vv1.y"
    { classstructure(yyvsp[-1],1);;}
    break;

  case 28:
#line 168 "vv1.y"
    { classstructure(yyvsp[-2],1);;}
    break;

  case 29:
#line 169 "vv1.y"
    { classstructure(yyvsp[-1],0);;}
    break;

  case 30:
#line 170 "vv1.y"
    { classstructure(yyvsp[-2],0);;}
    break;

  case 31:
#line 171 "vv1.y"
    { classstructure(yyvsp[-1],1);;}
    break;

  case 32:
#line 172 "vv1.y"
    { classstructure(yyvsp[-2],1);;}
    break;

  case 33:
#line 173 "vv1.y"
    { classstructure(yyvsp[-1],0);;}
    break;

  case 34:
#line 174 "vv1.y"
    { classstructure(yyvsp[-2],0);;}
    break;

  case 49:
#line 211 "vv1.y"
    {
					mvtemp=mvhead;
					while(mvtemp->next!=NULL)
						mvtemp=mvtemp->next;
					for(l=0;l<ais;l++)
						{
						mvtemp->next=(struct mvll *)malloc(sizeof(struct mvll));		
						mvtemp=mvtemp->next;
						strcpy(mvtemp->name,array[l]);
						strcpy(mvtemp->access,access);
						strcpy(mvtemp->isstatic,isstatic);
						strcpy(mvtemp->type,rettype);
						strcpy(mvtemp->filename,fname);
						mvtemp->cnt=0;
						mvtemp->flag=flagv;
						mvtemp->next=NULL;
						}
					strcpy(name," ");       strcpy(access," ");  strcpy(isstatic," ");
                                        strcpy(classname," ");  strcpy(rettype," ");
					ais=0;					
					;}
    break;

  case 50:
#line 232 "vv1.y"
    {
					mftemp=mfhead;	
					while(mftemp->next!=NULL)
						mftemp=mftemp->next;
					mftemp->next=(struct mfll *)malloc(sizeof(struct mfll));
					mftemp=mftemp->next;
					strcpy(mftemp->filename,fname);
					strcpy(mftemp->name,name);
					strcpy(mftemp->access,access);
					strcpy(mftemp->isstatic,isstatic);
					strcpy(mftemp->rettype,rettype);
					mftemp->cnt=0;
					mftemp->flag=flagm;            /* logical*/
					fptemp=fphead;
					while(fptemp!=NULL)
						{
						if(fptemp->flag==flagp)
							strcpy(fptemp->functionname,name);
						fptemp=fptemp->next;
						}
					flagp++;
					lvtemp=lvhead;
					while(lvtemp!=NULL)
						{
						if(lvtemp->flag==flagl)
							strcpy(lvtemp->functionname,name);
						lvtemp=lvtemp->next;
						}
					flagl++;
					strcpy(name," ");       strcpy(access," ");  strcpy(isstatic," ");
					strcpy(classname," "); strcpy(rettype," ");
					mftemp->next=NULL;
					;}
    break;

  case 57:
#line 277 "vv1.y"
    {
					int p;
					lvtemp=lvhead;
					while(lvtemp->next!=NULL)
						lvtemp=lvtemp->next;				
					for(p=0;p<ais1;p++)
						{
						lvtemp->next=(struct lvll *)malloc(sizeof(struct lvll));
						lvtemp=lvtemp->next;
						strcpy(lvtemp->name,array2[p]);
						strcpy(lvtemp->filename,fname);
						strcpy(lvtemp->type,rettype);
						strcpy(lvtemp->isstatic,isstatic1);
						lvtemp->flag=flagl;
						lvtemp->next=NULL;
						}
					strcpy(isstatic1,"");
				        ais1=0;	
                                        ;}
    break;

  case 72:
#line 310 "vv1.y"
    { fprintf(syt,"%s %s ",(char *)yyvsp[0],fname); ;}
    break;

  case 76:
#line 318 "vv1.y"
    { strcpy(isstatic1,"static");;}
    break;

  case 78:
#line 320 "vv1.y"
    { strcpy(rettype,(char *)yyvsp[-2]);;}
    break;

  case 79:
#line 321 "vv1.y"
    { 
								  strcpy(array2[ais1++],(char *)yyvsp[-6]);
								  strcpy(isstatic1,"static");
								  ;}
    break;

  case 80:
#line 325 "vv1.y"
    {strcpy(array2[ais1++],(char *)yyvsp[-6]);;}
    break;

  case 81:
#line 326 "vv1.y"
    {
									strcpy(rettype,(char *)yyvsp[-7]);
									strcpy(array2[ais1++],(char *)yyvsp[-6]);
									;}
    break;

  case 82:
#line 330 "vv1.y"
    { 
										 strcpy(isstatic1,"static");
										 strcpy(array2[ais1++],(char *)yyvsp[-8]);
										 ;}
    break;

  case 83:
#line 334 "vv1.y"
    {strcpy(array2[ais1++],(char *)yyvsp[-8]);;}
    break;

  case 84:
#line 335 "vv1.y"
    {
										     strcpy(rettype,(char *)yyvsp[-9]);
										     strcpy(array2[ais1++],(char *)yyvsp[-8]);
										     ;}
    break;

  case 87:
#line 345 "vv1.y"
    {strcpy(array2[ais1++],(char *)yyvsp[0]);;}
    break;

  case 88:
#line 346 "vv1.y"
    {strcpy(array2[ais1++],(char *)yyvsp[-1]);;}
    break;

  case 89:
#line 347 "vv1.y"
    {strcpy(array2[ais1++],(char *)yyvsp[-2]);;}
    break;

  case 91:
#line 351 "vv1.y"
    { strcpy(name,(char *)yyvsp[-4]);;}
    break;

  case 92:
#line 352 "vv1.y"
    { strcpy(name,(char *)yyvsp[-3]);;}
    break;

  case 93:
#line 353 "vv1.y"
    { strcpy(name,(char *)yyvsp[-4]);;}
    break;

  case 94:
#line 354 "vv1.y"
    { strcpy(name,(char *)yyvsp[-5]);;}
    break;

  case 95:
#line 355 "vv1.y"
    { strcpy(name,(char *)yyvsp[-6]);;}
    break;

  case 96:
#line 356 "vv1.y"
    { strcpy(name,(char *)yyvsp[-3]);;}
    break;

  case 97:
#line 359 "vv1.y"
    {
			fptemp=fphead;
			while(fptemp->next!=NULL)
				fptemp=fptemp->next;
			fptemp->next=(struct fpll *)malloc(sizeof(struct fpll));
			fptemp=fptemp->next;
			strcpy(fptemp->name,array1);
			strcpy(fptemp->type,rettype);
			strcpy(fptemp->filename,fname);
			fptemp->cnt=0;
			fptemp->flag=flagp;
			fptemp->next=NULL;
			;}
    break;

  case 98:
#line 372 "vv1.y"
    {
                        fptemp=fphead;
                        while(fptemp->next!=NULL)
                                fptemp=fptemp->next;
                        fptemp->next=(struct fpll *)malloc(sizeof(struct fpll));
                        fptemp=fptemp->next;
                        strcpy(fptemp->name,array1);
                        strcpy(fptemp->type,rettype);
                        strcpy(fptemp->filename,fname);
                        fptemp->cnt=0;
                        fptemp->flag=flagp;
                        fptemp->next=NULL;
                        ;}
    break;

  case 100:
#line 390 "vv1.y"
    { strcpy(array1,(char *)yyvsp[0]); ;}
    break;

  case 101:
#line 391 "vv1.y"
    { strcpy(array1,(char *)yyvsp[-1]); ;}
    break;

  case 102:
#line 392 "vv1.y"
    { strcpy(array1,(char *)yyvsp[-2]); ;}
    break;

  case 112:
#line 410 "vv1.y"
    { strcpy(array[ais++],(char *)yyvsp[-6]); ;}
    break;

  case 113:
#line 411 "vv1.y"
    { strcpy(array[ais++],(char *)yyvsp[-6]); ;}
    break;

  case 114:
#line 412 "vv1.y"
    { strcpy(array[ais++],(char *)yyvsp[-8]); ;}
    break;

  case 115:
#line 413 "vv1.y"
    { strcpy(array[ais++],(char *)yyvsp[-8]); ;}
    break;

  case 122:
#line 428 "vv1.y"
    { strcpy(array[ais++],(char *)yyvsp[0]); ;}
    break;

  case 123:
#line 429 "vv1.y"
    { strcpy(array[ais++],(char *)yyvsp[-1]); ;}
    break;

  case 124:
#line 430 "vv1.y"
    { strcpy(array[ais++],(char *)yyvsp[-2]); ;}
    break;

  case 134:
#line 448 "vv1.y"
    {strcpy(isstatic,"static");;}
    break;

  case 135:
#line 451 "vv1.y"
    {strcpy(access,"public");;}
    break;

  case 136:
#line 452 "vv1.y"
    {strcpy(access,"private");;}
    break;

  case 137:
#line 453 "vv1.y"
    {strcpy(access,"protected");;}
    break;

  case 138:
#line 456 "vv1.y"
    {strcpy(rettype,"byte");;}
    break;

  case 139:
#line 457 "vv1.y"
    {strcpy(rettype,"short");;}
    break;

  case 140:
#line 458 "vv1.y"
    {strcpy(rettype,"long");;}
    break;

  case 141:
#line 459 "vv1.y"
    {strcpy(rettype,"int");;}
    break;

  case 142:
#line 460 "vv1.y"
    {strcpy(rettype,"char");;}
    break;

  case 143:
#line 463 "vv1.y"
    {strcpy(rettype,"float");;}
    break;

  case 144:
#line 464 "vv1.y"
    {strcpy(rettype,"double");;}
    break;

  case 146:
#line 468 "vv1.y"
    {strcpy(rettype,(char *)yyvsp[0]);;}
    break;

  case 162:
#line 502 "vv1.y"
    {strcpy(rettype,"void");;}
    break;

  case 164:
#line 504 "vv1.y"
    {strcpy(rettype,"void");;}
    break;


    }

/* Line 991 of yacc.c.  */
#line 1823 "vv1.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__) \
    && !defined __cplusplus
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 511 "vv1.y"


/* Write the code for main function to solve the problem set */

extern FILE *yyin;
yyerror(char *s)
	{
        fprintf(stderr,"%s\n",s);
        }

void function(char *a)
        {
        struct dirent **name;
        int n=0;
        char aa[30];
        n=scandir(a,&name,0,alphasort);
        if (n < 0)
               {}
        else
                {
                while(n--)
                        {
                        if(strstr(name[n]->d_name,".java"))
                                {
				strcpy(javasource[js],a);
				strcat(javasource[js],"/");
                                strcat(javasource[js++],name[n]->d_name);
                                }
                       /* else if(strstr(name[n]->d_name,".class"))
                                printf("\nClass file %s\n",name[n]->d_name);*/
                        else if(strstr(name[n]->d_name,"."))
                                ;
                        else
                                {
                                strcpy(aa,a);
                                strcat(aa,"/");
                                strcat(aa,name[n]->d_name);
                                function(aa);
                                }
                        }
                }
        }

classstructure(char *v,int lm)
	{
        ctemp=chead;
        while(ctemp->next!=NULL)
        	ctemp=ctemp->next;
        ctemp->next=(struct cll *)malloc(sizeof(struct cll));
        ctemp=ctemp->next;
        strcpy(ctemp->name,v);
        mftemp=mfhead;
        while(mftemp!=NULL)
        	{
	        if(mftemp->flag==flagm)
        		{
		        strcpy(mftemp->classname,ctemp->name);
		        fptemp=fphead;
		        while(fptemp!=NULL)
			        {
			        if(!strcmp(fptemp->functionname,mftemp->name))
				        strcpy(fptemp->classname,ctemp->name);
			        fptemp=fptemp->next;
			        }
		        lvtemp=lvhead;
		        while(lvtemp!=NULL)
			        {
			        if(!strcmp(lvtemp->functionname,mftemp->name))
				        strcpy(lvtemp->classname,ctemp->name);
			        lvtemp=lvtemp->next;
			        }
		        }
	        mftemp=mftemp->next;
        	}
	flagm++;
        mvtemp=mvhead;
        while(mvtemp!=NULL)
        	{
        	if(mvtemp->flag==flagv)
	        	strcpy(mvtemp->classname,ctemp->name);
        	mvtemp=mvtemp->next;
        	}
        flagv++;
	if(lm==0)
	        strcpy(ctemp->access,"default");
	else if(lm==1)
		strcpy(ctemp->access,"public");	
	else	{}
        strcpy(ctemp->filename,fname);
        ctemp->cnt=0;
        ctemp->next=NULL;
        }


int main(int argc,char *argv[])
        {
        FILE *fp,*logf;
	int i=0;
	char tem[fz];
        struct dirent **namelist;
	fop=fopen("analysis.txt","w");
	syt=fopen("syt.txt","w");
	system("date >> logfile.txt");
	logf=fopen("logfile.txt","a");
        int n,k;
	chead =(struct  cll *)malloc(sizeof(struct  cll));      chead->next =NULL;
	mfhead=(struct mfll *)malloc(sizeof(struct mfll));	mfhead->next=NULL;	
	fphead=(struct fpll *)malloc(sizeof(struct fpll));	fphead->next=NULL;
	lvhead=(struct lvll *)malloc(sizeof(struct lvll));	lvhead->next=NULL;
	mvhead=(struct mvll *)malloc(sizeof(struct mvll));	mvhead->next=NULL;
        if(argc==1)
                {
                printf("improper no. of arguments\n");fprintf(logf,"improper no. of arguments\n");
		fprintf(logf,"--------------------------------------------------------------------------\n\n\n");
                exit(0);
                }
        function(argv[1]);
	if(js==0)
		{
		printf("\nNo JAVA Source Found in Project Exting......!\n");
		fprintf(logf,"\nNo JAVA Source Found in Project Exting......!\n");
		fprintf(logf,"--------------------------------------------------------------------------\n\n\n");
		exit(0);
		}
        printf("\n\nThe Java Source Files are \n\n"); fprintf(fop,"\n\nThe Java Source Files are \n\n");
	fprintf(logf,"\n\nThe JAVA Source Files are \n\n");
        for(i=0;i<js;i++)
                {
                printf("\t\t%s \n",javasource[i]); fprintf(fop,"\t\t%s \n",javasource[i]);
		fprintf(logf,"\t\t%s \n",javasource[i]);
                }
	fprintf(logf,"--------------------------------------------------------------------------\n\n\n");
	for(i=0;i<js;i++)
		{
	        fp=fopen(javasource[i],"r");
	        for(n=strlen(javasource[i])-1,k=0;javasource[i][n]!='/';n--,k++)
			tem[k]=javasource[i][n];
		tem[k]='\0';
		for(k=k-1,n=0;k>=0;k--,n++)
			fname[n]=tem[k];
		fname[n]='\0';
        	if(fp==NULL)
                	{
	                fprintf(stderr,"cannt open source file %s\n",fname);
			continue;
                	}
	        yyin=fp;
        	do
                	{
	                yyparse();
        	        }while(!feof(yyin));
		fclose(fp);
		ais=0;ais1=0;
		}
	PrintAndProcess();
	fclose(logf);
	}

void PrintAndProcess()
	{
	chead=chead->next;
        mfhead=mfhead->next;
        mvhead=mvhead->next;
        fphead=fphead->next;
        lvhead=lvhead->next;
/*Classes*/
	printf("\n\n\n\nThe Classes Declared in the Java Project are as listed\n\n");
	fprintf(fop,"\n\n\n\nThe Classes Declared in the Java Project are as listed\n\n");
	ctemp=chead;
        printf("  NameoftheClass\t  AccessType      FileName\n"); 
	fprintf(fop,"  NameoftheClass\t  AccessType      FileName\n");
	while(ctemp!=NULL)
		{
		printf("\t  %-10s \t  %-10s\t %-10s\n",ctemp->name,ctemp->access,ctemp->filename);
		fprintf(fop,"\t  %-10s \t  %-10s\t %-10s\n",ctemp->name,ctemp->access,ctemp->filename);
		ctemp=ctemp->next;
		}
/*Member Functions*/
	printf("\n\n\n\nThe Methods Declared in the Classes are as listed\n\n");
	fprintf(fop,"\n\n\n\nThe Methods Declared in the Classes are as listed\n\n");	
        mftemp=mfhead;
        printf("  Nameofthemethod\t\tAccessType \tIsStaticOrNot\t  ReturnType\tClassName\t  FileName\n");
	fprintf(fop,"  Nameofthemethod\t\tAccessType \tIsStaticOrNot\t  ReturnType\tClassName\t  FileName\n");
        while(mftemp!=NULL)
                {
                printf("\t  %-10s\t \t%-10s  \t %-10s  \t %-10s  \t %-10s\t %-10s\n",
			mftemp->name,mftemp->access,mftemp->isstatic,mftemp->rettype,mftemp->classname,mftemp->filename);
		fprintf(fop,"\t  %-10s\t \t%-10s  \t %-10s  \t %-10s  \t %-10s\t %-10s\n",
                        mftemp->name,mftemp->access,mftemp->isstatic,mftemp->rettype,mftemp->classname,mftemp->filename);
                mftemp=mftemp->next;
                }
/*Member Variables*/
	printf("\n\n\n\n The Member Variables Declared in the Classes are as listed\n\n");
	fprintf(fop,"\n\n\n\n The Member Variables Declared in the Classes are as listed\n\n");
	mvtemp=mvhead;
	printf("  NameofVariable\t \tAccessType \tIsStaticOrNot\t Type      \tClassName\t  FileName\n");
	fprintf(fop,"  NameofVariable\t \tAccessType \tIsStaticOrNot\t Type      \tClassName\t  FileName\n");
	while(mvtemp!=NULL)
		{
		printf("\t  %-10s\t \t%-10s  \t %-10s  \t %-10s  \t %-10s\t %-10s\n",
                        mvtemp->name,mvtemp->access,mvtemp->isstatic,mvtemp->type,mvtemp->classname,mvtemp->filename);
		fprintf(fop,"\t  %-10s\t \t%-10s  \t %-10s  \t %-10s  \t %-10s\t %-10s\n",
                        mvtemp->name,mvtemp->access,mvtemp->isstatic,mvtemp->type,mvtemp->classname,mvtemp->filename);
                mvtemp=mvtemp->next;
                }
/*Function Parameters*/
	printf("\n\n\n\n The FunctionParameters of Various Functions are as listed\n\n");
	fprintf(fop,"\n\n\n\n The FunctionParameters of Various Functions are as listed\n\n");
	fptemp=fphead;
	printf(" NameofParameter\t  Type\t\t FuctionName \t ClassName \t Filename\n");
	fprintf(fop," NameofParameter\t  Type\t\t FuctionName \t ClassName \t Filename\n");
	while(fptemp!=NULL)
	    {
	    printf("\t  %-10s\t %-10s \t %-10s \t %-10s \t %-10s\n",fptemp->name,fptemp->type,fptemp->functionname,
									fptemp->classname,fptemp->filename);
	    fprintf(fop,"\t  %-10s\t %-10s \t %-10s \t %-10s \t %-10s\n",fptemp->name,fptemp->type,fptemp->functionname,
                                                                         fptemp->classname,fptemp->filename);
	    fptemp=fptemp->next;
	    }
/*Local Variables*/
	printf("\n\n\n\n The Local Variables Declared in Various Functions are as listed\n\n");
	fprintf(fop,"\n\n\n\n The Local Variables Declared in Various Functions are as listed\n\n");
	lvtemp=lvhead;
	printf(" NameofLocalVariable \t IsStaticOrNot \t Type \t\tFunctionName \t Classname \t Filename\n");
	fprintf(fop," NameofLocalVariable \t IsStaticOrNot \t Type \t\tFunctionName \t Classname \t Filename\n");
	while(lvtemp!=NULL)
		{
		printf("\t  %-10s\t %-10s \t %-10s \t %-10s \t %-10s \t %-10s\n",lvtemp->name,lvtemp->isstatic,
					lvtemp->type,lvtemp->functionname,lvtemp->classname,lvtemp->filename);
		fprintf(fop,"\t  %-10s\t %-10s \t %-10s \t %-10s \t %-10s \t %-10s\n",lvtemp->name,lvtemp->isstatic,
                                        lvtemp->type,lvtemp->functionname,lvtemp->classname,lvtemp->filename);
		lvtemp=lvtemp->next;
		}
	fclose(syt);
	syt=fopen("syt.txt","r");
/*Solution to 3rd Question*/
/*Solution to 4th Question*/
	while(feof(syt)==0)
		{
		fscanf(syt,"%s%s",&name,&fname);
		lvtemp=lvhead;
		fptemp=fphead;
		mvtemp=mvhead;
		mftemp=mfhead;
		while(lvtemp!=NULL)
			{
			if(!strcmp(lvtemp->filename,fname))
				if(!strcmp(lvtemp->name,name))
					lvtemp->cnt+=1;
			lvtemp=lvtemp->next;
			}
		while(fptemp!=NULL)
                        {
                        if(!strcmp(fptemp->filename,fname))
                                if(!strcmp(fptemp->name,name))
                                        fptemp->cnt+=1;
                        fptemp=fptemp->next;
                        }
		while(mvtemp!=NULL)
                        {
                        if(!strcmp(mvtemp->filename,fname))
                                if(!strcmp(mvtemp->name,name))
                                        mvtemp->cnt+=1;
                        mvtemp=mvtemp->next;
                        }
		while(mftemp!=NULL)
                        {
                        if(!strcmp(mftemp->filename,fname))
                                if(!strcmp(mftemp->name,name))
                                        mftemp->cnt+=1;
                        mftemp=mftemp->next;
                        }
		}
/*3rd Question Output*/
printf("\n\n\n\n\nThese are the unused Private member variables and methods\n");
fprintf(fop,"\n\n\n\n\nThese are the unused Private member variables and methods\n");
	ctemp=chead;
	while(ctemp!=NULL)
		{
		mftemp=mfhead;
		mvtemp=mvhead;
		printf("\n----->In Class \"%s\" of File \"%s\" ",ctemp->name,ctemp->filename);
		fprintf(fop,"\n----->In Class \"%s\" of File \"%s\" ",ctemp->name,ctemp->filename);
		while(mftemp!=NULL)
			{
			if(!strcmp(mftemp->classname,ctemp->name))
				if(mftemp->cnt==0)
					if(!strcmp(mftemp->access,"private"))
						{
						printf("\n\t\t Unused Private Function is-->  %s()",mftemp->name);
						fprintf(fop,"\n\t\t Unused Private Function is-->  %s()",mftemp->name);
						}
			mftemp=mftemp->next;
			}
		while(mvtemp!=NULL)
			{
			if(!strcmp(mvtemp->classname,ctemp->name))
				if(mvtemp->cnt==0)
					if(!strcmp(mvtemp->access,"private"))
						{
						printf("\n\t\t Unused Private Variable is-->  %s",mvtemp->name);
						fprintf(fop,"\n\t\t Unused Private Variable is-->  %s",mvtemp->name);
						}
			mvtemp=mvtemp->next;
			}
		ctemp=ctemp->next;
		}
/*4TH Question Output*/
printf("\n\n\n\n\nThese are the unused Function Parameters and Local Variables\n");
fprintf(fop,"\n\n\n\n\nThese are the unused Function Parameters and Local Variables\n");
	mftemp=mfhead;
	while(mftemp!=NULL)
		{
		fptemp=fphead;
		lvtemp=lvhead;
     printf("\n----->In Function \"%s\" of Class \"%s\" in File \"%s\" ",mftemp->name,mftemp->classname,mftemp->filename);
 fprintf(fop,"\n----->In Function \"%s\" of Class \"%s\" in File \"%s\" ",mftemp->name,mftemp->classname,mftemp->filename);
		while(fptemp!=NULL)
			{
			if(!strcmp(mftemp->name,fptemp->functionname))
				if(!strcmp(mftemp->classname,fptemp->classname))
					if(!strcmp(mftemp->filename,fptemp->filename))
						if(fptemp->cnt==0)
							{
							printf("\n\t\t Unused Parameter is --> %s",fptemp->name);
							fprintf(fop,"\n\t\t Unused Parameter is --> %s",fptemp->name);
							}
			fptemp=fptemp->next;
			}
                while(lvtemp!=NULL)
                        {
                        if(!strcmp(mftemp->name,lvtemp->functionname))
                                if(!strcmp(mftemp->classname,lvtemp->classname))
                                        if(!strcmp(mftemp->filename,lvtemp->filename))
                                                if(lvtemp->cnt==0)
                                                        {
                                                        printf("\n\t\t Unused Parameter is --> %s",lvtemp->name);
							fprintf(fop,"\n\t\t Unused Parameter is --> %s",lvtemp->name);
                                                        }
                        lvtemp=lvtemp->next;
                        }
		mftemp=mftemp->next;
		}
/*Solution to 5TH Question*/
 	mvtemp=mvhead;
	ctemp=chead;
	printf("\n\n\n\n\nThese are Dependencies among the Various Classes of the Project\n");
	printf("\n---> These are the Dependencies in the Member Variable Section\n");
        fprintf(fop,"\n\n\n\n\nThese are Dependencies among the Various Classes of the Project\n");
        fprintf(fop,"\n---> These are the Dependencies in the Member Variable Section\n");
	while(ctemp!=NULL)
		{
		while(mvtemp!=NULL)
			{
			if(!strcmp(mvtemp->type,ctemp->name))
				{
			        printf("\n\t The \"%s\" class is (%s) making use of \"%s\" class in File \"%s\" ",
							mvtemp->classname,mvtemp->name,ctemp->name,mvtemp->filename);
  	                        fprintf(fop,"\n\t The \"%s\" class is (%s) making use of \"%s\" class in File \"%s\" ",
						        mvtemp->classname,mvtemp->name,ctemp->name,mvtemp->filename);
			        if(!strcmp(mvtemp->classname,ctemp->name))
					{
					printf("-->This is a self reference");	
					fprintf(fop,"-->This is a self reference");
					}
			    	}
			mvtemp=mvtemp->next;
			}
		mvtemp=mvhead;
		ctemp=ctemp->next;
		}
	printf("\n\n---> These are the Dependencies in the Local Variable Section(in a Member Function )\n");
	fprintf(fop,"\n\n---> These are the Dependencies in the Local Variable Section(in a Member Function )\n");
	lvtemp=lvhead;
	ctemp=chead;	
	while(ctemp!=NULL)
                {
                while(lvtemp!=NULL)
                        {
                        if(!strcmp(lvtemp->type,ctemp->name))
                        	{
                                printf("\n\t The \"%s\" class is (%s) making use of \"%s\" class in File \"%s\"  ",
							lvtemp->classname,lvtemp->name,ctemp->name,lvtemp->filename);
			        fprintf(fop,"\n\t The \"%s\" class is (%s) making use of \"%s\" class in File \"%s\" ",
							lvtemp->classname,lvtemp->name,ctemp->name,lvtemp->filename);
                                if(!strcmp(lvtemp->classname,ctemp->name))
                                	{
					printf("-->This is a self reference"); 
					fprintf(fop,"-->This is a self reference");
					}
                                }
                        lvtemp=lvtemp->next;
                        }
                lvtemp=lvhead;
                ctemp=ctemp->next;
                }
	printf("\n\n\t\t\t\t\t\tThank Q\n\n");
	fprintf(fop,"\n\n\t\t\t\t\tThank Q\n\n");
	fclose(syt);
	remove("syt.txt");
	free(chead);free(mfhead);free(mvhead);free(fphead);free(lvhead);
	fclose(fop);
        }

