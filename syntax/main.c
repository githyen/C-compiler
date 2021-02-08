#include<stdio.h>
#include<stdlib.h>
#include"type.h"
extern int syntax_err;
extern A_NODE *root;
extern FILE *yyin;
int main(int argc, char *argv[]) { 
		if((yyin=fopen(argv[argc-1],"r"))==NULL){
			printf("can not open input file: %s\n",argv[argc-1]);
			exit(1);
		} 
		initialize(); 
		yyparse(); 
		if(!syntax_err)
		print_ast(root); 
		return 0;
} 

