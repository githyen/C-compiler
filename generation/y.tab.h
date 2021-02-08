#ifndef YY_parse_h_included
#define YY_parse_h_included
/*#define YY_USE_CLASS 
*/
#line 1 "/usr/share/bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "/usr/share/bison++/bison.h"

#line 21 "/usr/share/bison++/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_parse_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_parse_COMPATIBILITY 1
 #else
  #define  YY_parse_COMPATIBILITY 0
 #endif
#endif

#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_parse_LTYPE
   #define YY_parse_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_parse_STYPE
   #define YY_parse_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_parse_DEBUG
   #define  YY_parse_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_parse_USE_GOTO
  #define YY_parse_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_parse_USE_GOTO
 #define YY_parse_USE_GOTO 0
#endif

#ifndef YY_parse_PURE

 #line 65 "/usr/share/bison++/bison.h"

#line 65 "/usr/share/bison++/bison.h"
/* YY_parse_PURE */
#endif


 #line 68 "/usr/share/bison++/bison.h"
#ifndef YY_USE_CLASS
# ifndef YYSTYPE
#  define YYSTYPE long
#  define YYSTYPE_IS_TRIVIAL 1
# endif
#endif

#line 68 "/usr/share/bison++/bison.h"
/* prefix */

#ifndef YY_parse_DEBUG

 #line 71 "/usr/share/bison++/bison.h"

#line 71 "/usr/share/bison++/bison.h"
/* YY_parse_DEBUG */
#endif

#ifndef YY_parse_LSP_NEEDED

 #line 75 "/usr/share/bison++/bison.h"

#line 75 "/usr/share/bison++/bison.h"
 /* YY_parse_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_parse_LSP_NEEDED
 #ifndef YY_parse_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;
  #endif

  #define YY_parse_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_parse_STYPE
 #define YY_parse_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_parse_PARSE
 #define YY_parse_PARSE yyparse
#endif

#ifndef YY_parse_LEX
 #define YY_parse_LEX yylex
#endif

#ifndef YY_parse_LVAL
 #define YY_parse_LVAL yylval
#endif

#ifndef YY_parse_LLOC
 #define YY_parse_LLOC yylloc
#endif

#ifndef YY_parse_CHAR
 #define YY_parse_CHAR yychar
#endif

#ifndef YY_parse_NERRS
 #define YY_parse_NERRS yynerrs
#endif

#ifndef YY_parse_DEBUG_FLAG
 #define YY_parse_DEBUG_FLAG yydebug
#endif

#ifndef YY_parse_ERROR
 #define YY_parse_ERROR yyerror
#endif

#ifndef YY_parse_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_parse_PARSE_PARAM
    #ifndef YY_parse_PARSE_PARAM_DEF
     #define YY_parse_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_parse_PARSE_PARAM
  #define YY_parse_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_parse_PURE
  #ifndef yylval
   extern YY_parse_STYPE YY_parse_LVAL;
  #else
   #if yylval != YY_parse_LVAL
    extern YY_parse_STYPE YY_parse_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "/usr/share/bison++/bison.h"
#define	IDENTIFIER	258
#define	TYPE_IDENTIFIER	259
#define	FLOAT_CONSTANT	260
#define	INTEGER_CONSTANT	261
#define	CHARACTER_CONSTANT	262
#define	STRING_LITERAL	263
#define	PLUS	264
#define	MINUS	265
#define	PLUSPLUS	266
#define	MINUSMINUS	267
#define	BAR	268
#define	AMP	269
#define	BARBAR	270
#define	AMPAMP	271
#define	ARROW	272
#define	SEMICOLON	273
#define	LSS	274
#define	GTR	275
#define	LEQ	276
#define	GEQ	277
#define	EQL	278
#define	NEQ	279
#define	DOTDOTDOT	280
#define	LP	281
#define	RP	282
#define	LB	283
#define	RB	284
#define	LR	285
#define	RR	286
#define	PERIOD	287
#define	COMMA	288
#define	EXCL	289
#define	STAR	290
#define	SLASH	291
#define	PERCENT	292
#define	ASSIGN	293
#define	COLON	294
#define	AUTO_SYM	295
#define	STATIC_SYM	296
#define	TYPEDEF_SYM	297
#define	STRUCT_SYM	298
#define	ENUM_SYM	299
#define	SIZEOF_SYM	300
#define	UNION_SYM	301
#define	IF_SYM	302
#define	ELSE_SYM	303
#define	WHILE_SYM	304
#define	DO_SYM	305
#define	FOR_SYM	306
#define	CONTINUE_SYM	307
#define	BREAK_SYM	308
#define	RETURN_SYM	309
#define	SWITCH_SYM	310
#define	CASE_SYM	311
#define	DEFAULT_SYM	312


#line 169 "/usr/share/bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_parse_CLASS
  #define YY_parse_CLASS parse
 #endif

 #ifndef YY_parse_INHERIT
  #define YY_parse_INHERIT
 #endif

 #ifndef YY_parse_MEMBERS
  #define YY_parse_MEMBERS 
 #endif

 #ifndef YY_parse_LEX_BODY
  #define YY_parse_LEX_BODY  
 #endif

 #ifndef YY_parse_ERROR_BODY
  #define YY_parse_ERROR_BODY  
 #endif

 #ifndef YY_parse_CONSTRUCTOR_PARAM
  #define YY_parse_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_parse_USE_CONST_TOKEN
  #define YY_parse_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_parse_USE_CONST_TOKEN != 0
  #ifndef YY_parse_ENUM_TOKEN
   #define YY_parse_ENUM_TOKEN yy_parse_enum_token
  #endif
 #endif

class YY_parse_CLASS YY_parse_INHERIT
{
public: 
 #if YY_parse_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "/usr/share/bison++/bison.h"
static const int IDENTIFIER;
static const int TYPE_IDENTIFIER;
static const int FLOAT_CONSTANT;
static const int INTEGER_CONSTANT;
static const int CHARACTER_CONSTANT;
static const int STRING_LITERAL;
static const int PLUS;
static const int MINUS;
static const int PLUSPLUS;
static const int MINUSMINUS;
static const int BAR;
static const int AMP;
static const int BARBAR;
static const int AMPAMP;
static const int ARROW;
static const int SEMICOLON;
static const int LSS;
static const int GTR;
static const int LEQ;
static const int GEQ;
static const int EQL;
static const int NEQ;
static const int DOTDOTDOT;
static const int LP;
static const int RP;
static const int LB;
static const int RB;
static const int LR;
static const int RR;
static const int PERIOD;
static const int COMMA;
static const int EXCL;
static const int STAR;
static const int SLASH;
static const int PERCENT;
static const int ASSIGN;
static const int COLON;
static const int AUTO_SYM;
static const int STATIC_SYM;
static const int TYPEDEF_SYM;
static const int STRUCT_SYM;
static const int ENUM_SYM;
static const int SIZEOF_SYM;
static const int UNION_SYM;
static const int IF_SYM;
static const int ELSE_SYM;
static const int WHILE_SYM;
static const int DO_SYM;
static const int FOR_SYM;
static const int CONTINUE_SYM;
static const int BREAK_SYM;
static const int RETURN_SYM;
static const int SWITCH_SYM;
static const int CASE_SYM;
static const int DEFAULT_SYM;


#line 212 "/usr/share/bison++/bison.h"
 /* decl const */
 #else
  enum YY_parse_ENUM_TOKEN { YY_parse_NULL_TOKEN=0
  
 #line 215 "/usr/share/bison++/bison.h"
	,IDENTIFIER=258
	,TYPE_IDENTIFIER=259
	,FLOAT_CONSTANT=260
	,INTEGER_CONSTANT=261
	,CHARACTER_CONSTANT=262
	,STRING_LITERAL=263
	,PLUS=264
	,MINUS=265
	,PLUSPLUS=266
	,MINUSMINUS=267
	,BAR=268
	,AMP=269
	,BARBAR=270
	,AMPAMP=271
	,ARROW=272
	,SEMICOLON=273
	,LSS=274
	,GTR=275
	,LEQ=276
	,GEQ=277
	,EQL=278
	,NEQ=279
	,DOTDOTDOT=280
	,LP=281
	,RP=282
	,LB=283
	,RB=284
	,LR=285
	,RR=286
	,PERIOD=287
	,COMMA=288
	,EXCL=289
	,STAR=290
	,SLASH=291
	,PERCENT=292
	,ASSIGN=293
	,COLON=294
	,AUTO_SYM=295
	,STATIC_SYM=296
	,TYPEDEF_SYM=297
	,STRUCT_SYM=298
	,ENUM_SYM=299
	,SIZEOF_SYM=300
	,UNION_SYM=301
	,IF_SYM=302
	,ELSE_SYM=303
	,WHILE_SYM=304
	,DO_SYM=305
	,FOR_SYM=306
	,CONTINUE_SYM=307
	,BREAK_SYM=308
	,RETURN_SYM=309
	,SWITCH_SYM=310
	,CASE_SYM=311
	,DEFAULT_SYM=312


#line 215 "/usr/share/bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_parse_PARSE(YY_parse_PARSE_PARAM);
 virtual void YY_parse_ERROR(char *msg) YY_parse_ERROR_BODY;
 #ifdef YY_parse_PURE
  #ifdef YY_parse_LSP_NEEDED
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL,YY_parse_LTYPE *YY_parse_LLOC) YY_parse_LEX_BODY;
  #else
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL) YY_parse_LEX_BODY;
  #endif
 #else
  virtual int YY_parse_LEX() YY_parse_LEX_BODY;
  YY_parse_STYPE YY_parse_LVAL;
  #ifdef YY_parse_LSP_NEEDED
   YY_parse_LTYPE YY_parse_LLOC;
  #endif
  int YY_parse_NERRS;
  int YY_parse_CHAR;
 #endif
 #if YY_parse_DEBUG != 0
  public:
   int YY_parse_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM);
public:
 YY_parse_MEMBERS 
};
/* other declare folow */
#endif


#if YY_parse_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_parse_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_parse_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_parse_DEBUG 
   #define YYDEBUG YY_parse_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "/usr/share/bison++/bison.h"
#endif
