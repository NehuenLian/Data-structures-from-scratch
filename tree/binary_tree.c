#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// classic binary tree

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* new_node(int value) {
    struct Node *node = malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct Node* insert_node(struct Node *root, int value) {
    if (root == NULL) {
        return new_node(value);
    }
    /*
    the tree will ignore if the values are greater or less than the father node
    with this logic the imbalance will be only 1 level
    */
    if (root->left == NULL) {
        root->left = insert_node(root->left, value);
    } else if (root->right == NULL) {
        root->right = insert_node(root->right, value);
    } else {
        root->left = insert_node(root->left, value);
    }
}

void print_preorder(struct Node *root) {
    if (root == NULL) return;

    printf("%d\n", root->value);
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_inorder(struct Node *root) {
    if (root == NULL) return;

    print_inorder(root->left);
    printf("%d\n", root->value);
    print_inorder(root->right);
}

void print_postorder(struct Node *root) {
    if (root == NULL) return;

    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d\n", root->value);
}

void free_tree(struct Node* root) {
    // free in postorder
    if (root == NULL) return;

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;

    root = insert_node(root, 10);
    root = insert_node(root, 20);
    root = insert_node(root, 30);
    root = insert_node(root, 40);
    root = insert_node(root, 50);

    printf("Preorder:\n");
    print_preorder(root);

    printf("\nInorder:\n");
    print_inorder(root);

    printf("\nPostorder:\n");
    print_postorder(root);

    return 0;
}