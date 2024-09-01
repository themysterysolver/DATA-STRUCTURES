//BINARY SEARCH TREEE!!!
#include<stdio.h>
#include<stdlib.h>

struct Node //node creation!!
{
        int key;
        struct Node *left;
        struct Node *right;
        int height;
};

struct Node* newNode(int key)  //newnode!!
{
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return(node);
}
struct Node* insert(struct Node* node, int key) /* inserting according into tree*/
{

        if (node == NULL)
                return(newNode(key));

        if (key < node->key)
                node->left = insert(node->left, key);
        else if (key > node->key)
                node->right = insert(node->right, key);
        else
                return node;
	    return node;
}


void preOrder(struct Node *root) //preorderfunctioN!!
{
        if(root != NULL)
        {
                printf("%d ", root->key);
                preOrder(root->left);
                preOrder(root->right);
        }
}


int main()
{
struct Node *root = NULL;


root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 30);
root = insert(root, 40);
root = insert(root, 50);
root = insert(root, 25);



printf("Preorder traversal of the constructed Binary search tree: tree is \n");
preOrder(root);

return 0;
}
