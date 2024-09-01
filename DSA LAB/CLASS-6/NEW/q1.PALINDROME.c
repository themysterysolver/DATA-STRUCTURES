#include <stdio.h>
#include <string.h>
#define MAX 50
int top1=-1;
int top2=-1;
char str[MAX];
char str1[MAX];
char str2[MAX];
void push(char data,char *x,int type);
char pop(char *x,int type);
int isFull(int type);
int isEmpty(int type);
void display(char *x,int type);
void palindrome(char *x );
int main(){
    printf("enter the string:"); //length
    scanf("%s",str);
    palindrome(str);

}
void palindrome(char *str){
     int l=strlen(str),i=0;
     int mid=l/2;
     int flag=1; //assume even
     printf("%d",l);
    (l%2==0)?(flag=1):(flag=0);
    if(flag==1){
        for(i=0;i<mid;i++)
            push(str[i],str1,0); //top for str1 is type 0 and str2 us type 1
        for(i=l-1;i>=mid;i--)
            push(str2[1],str2,1);
    }
    if(flag==0){
        for(i=0;i<mid;i++)
            push(str[i],str1,0);
        for(i=l-1;i>=mid+1;i++)
            push(str2[1],str2,1);
    }
    display(str1,0);
    display(str2,1);
}
void push(char data,char *x,int type){
        if(type==0){
            if(isFull(type)==0){
                printf("OVERFLOW");
            }
            else
            {
                top1++;
                x[top1]=data;
            }
        }
        else if(type==1){
            if(isFull(type)==0){
                printf("OVERFLOW");
                display(x,type);
            }
            else
            {
                top2++;
                x[top2]=data;
                display(x,type);
            }
        }
        

}
char pop(char *x,int type){
        if(type==0){
                if(isEmpty(type)==0)
                    printf("UNDERFLOW");
                else{
                    int temp=x[top1];
                    top1--;
                    return temp;
                }
            }
            else if(type==1){
                if(isEmpty(type)==0){
                    printf("UNDERFLOW");
                }
                else{
                int temp=x[top2];
                top2--;
                return temp;
                }
            }
    
}
int isFull(int type)
{
    if(type==0){
           if(top1==MAX-1)
                return 0;
            else 
                return 1;
         }
    else if(type==1){
            if(top2==MAX-1)
                return 0;
            else 
                return 1;
        }
    
}
int isEmpty(int type)
{
   if(type==0){
           if(top1==-1)
                return 0;
            else 
                return 1;
         }
    else if(type==1){
            if(top2==-1)
                return 0;
            else 
                return 1;
        }
}
void display(char *x,int type){
    int i=0;
    if(type==0){
        for(i=0;i<=top1;i++)
            printf("%c ",x[i]);
         }
    else if(type==1){
           for(i=0;i<=top2;i++)
                printf("%c ",x[i]);
        }
    
}

