#include "link.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue{
    linklist* rear;
} queue;

int qPeek(queue q){
    return q.rear->next->value;
}

int qIsFull(queue q){
    return 0;
}

int qIsEmpty(queue q){
    return q.rear == NULL;
}

int dequeue(queue* q){
    int dequeued = q->rear->next->value;
    if(q->rear == q->rear->next)    q->rear = NULL;
    else	del(&(q->rear), 1);
    return dequeued;
    
}
void enqueue(queue* q, int x){
	if(!qIsEmpty(*q)){
		insert(&(q->rear), x, 1);
		q->rear = q->rear->next;
	}
	else{
		insert(&(q->rear), x, 0);
		q->rear->next = q->rear;
	}
}

#endif QUEUE_H
