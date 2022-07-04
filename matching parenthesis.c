#include<stdio.h>
#include<conio.h>

struct stack
{
	char data[10];
	int top;
}s;
int count=0;

void init()
{
	s.top=0;
}

void push(char c)
{
	s.data[s.top]=c;
	s.top++;
	count++;
}

void pop()
{
	s.top--;
	count--;
}

int empty()
{
	return s.top==0;
}

int full()
{
	return s.top==10;
}

int main()
{
	char str[20];
	int i;
	printf("enter equation  ");
	scanf("%s",str);
	init();
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='(')
		{
			push(str[i]);
		}
		if(str[i]==')')
		{
			if(empty())
			{
				printf("invalid equation \n\n");
				return 0;
			}
			else
				pop(str[i]);
		}	
	}
	
	if(count==0)
		printf("parenthesis matched \n\n");
	else
		printf("parenthesis not matched \n\n");
		
	return 0;
}
