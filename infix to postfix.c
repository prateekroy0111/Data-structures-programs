#include<stdio.h>
#include<conio.h>
#include<ctype.h>

struct stack
{
	char data[10];
	int top;
}s;

int count=0;

void init()
{
	s.top=-1;
}

void push(char c)
{
	printf("pushed = %c\n\n",c);
	s.data[++s.top]=c;
}

char pop()
{
	return s.data[s.top--];
}

int empty()
{
	return s.top==-1;
}

int priority(char c)
{
	if(c=='+' || c=='-')
		return 1;
	if(c=='/' || c=='*')
		return 2;
}

int main()
{
	char str[20],out[20];
	int i,j=0;
	printf("enter equation  ");
	scanf("%s",str);
	init();
	for(i=0;str[i]!='\0';i++)
	{
		if(isalnum(str[i]))
		{
			out[j]=str[i];
			printf("out[%d] = %c\n",j,out[j]);
			j++;
		}
		else
		{
			if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
			{
				if(empty())
					push(str[i]);	
				else
				{
					printf("str[i] = %c , s.data[s.top] = %c\n",str[i],s.data[s.top]);
					
					int p1=priority(str[i]);
					int p2=priority(s.data[s.top]);
					printf("p1 = %d  p2 = %d\n\n",p1,p2);
					
					if(p1>p2)
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
	}
	
	while(s.data[s.top]!='\0')
	{
		printf("s.top = %d\n",s.top);
		out[j]=pop();
		printf("popped out[%d] = %c\n\n",j,out[j]);
		j++;
	}
	out[j]='\0';
	puts(out);
	
	return 0;
}
