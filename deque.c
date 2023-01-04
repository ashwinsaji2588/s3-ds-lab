#include<stdio.h>
#include<stdlib.h>
void insertf(int qu[],int *f,int *r,int dt,int N)
{   
	if(*f==0)
		printf("QUEUE OVERFLOW AT FRONT!!\n");
	else if(*f==-1 && *r==-1)
	{ 
		*f=N/2;*r=N/2;
		qu[*f]=dt;
	}
	else
	{ 
		*f=*f-1;
	      	qu[*f]=dt;
	}
}
void insertr(int qu[],int *f,int *r,int dt,int N)
{   
	if(*r==N-1)
		printf("QUEUE OVERFLOW AT REAR!!\n");
	else if(*f==-1 && *r==-1)
	{ 
		*f=N/2;*r=N/2;
	 	qu[*r]=dt;
	}
	else
	{ 
		*r=*r+1;
		qu[*r]=dt;
	}
}
void deletef(int qu[],int *f,int *r)
{   
	if(*r==-1 && *f==-1)
		printf("QUEUE UNDERFLOW!!\n");
    	else if(*f==*r)
    	{ 
	    	printf("Deleted Element: %d\n",qu[*f]);
		*f=-1,*r=-1;
	}
	else
	{ 
		printf("Deleted Element: %d\n",qu[*f]);
		*f=*f+1;
	}
}
void deleter(int qu[],int *f,int *r)
{   
	if(*r==-1 && *f==-1)
		printf("QUEUE UNDERFLOW!!\n");
	else if(*f==*r)
	{ 
		printf("Deleted Element: %d\n",qu[*r]);
		*f=-1,*r=-1;
	}
	else
	{ 
		printf("Deleted Element: %d\n",qu[*r]);
		*r=*r-1;
	}
}
void display(int qu[],int *f,int *r)
{   
	int i;
	if(*r==-1 && *f==-1)
		printf("QUEUE UNDERFLOW!!\n");
	else
	{ 
		for(i=*f;i<=*r;i++)
		{ 
			printf("%d\t",qu[i]);
		}
	}
}
void main()
{  
	int c,N,dt,op,t;
	int front=-1,rear=-1,qu[50];
	printf("Enter Queue limit:\n");
	scanf("%d",&N);
	do
	{
		printf("Menu\n");
		printf("1.Insert from front\n2.Insert from rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&c);
		switch(c)
	    	{
		    	case 1:
			    	printf("Enter the Element to insert:\n");
				scanf("%d",&dt);
				insertf(qu,&front,&rear,dt,N);
				break;
		     	case 2:
			     	printf("Enter the Element to insert:\n");
				scanf("%d",&dt);
				insertr(qu,&front,&rear,dt,N);
				break;
			case 3:
				deletef(qu,&front,&rear);
				break;
			case 4:
				deleter(qu,&front,&rear);
				break;
			case 5:
				display(qu,&front,&rear);
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("!Invalid Input!!!\n");
		}
	}while(1);
}
