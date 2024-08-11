#include<stdio.h>
void print(int n){
    if (n==1){   /*if(n==0)return;  works!!! */
        printf("%d",n);
        return;
    }
    print(n-1);
    printf("%d",n);
    return;

}
int main(){
    int num;
    printf("Enter number:");
    scanf("%d",&num);
    print(num);
}