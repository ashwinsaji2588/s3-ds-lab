#include<stdio.h>
int main()
{
	int r,k,c,i,j,d,v=0,w,z=1,q,r1,c1,x=1,a[10][3],b[10][3],res[20][3],b2[10][3];
	printf("Enter no of rows and coloums for 1st matrix(R x C):");
	scanf("%d%d",&r,&c);
	printf("\nEnter the elements:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&d);
			if(d!=0)
			{
				a[z][0]=i;
				a[z][1]=j;
				a[z][2]=d;
				z++;
			}
		}
	}
	z--;
	a[0][0]=r;
	a[0][1]=c;
	a[0][2]=z;
	for(i=0;i<=z;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("1.Sparse matrix addition\n2.Sparse matrix transpose\nEnter your choice:");
	scanf("%d",&q);
	switch(q)
	{
		case 1:
			printf("Enter no of rows and coloums for 2nd matrix(R x C):");
			scanf("%d%d",&r1,&c1);
			if(r1==r && c1==c)
			{
				printf("Enter the elements:\n");
				for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
					{
						scanf("%d",&w);
						if(w!=0)
						{
							b[x][0]=i;
							b[x][1]=j;
							b[x][2]=w;
							x++;
						}
					}
				}
				x--;
				b[0][0]=r1;
				b[0][1]=c1;
				b[0][2]=x;
				for(i=0;i<=x;i++)
				{
					for(j=0;j<3;j++)
						printf("%d\t",b[i][j]);
					printf("\n");
				}
				res[0][0]=r1;
				res[0][1]=c1;
				i=1;j=1;k=1;
				z++;x++;
				while(i<z&&j<x)
				{
					if(a[i][0]<b[j][0])	
					{
						res[k][0]=a[i][0];
						res[k][1]=a[i][1];
						res[k][2]=a[i][2];
						i++; k++;
					}
					else if(b[j][0]<a[i][0])
					{
						res[k][0]=b[j][0];
						res[k][1]=b[j][1];
						res[k][2]=b[j][2];
						j++;k++;
					}
					else if (a[i][1]<b[j][1])
					{
						res[k][0]=a[i][0];
						res[k][1]=a[i][1];
						res[k][2]=a[i][2];
						i++; k++;
					}
					else if (b[j][1]<a[i][1])
					{
						res[k][0]=b[j][0];
						res[k][1]=b[j][1];
						res[k][2]=b[j][2];
						j++; k++;
					}
					else	
					{
						res[k][0]=a[i][0];
						res[k][1]=a[i][1];
						res[k][2]=a[i][2]+b[j][2];
						i++; j++; k++;
					}
				}
				while(i<z)
				{   
					res[k][0]=a[i][0];
					res[k][1]=a[i][1];
					res[k][2]=a[i][2];
					i++; k++;
				}
				while(j<x)
				{
					res[k][0]=b[j][0];
					res[k][1]=b[j][1];
					res[k][2]=b[j][2];
					j++; k++;
				}
				k--;
				res[0][2]=k;
				printf("***************\n");
				for(i=0;i<=k;i++)
				{
					for(j=0;j<3;j++)
					{
						printf("%d\t",res[i][j]);
					}	
					printf("\n");
				}
			}
			break;
		case 2:
		    	b2[0][0]=a[0][1];
		    	b2[0][1]=a[0][0];
		    	b2[0][2]=a[0][2];
		    	k=1;
		    	for(i=0;i<a[0][1];i++)
		        	for(j=1;j<=a[0][2];j++)
		        		if(i==a[j][1])
					{
					    b2[k][0]=i;
					    b2[k][1]=a[j][0];
					    b2[k][2]=a[j][2];
					    k++;
					}
			printf("\nTranspose\n");
			for(i=0;i<=z;i++)
			{
				for(j=0;j<3;j++)
					printf("%d\t",b2[i][j]);
				printf("\n");
			}	
			break;
		default :
		 	printf("Wrong choice");
	}
}
