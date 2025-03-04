#include<stdio.h>
#include<stdlib.h>
#define size 10
void push(int);
void pop();
void display();
int stack[size],top=-1;
int main()
{
    int value,choice;
    while(1){
    printf("\n\n***menu***\n\n");
    printf("1.push\n2.pop\n3.display\n4.exit");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("enter the value to be inserted:");
        scanf("%d",&value);
        push(value);
        break;
        case 2:pop();
        break;
        case 3:display();
        break;
        case 4:exit(0);
        default :printf("wrong choice!!");
    }
    }
  return 0;
}
void push(int value)
{
    if(top==size-1)
        printf("\n stack is full!");
    else
    {
        top++;
        stack[top]=value;
        printf("\ninsertion success!");
    }
}
void pop()
{
    if(top==-1)
        printf("\nstack is empty!");
    else
    {
        printf("\ndeleted %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
        printf("stack is empty");
    else
    {
        int i;
        for(i=top;i>=0;i--)
            printf("%d\n",stack[i]);
    }
}
