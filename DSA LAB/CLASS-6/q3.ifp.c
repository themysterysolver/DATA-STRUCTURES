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
        printf("%c",output[i]); //printing OUTPUT!!
    return 0;
}
void itp(char *x)
{
    int l=strlen(x),i=0,j=0; //strlength and i j declaration!
    int data;
    for(i=0;i<l;i++)
        {
            switch(x[i]){
                case '(':
                    push(x[i]);
                    break;
                case '+':
                case '-':
                case '/':
                case '*':
                case '^':
                    if(top==-1){   //TO INSERT THE 1st element alone!!
                        push(x[i]);
                        break;
                    }
                    while(p(stack[top])>p(x[i])) //while(p(stack[top])>=p(x[i])) L--->R check!!
                        output[j++]=pop();
                    push(x[i]);
                    break;
                case ')':
                    while((data=pop())!='(')
                        output[j++]=data;
                    break;
                default:
                    output[j++]=x[i];
                    break;
            }
        }
        while(!isEmpty())
                output[j++]=pop();
            output[j]='\0';
}

int p(char ch){
    switch(ch){
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
void push(char data){
    if(isFull()==1)
        printf("OVERFLOW!");
    else{
        top++;
        stack[top]=data;
        // display();
        printf("STACK after push:%s\nOUTPUT:%s\n",stack,output);
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
        // display();
        printf("STACK after pop:%s\nOUTPUT:%s\n",stack,output);
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
