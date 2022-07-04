#include<conio.h>
#include<stdio.h>
#define MAX 20

void show(int stack[],int size,int top)
{
   int i;
   for(i=0;i<size;i++)
   {
      printf("\nValue at %d is %d",top,stack[top]);
      top=top-1;
   }
}
void reverse(int stack[],int qu[],int *t,int *r,int *f)
{
   *f=0;
   while(*t>-1)
   {
      *r=*r+1;
      qu[*r]=stack[*t];
      *t=*t-1;
   }
   while(*f<=*r)
   {
      *t=*t+1;
      stack[*t]=qu[*f];
      *f=*f+1;
   }
}
void main()
{
   int size;
   int item,t,i,stack[MAX],queue[MAX];
   int top=-1,front=-1,rear=-1;

   printf("Enter size of stack::");
   scanf("%d",&size);
   for(i=0;i<size;i++)
   {
      top=top+1;
      printf("Enter value of for position %d ::",top);
      scanf("%d",&item);
      stack[top]=item;
   }
   show(stack,size,top);
   reverse(stack,queue,&top,&rear,&front);
   printf("\n\nAfter reverse..............\n\n");
   show(stack,size,top);
   getch();
}
