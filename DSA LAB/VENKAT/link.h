#include <stdio.h>
#include <stdlib.h>

#ifndef LINK_H
#define LINK_H

typedef struct linklist{
        int value;
        struct linklist* next;
}linklist;

linklist* createnode(int val){
    linklist* node = (linklist*)malloc(sizeof(linklist));
    node->value = val;
    node->next = NULL;
    return node;
}

void print(linklist* list){
    if(list){
        printf("%d ", list->value);
        print(list->next);
    }
    else{
        printf("\n");
    }
}


void insert(linklist** list, int value, int pos){
    if(pos < -1){
        printf("Invalid position. This is not Python!\n");
        return;
    }
    if(pos == -1){
    	if(!(*list))
			pos = 0;
	}
    if(pos == 0){
        linklist* node = createnode(value);
        node->next = *list;
        *list = node;
        return;
    }
    
    else{
        if(!(*list)){
            printf("Invalid position!\n");
            return;
        }
        if(pos == -1)   pos++;
        insert(&((*list)->next), value, pos - 1);
    }
}

void del(linklist** list, int pos){
    if(pos < -1){
        printf("Invalid position. This is not Python!\n");
        return;
    }
    if(pos == 0){
    	//linklist* temp = list;
        *list = (*list)->next;
        //free(temp);
        return;
    }
    else{
        if(!(*list)){
            printf("Invalid position!\n");
            return;
        }
        del(&((*list)->next), pos - 1);
    }
}

int in(linklist* list, int val){
    if(!list)       return 0;
    if(list->value == val)  return 1;
    return in(list->next, val);
}


void clear(linklist** node){
    if(*node)	clear(&((*node)->next));
    free(*node);
    *node = NULL;
}


#endif