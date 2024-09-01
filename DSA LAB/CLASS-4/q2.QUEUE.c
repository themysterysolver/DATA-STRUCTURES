//ARRAY implementation of QUEUE
//FRONT(-)<----------------REAR(+)
#include<stdio.h>
#include<stdlib.h>
#define MAX 250
int arr[MAX];
int front=-1;//front
int rear=-1;//rear
void enqueue(int data);
int dequeue();
int isfront();
int isFull();
int isEmpty();
void print();

int main() {
    int choice, data;
    printf("\nQUEUE Menu:\n");
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. isfront\n");
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
                printf("Enter the element to be enqueueed:");
                scanf("%d",&data);
                enqueue(data);
                print();
                break;
            }
        case 2:
            if(isEmpty()==0)
                printf("UNDERFLOW");
            else
            {
                data=dequeue();
                printf("the dequeueped elemnt from the QUEUE is:%d\n",data);
            }
            print();
            break;
        case 3:
            if(isEmpty()==0)
                printf("EMPTY QUEUE");
            else
                printf("the front elemnt from the QUEUE is:%d\n",front);
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
    if(front==-1 && rear==-1){   //when empty!!
        front=0;
        rear=0;
        arr[rear]=data;
    }
    else{
    rear++;
    arr[rear]=data;
    }
}
int dequeue(){
    int temp=arr[front];
    front++;
    return temp;
}
int isfront(){
    return (arr[front]);
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
    else if(rear==front){
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
