#include <stdio.h>
#include <stdlib.h>

#ifndef bstTREE_H
#define bstTREE_H

struct NODE{ //DEFINING THE STRUCTURE FOR TREE!!
    int data;
    struct NODE *left;
    struct NODE *right;
};
typedef struct NODE node;

node *createnode(){   //creating a node!!!
    int x;
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("enter new node:");
    scanf("%d",&x);
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=x;
    return newnode;
}
node *createbst(node *root){ //creating bst!
    while(1){
    printf("enter -1 to terminate:");
    int i;
    scanf("%d",i);
    if(i==-1)
        break;
    if(root==NULL)
        root=createnewnode();
    node* cnode=createnode();
    insert(root,cnode);
    }
    return root;
}
node *insert(node *root,node *cnode){ //INSERT FUNCTION!!
    if(root->data<=cnode->data)
        root->left=insert(root->left)
}

void inorder(node *current){         //LEFT->CURRENT->RIGHT!
    if(current==0)
        return ;
    inorder(current->left);
    printf("%d",current->data);
    inorder(current->right);   
}
void preorder(node *current){         //CURRENT->LEFT->RIGHT!
    if(current==0)
        return ;
    printf("%d",current->data);
    preorder(current->left);
    preorder(current->right);   
}
void postorder(node *current){         //LEFT->RIGHT->CURRENT!
    if(current==0)
        return ;
    postorder(current->left);
    postorder(current->right);  
    printf("%d",current->data); 
}



#endif