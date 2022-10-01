#include<stdio.h>
#include<stdlib.h>

struct stackNode{
    int top;
    int size;
    int * arr;
};

int isFull(struct stackNode *s)
{
    if(s->top == s->size)
    return 1;
    else 
    return 0;
} 

int isEmpty(struct stackNode *s) {
    if(s->top == -1)
    return 1;
    else 
    return 0;
} 

int main()
{
    struct stackNode *s = (struct stackNode *)malloc(sizeof(struct stackNode));
    s->top = -1;
    s->size = 10;
    s->arr =(int *)malloc(s->size * sizeof(int));

    int a = isEmpty(s);
    printf("%d\n", a);

    return 0;
}