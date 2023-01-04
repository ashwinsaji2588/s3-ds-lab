#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char a[100];
int st[100];
int top = -1;
void push(char x)
{
    a[++top] = x;
}
char pop()
{
     return a[top--];
}
void push1(int x)
{
    st[++top] =x;
}
int pop1()
{
     return st[top--];
}
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}
void inf_post(char exp[],char post[])
{
	char *e,x;int i=0;
	e = exp;
    	while(*e!='\0')
    	{
		if(isalnum(*e))
		{
		    post[i]=*e;
		    i++;
		}
		else if(*e == '(')
		    push(*e);
		else if(*e == ')')
		{
		    while((x = pop()) != '(')
		    {
		        post[i]=x;
		        i++;
		    }
		}
		else if(top!=-1)
		{
		    while(priority(a[top]) >= priority(*e))
		    {
		        post[i]=pop();
		        i++;
		    }
		    push(*e);
		}
		else
		{
			push(*e);
		}
		e++;
    	}
    	while(top!=-1)
    	{
        	post[i]=pop();
        	i++;
    	}
}
void eval(char post[])
{
	top=-1;int n1,n2,n3,num;char *e;
	e=post;
	while(*e!='\0')
	{
		if(isdigit(*e))
        	{
		    num=*e-48;
		    push1(num);
        	}
        else
        {
            	n1 = pop1();
            	n2 = pop1();
            	switch(*e)
            	{
		    	case '+':
		    	{
				n3 = n1 + n2;
				break;
		    	}
		    	case '-':
		    	{
				n3 = n2 - n1;
				break;
		    	}
		    	case '*':
		    	{
				n3 = n1 * n2;
				break;
		    	}
		    	case '/':
		    	{
				n3 = n2 / n1;
				break;
		    	}
		}
		push1(n3);
        }
        	e++;
	}
}
int main()
{
    char exp[100],post[100];int ch;
    printf("Enter the expression:");
    scanf("%s",exp);
    inf_post(exp,post);
    printf("The postfix expression is %s",post);
    printf("\nDo you want to evaluate the postfix expression(1/0):");
    scanf("%d",&ch);
    if(ch==1)
	eval(post);
    else
    	exit(0);
	printf("\nThe result of expression %s=%d\n\n",post,pop1());
    return 0;
}
