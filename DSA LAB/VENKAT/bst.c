#include "binarytree.h"

int main(){
    BinaryTree *bst = NULL;
    int i, input, ch, n;
    printf("Enter inital number of elements:");
    scanf("%d", &n);
    printf("Enter elements:");
    for(i = 0; i < n; i++){
        scanf("%d", &input);
        binaryinsert(&bst, input);
    }
    printf("Enter 1 for input\nEnter 2 for deletion\nEnter 3 for traversal\nEnter 4 for searching\nEnter 5 for display\n");
    while(1){
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter input:");
                scanf("%d", &input);
                binaryinsert(&bst, input);
                break;
            case 2:
                if(!bst){
                    printf("Underflow");
                    break;
                }
                printf("Enter number to delete:");
                scanf("%d", &input);
                printf("Enter 1 for left replace\nEnter 2 for right replace\n");
                scanf("%d", &i);
                if(i == 1)      leftdel(&bst, input);
                else    rightdel(&bst, input);
                break;
            case 3:
                if(!bst){
                    printf("Empty tree");
                    break;
                }
                printf("Enter 1 for preorder\nEnter 2 for inorder\nEnter 3 for postorder\nEnter your choice:");
                scanf("%d", &i);
                if(i == 1)      preorder(bst);
                if(i == 2)      inorder(bst);
                if(i == 3)      postorder(bst);
                break;
                case 4:
                printf("Enter target to check:");
                scanf("%d", &input);
                if(inBST(bst, input))
                    printf("%d is in the tree\n", input);
                else
                    printf("%d is not in the tree\n", input);
                break;
            case 5:
                display(bst);
                break;
            default:
                return 0;
        }
    }
}