#include<stdio.h>
void lsearch(int a[],int n,int key)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(key==a[i])
		{
			printf("\nElement found at %d\n",i+1);
			flag=1;
		}
	}
	if(flag==0)
		printf("\nKey is not present!!");
}
void sort(int a[],int n)
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
}
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("\t%d",a[i]);
}
void bsearch(int a[],int n,int key)
{
	int mid,low=0,high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
		{
			printf("\nElement present\n");
			break;
		}	
		else if(key<a[mid])
			high=mid-1;
		else if(key>a[mid])
			low=mid+1;
	}
	if(low>high)
		printf("\nElement not found!!\n");
}
void main()
{
	int ch,i,key,n,a[20];
	while(1)
	{
		printf("\nMenu\n1.Linear Search\t\t2.Binary search\t\t3.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		if(ch>=3)
		{
			printf("Exiting..\n");
			return;
		}
		printf("Enter the size of array:");
		scanf("%d",&n);
		printf("Enter the array elements:");
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("Array elements:");
		display(a,n);
		printf("\n\nEnter the key to search:");
		scanf("%d",&key);
		switch(ch)
		{
			case 1:
				lsearch(a,n,key);
				break;
			case 2:
				sort(a,n);
				bsearch(a,n,key);
				break;
			default:
				printf("\nWrong input!!");
				break;
		}
	}
}

