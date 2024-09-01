#include "link.h"

typedef struct{
    linklist* top;
}stack;

int pop(stack*);
void push(stack*, int);
int peek(stack);
int isFull(stack);
int isEmpty(stack);

int main()
{
	printf("Enter 1 for push\nEnter 2 for pop\nEnter 3 for peek\nEnter anything else to exit\n");
	int ch, input;
	stack stack = {NULL};
	while (1)
	{
		printf("Enter your choice :");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			if (isFull(stack))
			{
				printf("Overflow Error\n");
				break;
			}
			printf("Enter a number to push:");
			scanf("%d", &input);
			push(&stack, input);
			print(stack.top);
			break;
		case 2:
			!isEmpty(stack) ? printf("%d is popped\n", pop(&stack)) : printf("Underflow Error\n");
			if(isEmpty(stack))      printf("Empty stack\n");
			break;
		case 3:
			!isEmpty(stack) ? printf("The peek is\n%d\n", peek(stack)) : printf("Underflow Error\n");
			break;
		default:
			printf("Exiting...");
			return 0;
		}
	}
}

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
