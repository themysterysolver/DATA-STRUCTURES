#include <stdio.h>
#include <ctype.h>
#include "stack.h"

int isHigherPrecedence(char first, char second)
{
	switch (first)
	{
	case '+':
	case '-':
		return second == '+' || second == '-';
	case '*':
	case '/':
		return second != '^';
	default:
		return 0;
	}
}

char *infixToPostfix(char *infix)
{
	int i, j;
	char *postfix = (char *)malloc(500), c = 65;
	stack stack = {NULL};
	for (i = 0, j = 0; infix[i]; i++)
	{
		if (isalnum(infix[i]))
		{
			putc(infix[i], stdout);
			postfix[j++] = infix[i];
		}
		else if (infix[i] == '(')
		{
			push(&stack, '(');
		}
		else if (infix[i] == ')')
		{
			while (!isEmpty(stack) && (c = pop(&stack)) != '(')
			{
				putc(c, stdout);
				postfix[j++] = c;
			}
		}
		else
		{
			while (!isEmpty(stack) && isHigherPrecedence(peek(stack), infix[i]))
			{
				c = pop(&stack);
				putc(c, stdout);
				postfix[j++] = c;
			}
			push(&stack, infix[i]);
		}
	}
	while (!isEmpty(stack))
	{
		c = pop(&stack);
		putc(c, stdout);
		postfix[j++] = c;
	}
	return postfix;
}

int main()
{
	infixToPostfix("a+a+a");

	return 0;
}
