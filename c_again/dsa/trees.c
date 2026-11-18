#include <stdio.h>
#include <stdlib.h>

/* A Binary Search Tree (BST) is a tree where each node has up to two children.
 * For every node: values in the left subtree are smaller, values in the right
 * subtree are larger. This makes search, insert, and delete fast (O(log n)
 * average case). */

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Create a new tree node with the given value.
 * Allocates memory with malloc, sets data, and leaves children as NULL. */
struct TreeNode *createNode(int value) {
    struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Insert a value into the BST rooted at `root`.
 * If root is NULL, the new node becomes the root.
 * Otherwise, compare the value with root->data and go left or right
 * until finding an empty spot. Returns the (possibly new) root. */
struct TreeNode *insert(struct TreeNode *root, int value) {
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

/* Search for a value in the BST rooted at `root`.
 * Return the node if found, otherwise NULL.
 * At each step, compare and go left (smaller) or right (larger). */
struct TreeNode *search(struct TreeNode *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

/* In-order traversal: visit left subtree, then root, then right subtree.
 * This prints the values in ascending order for a BST. */
void inorder(struct TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Free all nodes in the tree to avoid memory leaks.
 * Post-order traversal: free children before freeing the node itself. */
void freeTree(struct TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode *root = NULL;

    /* Build a BST by inserting values. */
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal (sorted): ");
    inorder(root);
    printf("\n");

    /* Search for a value that exists. */
    int find = 40;
    struct TreeNode *found = search(root, find);
    if (found != NULL) {
        printf("Found %d in the tree\n", find);
    } else {
        printf("%d not found in the tree\n", find);
    }

    /* Search for a value that does not exist. */
    find = 99;
    found = search(root, find);
    if (found != NULL) {
        printf("Found %d in the tree\n", find);
    } else {
        printf("%d not found in the tree\n", find);
    }

    /* Clean up allocated memory. */
    freeTree(root);

    return 0;
}
