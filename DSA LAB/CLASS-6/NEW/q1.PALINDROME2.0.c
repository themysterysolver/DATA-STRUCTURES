#include <stdio.h>
#define MAX 50
void push(int data,int arr[]);
int pop(int arr[]);
int peek(int arr[]);
int isFull(int arr[]);
int isEmpty(int arr[]);
void print(int arr[]);

int arr[MAX];
int arr1[MAX];
int arr2[MAX];
int top=-1;
int top1=-1;
int top2=-1;
int main()
    {
    int n,num,i,j;
    int choice, data;
    while (1) 
        {
            printf("\nStack Menu:\n");
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. check palindrome\n");
            printf("4. Quit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch(choice){
            case 1:
                if(isFull()==0)
                    printf("OVERFLOW");
                else{
                    printf("Enter the element to be pushed:");
                    scanf("%d",&data);
                    push(data);
                    print();
                    break;
                }
            case 2:
                if(isEmpty()==0)
                    printf("UNDERFLOW");
                else
                {
                    data=pop();
                    printf("the popped elemnt from the stack is:%d\n",data);
                }
                print();
                break;
            case 3:
                if(checkpalindrome())
                    printf("this is a palindrome!");
                else    
                    printf("this is not a palindorme!!");
            }
        }

}

int checkpalindrome(){
    int i=0,j=0;
    for(i=n,j=0;i>top/2;i--,j++)
        arr1[j]=pop(arr[i]);
    for(i=0;i<top/2;i++)
        arr2[i]=pop(arr[i]);
    print(arr1[]);
    print(arr2[]);
    }
    

void push(int data,int arr[]){
    top++;
    arr[top]=data;
}
int pop(int arr[]){
    int temp=arr[top];
    top--;
    return temp;
}
int peek(int arr[]){
    return (arr[top]);
    }
int isFull(int arr[])
{
    if(top==MAX-1)
        return 0;
    else 
        return 1;
}
int isEmpty(int arr[])
{
    if(top==-1)
        return 0;
    else 
        return 1;
}
void print(int arr[]){
    int i=0;
    for(i=0;i<=top;i++)
        printf("%d ",arr[i]);
}
