#include<stdio.h>
#include<stdlib.h>
struct term
{
        int coeff,exp;
}a[10],b[10],c[10],p[20];
void main()
{
        int a1,b1,i,j,k,count=0,ch;
        char option;
        printf("Enter the number of terms in 1st polynomial:");
        scanf("%d",&a1);
        printf("\nEnter the number of terms in 2nd polynomial:");
        scanf("%d",&b1);
        printf("\nEnter the first polynomial");
        for(i=0;i<a1;i++)
        {
                printf("\nEnter the coefficient:");
                scanf("%d",&a[i].coeff);
                printf("\nEnter the exponent:");
                scanf("%d",&a[i].exp);
        }
        printf("\nEnter the second polynomial");
        for(j=0;j<b1;j++)
        {
                printf("\nEnter the coefficient:");
                scanf("%d",&b[j].coeff);
                printf("\nEnter the exponent:");
                scanf("%d",&b[j].exp);
        }
        printf("\nPolynomial A:");
        for(i=0;i<a1-1;i++)
                printf("%dx^%d + ",a[i].coeff,a[i].exp);
        printf("%dx^%d\n",a[i].coeff,a[i].exp);
        printf("Polynomial B:");
        for(j=0;j<b1-1;j++)
                printf("%dx^%d + ",b[j].coeff,b[j].exp);
        printf("%dx^%d\n",b[j].coeff,b[j].exp);
        printf("1.Polynomial Addition\n2.Polynomail Multiplication\n3.Quit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
             case 1:
                        i=0;j=0;k=0;
                        while((i<a1) && (j<b1))
                        {
                        if(a[i].exp==b[j].exp)
                        {
                                c[k].coeff=a[i].coeff+b[j].coeff;
                                c[k].exp=a[i].exp;
                                k++;i++;j++;
                        }
                        else if(a[i].exp>b[j].exp)
                        {
                                c[k].exp=a[i].exp;
                                c[k].coeff=a[i].coeff;
                                k++;i++;
                        }
                        else if(a[i].exp<b[j].exp)
                        {
                                c[k].coeff=b[j].coeff;
                                c[k].exp=b[j].exp;
                                k++;j++;
                        }
                        }
                        while(i<a1)
                        {
                                c[k].exp=a[i].exp;
                                c[k].coeff=a[i].coeff;
                                i++;k++;
                        }
                        while(j<b1)
                        {
                                c[k].exp=b[j].exp;
                                c[k].coeff=b[j].exp;
                                j++;k++;
                        }
                        count=k;
                        printf("Polynomial after addition:");
                        for(k=0;k<count-1;k++)
                                printf("%dx^%d + ",c[k].coeff,c[k].exp);
                        printf("%dx^%d\n",c[k].coeff,c[k].exp);
                        break;
                case 2:
                        i=0;j=0;k=0;
                        for(i=0;i<a1;i++)
                        {
                                for(j=0;j<b1;j++)
                                {
                                        p[k].coeff=a[i].coeff*b[j].coeff;
                                        p[k].exp=a[i].exp+b[j].exp;
                                        k++;
                                }
                        }
			int t=0;
			for(i=0;i<(k-t-1);i++)
			{
			    for(j=i+1;j<(k-t);j++)
			    {
				if(p[i].exp==p[j].exp)
				{
				    p[i].coeff=p[i].coeff+p[j].coeff;
				    for(int z=j;z<k-t;z++)
				    {
					p[z].exp=p[z+1].exp;
					p[z].coeff=p[z+1].coeff;
				    }
				    t++;j--;
				}
			    }
			}
                        for(i=0;i<k-t-1;i++)
                                printf("%dx^%d + ",p[i].coeff,p[i].exp);
                        printf("%dx^%d\n",p[i].coeff,p[i].exp);
                        break;
                case 3:
                        exit(0);
                default:
                        printf("Wrong input\n");
        }
}

