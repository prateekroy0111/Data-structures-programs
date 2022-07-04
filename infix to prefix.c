/*
scan infix expression
reverse it
then convert it to postfix expression
then reverse it again that's the prefix expression
*/
#include<stdio.h>
#include<string.h>

void init();
void push(char);
char pop();
int empty();
int priority(char);

struct stack
{
	char data[10];
	int top;
}s;

void init()
{
	s.top=-1;
}

void push(char x)
{
	s.data[++s.top]=x;
	printf("pushed -> %c at s.data[%d]\n\n",x,s.top);
}

char pop()
{
	return s.data[s.top--];
}

int empty()
{
	if (s.top==-1)
		return 1;
}

int priority(char c)
{
	if(c=='+' || c=='-')
		return 1;
	if(c=='*' || c=='/')
		return 2;
}
 
int main()
{
	int i,j=0,len=0;
	char str[10],out[10];
	
	init();
	
	printf("enter the infix expression  ");
	scanf("%s",str);
	
	strrev(str);
	puts(str);
	
	len=strlen(str);
	
	for(i=0;i<=len-1;i++)
	{
		if(isalnum(str[i]))
		{
			out[j]=str[i];
			printf("out[%d] = %c\n",j,out[j]);
			j++;
		}
		if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
		{
			if(empty())
			{
				printf("stack empty \n");
				push(str[i]);
			}
				
			else
			{
				printf("str[i] = %c , s.data[s.top] = %c\n",str[i],s.data[s.top]);
					
				int p1=priority(str[i]);
				int p2=priority(s.data[s.top]);
				printf("p1 = %d  p2 = %d\n\n",p1,p2);
				
				if(p1>=p2)
				{
					push(str[i]);
				}
				else
				{
					out[j]=pop();
					printf("popped out[%d] = %c\n\n",j,out[j]);
					push(str[i]);
					j++;
				}
			}
		}	
	}
	
	
	printf("\n\ninside stack\n\n");
	
	while(s.top!=-1)
	{
		printf("s.data[s.top] = %c\n",s.data[s.top]);
		printf("s.top = %d\n",s.top);
		out[j]=pop();
		printf("popped out[%d] = %c\n\n",j,out[j]);
		j++;
	}
	out[j]='\0';
	
	strrev(out);
	
	printf("prefix expression    ");
	puts(out);
	
	return 0;
}
