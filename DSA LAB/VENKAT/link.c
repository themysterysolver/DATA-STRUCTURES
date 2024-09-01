#include <stdio.h>
#include <stdlib.h>

typedef struct linklist{
        struct linklist* next;
        int value;
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

void delete(linklist** list, int pos){
        if(pos < -1){
                printf("Invalid position. This is not Python!\n");
                return;
        }
        if(pos == 0){
                *list = (*list)->next;
                return;
        }
        else{
                if(!(*list)){
                        printf("Invalid position!\n");
                        return;
                }
                delete(&((*list)->next), pos - 1);
        }
}

int in(linklist* list, int val){
        if(!list)       return 0;
        if(list->value == val)  return 1;
        return in(list->next, val);
}


void clear(linklist** node){
        if(*node)       clear(&((*node)->next));
        free(*node);
        *node = NULL;
}

int main(){
        linklist *head = NULL;
        int i, ch, j, k;
        printf("Enter no. of initial elements:");
        scanf("%d", &j);
        printf("Enter elements:\n");
        for(i = 0; i < j; i++){
                scanf("%d", &k);
                insert(&head, k, i);
        }
        while(1){
                printf("Enter 1 for insert\nEnter 2 for delete\nEnter 3 for search\nEnter 4 for display\nEnter your choice:");
                scanf("%d", &ch);
                switch(ch){
                        case 1:
                                printf("Enter position:");
                                scanf("%d", &i);
                                printf("Enter value:");
                                scanf("%d", &j);
                                insert(&head, j, i);
                                break;
                        case 2:
                                printf("Enter deletion position:");
                                scanf("%d", &k);
                                delete(&head, k);
                                break;
                        case 3:
                                printf("Enetr number to search:");
                                scanf("%d", &k);
                                if(in(head, k)) printf("%d found\n", k);
                                else    printf("%d not found\n", k);
                                break;
                        case 4:
                                print(head);
                                break;
                        default:
                                clear(&head);
                                return 0;
                }
        }
}
