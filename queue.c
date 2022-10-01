#include <stdio.h>
#include <stdlib.h>

int a[10],front=0,rear=-1;

int push()
{
  int n;
  if(rear<10-1)
  {
    printf("enetr an integer : ");
    scanf("%d",&n);
    rear++;
    a[rear]=n;

  }
  else
  {
    printf("\n\t OVERFLOW \n");
  }
}
int pop()
{
  if(rear>=front)
  {
    printf("\n\tthe poped element is %d ",a[front]);
    front++;
  }
  else
  {printf("\n\tQUE IS empty\n");}
}

int print_que()
{ int i,choice=10;
  printf("\n[ ");
  for(i=front;i<=rear;i++)
  {
    printf(" %d {%d}",a[i],rear);
  }
  printf("]\n");
}

int main()
{
  int i,choice;
  for(i=0;i<5;i++)
  {
    push();
  }

  print_que();
  while(1)
  {
    printf("\nenter 0: to end the programe");
    printf("\nenter 1: to push the elements");
    printf("\nenter 2: to pop the elements\n");
    scanf("%d",&choice);
    if(choice>3)
    {return 0;}
    switch (choice)
    {
      case 1:
        push();
        print_que();
        break;
      case 2:
        pop();
        print_que();
        break;
      case 0:
        return 0;
    }
  }
}