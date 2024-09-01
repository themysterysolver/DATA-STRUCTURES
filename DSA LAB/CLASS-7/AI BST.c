#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

struct Node* minValueNode(struct Node* node) {  //in right subt tree the smallest value is in the left,that is the INORDER SUCESSOR!!
    struct Node* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int value, deleteValue;
    char choice;

    do {
        printf("Enter a value to insert into the binary search tree: ");
        scanf("%d", &value);
        
        root = insert(root, value);

        printf("Do you want to continue inserting nodes? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Enter a value to delete from the binary search tree: ");
    scanf("%d", &deleteValue);

    root = deleteNode(root, deleteValue);

    printf("Binary search tree (inorder traversal) after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
