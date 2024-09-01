#include<stdio.h>
#include<stdlib.h>
 
#ifndef STACK_H
#define STACK_H

void push(int data){
    top++;
    stack[top]=data;
}
int pop(){
    node* temp=stack[top];
    top--;
    return temp;
}
int peek(){
    return (stack[top]);
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
        printf("%c ",stack[i]);
}

#endif