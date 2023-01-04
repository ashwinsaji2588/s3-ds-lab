#include<stdio.h>
void display(int a[],int n)
{
	int i;
	printf("\nArray elements:");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
void bubble(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}	
		}
	}
	display(a,n);
}
void insertion(int a[],int n)
{
	int i,temp,j;
	for(i=1;i<n;i++) 
	{        
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
	}
	display(a,n);
}
void selection(int a[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])	
				min=j;
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
	display(a,n);
}
void main()
{
	int ch,n,a[20],i;
	while(1)
	{
		printf("\nMenu\n1.Bubble sort\t2.Insertion sort\t3.Selection sort\t4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		if(ch==4)
			return;
		printf("Enter the size of array:");
		scanf("%d",&n);
		printf("Enter the array elements:");
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("Array elements:");
		display(a,n);
		switch(ch)
		{
			case 1:
				bubble(a,n);
				break;
			case 2:
				insertion(a,n);
				break;
			case 3:
				selection(a,n);
				break;
		}
	}
}
