#include<stdio.h>
#include<stdlib.h>
void push(int a[],int *top,int n,int data)
{
	if(*top==n-1)
		printf("\n****Stack overflow****");
	else
	{
		(*top)++;
		a[*top]=data;
	}
}
void pop(int a[],int *top)
{
	if(*top==-1)
		printf("\n****Stack underflow****");
	else
		printf("****\n%d deleted****",a[(*top)--]);
}
void peep(int a[],int *top,int n)
{
	if(*top==-1)
		printf("\n****Stack underflow****");
	else
		printf("\n%d",a[*top]);
}
void is_full(int *top,int n)
{
	if(*top==n-1)
		printf("\n****Stack overflow****");
	else
		printf("\n****Stack Not full****");
}
void is_empty(int *top,int n)
{
	if(*top==-1)
		printf("\n****Stack underflow****");
	else
		printf("\n****Stack not empty****");
}
void display(int a[],int *top,int n)
{
	int i;
	if(*top==-1)
		printf("\n****Stack underflow****");
	else
	{
		for(i=0;i<=*top;i++)
			printf("%d\t",a[i]);
	}
}
void main()
{
	int top=-1,a[15],ch,n,data;
	printf("Enter the stack size:");
	scanf("%d",&n);
	do
	{
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Is full\n5.Is empty\n6.Display\n7.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
			if(ch==1)
			{
			    printf("\nEnter the data:");
				scanf("%d",&data);
				push(a,&top,n,data);
			}
			else if(ch==2)
				pop(a,&top);
			else if(ch==3)
				peep(a,&top,n);
			else if(ch==4)
				is_full(&top,n);
			else if(ch==5)
				is_empty(&top,n);
			else if(ch==6)
				display(a,&top,n);
			else if(ch==7)
				exit(0);
			else
				printf("Wrong input");
	}while(1);	
}
