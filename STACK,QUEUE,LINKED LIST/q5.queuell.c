//implementation of queue using ll
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct NODE{
    int data;
    struct NODE *next;
};
typedef struct NODE node;
node *getnode();

void enqueue();
void dequeue();
void display();
void isEmpty();

node *front=NULL,*rear=NULL; //VALID

int main(){
    int ch,data;
    printf("\n \tqueue operations using pointers.. ");
    printf("\n -----------**********-------------\n");
    printf("\n 1. Enqueue ");
    printf("\n 2. dequeue ");
    printf("\n 3. isEmpty");
    printf("\n 4. Display");
    printf("\n 5. Quit ");
    while(1){
    printf("\n Enter your choice: ");
    scanf("%d",&ch);
    
        switch(ch){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("INVALID CHOICE!TRY AGAIN!\n");
                continue;

        }
    }
}
node *getnode(){
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("data for this node:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}
void enqueue(){
    node *newnode;
    node *temp;
    if(rear==NULL && front==NULL){
        front=getnode();
        rear=front;
    }
    else{
        newnode=getnode();
        rear->next=newnode;
        rear=newnode;
    }
    display();
}
void display(){
    node *temp;
    temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);   //last element!1
        temp=temp->next; 
    }
    
    //printf("%d ",temp->data);
}
void dequeue(){
    node *temp;
    node *prev;
    temp=front;
    if(rear==NULL && front==NULL) {
        printf("empty queue!\n");  //if empty
    }
    else if(rear==front){
        printf("the dequeueped up element is %d\n",front->data); //only 1 element!!
        rear=NULL;
        front==NULL;
        free(temp);
    }
        
    else{
        front=temp->next;
        free(temp);
        free(temp);
    }
    display();
}
void isEmpty(){
    if(rear==front)
        printf("queue is empty!!\n");
    else
        printf("queue is NOT EMPTY!!\n");
}





