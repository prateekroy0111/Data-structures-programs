#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;	
};
struct node *top;

void init()
{
	top=NULL;	
}

int empty()
{
	if(top==NULL)
		return 1;
	else	
		return 0;
}

void push(int x)
{
	struct node *np;
	np=(struct node *)malloc(sizeof(struct node));
	np->data=x;
	np->next=top;
	top=np;
}

int pop()
{
	struct node *np;
	int x;
	np=top;
	x=np->data;
	
	top=top->next;
	free(np);
	return x;	
}

void display()
{
	struct node *np;
	for(np=top;np!=NULL;np=np->next)
		printf("data = %d\n",np->data);
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
		printf("\n\n");
		switch(choice)
		{
			case 1:
			{
				printf("enter number  ");
				scanf("%d",&num);
				push(num);
				
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
	return 0;
}
