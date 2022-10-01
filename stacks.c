#include <stdlib.h>
#include <stdio.h>

struct stackNode
{
    int *arr;
    int top;
    int size;
};

int isFull(struct stackNode *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(struct stackNode *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

void push(struct stackNode * ptr,int data)
{
    if(isFull(ptr))
    printf("Stack Underflow\n");
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=data;
        printf("Pushed  %d into the stack \n", data);
    }
}

void peek(struct stackNode * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
    }
    else
    {
     printf("Topmost element in stack is %d\n",ptr->arr[ptr->top]);   
    }
}

void pop(struct stackNode * ptr)
{
    if(isEmpty(ptr))
    printf("Stack Overflow\n");
    else
    {
        printf("%d\n",ptr->arr[ptr->top]);
        ptr->top--;
    }
}   

int main()
{
    struct stackNode *s = (struct stackNode *)malloc(sizeof(struct stackNode));
    s->size = 4;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    //* Check if Stack is Empty
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    pop(s);
    peek(s);
    
    return 0;
}