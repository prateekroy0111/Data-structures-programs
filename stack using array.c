#include<stdio.h>
#include<conio.h>
#define max 3

struct stack
{
	int data[max];
	int top;
}s;

void init();
void push(int);
int pop();
int full();	//overflow
int empty();	//underflow
void display();

void init()
{
	s.top=0;
}

void push(int x)
{
	s.data[s.top]=x;
	s.top++;
}

int pop()
{
	s.top--;
	return s.data[s.top];
}

int full()
{
	return s.top==max;
}

int empty()
{
	return s.top==0;
}

void display()
{
	int i;
	for(i=0;i<s.top;i++)
	{
		printf("%d\n",s.data[i]);
	}
}

int main()
{
	int num,del,choice;
	char ch;
	init();
	do
	{
		printf("1. push \n2. pop \n3. display \n\n");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1:
			{
				if(full())
				{
					printf("Stack is full");
				}
				else
				{
					printf("enter number  ");
					scanf("%d",&num);
					push(num);
				}
			}
			break;
			
			case 2:
			{
				if(empty())
				{
					printf("stack is empty\n\n");
				}
				else
				{
					del=pop();
					printf("deleted element = %d",del);
				}
			}
			break;
			
			case 3:
			{
				if(empty())
					printf("stack is empty\n\n");
				else
					display();
			}
			break;		
			
			default:
				printf("enter correct option.\n\n");
		}
		printf("\n\nenter y or Y to continue  ");
		scanf(" %c",&ch);
	}
	while(ch=='y'||ch=='Y');
	return 0;
}
