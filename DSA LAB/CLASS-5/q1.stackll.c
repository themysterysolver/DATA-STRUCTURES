//implementation of stack using ll
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct NODE{
    int data;
    struct NODE *next;
};
typedef struct NODE node;
node *getnode();

void push();
void pop();
void display();
void isEmpty();

node *head=NULL,*top=NULL; //VALID

int main(){
    printf("\n \tStack operations using pointers.. ");
    printf("\n -----------**********-------------\n");
    printf("\n 1. Push ");
    printf("\n 2. Pop ");
    printf("\n 3. isEmpty");
    printf("\n 4. Display");
    printf("\n 5. Quit ");
    int ch,data;
    while(1){
    printf("\n Enter your choice: ");
    scanf("%d",&ch);
    
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
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
void push(){
    node *newnode;
    node *temp;
    if(top==NULL && head==NULL){
        head=getnode();
        top=head;
    }
    else{
        newnode=getnode();
        top->next=newnode;
        top=newnode;
    }
    display();
}
void display(){
    node *temp;
    temp=head;
    while(temp->next!=NULL){
        if(head->next==NULL){
            printf("%d ",temp->data);
            break;}
        printf("%d ",temp->data);
        temp=temp->next; 
    }
    
    printf("%d ",temp->data);
}
void pop(){
    node *temp;
    node *prev;
    temp=head;
    if(top==NULL){
        printf("empty stack!\n");
    }
    else if(top==head){
        printf("the popped up element is %d\n",head->data);
        top=NULL;
    }
        
    else{
       while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
       }
       top=prev;
       top->next=NULL;
       printf("the popped element is %d\n",temp->data);
       free(temp);
    }
    display();
}
void isEmpty(){
    if(top==NULL)
        printf("stack is empty!!\n");
    else
        printf("stack is NOT EMPTY!!\n");
}