#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head;
int count=0;

void init()
{
	head=NULL;
}

int empty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}

void insert(int x)
{
	struct node *np,*nextptr,*preptr;
	np=(struct node *)malloc(sizeof(struct node));
	np->data=x;
	np->next=NULL;
	
	if(empty())
		head=np;
		
	else if(x < head->data)
	{
		np->next=head;
		head=np;
	}
	
	else
	{
		preptr=head;
		nextptr=preptr->next;
		while(nextptr!=NULL)
		{
			if(preptr->data < x && nextptr->data > x)
			{
				preptr->next=np;
				np->next=nextptr;	
				break;
			}
			else
			{
				preptr=nextptr;
				nextptr=preptr->next;
			}
		}
		preptr->next=np;
	}
	printf("inserted successfully!!!");
}
int deletefrombeg()
{
	if(empty())
	{
		printf("empty\n");
	}
	else
	{
		struct node *nextptr;
		nextptr=head;
		head=head->next;
		nextptr->next=NULL;
		return nextptr->data;
		free(nextptr);
	}
}

int deletefrommid(int pos)
{
	if(empty())
	{
		printf("empty\n");
	}
	else
	{
		int i;
			struct node *nextptr,*prevptr;
			for(prevptr=head,i=1;i<pos-1;prevptr=prevptr->next,i++);
			nextptr=prevptr->next;
			prevptr->next=nextptr->next;
			return nextptr->data;
			free(nextptr);
	}
}

void display()
{
	if(empty())
	{
		printf("empty\n");
	}
	else
	{
		struct node *nextptr;
		printf("display all nodes\n");
		for(nextptr=head;nextptr!=NULL;nextptr=nextptr->next)
		{
			printf("%d\t",nextptr->data);
		}
	}	
}

int main()
{
	int num,del,choice;
	init();
	do
	{
		printf("\n\n1. insert \n2. delete from begining \n3. delete from position \n4. display \n5. exit\n\n");
		scanf("%d",&choice);
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
				del=deletefrombeg();
				printf("deleted element = %d ",del);
			}
			break;
			
			case 3:
			{
				printf("enter node position to delete  ");
				scanf("%d",&num);
				del=deletefrommid(num);
				printf("deleted element = %d ",del);
			}
			break;
			
			case 4:
			{
				if(empty())
					printf("Linked List is empty\n");
				else
					display();
			}
			break;
			
			case 5:
			{
				exit(0);
			}
			break;		
			
			default:
				printf("enter correct option.\n");
		}
	}
	while(choice!=5);
	return 0;
}
