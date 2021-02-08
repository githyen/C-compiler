digit [0-9]
letter [a-zA-Z]
delim [ \t]
line [\n]
ws {delim}+

%{
#include <string.h>
#include "y.tab.h"
int line_no;
int checkIdentifier();
%}

%%
{ws} {}
{line}	{line_no++;}
auto	{return(AUTO_SYM);}
break	{return(BREAK_SYM);}
case	{return(CASE_SYM);}
continue	{return(CONTINUE_SYM);}
default	{return(DEFAULT_SYM);}
do		{return(DO_SYM);}
else	{return(ELSE_SYM);}
enum	{return(ENUM_SYM);}
for		{return(FOR_SYM);}
if		{return(IF_SYM);}
return	{return(RETURN_SYM);}
sizeof	{return(SIZEOF_SYM);}
static	{return(STATIC_SYM);}
struct	{return(STRUCT_SYM);}
switch	{return(SWITCH_SYM);}
typedef	{return(TYPEDEF_SYM);}
union	{return(UNION_SYM);}
while	{return(WHILE_SYM);}

"\+\+"	{return(PLUSPLUS);}
"\-\-"	{return(MINUSMINUS);}
"\-\>"	{return(ARROW);}
"\<"	{return(LT);}
"\>"	{return(GT);}
"\<\="	{return(LE);}
"\>\="	{return(GE);}
"\=\="	{return(EQUAL);}
"\!\="	{return(NOTEQUAL);}
"\&\&"	{return(ANDAND);}
"\|\|"	{return(OROR);}
"\("	{return(LPARAM);}
"\)"	{return(RPARAM);}
"\["	{return(LBIGPARAM);}
"\]"	{return(RBIGPARAM);}
"\{"	{return(LMIDPARAM);}
"\}"	{return(RMIDPARAM);}
"\:"	{return(COLON);}
"\;"	{return(SEMICOLON);}
"\."	{return(DOT);}
"\,"	{return(COMMA);}
"\!"	{return(NOT);}
"\*"	{return(STAR);}
"\/"	{return(SLASH);}
"\%"	{return(PERCENT);}
"\&"	{return(AND);}
"\+"	{return(PLUS);}
"\-"	{return(MINUS);}
"\="	{return(ASSIGN);}

{digit}+	{return(INTEGER_CONSTANT);}
{digit}+\.{digit}+	{return(FLOAT_CONSTANT);}
\"([^"\n]|\\["\n])*\"	{return(STRING_LITERAL);}
\'([^"\n]|\'\')\'	{return(CHARACTER_CONSTANT);}
{letter}({letter}|{digit})*	{return(checkIdentifier(yytext));}
%%

int checkIdentifier(char *s)
{
	if(!strcmp(s, "int") || !strcmp(s, "float") || !strcmp(s, "char") || !strcmp(s, "void"))
		return(TYPE_IDENTIFIER);
	return(IDENTIFIER);
}
