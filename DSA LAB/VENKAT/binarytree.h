#include <stdio.h>
#include <stdlib.h>

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct BinaryTree
{
    struct BinaryTree *left;
    struct BinaryTree *right;
    int val;
} BinaryTree;

BinaryTree *createleaf(int value)
{
    BinaryTree *leaf = (BinaryTree *)malloc(sizeof(BinaryTree));
    leaf->val = value;
    leaf->left = NULL;
    leaf->right = NULL;
    return leaf;
}

void binaryinsert(BinaryTree **tree, int value)
{
    if (!*tree)
        *tree = createleaf(value);
    else
    {
        if (value < (*tree)->val)
            binaryinsert(&((*tree)->left), value);
        else if (value > (*tree)->val)
            binaryinsert(&((*tree)->right), value);
    }
}

int inBST(BinaryTree *t, int target){
    if(!t)  return 0;
    if(t->val == target)   return 1;
    if(t->val > target)    return inBST(t->left, target);
    else    return inBST(t->right, target);
}

int inBT(BinaryTree *t, int target){
    if(!t)  return 0;
    return t->val || inBT(t->left, target) || inBT(t->right, target);
}

int min(BinaryTree *t)
{
    int a = (t->left) ? min(t->left) : t->val, b = (t->right) ? min(t->right) : t->val;
    return (a > b) ? b : a;
}

int max(BinaryTree *t)
{
    int a = (t->left) ? max(t->left) : t->val, b = (t->right) ? max(t->right) : t->val;
    return (a > b) ? a : b;
}

void leftdel(BinaryTree **tree, int val)
{
    if ((*tree)->val == val)
    {
        if ((*tree)->left)
        {
            if ((*tree)->right)
            {
                int predecessor = max((*tree)->left);
                leftdel(&((*tree)->left), predecessor);
                (*tree)->val = predecessor;
            }
            else
            {
                *tree = (*tree)->left;
            }
        }
        else
        {
            *tree = (*tree)->right;
        }
    }
    else if ((*tree)->val > val)
        leftdel(&((*tree)->left), val);
    else
        leftdel(&((*tree)->right), val);
}

void rightdel(BinaryTree **tree, int val)
{
    if ((*tree)->val == val)
    {
        if ((*tree)->left)
        {
            if ((*tree)->right)
            {
                int successor = min((*tree)->right);
                rightdel(&((*tree)->right), successor);
                (*tree)->val = successor;
            }
            else
            {
                *tree = (*tree)->left;
            }
        }
        else
        {
            *tree = (*tree)->right;
        }
    }
    else if ((*tree)->val > val)
        rightdel(&((*tree)->left), val);
    else
        rightdel(&((*tree)->right), val);
}

void preorder(BinaryTree *tree)
{
    if (!tree)
        return;
    printf(" %d ", tree->val);
    preorder(tree->left);
    preorder(tree->right);
}

void inorder(BinaryTree *tree)
{
    if (!tree)
        return;
    inorder(tree->left);
    printf(" %d ", tree->val);
    inorder(tree->right);
}

void postorder(BinaryTree *tree)
{
    if (!tree)
        return;
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ", tree->val);
}

int depth(BinaryTree* tree){
    if(!tree)   return 0;
    int a = depth(tree->left), b = depth(tree->right);
    if(a > b)   return a + 1;
    else    return b + 1;
}

typedef struct
{
    BinaryTree *node;
    int depth, pos;
} queue1;

typedef struct
{
    int data, depth, pos;
} queue2;

long power(int base, int exp)
{
    if (exp == 0)
        return 1;
    else
        return base * power(base, exp - 1);
}

void display(BinaryTree *tree){
    int deep = depth(tree), n = power(2, deep), i = 0;
    int front1 = 0, front2 = 0, front3 = 0;
    int rear1 = 0, rear2 = 0, rear3 = 0;
    queue1 *q1 = (queue1*)malloc(n * sizeof(queue1)), temp;
    queue2 *q2 = (queue2*)malloc(n * sizeof(queue2)), temp2;
    queue2 *q3 = (queue2*)malloc(n * sizeof(queue2));
    q1[rear1++] = (queue1){tree, 1, power(2, deep) - 2};
    q2[rear2++] = (queue2){tree->val, q1[0].depth, q1[0].pos};
    while(front1 != rear1){
        temp = q1[front1++];
        if(temp.node->left){
            q1[rear1++] = (queue1){temp.node->left, 
            temp.depth + 1, 
            temp.pos - power(2, deep - temp.depth)
            };
            q2[rear2++] = (queue2){q1[rear1-1].node->val, 
            q1[rear1-1].depth, 
            q1[rear1-1].pos};
        }
        if(temp.node->right){
            q1[rear1++] = (queue1){temp.node->right, 
            temp.depth + 1, 
            temp.pos + power(2, deep - temp.depth)
            };
            q2[rear2++] = (queue2){q1[rear1-1].node->val, 
            q1[rear1-1].depth, 
            q1[rear1-1].pos};
        }
    }
    int currentDepth = 0, currentOffset = 0;
    printf("The tree:");
    for(i = 0; i < rear2; i++){
        temp2 = q2[i];
        if(temp2.depth != currentDepth){
            printf("\n\n");
            currentDepth = temp2.depth;
            currentOffset = 0;
        }
        printf("%*s%2d", temp2.pos - currentOffset, "", temp2.data);
        currentOffset = temp2.pos + 2;
    }
    printf("\n");
}

void inOrderPos(BinaryTree* tree, queue2* positions, int level, int* j){
    if(!tree)   return;
    inOrderPos(tree->left, positions, level + 1, j);
    positions[*j] = (queue2){tree->val, level, (*j)++};
    inOrderPos(tree->right, positions, level + 1, j);
}

int noOfNodes(BinaryTree* t){
    if(!t)  return 0;
    return 1 + noOfNodes(t->left) + noOfNodes(t->right);
}

void display1(BinaryTree* tree){
    if(!tree){
        printf("Empty tree\n");
        return;
    }
    printf("\n\n");
    int n = noOfNodes(tree), deep = depth(tree), i = 0, level, currentOffset;
    queue2 *q = (queue2*)malloc(n * sizeof(queue2)), temp2;
    inOrderPos(tree, q, 1, &i);
    for(level = 1; level <= deep; level++){
        currentOffset = 0;
        for(i = 0; i < n; i++){
            if(q[i].depth != level) continue;
            currentOffset += printf("%*d", 2 * q[i].pos - currentOffset + 2, q[i].data);
        }
        printf("\n\n");
    }
}

#endif
