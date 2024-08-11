#include<stdio.h>
void print(int num){
    if(num==0)return;
    printf("%d",num);
    //if(num==0)return;
    print(num-1);
}
int main(){
    int num;
    printf("Enter number:");
    scanf("%d",&num);
    print(num);
}