#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// n-ary tree (first_child/next_sibling model)

struct Node {
    int value;
    struct Node* first_child;
    struct Node* next_sibling;
};

struct Node* create_node(int value) {
    struct Node* new_node = malloc(sizeof(struct Node));

    new_node->value = value;
    new_node->first_child = NULL;
    new_node->next_sibling = NULL;

    return new_node;
}

void add_child(struct Node* parent, struct Node* child) {
    if (parent->first_child == NULL) {
        parent->first_child = child;
    } else {
        struct Node *temp = parent->first_child;
        while (temp->next_sibling != NULL) {
            temp = temp->next_sibling;
        }
        temp->next_sibling = child;
    }
}

void print_preorder(struct Node* root, int level) {
    if (root == NULL) return;

    for (int i = 0; i < level; i++) {
        printf(" ");
    }
    printf("%d\n", root->value);

    print_preorder(root->first_child, level + 1);
    print_preorder(root->next_sibling, level);
}

void free_tree(struct Node *root) {
    // frees in postorder
    if (root == NULL) return;

    free_tree(root->first_child);
    free_tree(root->next_sibling);
    free(root);
}

int main() {
    struct Node* root = create_node(1); // create first node

    /*
    create some nodes
    */
    struct Node* n2 = create_node(2);
    struct Node* n3 = create_node(3);
    struct Node* n4 = create_node(4);

    /*
    add to root the nodes previously created, now they'will be root children
    */
    add_child(root, n2);
    add_child(root, n3);
    add_child(root, n4);

    /*
    add child nodes to the nodes added to root
    */
    add_child(n2, create_node(5));
    add_child(n2, create_node(6));
    add_child(n3, create_node(7));
    /*
    Out:
    1
     2
      5
      6
     3
      7
     4
    */
    print_preorder(root, 0); // print the tree from root (0 arg is only for visual indentation)
    free_tree(root); // free tree to root

    return 0;
}