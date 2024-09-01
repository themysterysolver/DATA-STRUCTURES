#include<stdio.h>
#include<string.h>
#define MAX 100
void check(char *str);
void push(char data);
char pop();
int isFull();
int isEmpty();
void display();
char stack[MAX];
char comp(char comp);
int top=-1;
int main(){
    char str[MAX];
    printf("enter string:");
    scanf("%s",str);
    printf("\n%s\n",str);
    check(str);
    return 0;
}
void check(char *str){
    int l=strlen(str);
    int i=0,flag=1;
    for(i=0;i<l;i++)
    {
        if(str[i]=='{'||str[i]=='('||str[i]=='[')
            push(str[i]);
        else if(str[i]=='}'||str[i]==')'||str[i]==']')
            {
                char temp=pop();
                if(temp==comp(str[i]))
                    flag=1;
                else
                    flag=0;
                    break;
            }
    }
    if(flag==1)
        printf("string is balanced in brackets!");
    else 
        printf("string is not balanced!");
}
void push(char data){
    if(isFull()==1)
        printf("OVERFLOW!");
    else{
        top++;
        stack[top]=data;
        //display();
    }
}
char pop(){
    if(isEmpty()==1)
        printf("UNDEFLOW!");
    else{
        char temp=stack[top];
        top--;
        //display();
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
    int i=0;
     for(i=0;i<strlen(stack);i++)
        printf("%c\n",stack[i]);
}
char comp(char comp){
    switch (comp){
        case '}':
            return ('{');
        case ')':
            return ('(');
        case ']':
            return ('[');
    }

}