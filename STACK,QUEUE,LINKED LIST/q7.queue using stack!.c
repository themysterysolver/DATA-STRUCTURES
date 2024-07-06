//ARRAY implementation of STACKS
#include<stdio.h>
#include<stdlib.h>
#define MAX 250
int stack1[MAX];
int stack2[MAX];
int top1=-1;
int top2=-1;
void enqueue(int data);
void dequeue();
void push(int data,int stack[],int *top);
int pop(int stack[], int *top) ;
int peek(int stack[],int top);
int isFull(int stack[],int top);
int isEmpty(int stack[],int top);
void print(int stack[],int top);

int main() {
    int choice, data;
    printf("\nStack Menu:\n");
    printf("1. enqueue\n");
    printf("2. dequeue\n");
    printf("3. Peek\n");
    printf("4. Is Full\n");
    printf("5. Is Empty\n");
    printf("6. Quit\n");
    while (1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    switch(choice){
        case 1:
            if(isFull(stack1,top1)==1)
                printf("OVERFLOW");
            else{
                printf("Enter the element to be pushed:");
                scanf("%d",&data);
                enqueue(data);
                print(stack1,top1);
                break;
            }
        case 2:
            if(isEmpty(stack1,top1)==1)
                printf("UNDERFLOW\n");
            else
            {
                dequeue();
                //printf("the popped elemnt from the queue is:%d\n",data);
            }
            print(stack1,top1);
            break;
        case 3:
            if(isEmpty(stack1,top1)==1)
                printf("EMPTY QUEUE");
            else
                printf("the top(front) elemnt from the QUEUE is:%d\n",stack1[top1]);
            print(stack1,top1);
            break;
        case 4:
            if(isFull(stack1,top1)==1)
                printf("FULL\n");
            else
                printf("NOT FULL!\n")  ;
            print(stack1,top1);
            break;
        case 5:
            if(isEmpty(stack1,top1)==1)
                printf("EMPTY\n");
            else
                printf("NOT EMPTY!\n") ;
            print(stack1,top1);
            break;
        case 6:
            exit(1);
        default:
                printf("Exiting...");
                return 0;
        }
    }
}
void enqueue(int data){
    if(isEmpty(stack1,top1))
        stack1[++top1]=data;
    else if(isFull(stack1,top1))
        printf("OVERFLOW");
    else
        push(data,stack1,&top1);
}
void dequeue(){
    if(isEmpty(stack1,top1))
        printf("\nUNDERFLOW\n");
     while(top1!=-1)
         push(pop(stack1,&top1),stack2,&top2);
    int temp=pop(stack2,&top2);
    printf("the dequeed element from the stack is %d",temp);
    while(top2!=-1)
        push(pop(stack2,&top2),stack1,&top1); //UNECESSARY!!
}

void push(int data,int stack[],int *top){
    //int dummy=*top;
    if(isEmpty(stack1,top1))      // Error: Misplaced condition
        printf("UNDERFLOW\n\n");
    (*top)++;   // Increment top pointer before pushing
    stack[*top]=data;
}
int pop(int stack[], int *top) {
    if(isEmpty(stack1, top1)) // Error: Misplaced condition
        printf("UNDERFLOW\n\n\n");
    int temp = stack[*top];
    (*top)--; // Decrement top pointer after popping
    return temp;
}
int peek(int stack[],int top){
    return (stack[top]);
    }
int isFull(int stack[],int top)
{
    if(top==MAX-1)
        return 1;
    else 
        return 0;
}
int isEmpty(int stack[],int top)
{
    if(top==-1)
        return 1;
    else 
        return 0;
}
void print(int stack[],int top){
    int i=0;
    for(i=0;i<=top;i++)
        printf("%d ",stack[i]);
}
