# C-compiler
C project (compiler)

------------
grammer file

yacc -d test.y
lex test.l

gcc lex.yy.c y.tab.c

a.out < file name
-----------------
semantic file

gcc func.c main.c print.c sem_print.c semantic.c lex.yy.c y.tab.c
-----------------------------------------------------------------




