#include <stdio.h>
#define MAX 256
#define MIN 0
void enqueue(int *,int);
int dequeue(int *);
int peek(int *);
int isFull(int*);
int isEmpty(int*);
static int front=0,rear=0;
int main(){
    printf("Enter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for peek\nEnter anything else to exit\n");
    int ch,num[MAX],input;
    while(1){
        printf("Enter your choice :"); 
        scanf("%d",&ch);
        switch(ch){
            case 1:
                if(isFull(num)){
                    printf("Overflow Error\n");
                    break;
                }
                printf("Enter a number to push:");
                scanf("%d",&input);
                enqueue(num,input);
                break;
            case 2:
                !isEmpty(num)?printf("%d is dequeued\n", dequeue(num)):printf("Underflow Error\n");
                break;
            case 3:
                !isEmpty(num)?printf("The front is \n%d\n", peek(num)):printf("Underflow Error\n");
                break;
            default:
                printf("Exiting...");
                return 0;
        }
    }
}
int dequeue(int *arr){
    return arr[front++];
}
void enqueue(int *arr,int x){
    arr[rear%MAX]=x;
    rear++;
}
int peek(int *arr){
    return arr[front];
}

int isFull(int* arr){
    return rear-front==MAX;
}

int isEmpty(int* arr){
    return front==rear;
}
