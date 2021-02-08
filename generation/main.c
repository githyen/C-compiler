#include<stdio.h>
#include<stdlib.h>
#include"type.h"
extern int syntax_err;
extern int semantic_err;
extern A_NODE *root;
FILE *fout;
FILE *yyin;
void initialize();
void print_ast();
void print_sem_ast();
void code_generation();
void semantic_analysis();
void main(int argc, char **argv)
{
		if((yyin=fopen(argv[argc-1],"r"))==NULL)
		{
				fprintf(stderr,"con not open input file : %s \n",argv[argc-1]);
				exit(1);
		}
		initialize();
		yyparse();
		if(syntax_err) exit(1);
		semantic_analysis(root);
		if(semantic_err) exit(1);
		if((fout=fopen("a.asm","w"))==NULL)
		{
				printf("con not open output file:a.asm\n");
				exit(1);
		}
		fprintf(fout,"SUB 0,0");
		code_generation(root);
		fclose(yyin);
		fclose(fout);
		return;
}
