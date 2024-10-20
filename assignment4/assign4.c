#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to add a node to the BST
Node* addNode(Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = addNode(root->left, data);
    } else if (data > root->data) {
        root->right = addNode(root->right, data);
    }

    // Return the unchanged node pointer
    return root;
}

// In-order traversal to print the tree
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Main function to demonstrate the functionality
int main() {
    Node* root = NULL;

    // Adding nodes to the BST
    root = addNode(root, 50);
    root = addNode(root, 30);
    root = addNode(root, 70);
    root = addNode(root, 20);
    root = addNode(root, 40);
    root = addNode(root, 60);
    root = addNode(root, 80);

    // Printing the BST in order
    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
