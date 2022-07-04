#include<stdio.h>
#include<conio.h>
#define max 3

int data[max];
int top;

void init();
void push();
void pop();
int full();
int empty();
void display();

void init()
{
	top=0;
}

void push(int x)
{
	data[top]=x;
	top++;
}

void pop()
{
	top--;
}

int full()
{
	return top==max;
}

int empty()
{
	return top==0;
}

void display()
{
	int i;
	for(i=0;i<top;i++)
	{
		printf("%d\n",data[i]);
	}
}

void main()
{
	int choice, num;
	char ch;
	do
	{
		printf("1. push \n2. pop \n3. display \n\n");
		scanf("%d",&choice);
		printf("\n\n");
		
		switch(choice)
		{
			case 1:
			{
				if(full())
				{
					printf("stack full\n\n");
				}
				else
				{
					printf("enter number  ");
					scanf("%d",&num);
					push(num);
					printf("element added to the stack");
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
					pop();
					printf("element deleted");
				}
			}
			break;
			
			case 3:
			{
				if(empty())
				{
					printf("stack is empty\n\n");
				}
				else
				{
					display();
				}
			}
			break;		
			
			default:
				printf("enter correct option.\n\n");
		}
		printf("\n\nenter y or Y to continue  ");
		scanf(" %c",&ch);
	}
	while(ch=='y'||ch=='Y');	
}
