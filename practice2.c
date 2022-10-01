#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);    
    }
}
int main()
{
    struct node *p1=create_node(8);
    struct node *p2=create_node(6);
    struct node *p3=create_node(5);
    struct node *p4=create_node(3);
    struct node *p5=create_node(2);
    struct node *p6=create_node(9);
    struct node *p7=create_node(7);
    
    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    p3->left=p6; 
    p3->right=p7;

    printf("\nINORDER TRAVERSAL:");
    inorder(p1);

    printf("\nPREORDER TRAVERSAL:");
    preorder(p1);

    printf("\nPOSTORDER TRAVERSAL:");
    postorder(p1);
}