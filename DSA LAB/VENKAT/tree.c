#include "tree.h"

int main(){
	Treelist* tree4 = NULL;
	Treelist* tree3 = NULL;
	Treelist* tree2 = NULL;
	Treelist* tree1 = NULL; 
	Tree* tree0 = NULL;
	
	appendSubtree(&tree4, createLeaf(10));
	appendSubtree(&tree4, createLeaf(11));
	appendSubtree(&tree4, createLeaf(12));
	
	appendSubtree(&tree3, createLeaf(7));
	appendSubtree(&tree3, createLeaf(8));
	appendSubtree(&tree3, createLeaf(9));
	
	appendSubtree(&tree2, createLeaf(4));
	appendSubtree(&tree2, createLeaf(5));
	appendSubtree(&tree2, createLeaf(6));

	Tree* t1 = createLeaf(1);
	t1->children = tree2;
	Tree* t2 = createLeaf(2);
	t2->children = tree3;
	Tree* t3 = createLeaf(3);
	t3->children = tree4;

	appendSubtree(&tree1, t1);
	appendSubtree(&tree1, t2);
	appendSubtree(&tree1, t3);

	tree0 = createLeaf(0);
	tree0->children = tree1;

	preorder(tree0);

	postorder(tree0);
	
	//pretraverse(tree1);
	/*pretraverse(tree2);
	pretraverse(tree3);
	pretraverse(tree4);*/
	return 0;
}

