#include <stdio.h>
#include <stdlib.h>
#include "link.h"
#include "binarytree.h"

#ifndef HEADERS_H
#define HEADERS_H

linklist* randomlist(int p, int low, int high, int max){
    int c = rand();
    if(c % p == 0 || max == 0)
        return NULL;
    linklist* node = createnode(c % high + low);
    node->next = randomlist(p, low, high, max - 1);
    return node;
}

void printarray(int p, char sep, int low, int high, int max){
    int c = rand();
    if(c % p == 0 || max == 0)
        return;
    else{
        printf("%d%c ", c % high + low, sep);
        printarray(p, sep, low, high, max - 1);
    }
}

BinaryTree* randomtree(int p, int low, int high, int lev){
    int c = rand();
    if(c % p == 0 || lev == 0)
        return NULL;
    BinaryTree* node = createleaf(c % high + low);
    node->left = randomtree(p, low, high, lev - 1);
    node->right = randomtree(p, low, high, lev - 1);
    return node;
}

#endif
