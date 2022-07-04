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

void addatbeg(int x)
{
	struct node *np,*temp;
	np=(struct node *)malloc(sizeof(struct node));
	np->data=x;
	np->next=NULL;
	if(empty())
	{
		head=np;
		np->next=head;
	}
	else
	{
		np->next=head;
		temp=head;
		while(temp->next!=head)
			temp=temp->next;
		temp->next=np;
		head=np;
	}
	printf("inserted successfully!!!");
	count++;
}

void addatmid(int pos,int x)
{
	int i;
	if(pos<1 || pos>count)
	{
		printf("Wrong Input!!!");
	}	
	else
	{
		struct node *np,*temp;
		np=(struct node *)malloc(sizeof(struct node));
		np->data=x;
		np->next=NULL;
		
		for(temp=head,i=1;i<pos-1;temp=temp->next,i++);
		
		np->next=temp->next;
		temp->next=np;	
		printf("inserted successfully!!!");
		count++;
	}
}

void addatend(int x)
{
	if(count==0)
		printf("Linked List Empty!!!");
	else
	{
		struct node *temp;
		temp=head;
		while(temp->next!=head)
			temp=temp->next;
		
		struct node *np;
		np=(struct node *)malloc(sizeof(struct node));
		np->data=x;
		np->next=NULL;
		
		np->next=temp->next;
		temp->next=np;
		temp=np;
		
		printf("inserted successfully!!!");
		count++;	
	}	
}

int deletefrombeg()
{
	if(count==0)
		printf("Error!!!");
	else
	{
		struct node *lastptr,*firstptr;
		
		lastptr=head;
		while(lastptr->next!=head)
			lastptr=lastptr->next;
		
		firstptr=head;
		head=firstptr->next;
		
		return firstptr->data;
		
		lastptr->next=head;
		free(firstptr);	
		
		count--;
	}
}

int deletefrommid(int pos)
{
	if(count==0 || pos>count)
		printf("Error!!!");
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

int deletefromend()
{
	if(count==0)
		printf("Error!!!");
	else
	{
		struct node *nextptr,*prevptr;
		
		prevptr=head;
		while(prevptr->next->next!=head)
			prevptr=prevptr->next;
			
		nextptr=prevptr->next;
		
		prevptr->next=nextptr->next;
		return nextptr->data;
		free(nextptr);
		count--;
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
		nextptr=head;
		do
		{
			printf("%d\t",nextptr->data);
			nextptr=nextptr->next;
		}
		while(nextptr!=head);
		
	}
}

int main()
{
	int num,del,choice;
	init();
	do
	{
		printf("\n\n1. insert at begining \n2. insert at middle \n3. insert at end \n");
		printf("4. delete from begining \n5. delete from middle \n6. delete from end \n");
		printf("7. display \n8. Exit\n\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("enter number  ");
				scanf("%d",&num);
				addatbeg(num);
			}
			break;
			
			case 2:
			{
				if(empty())
				{
					printf("Linked List is empty\n\n");
				}
				else
				{
					int pos;
					printf("enter number to insert  ");
					scanf("%d",&num);
					printf("enter the position to insert  ");
					scanf("%d",&pos);
					addatmid(pos,num);
				}
			}
			break;
			
			case 3:
			{
				printf("enter number to insert  ");
				scanf("%d",&num);
				addatend(num);
			}
			break;
			
			case 4:
			{
				del=deletefrombeg();
				printf("deleted element = %d ",del);
			}
			break;
			
			case 5:
			{
				printf("enter node position to delete  ");
				scanf("%d",&num);
				del=deletefrommid(num);
				printf("deleted element = %d ",del);
			}
			break;
			
			case 6:
			{
				del=deletefromend();
				printf("deleted element = %d ",del);
			}
			break;
			
			case 7:
			{
				if(empty())
					printf("Linked List is empty\n");
				else
					display();
			}
			break;	
			
			case 8:
			{
				exit(0);
			}
			break;		
			
			default:
				printf("enter correct option.\n");
		}
	}
	while(choice!=8);
	return 0;
}
