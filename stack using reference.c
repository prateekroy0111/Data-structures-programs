#include<stdio.h>
#include<conio.h>
#define max 4

typedef struct
{
	int data[max];
	int top;
}stack;

void init(stack *s);
void push(stack *s,int);
int pop(stack *s);
int full(stack *s);	//overflow
int empty(stack *s);	//underflow
void display(stack *s);

void init(stack *s)
{
	s->top=0;
}

void push(stack *s,int x)
{
	s->data[s->top]=x;
	s->top++;
}

int pop(stack *s)
{
	s->top--;
	return s->data[s->top];
}

int full(stack *s)
{
	return s->top==max;
}

int empty(stack *s)
{
	return s->top==0;
}

void display(stack *s)
{
	int i;
	for(i=0;i<s->top;i++)
	{
		printf("%d\n",s->data[i]);
	}
}

int main()
{
	stack s;

	int num,del,choice;
	char ch;
	init(&s);
	do
	{
		printf("1. push \n2. pop \n3. display \n\n");
		scanf("%d",&choice);
		printf("\n\n\n\n");
		switch(choice)
		{
			case 1:
			{
				if(full(&s))
				{
					printf("Stack is full");
				}
				else
				{
					printf("enter number  ");
					scanf("%d",&num);
					push(&s,num);
				}
			}
			break;
			
			case 2:
			{
				if(empty(&s))
				{
					printf("stack is empty\n\n");
				}
				else
				{
					del=pop(&s);
					printf("deleted element = %d",del);
				}
			}
			break;
			
			case 3:
			{
				if(empty(&s))
				{
					printf("stack is empty\n\n");
				}
				else
				{
					display(&s);
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
	return 0;
}
