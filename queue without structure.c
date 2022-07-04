#include<stdio.h>
#include<string.h>
#define MAX 4

int data[MAX];
int front,rear;

void init();

void init()
{
	front=0;
	rear=0;
}

int empty()
{
	if(front==rear)
		return 1;
	else
		return 0;
}

int full()
{
	if(rear==MAX)
		return 1;
	else
		return 0;
}

void add(int x)
{
	data[rear]=x;
	rear++;
}

int deletee()
{
	return data[front++];
}

void display()
{
	for(i=front;i<rear;i++)
	{
		printf("%d\n",data[i]);
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
		printf("\n\n\n\n");
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
					printf("elements in the queue - \n");
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
