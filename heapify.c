#include<stdio.h>
int a[20];
void heapify(int root,int n)
{
    int l,r,temp,lar;
    lar=root; l=2*root; r=l+1;
    if((l<n)&&(a[l]>a[lar]))
        lar=l;
    if((r<n)&&(a[r]>a[lar]))
        lar=r;
    if(lar!=root)
    {
        temp=a[root];
        a[root]=a[lar];
        a[lar]=temp;
        heapify(lar,n);
    }
}
void heapsort (int n)
{
    int i, j,temp;
    for(i=n/2;i>0;i--)
        heapify(i,n);
    for(i=n;i>0;i--)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        heapify(1,i);
    }
}
int main()
{
    printf("......HEAP SORT......");
    int ch,n,i,l;
    printf("\nEnter the Array size:");
    scanf("%d",&n);
    printf("\nEnter the Array elements:");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    heapsort(n);
    for(i=1;i<=n;i++)
        printf("%d\t",a[i]);
}
