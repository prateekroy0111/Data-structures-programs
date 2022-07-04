#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;	
};
struct node *f,*r;

void init()
{
	f=NULL;	
	r=NULL;	
}

int empty()
{
	//if(f==NULL && r==NULL)
	if(f==NULL)
		return 1;
	else	
		return 0;
}

void insert(int x)
{
	struct node *np;
	np=(struct node *)malloc(sizeof(struct node));
	np->data=x;
	np->next=NULL;
	if(f==NULL)	//for first node
	{
		f=np;
		r=np;
	}
	else
	{
		r->next=np;
		r=np;
	}	
}

int deletee()
{
	struct node *np;
	int x;
	np=f;
	x=np->data;
	f=f->next;
	if(f==NULL)	//if single node is left
		r=NULL;
	free(np);
	return x;	
}

void display()
{
	struct node *np;
	for(np=f;np!=NULL;np=np->next)
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
				insert(num);
			}
			break;
			
			case 2:
			{
				if(empty())
				{
					printf("Queue is empty\n\n");
				}
				else
				{
					del=deletee();
					printf("deleted element = %d",del);
				}
			}
			break;
			
			case 3:
			{
				if(empty())
				{
					printf("Queue is empty\n\n");
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
