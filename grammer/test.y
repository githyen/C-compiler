%{
#include <stdio.h>
extern int line_no;

int yylex(void);
int yyerror(char *s);

int yywrap(void)
{
	return 1;
}
%}

%start 	program
%token 	AUTO_SYM BREAK_SYM CASE_SYM CONTINUE_SYM DEFAULT_SYM DO_SYM ELSE_SYM ENUM_SYM FOR_SYM IF_SYM RETURN_SYM SIZEOF_SYM STATIC_SYM STRUCT_SYM SWITCH_SYM TYPEDEF_SYM UNION_SYM WHILE_SYM 
		PLUSPLUS MINUSMINUS ARROW LT GT LE GE EQUAL NOTEQUAL ANDAND OROR LPARAM RPARAM LBIGPARAM RBIGPARAM LMIDPARAM RMIDPARAM COLON SEMICOLON DOT DOTDOTDOT COMMA NOT STAR SLASH PERCENT AND PLUS MINUS ASSIGN
		INTEGER_CONSTANT FLOAT_CONSTANT CHARACTER_CONSTANT STRING_LITERAL TYPE_IDENTIFIER IDENTIFIER
%%

program
						: translation_unit
						;
translation_unit
						:	external_declaration
						|	translation_unit external_declaration
						;
external_declaration
						:	function_definition
						|	declaration
						;
function_definition
						:	declaration_specifiers declarator compound_statement
						|	declarator compound_statement
						;

declaration
						:	declaration_specifiers init_declarator_list SEMICOLON
						;
declaration_specifiers
						:	type_specifier
						|	storage_class_specifier
						|	type_specifier declaration_specifiers
						|	storage_class_specifier declaration_specifiers
						;
storage_class_specifier
						:	AUTO_SYM
						|	STATIC_SYM
						|	TYPEDEF_SYM
						;
init_declarator_list
						:	init_declarator
						|	init_declarator_list COMMA init_declarator
						;
init_declarator
						:	declarator
						|	declarator ASSIGN initializer
						;

type_specifier
						:	struct_specifier
						|	enum_specifier
						|	TYPE_IDENTIFIER
						;
struct_specifier
						:	struct_or_union IDENTIFIER LMIDPARAM struct_declaration_list RMIDPARAM
						|	struct_or_union LMIDPARAM struct_declaration_list RMIDPARAM
						|	struct_or_union	IDENTIFIER
						;
struct_or_union
						:	STRUCT_SYM
						|	UNION_SYM
						;
struct_declaration_list
						:	struct_declaration
						|	struct_declaration_list struct_declaration
						;
struct_declaration
						:	type_specifier struct_declarator_list SEMICOLON
						;
struct_declarator_list
						:	struct_declarator
						|	struct_declarator_list COMMA struct_declarator
						;
struct_declarator
						:	declarator
						;
enum_specifier
						:	ENUM_SYM IDENTIFIER LMIDPARAM enumerator_list RMIDPARAM
						|	ENUM_SYM LMIDPARAM enumerator_list RMIDPARAM
						|	ENUM_SYM IDENTIFIER
						;
enumerator_list
						:	enumerator
						|	enumerator_list COMMA enumerator
						;
enumerator
						:	IDENTIFIER
						|	IDENTIFIER ASSIGN constant_expression
						;

declarator
						:	pointer direct_declarator
						|	direct_declarator
						;
pointer
						:	STAR
						|	STAR pointer
						;
direct_declarator
						:	IDENTIFIER
						|	LPARAM declarator RPARAM
						|	direct_declarator LBIGPARAM constant_expression_opt RBIGPARAM
						|	direct_declarator LPARAM parameter_type_list_opt RPARAM
						;
constant_expression_opt
						:
						|	constant_expression
						;
parameter_type_list_opt
						:
						|	parameter_type_list
						;
parameter_type_list
						:	parameter_list
						|	parameter_list COMMA DOTDOTDOT
						;
parameter_list
						:	parameter_declaration
						|	parameter_list COMMA parameter_declaration
						;
parameter_declaration
						:	declaration_specifiers declarator
						|	declaration_specifiers abstract_declarator
						|	declaration_specifiers
						;
abstract_declarator
						:	pointer
						|	direct_abstract_declarator
						|	pointer direct_abstract_declarator
						;
direct_abstract_declarator
						:	LPARAM abstract_declarator RPARAM
						|	LBIGPARAM constant_expression_opt RBIGPARAM
						|	LPARAM parameter_type_list_opt RPARAM
						|	direct_abstract_declarator LBIGPARAM constant_expression_opt RBIGPARAM
						|	direct_abstract_declarator LPARAM parameter_type_list_opt RPARAM
						;

initializer
						:	constant_expression
						|	LMIDPARAM initializer_list RMIDPARAM
						;
initializer_list
						:	initializer
						|	initializer_list COMMA initializer
						;
statement
						:	labeled_statement
						|	compound_statement
						|	expression_statement
						|	selection_statement
						|	iteration_statement
						|	jump_statement
						;
labeled_statement
						:	CASE_SYM constant_expression COLON statement
						|	DEFAULT_SYM COLON statement
						;
compound_statement
						:	LMIDPARAM declaration_list statement_list RMIDPARAM
						;
declaration_list
						:
						|	declaration_list declaration
						;
statement_list
						:
						|	statement_list statement
						;
expression_statement
						:	SEMICOLON
						|	expression SEMICOLON
						;
selection_statement
						:	IF_SYM LPARAM expression RPARAM statement
						|	IF_SYM LPARAM expression RPARAM statement ELSE_SYM statement
						|	SWITCH_SYM LPARAM expression RPARAM statement
						;
iteration_statement
						:	WHILE_SYM LPARAM expression RPARAM statement
						|	DO_SYM statement WHILE_SYM LPARAM expression RPARAM
						|	FOR_SYM LPARAM expression_opt SEMICOLON expression_opt SEMICOLON expression_opt RPARAM statement
						;
jump_statement
						:	RETURN_SYM expression_opt SEMICOLON
						|	CONTINUE_SYM SEMICOLON
						|	BREAK_SYM SEMICOLON
						;
expression_opt
						:
						|	expression
						;

primary_expression
						:	IDENTIFIER
						|	INTEGER_CONSTANT
						|	FLOAT_CONSTANT
						|	CHARACTER_CONSTANT
						|	STRING_LITERAL
						|	LPARAM expression RPARAM
						;
postfix_expression
						:	primary_expression
						|	postfix_expression LBIGPARAM expression RBIGPARAM
						|	postfix_expression LPARAM arg_expression_list_opt RPARAM
						|	postfix_expression DOT IDENTIFIER
						|	postfix_expression ARROW IDENTIFIER
						|	postfix_expression PLUSPLUS
						|	postfix_expression MINUSMINUS
						;
arg_expression_list_opt
						:
						|	arg_expression_list
						;
arg_expression_list
						:	assignment_expression
						|	arg_expression_list COMMA assignment_expression
						;
unary_expression
						:	postfix_expression
						|	PLUSPLUS unary_expression
						|	MINUSMINUS unary_expression
						|	AND cast_expression
						|	STAR cast_expression
						|	NOT cast_expression
						|	MINUS cast_expression
						|	PLUS cast_expression
						|	SIZEOF_SYM unary_expression
						|	SIZEOF_SYM LPARAM type_name RPARAM
						;
cast_expression
						:	unary_expression
						|	LPARAM type_name RPARAM cast_expression
						;
type_name
						:	declaration_specifiers
						|	declaration_specifiers abstract_declarator
						;
multiplicative_expression
						:	cast_expression
						|	multiplicative_expression STAR cast_expression
						|	multiplicative_expression SLASH cast_expression
						|	multiplicative_expression PERCENT cast_expression
						;
additive_expression
						:	multiplicative_expression
						|	additive_expression PLUS multiplicative_expression
						|	additive_expression MINUS multiplicative_expression
						;
relational_expression
						:	additive_expression
						|	relational_expression LT additive_expression
						|	relational_expression GT additive_expression
						|	relational_expression LE additive_expression
						|	relational_expression GE additive_expression
						;
equality_expression
						:	relational_expression
						|	equality_expression EQUAL relational_expression
						|	equality_expression NOTEQUAL relational_expression
						;
logical_and_expression
						:	equality_expression
						|	logical_and_expression ANDAND equality_expression
						;
logical_or_expression
						:	logical_and_expression
						|	logical_or_expression OROR logical_and_expression
						;
assignment_expression
						:	logical_or_expression
						|	unary_expression ASSIGN assignment_expression
						;
comma_expression
						:	assignment_expression
						;
expression
						:	comma_expression
						;
constant_expression
						:	expression
						;
%%

extern char *yytext;

int yyerror(char *s)
{
	printf("line %d: %s near %s\n", line_no, s, yytext);
	return 0;
}

int main(void)
{
	yyparse();
	return 0;
}
