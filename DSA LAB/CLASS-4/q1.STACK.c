//ARRAY implementation of STACKS
#include<stdio.h>
#include<stdlib.h>
#define MAX 250
int arr[MAX];
int top=-1;
void push(int data);
int pop();
int peek();
int isFull();
int isEmpty();
void print();

int main() {
    int choice, data;
    printf("\nStack Menu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Is Full\n");
    printf("5. Is Empty\n");
    printf("6. Quit\n");
    while (1) {
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    switch(choice){
        case 1:
            if(isFull()==0)
                printf("OVERFLOW");
            else{
                printf("Enter the element to be pushed:");
                scanf("%d",&data);
                push(data);
                print();
                break;
            }
        case 2:
            if(isEmpty()==0)
                printf("UNDERFLOW");
            else
            {
                data=pop();
                printf("the popped elemnt from the stack is:%d\n",data);
            }
            print();
            break;
        case 3:
            if(isEmpty()==0)
                printf("EMPTY STACK");
            else
                printf("the top elemnt from the stack is:%d\n",arr[top]);
            print();
            break;
        case 4:
            if(isFull()==0)
                printf("FULL\n");
            else
                printf("NOT FULL!\n")  ;
            print();
            break;
        case 5:
            if(isEmpty()
            ==0)
                printf("EMPTY\n");
            else
                printf("NOT EMPTY!\n") ;
            print();
            break;
        case 6:
            exit(1);
        default:
                printf("Exiting...");
                return 0;
        }
    }

        
    }


void push(int data){
    top++;
    arr[top]=data;
}
int pop(){
    int temp=arr[top];
    top--;
    return temp;
}
int peek(){
    return (arr[top]);
    }
int isFull()
{
    if(top==MAX-1)
        return 0;
    else 
        return 1;
}
int isEmpty()
{
    if(top==-1)
        return 0;
    else 
        return 1;
}
void print(){
    int i=0;
    for(i=0;i<=top;i++)
        printf("%d ",arr[i]);
}
