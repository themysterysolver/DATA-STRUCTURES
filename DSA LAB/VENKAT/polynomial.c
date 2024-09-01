#include <stdio.h>
#include <math.h>
#include "link.h"

typedef linklist polynomial;

polynomial* add(polynomial* first, polynomial* second){
	if(first == NULL)   return second;
	else if(second == NULL) return first;
	polynomial* result = createnode(first->value + second->value);
	result->next = add(first->next, second->next);
	return result; 
}

polynomial* polyTimesC(polynomial* poly, int c){
	if(poly == NULL)    return poly;
	polynomial* result = createnode(poly->value * c);
	result->next = polyTimesC(poly->next, c);
	return result;
}

polynomial* multiply(polynomial* first, polynomial* second){
	if(first == NULL || second == NULL) return NULL;
	polynomial* currentResult = polyTimesC(first, second->value);
	polynomial nextResult = {0, first};
	return add(currentResult, multiply(&nextResult, second->next));
}

double evalPolyStartingWithDegreeN(polynomial* poly, int x, int n){
	if(poly == NULL)	return 0;
	else	return poly->value*pow(x, n) + evalPolyStartingWithDegreeN(poly->next, x, n + 1);
}

double evalPolyAtX(polynomial* poly, int x){
	return evalPolyStartingWithDegreeN(poly, x, 0);
}

void displayDegreeN(polynomial* poly, int n){
	if(poly){
		printf(" + %dx^%d", poly->value, n);
		displayDegreeN(poly->next, n + 1);
	}
	else printf("\n");
}

void display(polynomial* poly){
	displayDegreeN(poly, 0);
}

int main(){
	int degree1, degree2, input, i;
	polynomial *one = NULL;
	polynomial *two = NULL;

	printf("Enter the degree of the first polynomial: ");
	scanf("%d", &degree1);
	printf("Enter coefficients for the first polynomial:\n");
	for (i = degree1; i >= 0; i--) {
		printf("Enter coefficient for %dth degree: ", i);
		scanf("%d", &input);
		insert(&one, input, 0);
	}

	printf("First polynomial:\n");
	display(one);

	printf("Enter the degree of the second polynomial: ");
	scanf("%d", &degree2);
	printf("Enter coefficients for the second polynomial:\n");
	for (i = degree2; i >= 0; i--) {
		printf("Enter coefficient for %dth degree: ", i);
		scanf("%d", &input);
		insert(&two, input, 0);
	}
	
	printf("Second polynomial:\n");
	display(two);

	printf("The sum is:\n");
	display(add(one, two));

	printf("The product is:\n");	
	display(multiply(one, two));

	printf("Enter value to evaluate the polynomial at:");
	scanf("%d", &input);
	printf("The first polynomial at %d is %f", input, evalPolyAtX(one, input));

	return 0;
}

