//LINEAR SEARCH!!
#include <stdio.h>
#define MAX 50
int main(){
int l,num,i=0,arr[MAX],pos;
printf("enter the length of the array:"); //length
scanf("%d",&l);

printf("\nenter the array:\n"); //arr i/o
for(i=0;i<l;i++){
    scanf("%d",&arr[i]);}
printf("\nenter the number to be found:"); //num
scanf("%d",&num);
for(i=0;i<l;i++){
    if(arr[i]==num)
        printf("the element %d is found in %d position.",num,i);
}
}