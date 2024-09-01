#include <stdio.h>
#include "stack.h"

int isPalindrome(char* string){
	int i, n;
	stack stackedString = {NULL};
	for(n = 0; string[n]; n++);
	for(i = 0; i < n / 2; i++)
		push(&stackedString, string[i]);
	for(i = (n - 1) / 2 + 1; i < n; i++)
		if(pop(&stackedString) != string[i]) 
			return 0;
	return 1;
}

int main(){
	char inputString[500];
	printf("Enter a string to check palindrome:\n");
	gets(inputString);
	if(isPalindrome(inputString))
		printf("%s is a palindrome", inputString);
	else
		printf("%s is not a palindrome", inputString);
	return 0;
}

