// PALINDROME using half STACK and procedd string check!!
#include <stdio.h>
#include <string.h>
#define MAX 50
int top=-1;
char str[MAX];
char stack[MAX];
void push(char data);
char pop();
int isFull();
int isEmpty();
int palindrome();
void display();
int main(){
    printf("enter the string:"); //length
    scanf("%s",str);
    if(palindrome())
        printf("It is a palindrome!");
    else
        printf("It is NOT a plaindrome!!");
}
int palindrome(){
     int l=strlen(str),i=0;
     int mid=(l+1)/2;
     for(i=0;i<l;i++)
    {
        if(i<l/2)
            push(str[i]);
        else if(i>=mid)
        {
            if(str[i]==pop())
                continue;
            else
                return 0;
        }
    }
    return 1;
}

void push(char data){
    if(isFull()){
        printf("OVERFLOW!\n");
        }
    else
        stack[++top]=data;
}
char pop(){
    if(isEmpty())
        printf("UNDERFLOW!\n");
    else
    {
        char temp;
        temp=stack[top--];
        return temp;
    }
}
int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;

}
int isEmpty(int type){
    if(top==-1)
        return 1;
    else
        return 0;
}
void display(){
    int i=0;
    for(i=0;i<=top;i++)
        printf("%c ",stack[i]);
}


