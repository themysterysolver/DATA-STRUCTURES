#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct ExprTree{
    struct ExprTree* left;
    char operator;
    struct ExprTree* right;
}ExprTree;

ExprTree* createleaf(char c){
    ExprTree* operand = (ExprTree*)malloc(sizeof(ExprTree));
    operand->left = NULL;
    operand->operator = c;
    operand->right = NULL;
    return operand;
}

int isHigherPrecedence(char first, char second){
	switch(first){
		case '+': case '-': return second == '+' || second == '-';
		case '*': case '/': case '^': return second != '^';
		default: return 0;
	}
}

void preFix(ExprTree *tree)
{
    if (!tree)  return;
    printf("%c", tree->operator);
    preFix(tree->left);
    preFix(tree->right);
}

void inFix(ExprTree *tree)
{
    if (!tree->left){
        printf("%c", tree->operator);
        return;
    }
    else{
        printf("(");
        inFix(tree->left);
        printf("%c", tree->operator);
        inFix(tree->right);
        printf(")");
        return;
    }
}

void postFix(ExprTree *tree)
{
    if (!tree)  return;
    postFix(tree->left);
    postFix(tree->right);
    printf("%c", tree->operator);
}

ExprTree* infixToTree(char* infix){
    int i = 0, j, operTop = 0, exprTop = 0;
    ExprTree *lvalue = NULL, *rvalue = NULL, *temp;
    ExprTree** expressionStack = (ExprTree**)malloc(100 * sizeof(ExprTree*));
    char operatorStack[200], c;
    for(i = 0; infix[i]; i++){
        if(isspace(infix[i])){
            continue;
        }
        else if(isalnum(infix[i])){
            expressionStack[exprTop++] = createleaf(infix[i]);
        }
        else if(infix[i] == '('){
            operatorStack[operTop++] = infix[i];
        }
        else if(infix[i] == ')'){
            while((c = operatorStack[--operTop]) != '('){
                rvalue = expressionStack[--exprTop];
                lvalue = expressionStack[--exprTop];
                temp = createleaf(c);
                temp->left = lvalue;
                temp->right = rvalue;
                expressionStack[exprTop++] = temp;
            }
        }
        else{
            while(operTop > 0 && isHigherPrecedence(operatorStack[operTop - 1], infix[i])){
                rvalue = expressionStack[--exprTop];
                lvalue = expressionStack[--exprTop];
                temp = createleaf(operatorStack[--operTop]);
                temp->left = lvalue;
                temp->right = rvalue;
                expressionStack[exprTop++] = temp;
            }
            operatorStack[operTop++] = infix[i];
        }
    }
    while(operTop > 0){
        rvalue = expressionStack[--exprTop];
        lvalue = expressionStack[--exprTop];
        temp = createleaf(operatorStack[--operTop]);
        temp->left = lvalue;
        temp->right = rvalue;
        expressionStack[exprTop++] = temp;
    }
    return expressionStack[0];
}

int main(){
    char infix[500];
    printf("Enter infix:\n");
    scanf("%[^\n]s", infix);
    ExprTree* expression = infixToTree(infix);
    printf("\nPre-fix:\n");
    preFix(expression);
    printf("\nIn-fix:\n");
    inFix(expression);
    printf("\nPost-fix:\n");
    postFix(expression);
    return 0;
}