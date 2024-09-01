#include <stdio.h>
#include "stack.h"

int isLeft(char c){
    return c == '(' || c == '[' || c == '{';
}

int isRight(char c){
    return c == ')' || c == ']' || c == '}';
}

int doesMatch(char left, char right){
    switch(left){
        case '(': return right == ')';
        case '[': return right == ']';
        case '{': return right == '}';
    } 
}

int isParenMatched(char* parantheses){
    stack leftParens = {NULL};
    int i;
    for(i = 0; parantheses[i]; i++)
        if(isLeft(parantheses[i]))
            push(&leftParens, parantheses[i]);
        else if(isRight(parantheses[i])){
            if(isEmpty(leftParens))
                return 0;
            else if(doesMatch(pop(&leftParens), parantheses[i]))
                ;
            else
                return 0;
        }
    return 1;
}

int main(){
    char parens[500];
    printf("Enter parantheses pattern:\n");
    scanf("%s", parens);
    if(isParenMatched(parens))
        printf("Parenthheses matches");
    else
        printf("Parantheses does not match");
    return 0;
}