//DELETION in a array with the position and elemnt of insertion is given
#include <stdio.h>
#define MAX 50
int main(){
int l,i=0,arr[MAX],pos;
printf("enter the length of the array:"); //length
scanf("%d",&l);

printf("\nenter the array:\n"); //arr i/o
for(i=0;i<l;i++){
    scanf("%d",&arr[i]);
}
printf("\nenter the position on which the element should be removed:"); //pos
scanf("%d",&pos);

printf("\nthe old array:"); //old array
for(i=0;i<l;i++){
    printf("%d ",arr[i]);
}

pos--; 
for(i=pos;i<l;i++){ //insertion function
    arr[i]=arr[i+1];
}
l--;

printf("\nthe new array:"); //new array
for(i=0;i<l;i++){
    printf("%d ",arr[i]);
}


}

