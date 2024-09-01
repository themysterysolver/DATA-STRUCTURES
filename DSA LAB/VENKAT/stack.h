#include "link.h"

#ifndef STACK_H
#define STACK_H

typedef struct{
    linklist* top;
}stack;

int isFull(stack l)
{
	return 0;
}

int isEmpty(stack l)
{
	return l.top == NULL;
}

void push(stack *l, int n)
{
	insert(&(l->top), n, 0);
}

int pop(stack* l){
	int popped = l->top->value;
	del(&(l->top), 0);
	return popped;
}

int peek(stack l){
	return l.top->value;
}

#endif STACK_H
