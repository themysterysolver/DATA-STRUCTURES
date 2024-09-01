#include "link.h"

typedef struct queue{
    linklist* rear;
} queue;

void enqueue(queue *,int);
int dequeue(queue *);
int peek(queue);
int isFull(queue);
int isEmpty(queue);

void display(queue q){
        if(!q.rear){
                printf("Empty queue\n");
                return;
        }
        else{
                linklist *temp = q.rear->next;
                do{
                        printf("%d ", temp->value);
                                temp = temp->next;
                        }while(temp != q.rear->next);
                        printf("\n");
                }
}

int main(){
    printf("Enter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for peek\nEnter anything else to exit\n");
    int ch, input;
	queue queue = {NULL};
    while(1){
        printf("Enter your choice :"); 
        scanf("%d",&ch);
        switch(ch){
            case 1:
                if(isFull(queue)){
                    printf("Overflow Error\n");
                    break;
                }
                printf("Enter a number to push:");
                scanf("%d",&input);
                enqueue(&queue,input);
                display(queue);
                break;
            case 2:
                !isEmpty(queue)?printf("%d is dequeued\n", dequeue(&queue)):printf("Underflow Error\n");
                display(queue);
                break;
            case 3:
                !isEmpty(queue)?printf("The front is \n%d\n", peek(queue)):printf("Underflow Error\n");
                break;
            default:
                printf("Exiting...");
                return 0;
        }
    }
}

int dequeue(queue* q){
    int dequeued = q->rear->next->value;
    if(q->rear == q->rear->next)    q->rear = NULL;
    else	del(&(q->rear), 1);
    return dequeued;
    
}
void enqueue(queue* q, int x){
	if(!isEmpty(*q)){
		insert(&(q->rear), x, 1);
		q->rear = q->rear->next;
	}
	else{
		insert(&(q->rear), x, 0);
		q->rear->next = q->rear;
	}
}
int peek(queue q){
    return q.rear->next->value;
}

int isFull(queue q){
    return 0;
}

int isEmpty(queue q){
    return q.rear == NULL;
}
