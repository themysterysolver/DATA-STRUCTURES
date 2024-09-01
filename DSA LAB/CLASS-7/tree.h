#include <stdio.h>
#include <stdlib.h>

#ifndef TREE_H
#define TREE_H

struct NODE{ //DEFINING THE STRUCTURE FOR TREE!!
    int data;
    struct NODE *left;
    struct NODE *right;
};
typedef struct NODE node;

node *create(){   //creating a binary tree!!
    int x;
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("enter the data and -1 to indicate the child:");
    scanf("%d",&x);
    if(x==-1)
        return 0;
    newnode->data=x;
    printf("\nenter the data of left subtree:");
    newnode->left=create();
    printf("\nenter the data of right subtree:");
    newnode->right=create();
    return newnode;
}
node *createbst(){   //creating a binary search! tree!!
    int x;
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("enter the data and -1 to indicate the child:");
    scanf("%d",&x);
    if(x==-1)
        return 0;
    newnode->data=x;
    printf("\nenter the data of left subtree:");
    newnode->left=create();
    printf("\nenter the data of right subtree:");
    newnode->right=create();
    return newnode;
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