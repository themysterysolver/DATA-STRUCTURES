#include<stdio.h>
#include<ctype.h>
#include "LL.h"
#define MAX 100
int top=-1;
char postfix[MAX];
node* stack[MAX];
#include "stack.h"
void ET();
node* create(int data);
//MAIN FUNCTION!!
int main(){
    printf("enter the postfix expression:");
    scanf("%s",&postfix);
    printf("\nthe postfix expression is %s\n",postfix);
    ET();
    preorder(stack[0]);
    printf("\n");
    inorder(stack[0]);
}
//EXPRESSION TREE CODE!!
void ET(){
    int i=0;
    while(postfix[i]!='\0'){
        if(isalnum(postfix[i]))
            push(createnode(postfix[i]));
        else if(postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='^')
            push(create(postfix[i]));
    i++;
    }
}
 //creating a subtree and then returning it into stack!
node* create(int data){
    node* new=createnode(data);
    new->right=pop();
    new->left=pop();
    
    return new;
}
