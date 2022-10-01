#include<stdio.h>
#include<stdlib.h>

struct list
{
    int data;
    struct list *next;
};
struct list *head=NULL;
struct list *create(int n)
{
    struct list *new;
    new=(struct list*)malloc(sizeof(struct list));
    new->data=n;
    new->next=NULL;
    return (new);
}

struct list *create_list(struct list *new)
{
    struct list *temp;
    temp=head;
    if(head==NULL)
        head=new;
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=new;
        }
        return (head);
}

struct list *print_list(struct list *temp)
{
    printf("Linkedlist created is:");
    printf("\n  %d(head)",temp);
    while(temp!=NULL)
    {
        printf("--->%d (%d) | %d",temp->data,&temp->data,temp->next);
        temp=temp->next;
    }
}

int main()
{
    int n,i,no;
    struct list *new,*k;
    printf("Enter the no.of node:\n");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
        printf("Enter th data:");
        scanf("%d",&n);
        new=create(n);
        k=create_list(new);
    }
    print_list(k);
    return 0;
}