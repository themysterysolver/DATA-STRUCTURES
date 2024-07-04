#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

int linear_search(int *arr,int n,int key){
    int i=0;
    for(i=0;i<n;i++){
        if(arr[i]==key)
            return 1;
    }
    return 0;
}
#endif