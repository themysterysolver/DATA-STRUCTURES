#include <stdio.h>
#define MAX 256
#define MIN 0
int pop(int*);
void push(int*,int);
int peek(int*);
int isFull(int*);
int isEmpty(int*);
static int top=0;
int main(){
    printf("Enter 1 for push\nEnter 2 for pop\nEnter 3 for peek\nEnter anything else to exit\n");
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
                push(num,input);
                break;
            case 2:
                !isEmpty(num)?printf("%d is popped\n",pop(num)):printf("Underflow Error\n");
                break;
            case 3:
                !isEmpty(num)?printf("The peek is\n%d\n", peek(num)):printf("Underflow Error\n");
                break;
            default:
                printf("Exiting...");
                return 0;
        }
    }
}
int pop(int *arr){
    return arr[--top];
}
void push(int *arr,int x){
    arr[top++]=x;
}
int peek(int *arr){
    return arr[top-1];
}
int isFull(int* arr){
    return top==MAX;
}
int isEmpty(int* arr){
    return top==MIN;
}
