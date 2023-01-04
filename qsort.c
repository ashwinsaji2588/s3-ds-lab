#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void display(int a[],int n)
{
	int i;
	printf("\nArray elements:");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
void qsort(int a[],int p,int r)
{
	int pivot,i,j;
	if(p<r)
	{
		pivot=a[p];
		i=p;
		j=r+1;
		do
		{
			do
			{
				if(i==r)
					break;
				i++;
			}while(a[i]<pivot);
			do
			{
				j--;
			}while(a[j]>pivot);
			if(i<j)
			{
				swap(&a[i],&a[j]);
			}
		}while(i<j);
		swap(&a[j],&a[p]);
		qsort(a,p,j-1);
		qsort(a,j+1,r);
	}
}
void merge(int a[],int start,int mid,int end)
{
	int temp[25],i,j,k;
	i=start;j=mid+1;k=0;
	while(i<=mid && j<=end)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			i++;k++;
		}
		if(a[j]<a[i])
		{
			temp[k]=a[j];
			j++;k++;
		}
	}
	while(j<=end)
	{
		temp[k]=a[j];
		j++;k++;
	}
	while(i<=mid)
	{
		temp[k]=a[i];
		i++;k++;
	}
	for(i=start,j=0;i<=end;i++,j++)
	{
		a[i]=temp[j];
	}
}
void msort(int a[],int start,int end)
{
	int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		msort(a,start,mid);
		msort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}
void main()
{
	int ch,n,a[20],i;
	while(1)
	{
		printf("\nMenu\n1.Quick sort\t2.Merge sort\t3.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		if(ch==3)
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
				qsort(a,0,n-1);
				display(a,n);
				break;
			case 2:
				msort(a,0,n-1);
				display(a,n);
				break;
		}
	}
}
