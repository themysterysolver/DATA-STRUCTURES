#include "headers.h"

int main()
{   
    srand(time(0));
    int a[] = {57, 43, 38, 88, 5, 21, 3, 68, 57, 26, 72, 73, 96, 64}, i;
    linklist *list1 = randomlist(10, 0, 99, 25), *t;
    printf("The list:\n");
    print(list1);
    BinaryTree *root2 = createleaf(list1->value), *root1 = randomtree(100, 0, 10, 3);
    for (t = list1; t; t = t->next)
    {
        //printf("%d ", t->value);
        binaryinsert(&root2, t->value);
    }
    /*for (linklist *t = list2; t; t = t->next)
    {
        //printf("%d ", t->value);
        binaryinsert(&root2, t->value + 1);
    }*/
    display(root1);
    display1(root2);
    printf("\nIn-order:\n");
    inorder(root1);
    printf("\nPre-order\n");
    preorder(root1);
    printf("\nPost-order\n");
    postorder(root1);
    printf("\nDepth (or height, whatever): %d\n", depth(root1));
    //printf("%d", printf("%*d", 5, 30));
    getchar();
    return 0;
}
