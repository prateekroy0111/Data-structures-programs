#include<stdio.h>
#include<string.h>
#define MAX 4

struct queue
{
	int data[MAX];
	int front,rear;
}q;

void init();

void init()
{
	q.front=0;
	q.rear=0;
}

int empty()
{
	if(q.front==q.rear)
		return 1;
	else
		return 0;
}

int full()
{
	if(q.rear==MAX)
		return 1;
	else
		return 0;
}

void add(int x)
{
	q.data[q.rear]=x;
	q.rear++;
}

int deletee()
{
	return q.data[q.front++];
}

void display()
{
	int i;
	for(i=q.front;i<q.rear;i++)
	{
		printf("%d\n",q.data[i]);
	}
}

int main()
{
	int num,del,choice;
	char ch;
	init();
	do
	{
		printf("1. add \n2. delete \n3. display \n\n");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1:
			{
				if(full())
				{
					printf("Queue is full");
				}
				else
				{
					printf("enter number to insert  ");
					scanf("%d",&num);
					add(num);
				}
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
