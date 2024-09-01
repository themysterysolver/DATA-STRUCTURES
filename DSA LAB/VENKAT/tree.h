#include <stdio.h>
#include <stdlib.h>

#ifndef TREE_H
#define TREE_H

typedef struct Tree Tree;

typedef struct Treelist{
	Tree* tr;
	struct Treelist* next;
} Treelist;

struct Tree{
	int data;
	Treelist* children;
};

void preorder(Tree*);
void postorder(Tree*);

Tree* createLeaf(int x){
	Tree* leaf = (Tree*)malloc(sizeof(Tree));
	leaf->children = NULL;
	leaf->data = x;
	return leaf;
}

void appendSubtree(Treelist** tl, Tree* t){
	if(*tl) appendSubtree(&((*tl)->next), t);
	else{
		*tl = (Treelist*)malloc(sizeof(Treelist));
		(*tl)->tr = t;
		(*tl)->next = NULL;
	}
}

void pretraverse(Treelist* tl){
	if(tl){
		preorder(tl->tr);
		pretraverse(tl->next);
	}
	else    printf("cc\n");
}

void preorder(Tree* t){
	if(t){
		printf("%d ", t->data);
		pretraverse(t->children);
	}
	else{
		printf("cb");
	}
}

void posttraverse(Treelist* tl){
	if(tl){
		postorder(tl->tr);
		posttraverse(tl->next);
	}
}

void postorder(Tree* t){
	if(t){
		posttraverse(t->children);
		printf("%d ", t->data);
	}
}

#endif