//STACK USING A QUEUE
//FRONT(-)<----------------REAR(+)
#include<stdio.h>
#include<stdlib.h>
#define MAX 250
int arr[MAX];
int front=-1;//front
int rear=-1;//rear
int count=0;
void enqueue(int data);
int dequeue();
int isFull();
int isEmpty();
int isfront();
void print();
void push(int data){
    enqueue(data);
};
int pop(){
    int temp=count-1;
    int i=0;
    while(i<temp){
        enqueue(dequeue());
        i++;
    }
    return dequeue();
};
int peek(){
    int temp=count-1;
    int i=0;
    while(i<temp){
        enqueue(dequeue());
        i++;
    }
    int topeh=isfront();
    enqueue(dequeue());
    return topeh;
};

int main() {
    int choice, data;
    printf("\nQUEUE Menu:\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
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
                printf("the popped elemnt from the STACK is:%d\n",data);
            }
            print();
            break;
        case 3:
            if(isEmpty()==0)
                printf("EMPTY STACK");
            else
                printf("top of stack is:%d\n",peek());
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
            if(isEmpty()==0)
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

void enqueue(int data){
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
        arr[rear]=data;
        
    }
    else{
    rear++;
    arr[rear]=data;
    }
    count++;
}
int dequeue(){
    if (isEmpty() == 0) { 
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;  
    }
    int temp = arr[front];
    front++;
    if (front > rear) { 
        front = rear = -1;
    }
    count--;
    return temp;
    
}
int isFull()
{
    if(rear==MAX-1)
        return 0;
    else
        return 1;
}
int isEmpty()
{
    if(rear==-1 && front==-1)
        return 0;
    if(rear<front){
        rear=-1;
        front=-1;
        return 0;
    }
    else
        return 1;
}
void print(){
    int i=front;
    for(i=front;i<=rear;i++)
        printf("%d ",arr[i]);
}
int isfront(){
    return (arr[front]);
}
