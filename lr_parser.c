#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define NUMBER 256
#define PLUS 257
#define STAR 258
#define LP 259
#define RP 260
#define END 261
#define EXP 0
#define TERM 1
#define FACTOR 2
#define ACC 999

#if 0
typedef struct tokenType{
int number; //token number
  union {
   float numb;
   int numa;
   } value; // token value
}Type;
#endif


int action[12][6]={{5,0,0,4,0,0},{0,6,0,0,0,ACC},{0,-2,7,0,-2,-2},{0,-4,-4,0,-4,-4},
               {5,0,0,4,0,0},{0,-6,-6,0,-6,-6},{5,0,0,4,0,0},{5,0,0,4,0,0},
               {0,6,0,0,11,0},{0,-1,7,0,-1,-1},{0,-3,-3,0,-3,-3},{0,-5,-5,0,-5,-5}};

int go_to[12][3]={{1,2,3},{0,0,0},{0,0,0},{0,0,0},{8,2,3},{0,0,0},{0,9,3},{0,0,10},{0,0,0},
              {0,0,0},{0,0,0},{0,0,0}};

int prod_left[7]={0,EXP,EXP,TERM,TERM,FACTOR,FACTOR}; 
int prod_lenght[7]={0,3,1,3,1,3,1}; 

int stack[1000];   int top=-1;      int sym;   int yyval;
int value[10];
int output;

void push(int);
void reduce(int);
void yyerror();
void lex_error();
int yyparse();
int yylex();
void shift(int);

int main()
{
      yyparse();
	 printf("output : %d \n",output);
	  return 0;
}

int yyparse()
{
      int i;
      stack[++top]=0;
      sym=yylex();

      do
      {   
            i=action[stack[top]][sym-256]; 
            if(i==ACC)   printf("succeses ! \n");

            else if(i>0) shift(i);

            else if(i<0) reduce(-i);

            else yyerror();
      }while(i!=ACC);

  return  0;	
}
#if 1
void push(int i)
{
      top++;
      stack[top]=i;
}
#endif
void shift(int i)
{
      push(i);
      value[top]=yyval;
      sym=yylex();
}

void reduce(int i)
{	  
      int old_top;
      top-=prod_lenght[i];
      old_top=top;
      switch(i)
      {
            case 1:
                  value[top]=stack[old_top+1]+value[old_top+3];
                  break;
            case 2:
                  value[top]=value[old_top+1];
                  break;
            case 3:
                  value[top]=value[old_top+1]*value[old_top+3];
				  output=value[top]+value[1];
                  break;
            case 4:
                  value[top]=value[top+1];
                  break;
            case 5:
                  value[top]=value[old_top+2];
				  break;
            case 6:
                  value[top]=value[old_top+1];
                  break;
            default:
                  yyerror();
                  break;
      }
	  push(go_to[stack[old_top]][prod_left[i]]);
}

void yyerror()
{
      printf("syntax error\n");
      exit(1);
}

int yylex()
{
      
   char text[32];
   int i=0;
   static char ch=' ';
	while(ch==' '||ch=='\t'||ch=='\n') ch=getchar();

    if(isdigit(ch))
    {
	   do
	   {
		   text[i++]=ch;
		   ch=getchar();
	   }while(isdigit(ch));

		text[i]=0;
		yyval=atoi(text);
	    return(NUMBER);
   }
                
    else if(ch=='+')
	{
		ch=getchar();
        return(PLUS);}

    else if(ch=='*')
	{
		ch=getchar();
        return(STAR);}
         
    else if(ch=='('){
		ch=getchar();
        return(LP);}

    else if(ch==')'){
		ch=getchar();
                return(RP);}
	else if(ch==EOF)
		return(END);
   else
	   lex_error();

 return 0;
}
void lex_error()
{
      printf("illegal token!\n");
      return;
}
