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

void push(int x)
{
	struct node *np;
	np=(struct node *)malloc(sizeof(struct node));
	np->data=x;
	np->next=top;
	top=np;
}

void display()
{
	struct node *np;
	for(np=top;np!=NULL;np=np->next)
		printf("%d\t",np->data);
}

void displayHalfEven(int size)
{
	struct node *np;
	int i;
	printf("\n\nFirst half Stack\n");
	for(np=top,i=1; i<=size; np=np->next,i++)
	{
		printf("%d\t",np->data);
	}
	
	printf("\n\nSecond half Stack\n");
	for(; i<=size*2; np=np->next,i++)
	{
		printf("%d\t",np->data);
	}	
}

void displayHalfOdd(int size)
{
	struct node *np;
	int i;
	printf("\n\nFirst half Stack\n");
	for(np=top,i=1; i<=size; np=np->next,i++)
	{
		printf("%d\t",np->data);
	}
	
	printf("\n\nSecond half Stack\n");
	for(; i<=(size*2)+1; np=np->next,i++)
	{
		printf("%d\t",np->data);
	}	
}

void sortStack()
{
	struct node *np,*np2;
	int temp;
	for(np=top;np!=NULL;np=np->next)
	{
		for(np2=np->next;np2!=NULL;np2=np2->next)
		{
			if(np->data > np2->data)
			{
				temp = np->data;
				np->data = np2->data;
				np2->data = temp;
			}
		}
	}
	
	printf("\n\nSorted Stack\n");
	display();
}

void checkDivisibility()
{
	struct node *np;
	printf("\n\nDivisibility by 8\n");
	for(np=top;np!=NULL;np=np->next)
	{
		if(np->data % 8 == 0)
		{
			printf("%d divisible by 8\n",np->data);
		}
	}
		
}

int main()
{
	int num,choice,i;
	char ch;
	init();
	do
	{
		printf("1.Half the stack \n2. Sort Stack \n3. Check Divisibility by 8 \n\n");
		scanf("%d",&choice);
		printf("\n\n");
		switch(choice)
		{
			case 1:
			{
				int size,num;
				printf("enter total number of elements in stack ");
				scanf("%d",&size);
				for(i=1;i<=size;i++)
				{
					printf("\nenter value %d to push ",i);
					scanf("%d",&num);
					push(num);
					printf("%d pushed to stack",num);
				}
				int stackHalfs = size/2;
				if(size%2 == 0)
				{
					
					displayHalfEven(stackHalfs);
				}
				else
				{
					displayHalfOdd(stackHalfs);
				}			
			}
			break;
			
			case 2:
			{
				int size,num;
				printf("enter total number of elements in stack ");
				scanf("%d",&size);
				for(i=1;i<=size;i++)
				{
					printf("\nenter value %d to push ",i);
					scanf("%d",&num);
					push(num);
					printf("%d pushed to stack",num);
				}
				sortStack();
			}
			break;
			
			case 3:
			{
				int size,num;
				printf("enter total number of elements in stack ");
				scanf("%d",&size);
				for(i=1;i<=size;i++)
				{
					printf("\nenter value %d to push ",i);
					scanf("%d",&num);
					push(num);
					printf("%d pushed to stack",num);
				}
				checkDivisibility();
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
