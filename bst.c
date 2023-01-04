#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *lc,*rc;
}*start=NULL;
struct node* insert(struct node *ptr,int val)
{
    if(ptr==NULL)
    {
        struct node *newn=(struct node*)malloc(sizeof(struct node));
        newn->data=val;
        newn->lc=NULL;
        newn->rc=NULL;
        ptr=newn;
    }
    else if(val<ptr->data)
        ptr->lc=insert(ptr->lc,val);
    else if(val>ptr->data)
        ptr->rc=insert(ptr->rc,val);
    return ptr;
}
void inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->lc);
        printf("%d\t",ptr->data);
        inorder(ptr->rc);
    }
}
void preorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        preorder(ptr->lc);
        preorder(ptr->rc);
    }
}
void postorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->lc);
        postorder(ptr->rc);
        printf("%d\t",ptr->data);
    }
}
void search(struct node *root,int key)
{
    struct node *ptr=root;
    int flag=0;
    while(ptr!=NULL && flag==0)
    {
        if(key==ptr->data)
            flag=1;
        else if(key<ptr->data)
            ptr=ptr->lc;
        else if(key>ptr->data)
            ptr=ptr->rc;
    }
    if(flag==1)
        printf("Element found");
    else 
        printf("Element not found");
}
struct node* delete(struct node *ptr, int val)
{
 struct node *par;
    while(ptr!=NULL)
    {
        if(val<ptr->data)
            {
                par=ptr;
                ptr=ptr->lc;
            }
        else if(val>ptr->data)
            {
                par=ptr;
                ptr=ptr->rc;
            }
        else if(val==ptr->data)
        {
            if(ptr->lc==NULL&&ptr->rc==NULL)
            {
                if(ptr==par->lc)
                    par->lc=NULL;
                else if(ptr==par->rc)
                    par->rc=NULL;
                free(ptr);
                return ptr;
            }
            else if(ptr->lc!=NULL&&ptr->rc==NULL)
            {
                if(ptr==par->lc)
                    par->lc=ptr->lc;
                else if(ptr==par->rc)
                    par->rc=ptr->lc;
                free(ptr);
                return ptr;
            }
            else if(ptr->lc==NULL&&ptr->rc!=NULL)
            {
                if(ptr==par->lc)
                    par->lc=ptr->rc;
                else if(ptr==par->rc)
                    par->rc=ptr->rc;
                free(ptr);
                return ptr;
            }
            else
            {
                struct node *succ=ptr->rc;
                if(succ->lc==NULL)
                {
                    ptr->data=succ->data;
                    ptr->rc=succ->rc;
                    free(succ);
                }
                else
                {
                    struct node *temp;
                    while(succ->lc!=NULL)
                    {
                        temp=succ;
                        succ=succ->lc;
                    }
                    ptr->data=succ->data;
                    temp->lc=succ->rc;
                    free(succ);
                }
            }
        }
    }
    return ptr;
}
void main()
{
    int ch,val,op,key;
    do
    {
        printf("\nMenu\n1.Insertion\t2.Deletion\t3.Traversal\t4.Search\t5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the data:");
                scanf("%d",&val);
                start=insert(start,val);
                break;
            case 2:
                printf("Enter the data to delete:");
                scanf("%d",&val);
                delete(start,val);
                break;
            case 3:
                printf("\n\t1.Inorder\t2.Pre order\t3.Post order");
                printf("\nEnter your choice:");
                scanf("%d",&op);
                switch(op)
                {
                case 1:
                    inorder(start);
                    break;
                case 2:
                    preorder(start);
                    break;
                case 3:
                    postorder(start);
                    break;
                default:
                    printf("Invalid choice");
                    break;
                }
                break;
            case 4:
                printf("\nEnter the value to search:");
                scanf("%d",&key);
                search(start,key);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }while(ch!=5); 
}