#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int element) {
    if (top < MAX - 1) {
        top = top + 1;
        stack[top] = element;
    } else {
        printf("Couldn't push element: the stack is full.\n");
    }
}

int pop() {
    if (top >= 0) {
        int last_element = stack[top];
        top = top - 1;
        return last_element;
    } else {
        printf("Couldn't pop element: the stack is empty.\n");
        return -1; // return -1 only for return an int
    }
}

int peek() {
    if (top >= 0) {
        return stack[top];
    }
    printf("The stack is empty.\n");
    return -1; // return -1 only for return an int
}

void is_empty() {
    printf("Is empty?:\n");

    if (top < 0) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack has elements.\n");
    }
}

void print_stack() {
    printf("printing...\n");
    if (top < 0) {
        printf("Couldn't show elements: the stack is empty.\n");
    } else {
        for (int i = 0; i < top + 1; i++) {
            printf("%d : %d\n", i, stack[i]);
        }
    }
    printf("Finish printing.\n");
}

int main() {
    // check if the stack is empty first
    is_empty();

    //push some elements
    push(5);
    push(10);
    push(15);

    // get the last
    int last_element = peek();
    printf("Last element: %d.\n", last_element);

    // show elements
    print_stack();

    // pop 2 elments (1 remaining)
    pop();
    pop();

    // verify status (must be "The stack has elements.")
    is_empty();

    // pop last element
    pop();

    // verify status (must be "The stack is empty.")
    is_empty();

    return 0;
}


