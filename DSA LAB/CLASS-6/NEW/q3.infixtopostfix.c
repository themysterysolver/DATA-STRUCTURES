#include<stdio.h>
#include<string.h>
#define MAX 50
int top=-1;
char stack[MAX]; //stack for operators!!
char output[MAX]; //string for output expression!!
void itp(char *x);
void push(char data);
char pop();
int isFull();
int isEmpty();
void display();
int p(char ch);
int main(){
    char x[MAX];
    printf("enter the expresiion that to be converted from infix to psotfix:");
    scanf("%s",x);
    itp(x);
    //printf("%s",output);
    int i=0;
    for(i=0;output[i]!='\0';i++)
        printf("%c",output[i]);
    return 0;
}
void itp(char *x)
{
    int l=strlen(x),i=0,j=0;
    for(i=0;i<l;i++)
        {
            if(x[i]=='+'||x[i]=='-'||x[i]=='('||x[i]==')'||x[i]=='*'||x[i]=='/'||x[i]=='^') //operator!!
            {
                if(x[i]==')'){
                    while(stack[top]!='('){
                        output[j]=pop();
                        j++;
                        }
                     if (stack[top] == '(') {
                        pop(); // Used to pop the left bracket!
                }
                }
                else if(p(stack[top])>=p(x[i])){ //PRECEDENCE CHECK WITH P(),precedence function!!
                    while(p(stack[top])>=p(x[i])){ //popping until least precedent element comes!!
                        output[j]=pop();
                        j++;
                    }
                }
                if(i==l-1){
                    while(top!=-1){
                        output[j]=pop();
                        j++;
                    }
                }
                push(x[i]);
            }
            else{                       //operand and final expression!
                output[j]=x[i];
                j++;
            }
            output[j]='\0';
}
}
int p(char ch){
    switch(ch){
        case '^':
            return 5;
        case '*':
        case '/':
            return 4;
        case '+':
        case '-':
            return 3;
        return 0;
    }
}
void push(char data){
    if(isFull()==1)
        printf("OVERFLOW!");
    else{
        top++;
        stack[top]=data;
        display();
    }
}
char pop(){
    if(isEmpty()==1){
        printf("UNDEFLOW!");
        return '\0';
    }
    else{
        char temp=stack[top];
        top--;
        display();
        return temp;
    }
}
int isFull(){
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}
void display(){
    //int i=0;
     //for(i=0;i<strlen(stack);i++)
    printf("%s\n",stack);
}
