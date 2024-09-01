#include "tree.h"
int check(node* root);
int main(){
    printf("1.create a binary tree\n2.diplay inorder\n3.display preorder\n4.display postorder\n7.exit");
    int ch;
    node* root=NULL;
    while(1)
    {
        printf("\nEnter ur choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                root=create();
                printf("tree created sucessfully!!\n");
                break;
            case 2:
                if(check(root))
                    break;
                printf("\ninorder:");
                inorder(root);
                break;
            case 3:
                if(check(root))
                    break;
                printf("\npreorder:");
                preorder(root);
                // printf("\npreorder:");
                break;
            case 4:
                if(check(root))
                    break;
                printf("\npostorder:");
                postorder(root);
                break;
            case 7:
                exit(1);
            default:
                break;
        }
    }

}
int check(node* root){
    if(root==NULL){
        printf("create a tree,TRY again!!\n");
        return 1;
        }
    return 0;
}