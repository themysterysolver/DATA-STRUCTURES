//BST traversals with insertion and deletion!!
//initialise poniters to NULL!!
//
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct NODE{                //STRUCTURE OF A NODE!!
    struct NODE *left;
    struct NODE *right;
    int data;
};
typedef struct NODE node;
node *createnode(int val){                  //node creation function!!
    node* newnode=(node*)malloc(sizeof(node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=val;
    return newnode;
}
void preorder(node *root){
    if(!root) return;            //breaking condition!!
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root){
    if(!root) return;           //breaking condition!!
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(node *root){
    if(!root) return;           //breaking condition!!
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
node *insert(node *root,int val){
    if(root==NULL)
        return createnode(val); //acts at last.......breaking condition!!...else at first condition for 1st insertion!!!!
    if(val<root->data)
        root->left=insert(root->left,val);
    else if(val>root->data)
        root->right=insert(root->right,val);
    return root;
}
node *max(node *root){ 
    node *current=root->right;
    while(current && current->right!=NULL)
        current=current->right;
    return current;
}
//deletion have 3 cases del of 0,1,2 child!!
node *del(node *root,int val){
    if(root==NULL)
        return root;
    if(val<root->data)
        root->left=del(root->left,val);
    else if(val>root->data)
        root->right=del(root->right,val); //traversing!!
    else{                                               //KEY PART!!---HEART OF DELETION FUNCTION!!
        if(root->left==NULL){
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node *temp=root->left;
            free(root);
            return temp;
        }//0 node condition!!

    node *temp = max(root->left); // Find the maximum value node in the left subtree
    root->data = temp->data;      // Copy the data of the maximum value node to the current node being deleted
    root->left=del(root->left,temp->data); // Recursively delete the node with the value copied 
    }
    return root;
}


int main(){
    printf("MENU:\n1.insert a node\n2.delete a node\n3.preorder\n4.postorder\n5.inorder\n6.exit\n");
    int ch,x;
    node *root=NULL;
    while(1){
        printf("enter ur choice:");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                printf("enter the value to be inserted:");
                scanf("%d",&x);
                root=insert(root,x);
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("enter the value to be deleted:");
                scanf("%d",&x);
                root=del(root,x);
                inorder(root);
                printf("\n");
                break;
            case 3:
                preorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            case 5:
                inorder(root);
                printf("\n");
                break;
            case 6:
                exit(1);
            default:
                continue;
        }
    }
}
