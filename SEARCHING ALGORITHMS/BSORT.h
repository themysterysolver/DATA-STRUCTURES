#ifndef Bsort_H
#define Bsort_H

int* Bubble_sort(int *arr,int n){
    int i=0,j=0;
    int temp;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                }
        }
    }
    return arr;
}
#endif