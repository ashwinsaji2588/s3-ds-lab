#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff,exp;
	struct node *link;
}*start1=NULL,*start2=NULL,*start3=NULL;
struct node* insert(struct node* start,int coeff,int exp)
{
	struct node *newn=(struct node*)malloc(sizeof(struct node));
	newn->coeff=coeff;
	newn->exp=exp;
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
	return start;
}
void display(struct node *start)
{
	if(start==NULL)
		printf("UNDERFLOW!!\n");
	else
	{
		struct node *temp=start;
		while(temp->link!=NULL)
		{   
			printf("%dx^%d + ",temp->coeff,temp->exp);
			temp=temp->link;
		}
		printf("%dx^%d\n",temp->coeff,temp->exp);
	}
}
void add(struct node *start1,struct node *start2)
{
	struct node *p1=start1;
	struct node *p2=start2;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->exp==p2->exp)
		{
			start3=insert(start3,p1->coeff+p2->coeff,p1->exp);
			p1=p1->link;
			p2=p2->link;
		}
		else if(p1->exp<p2->exp)
		{
			start3=insert(start3,p2->coeff,p2->exp);
			p2=p2->link;
		}
		else if(p1->exp>p2->exp)
		{
			start3=insert(start3,p1->coeff,p1->exp);
			p1=p1->link;
		}
	}
	while(p2!=NULL)
	{
		start3=insert(start3,p2->coeff,p2->exp);
		p2=p2->link;
	}
	while(p1!=NULL)
	{
		start3=insert(start3,p1->coeff,p1->exp);
		p1=p1->link;
	}
}
void mergeNodes(struct node *head)
{
	struct node *ptr1,*ptr2,*dup;
	ptr1=head;
	while (ptr1!=NULL && ptr1->link!=NULL)
	{
		ptr2=ptr1;
		while (ptr2->link!= NULL)
		{
			if (ptr1->exp== ptr2->link->exp)
			{
				ptr1->coeff= ptr1->coeff+ ptr2->link->coeff;
				dup = ptr2->link;
				ptr2->link = ptr2->link->link;
				free(dup);
			}
			else
				ptr2 = ptr2->link;
		}
		ptr1 = ptr1->link;
	}
}
void multiply(struct node *start1,struct node *start2)
{
	struct node *p1=start1;
	struct node *p2=start2;
	while(p1!=NULL)
	{
		while(p2!=NULL)
		{
			int coeff, power;
			coeff=p1->coeff*p2->coeff;
			power=p1->exp+p2->exp;
			start3=insert(start3,coeff,power);
			p2=p2->link;
		}
		p2=start2;
		p1=p1->link;
	}
	mergeNodes(start3);
}
void main()
{
	int ch,n1,n2,coeff,exp,i,j;
	printf("Enter the number of terms in 1st polynomial:");
	scanf("%d",&n1);
	printf("\nEnter the number of terms in 2nd polynomial:");
	scanf("%d",&n2);
	printf("\nEnter the first polynomial");
	for(i=0;i<n1;i++)
	{
		printf("\nEnter the coefficient:");
		scanf("%d",&coeff);
		printf("Enter the exponent:");
		scanf("%d",&exp);
		start1=insert(start1,coeff,exp);
	}
	printf("\nEnter the second polynomial");
	for(j=0;j<n2;j++)
	{
		printf("\nEnter the coefficient:");
		scanf("%d",&coeff);
		printf("Enter the exponent:");
		scanf("%d",&exp);
		start2=insert(start2,coeff,exp);
	}
	display(start1);
	display(start2);
	printf("\n1.Polynomial Addition\n2.Polynomial Multiplication\n3.Quit\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			add(start1,start2);
			display(start3);
			break;
		case 2:
			multiply(start1,start2);
			display(start3);
			break;
		case 3:
			exit(0);
		default:
			printf("\n!!!Wrong choice!!!");
	}
}
