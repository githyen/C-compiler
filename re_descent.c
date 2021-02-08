#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>


float num;

enum{NUMBER,PLUS,STAR,MINUS,DIV,LP,RP,END} token;
int get_token();
void error(int i);
float factor();
float term();
float exp_s();

int  main()
{
	float result;
	get_token();
	result=exp_s();
	if(token!=END)
		error(3);
	else
		printf("%.2f \n",result);

	return 0;
}

float exp_s()
{
	float result;
	result=term();
	if(token==PLUS)
	{
		get_token();
		result=result+term();
	}
    if(token==MINUS)
	{
			get_token();
			result=result-term();
	}

	return result;
}

float term()
{
	float result;
	result=factor();
    while(token==STAR)
	{
		get_token();
		result=result*factor();
	}
	while(token==DIV)
	{
			get_token();
			result=result/factor();
	}
	return result;
}

float factor()
{
	float result;
	if(token==NUMBER)
	{
		result=num;
		get_token();
		
	}
	else if(token==LP)
	{
		get_token();
		result=exp_s();
		if(token==RP)
			get_token();
		else
			error(2);
	}
	else
		error(1);
	return result;
}

int get_token()
{
    char text[32];
	int i=0;
    int ch;
   printf("토큰입력 :");
    while(1)
	{
		ch=getchar();
		text[i++]=ch;
		if(ch=='\n') break;
	}
    text[i]=0;	

   for(int i=0; text[i]!='\n'; i++)
   {
		   if(text[i]>='0' && text[i]<='9'||text[i]=='.')
		   {
				   num=atof(text);
				   token=NUMBER;
		   }
			else if(text[i]=='+')
				   token=PLUS;
			else if(text[i]=='*')
				   token=STAR;
		   else if(text[i]=='-')
				   token=MINUS;
		   else if(text[i]=='/')
				   token=DIV;
			else if(text[i]=='(')
		    token=LP;
		    else if(text[i]==')')
		    token=RP;
	     	else
	    	token=END;
   }

	return 0;
}

void error(int i)
{
	switch(i)
	{
		case 1:
			printf("error(1): number or'('expected\n");
			break;
		case 2:
			printf("error(2): ')'expected\n");
			break;
		case 3:
			printf("error(3): EOF expected\n");
			break;
	}
}
