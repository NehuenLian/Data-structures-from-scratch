#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Qeue implemented with a linked list

struct LinkedList {
    struct Node *front;
    struct Node *rear;
};

struct Node {
    int value;
    struct Node *next;
};

struct LinkedList* enqueue(struct LinkedList *linked_list, int value) {
    struct Node *new_node = malloc(sizeof(struct Node));

    new_node->value = value;
    new_node->next = NULL;

    if (linked_list == NULL) {

        struct LinkedList *linked_list = malloc(sizeof(struct LinkedList));

        linked_list->front = new_node;
        linked_list->rear = new_node;

        return linked_list;
    }

    linked_list->rear->next = new_node;
    linked_list->rear = new_node;

    return linked_list;

}

struct LinkedList* dequeue(struct LinkedList *linked_list) {
    if (linked_list == NULL) {
        printf("Nothing to dequeue: list is empty.\n");
        exit(1);
    }

    struct Node *new_front = linked_list->front->next;
    free(linked_list->front);
    if (new_front == NULL) {
        printf("Las element dequeued: Queue is empty.\n");
        linked_list->rear = NULL;
        linked_list->front = NULL;
        
        return linked_list;
    }
    linked_list->front = new_front;

    return linked_list;
}

int peek(struct LinkedList *linked_list) {
    if (linked_list->front == NULL) {
        printf("Queue is empty.\n");
        exit(1);
    }
    int first_in = linked_list->front->value;

    return first_in;
}

void is_empty(struct LinkedList *linked_list) {
    printf("Is empty?\n");

    if (linked_list->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue has elements.\n");
    }
}

int main() {

    struct LinkedList *linked_list = NULL;

    // enqueue three elements
    linked_list = enqueue(linked_list, 5);
    linked_list = enqueue(linked_list, 10);
    linked_list = enqueue(linked_list, 15);

    // dequeue one element
    linked_list = dequeue(linked_list);

    // take first added element
    int first_in = peek(linked_list);
    printf("First added: %d\n", first_in);

    // verify status. expected: "Queue has elements."
    is_empty(linked_list);

    // dequeue the last two elements
    linked_list = dequeue(linked_list);
    linked_list = dequeue(linked_list);

    // verify status. expected: "Queue is empty."
    is_empty(linked_list);

    // free references
    free(linked_list);

    return 0;
}