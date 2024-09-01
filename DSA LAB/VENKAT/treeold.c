#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct binarytree
{
    struct binarytree *left;
    struct binarytree *right;
    int val;
} binarytree;

binarytree *createleaf(int value)
{
    binarytree *leaf = (binarytree *)malloc(sizeof(binarytree));
    leaf->val = value;
    leaf->left = NULL;
    leaf->right = NULL;
    return leaf;
}

void binaryinsert(binarytree **tree, int value)
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

void preorder(binarytree *tree)
{
    if (!tree){
        printf("{}");
        return;
    }
    printf("{ %d ", tree->val);
    preorder(tree->left);
    preorder(tree->right);
    printf("}");
}

void inorder(binarytree *tree)
{
    if (!tree){
        printf("{}");
        return;
    }
    inorder(tree->left);
    printf("{ %d ", tree->val);
    inorder(tree->right);
    printf("}");
}

void postorder(binarytree *tree)
{
    if (!tree)
        return;
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ", tree->val);
}

binarytree* randomtree(int p, int low, int high, int lev){
    int c = rand();
    if(c % p == 0 || lev == 0)
        return NULL;
    binarytree* node = createleaf(c % high + low);
    node->left = randomtree(p, low, high, lev - 1);
    node->right = randomtree(p, low, high, lev - 1);
    return node;
}

int compareStructure(binarytree *tree1, binarytree *tree2){
    if(!tree1){
        if(tree2)   return 0;
        else    return 1;
    }
    else{
        if(!tree2)  return 0;
        else return compareStructure(tree1->left, tree2->left) && compareStructure(tree1->right, tree2->right);
    }
}

int depth(binarytree* tree){
    if(!tree)   return 0;
    int a = depth(tree->left), b = depth(tree->right);
    if(a > b)   return 1 + a;
    else    return 1 + b;
}

int max(int a[], int n){
    if(n == 1)  return a[0];
    int t = max(a + 1, n - 1);
    if(t > a[0])    return t;
    else return a[0];
}


int main()
{   
    srand(time(0));
    /*//int a[] = {57, 43, 38, 88, 5, 21, 3, 68, 57, 26, 72, 73, 96, 64}, i;
    linklist *list1 = randomlist(15, 0, 200, 25);//, *list2 = randomlist(15, 0, 200, 7);
    //print(list);
    binarytree *root1 = createleaf(list1->value);//, *root2 = createleaf(list2->value);
    for (linklist *t = list1; t; t = t->next)
    {
        //printf("%d ", t->value);
        binaryinsert(&root1, t->value);
    }
    /*for (linklist *t = list2; t; t = t->next)
    {
        //printf("%d ", t->value);
        binaryinsert(&root2, t->value + 1);
    }
    /*printf("boo");
    preorder(head);
    printf("\n");
    printf("boo");
    inorder(head);
    printf("\n");
    printf("boo");
    postorder(head);
    printf("\n");
    printf("boo");*/
    binarytree *root1 = randomtree(4, 0, 20, 5);
    printf("\n");
    preorder(root1);
    printf("\n%d %d\n", maxPathSum(root1), depth(root1));
    return 0;
}