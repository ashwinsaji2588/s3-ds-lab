#include<stdio.h>
#include<stdlib.h>
struct node
{   
	int data;
	struct node *link;
}*start=NULL;
void insert_beg(int dt)
{   
	struct node *newn=(struct node*)malloc(sizeof(struct node));
	newn->data=dt;
	newn->link=start;
	start=newn;
}
void insert_end(int dt)
{
	struct node *newn=(struct node *)malloc(sizeof(struct node));
	newn->data=dt;
	newn->link=NULL;
	if(start==NULL)
        	start=newn;
	else
	{
		struct node *temp=start;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=newn;
	}
}
void insert_aft(int dt,int key)
{
	if(start==NULL)
		printf("UNDERFLOW!!\n");
	else
	{
		struct node *newn=(struct node*)malloc(sizeof(struct node));
		newn->data=dt;
		struct node *temp=start;
		while(temp->data!=key)
		{
			temp=temp->link;
		}
		newn->link=temp->link;
		temp->link=newn;
	}
}
void del_beg()
{
	if(start==NULL)
		printf("UNDERFLOW!!\n");
	else if(start->link==NULL)
	{
		printf("Deleted Element: %d\n",start->data);
		free(start);
		start=NULL;
	}
	else
	{   
		struct node *temp=start;
		start=start->link;
		printf("Deleted Element: %d\n",temp->data);
		free(temp);
	}
}
void del_end()
{
	if(start==NULL)
		printf("UNDERFLOW!!\n");
	else if(start->link==NULL)
	{
		printf("Deleted Element: %d\n",start->data);
		free(start);
		start=NULL;
	}
	else
	{   
		struct node *prev;
		struct node *temp=start;
		while(temp->link!=NULL)
		{   
			prev=temp;
			temp=temp->link;
		}
		printf("Deleted Element: %d\n",temp->data);
		free(temp);
		prev->link=NULL;
	}
}
void del_sp(int dt)
{
	if(start==NULL)
		printf("UNDERFLOW!!\n");
	else if(start->link==NULL)
	{
		printf("Deleted Element: %d\n",start->data);
		free(start);
		start=NULL;
	}
	else
	{   
		struct node *prev;
		struct node *temp=start;
		while(temp->data!=dt)
		{   
			prev=temp;
			temp=temp->link;
		}
		prev->link=temp->link;
		printf("Deleted Element: %d\n",temp->data);
		free(temp);
	}
}
void display()
{
	if(start==NULL)
	printf("UNDERFLOW!!\n");
	else
	{
		struct node *temp=start;
		while(temp!=NULL)
		{   
			printf("%d\t",temp->data);
			temp=temp->link;
		}
	}
}
void main()
{
	int c,dt,op,ch,key;
	do
	{  
	printf("\nMenu\n");
	printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&c);
	switch(c)
	{   
	case 1: 
		printf("\n\t1. Insert at the beginning\n\t2. Insert at the end\n\t3. Insert after a specified node\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		printf("Enter the Element to insert:\n");
		scanf("%d",&dt);
		switch(ch)
		{
			case 1:
				insert_beg(dt);
				break;
			case 2:
				insert_end(dt);
				break;
			case 3:
				printf("Enter the specified node value:\n");
				scanf("%d",&key);
				insert_aft(dt,key);
				break;
			default:
				printf("!nvalid Input!!\n");
		}
		break;
	case 2:
		printf("\n\t1. Delete from the beginning\n\t2. Delete from the end\n\t3. Delete a specified node\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				del_beg();
				break;
			case 2:
				del_end();
				break;
			case 3:
				printf("Enter the specified node value:\n");
				scanf("%d",&dt);
				del_sp(dt);
				break;
			default:
				printf("Invalid Input!!\n");
		}
		break;
	case 3:
		display();
		break;
	case 4: 
		exit(0);
		break;
        default:
        	printf("Invalid Input!!\n");
	}
 }while(c>=1&&c<=4);
}
