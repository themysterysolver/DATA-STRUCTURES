#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H
#include "BSORT.h"

int binary_search(int *arr,int n,int key){
    Bubble_sort(arr,n);
    int i=0;
    int mid;
    int low=0,high=n;
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]<key)
            low=mid+1;
        else if(arr[mid]>key)
            high=mid-1;
        else if(arr[mid]==key)
            return 1;
    }
    return 0;
}
#endif