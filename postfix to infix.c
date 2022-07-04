#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 10

struct stack
{
	char data[max][max];
	int top;
}s;

void init();
void push(char *);
char * pop();
void display();

void init()
{
	s.top=0;
}

void push(char *x)
{
	puts(x);
	strcpy(s.data[s.top],x);
	s.top++;
}

char * pop()
{
	s.top--;
	return s.data[s.top];
}

int main()
{
	char str[10],temp[10],b[max],op1[max],op2[max];
	int i,len;
	
	printf("enter postfix expression  ");
	gets(str);
	printf("\n\n\nelement pushed\n");
	init();
	len=strlen(str);
	
	for(i=0;i<len;i++)
	{
		temp[0]=str[i];
		temp[1]='\0';
		if(isalnum(str[i]))
		{
			push(temp);
		}
		else
		{
			strcpy(op2,pop());
			strcpy(op1,pop());
			
			strcat(op1,temp);
			strcat(op1,op2);
			
			push(op1);
		}
	}
	printf("\n\n\npostfix expression\t%s",s.data[--s.top]);
	return 0;
}
