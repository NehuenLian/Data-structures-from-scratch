#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    struct Node *left;
    struct Node *right;
    int value;
};

struct Node* insert_node(int value, struct Node *root) {

    if (root == NULL) {
        struct Node *new_node = malloc(sizeof(struct Node));

        new_node->left = NULL;
        new_node->right = NULL;
        new_node->value = value;

        return new_node;
    }

    if (value < root->value) {
        root->left = insert_node(value, root->left);
    } else if (value > root->value) {
        root->right = insert_node(value, root->right);
    }

    return root;
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

void free_tree(struct Node *root) {
    if (root == NULL) return;

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    struct Node *root = NULL;

    root = insert_node(10, root); // root must be 10
    root = insert_node(5, root); // left must be 5
    root = insert_node(15, root); // right must be 15
    /*
       10
       / \
      5  15
    */

    printf("Inorder:\n");
    print_inorder(root);
    
    printf("\nPreorder:\n");
    print_preorder(root);
    
    printf("\nPostorder:\n");
    print_postorder(root);

    free_tree(root);
    root = NULL;

    return 0;
}