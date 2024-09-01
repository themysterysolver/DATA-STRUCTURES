#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct NODE{
    struct NODE *left;
    struct NODE *right;
    int data;
};
typedef struct NODE node;
node *createnode(int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=val;
    return newnode;
}
void preorder(node *root){
    if(!root) return;
    printf("%c",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root){
    if(!root) return;
    inorder(root->left);
    printf("%c",root->data);
    inorder(root->right);
}
void postorder(node *root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c",root->data);
}
node *insert(node *root,int val){
    if(root==NULL)
        return createnode(val);
    if(val<root->data)
        root->left=insert(root->left,val);
    else if(val>root->data)
        root->right=insert(root->right,val);
    return root;
}

#endif