#include <stdio.h>
#include <stdlib.h>

// Structure representing a tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function prototypes
struct TreeNode *createNode(int data);
struct TreeNode *insert(struct TreeNode *root, int data);
struct TreeNode *deleteNode(struct TreeNode *root, int key);
void inorderTraversal(struct TreeNode *root);
void preorderTraversal(struct TreeNode *root);
void postorderTraversal(struct TreeNode *root);
void displayMenu();

int main() {
    struct TreeNode *root = NULL;
    int choice, value;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;

        case 3:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;

        case 4:
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;

        case 5:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;

        case 6:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

// Function to create a new tree node
struct TreeNode *createNode(int data) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct TreeNode *insert(struct TreeNode *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to delete a node with a given key from the BST
struct TreeNode *deleteNode(struct TreeNode *root, int key) {
    // Implement deletion logic (not shown in this example)
    // You can refer to standard BST deletion algorithms
    return root;
}

// Function for inorder traversal of the BST
void inorderTraversal(struct TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function for preorder traversal of the BST
void preorderTraversal(struct TreeNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function for postorder traversal of the BST
void postorderTraversal(struct TreeNode *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\nBinary Search Tree Menu:\n");
    printf("1. Insert Element\n");
    printf("2. Delete Element\n");
    printf("3. Display Inorder Traversal\n");
    printf("4. Display Preorder Traversal\n");
    printf("5. Display Postorder Traversal\n");
    printf("6. Exit\n");
}
