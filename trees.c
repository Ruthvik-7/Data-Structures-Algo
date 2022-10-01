#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node*left;
  struct node*right;
};
struct node* root=NULL;
int count=0;
struct node* create_node(int n)
{
  struct node*new=(struct node*)(malloc(sizeof(struct node)));
  new->data=n;
  new->left=new->right=NULL;
  return new;
}

struct node* print_tree(struct node*temp)
{struct node*prev=temp;
  if(temp!=NULL)
  {
    prev=temp;
    //printf(" [ %d (%d) | %d (%d)| %d (%d) ] \n",temp->left,prev->left->data,temp->data,temp,temp->right,prev->right->data);
    if(prev->left!=NULL)
    {printf("[ %d",prev->left->data);}
    else
    {printf("[ X");}
    //printf("[ %d |",temp->left);
    printf(" %d ",temp->data);
    //printf(" (%d)| ",temp);
    //printf("  %d ] ",temp->right);
    if(prev->right!=NULL)
    {printf(" %d ]",prev->right->data);}
    else
    printf(" X ]");
    printf("\n");
    print_tree(temp->left);
    print_tree(temp->right);
  }
}

struct node*create_tree(struct node* temp,int new)
{
   struct node*prev=temp;
  if(temp==NULL)
    {
      return create_node(new);
    }

  else if( new>temp->data )
    {
        temp->right=create_tree(temp->right,new);
    }
  else if( new <temp->data)
    {
        temp->left=create_tree(temp->left,new);
    }
else
    return temp;
}

struct node*post_order (struct node*temp)
{
  if(temp!=NULL)
  {
    post_order(temp->left);
    post_order(temp->right);
    printf(" %d ",temp->data);
  }
}

struct node*inorder (struct node*temp)
{
  if(temp!=NULL)
  {
    inorder(temp->left);
    printf(" %d ",temp->data);
    inorder(temp->right);
  }
}
struct node*preorder (struct node*temp)
{
  if(temp!=NULL)
  {
    printf(" %d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
  }
}

struct node *search(struct node*temp,int s)
{
  while(1)
  {

     if(s>temp->data)
    {
      temp=temp->right;
    }
    else if(s<temp->data)
    {
      temp=temp->left;
    }
    else if(temp->data==s)
    {
      printf("element found :");
      printf("%d is found ie %d ",temp->data,s);
      break;
    }
    else
    {printf("element %d not found ",s);
     break;
    }

  }
}
struct node*add_node(struct node*temp,int new)
{
  create_tree(temp,new);
  printf("\n\tnode inserted \n");
  print_tree(temp);
}
struct node*del_node(struct node*temp,int del)
{
  struct node*prev=temp,*x1del;
  int choice;
  while(1)
  {
    if(del==temp->data)
    {
      if(temp->left==NULL && temp->right==NULL)
      {
        if(temp->data>prev->data)
         {
           prev->right=NULL;
          // free(temp);
         }
        if(temp->data<prev->data)
         {
           prev->left=NULL;
          // free(temp);
         }
      }
      if(temp->left==NULL && temp->right!=NULL)
      {
        if(temp->data>prev->data)
         {
           prev->right=temp->right;
           temp->right=NULL;
           //free(temp);
         }
        if(temp->data<prev->data)
         {
           prev->left=temp->right;
           temp->right=NULL;
          // free(temp);
         }
      }
      if(temp->left!=NULL && temp->right==NULL)
      {
        if(prev->data>temp->data)
        {
          prev->left=temp->left;
          temp->left=NULL;
          //free(temp);
        }
        if(prev->data<temp->data)
        {
          prev->right=temp->left;
          temp->left=NULL;
          //free(temp);
        }
      }
      if(temp->left!=NULL && temp->right!=NULL)
      {
        printf("\n enetr '1' to swap with predecesor\n enter '2' to swap with sucessor\n");
        scanf("%d",&choice);
        //check these two;
        if(choice==1)
        {

          printf("\n%d\n",temp->data);
          x1del=temp;
          prev=temp;
          temp=temp->left;

          while(temp->right!=NULL)
          {
            prev=temp;
            temp=temp->right;
          }
          printf("\n%d\n",x1del->data);
          printf(" \n%d,%d \n",prev->data,temp->data);
          x1del->data=temp->data;
          if(prev->right->data!=temp->data)
          {
            if(temp->left!=NULL)
            {
              prev->left=temp->left;
            }
            if(temp->left==NULL)
            {
              prev->left=NULL;
            }
          }
          else
          {
            if(temp->left!=NULL)
            {
              prev->right=temp->left;
            }
            if(temp->left==NULL)
            {
              prev->right=NULL;
            }
          }

        }
        else
        {
          x1del=temp;
          prev=temp;
          temp=temp->right;
          while(temp->left!=NULL)
          {
            prev=temp;
            temp=temp->left;
          }
          printf("\n%d\n,prev=%d\ncurr=%d\n",x1del->data,prev->data,temp->data);
          x1del->data=temp->data;
          if(prev->left->data!=temp->data)

        {  if(temp->right!=NULL)
          {
            prev->right=temp->right;
          }
          if(temp->right==NULL)
          {
            prev->right=NULL;
          }
        }
        else
        {
          if(temp->right!=NULL)
            {
              prev->left=temp->right;
            }
            if(temp->right==NULL)
            {
              prev->left=NULL;
            }
        }
        }

      }
      break;
    }
    else if(del>temp->data)
    {
      prev=temp;
      temp=temp->right;
    }
    else if(del<temp->data)
    {
      prev=temp;
      temp=temp->left;
    }
    else
    {
      printf("element not found dude\n");
      break;
    }
  }
  print_tree(root);
}

struct node *traverse(struct node*temp)
{
  printf("\n\tthe postorder\n");
  post_order(root);
  printf("\n\tthe inorder\n");
  inorder(root);
  printf("\n\tthe preorder\n");
  preorder(root);
}

int main()
{
  int i,n,no,s,new,del,choice;
  printf("enter no of node to be entered : ");
  scanf("%d",&no);
  for(i=0;i<no;i++)
   {
       printf("enetr data :");
       scanf("%d",&n);
       root=create_tree(root,n);
   }

   print_tree(root);
   traverse(root);
   while(1)
   {
     printf("\nenter 0: To End the Programe ");
     printf("\nenter 1: To search element ");
     printf("\nenter 2: To Insert an element ");
     printf("\nenter 3: To Delete an element ");
     printf("\nenter 4: To traverse \n");
     scanf("%d",&choice);
     switch (choice)
   {
     case 1:
      printf("\neneter the element need to be searched : ");
      scanf("%d",&s);
      search(root,s);
      break;
     case 2:
      printf("\nenter data to the new node : ");
      scanf("%d",&new);
      add_node(root,new);
      traverse(root);
      break;
     case 3:
      printf("\nenetr the element to be deleted : ");
      scanf("%d",&del);
      del_node(root,del);
      traverse(root);
      break;
     case 0:
      return 0;
     case 4 :
      traverse(root);
      break;

   };
 }
}