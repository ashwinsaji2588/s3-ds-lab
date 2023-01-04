#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,q[20],p[20];
void sort()
{
	int i,j,temp=0;
	for(i=front;i<rear;i++)    
	{    
		for(j=i+1;j<=rear;j++)    
		{    
			if(p[j]<p[i])    
			{            
				temp=q[i];    
				q[i]=q[j];    
				q[j]=temp;  
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;   
			}     
		}     
	} 
}
void enqueue(int data,int P,int n)
{
	if(rear==n-1)
		printf("\n****Queue overflow****");
	else if(front==-1 && rear==-1)
	{
		front=0;rear=0;
		q[rear]=data;
		p[rear]=P;
	}
	else
	{
		rear++;
		q[rear]=data;
		p[rear]=P;
	}
}
void dequeue()
{
	if(front==-1 && rear==-1)
		printf("\n****Queue underflow****");
	else if(front==rear)
	{
		printf("\n%d deleted",q[front]);
		front=-1;rear=-1;
	}
	else 
	{
		printf("\n%d deleted",q[front]);
		front++;
	}
}
void display()
{
	int i;
	if(front==-1 && rear==-1)
		printf("\n****Queue underflow****");
	else
	{
		printf("\nQueue elements:");
		for(i=front;i<=rear;i++)
			printf(" %d\t",q[i]);
		printf("\nPriority:\t");
		for(i=front;i<=rear;i++)
			printf("%d\t ",p[i]);
	}
}
void main()
{
	int ch,data,n,p;
	printf("Enter the queue size:");
	scanf("%d",&n);
	do
	{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the data:");
				scanf("%d",&data);
				printf("\nEnter priority:");
				scanf("%d",&p);
				enqueue(data,p,n);
				break;
			case 2:
				sort();
				dequeue();
				break;
			case 3:
				sort();
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nWrong input");
				break;
		}
	}while(1);
}
