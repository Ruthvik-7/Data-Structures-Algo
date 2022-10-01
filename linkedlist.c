#include<stdio.h>
#include<stdlib.h>

struct list
{
  int data;
  struct list *next;
};
// helloruthvik

struct list* head=NULL;
int count=0;

struct list *create(int n)
{ struct list *new;
  new=(struct list*)malloc(sizeof(struct list));
  new->data=n;
  new->next=NULL;
  return (new);
}

struct list *create_list(struct list*new)
{ struct list *temp;
  temp=head;
  if(head==NULL)
  {
    head=new;
  }
  else
  { while(temp->next!=NULL)
    {
    temp=temp->next;
    }
    temp->next=new;
  }
  return (head);
}
struct list *print_list(struct list *temp)
{
  printf("\nthe new linkedd list is --\n");
  count=0;
  printf("[%d(head)]",temp);
  while(temp!=NULL)
  { count++;
    printf("--->[%d (%d) | %d ]",temp->data,&temp->data,temp->next);
    temp=temp->next;
  }

}

struct list *add_at_end(struct list *temp)
{ int p;
  printf("\nenter new data :");
  scanf("%d",&p);
  struct list *new2=create(p);
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=new2;
  print_list(head);
  return head;
}
struct list *add_at_beg(struct list *temp)
{ int p;
  printf("\nenter new data :");
  scanf("%d",&p);
  struct list *new2=create(p);
  head=new2;
  new2->next=temp;
  print_list(head);
return head;
}
struct list *add_at_int(struct list *temp)
{ int p;
  printf("\nenter new data :");
  scanf("%d",&p);
  int po,i=1;
  struct list *new2=create(p);
  printf("enter the position to add new node :");
  scanf("%d",&po);
  if(po<count)
  while(temp->next!=NULL && i<po)
  {
    temp=temp->next;
    i++;
  }
  new2->next=temp->next;
  temp->next=new2;
  printf("\\\n\n\n\n");
  print_list(head);
  return head;
}
struct list *delete_node_int(struct list *temp)
{ int pos,i;
  printf("\nenter position of node to delete :");
  scanf("%d",&pos);
  struct list *clear;
  if(pos<count)
  {
    for(i=1;i<pos;i++)
    {
      temp=temp->next;
    }
    temp->next=temp->next->next;
    temp=temp->next;
    temp=NULL;

  }
  print_list(head);
  free(temp);
  return(head);


}
struct list *delete_node_end(struct list *temp)
{
  while(temp->next->next!=NULL)
  {
    temp=temp->next;
  }
  temp=temp->next=NULL;
  free(temp);
  printf("\nlist after del-end\n");
  print_list(head);
    return(head);
}
struct list *delete_node_beg(struct list *temp)
{

  head=temp->next;
  temp=temp->next=NULL;
  printf("\nlist after begining del\n");
  free(temp);
  print_list(head);
  return head;

}
struct list *rev_trav(struct list *temp)
{
  if(temp==NULL)
  {return 0;}
  rev_trav(temp->next);
  printf("[%d]<---",temp->data);

}


struct list *freedata(struct list *temp)
{ struct list *fre;
  while(temp!=0)
  { fre=temp;
    temp=temp->next;
    free(fre);
  }
}


int main()
{
  int n,i,no,choice=10;
  struct list *new,*k;
  printf("enter no of nodes to insert : ");
  scanf("%d",&no);
  for(i=0;i<no;i++)
  {
    printf("enter the data : ");
    scanf("%d",&n);
    new=create(n);
    k=create_list(new);
  }
  print_list(k);
  while(choice!=0)
  {
    printf("\nenter 0 :to end programe\nenter 1 :to add node at end\nenter 2 :to add node at begining\nenter 3:to add node at intermediate\n");
    printf("enter 4:to delete node at intermediate\nenter 5:to delete node at end\nenter 6:to delete node at begining\n");
    printf("enter 7: to traverse reverse\n");
    scanf("%d",&choice);
    if(choice==0)
    { freedata(k);
      return 0;}
    if(choice>7)
    {
      printf("\nout of range");
      freedata(k);
      return 0;
    }


    switch(choice)
     {
       case 1:
        k= add_at_end(k);
         break;
       case 2:
        k= add_at_beg(k);
         break;
       case 3:
        k= add_at_int(k);
         break;
      case 4:
      k=  delete_node_int(k);
      break;
      case 5:
      k=  delete_node_end(k);
      break;
      case 6:
      k=  delete_node_beg(k);
      break;
      case 7:
      k=  rev_trav(k);
      break;

     }
  }
}