#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int queue[MAX];
int front = 0;
int rear = 0;

void enqueue(int element) {

    if ((rear + 1) % MAX == front) { // if the result of rear + 1 % 10 == current value of front...
        printf("Queue is full.\n");
        exit(1);
    }
    queue[rear] = element;
    rear = (rear + 1) % MAX;
}

int dequeue() {

    if (front == rear) {
        printf("Queue is empty.\n");
        exit(1);
    }

    int value = queue[front];
    front = (front + 1) % MAX;
    return value;
}

void is_empty() {
    if (front == rear) {
        printf("Queue is empty.\n");
    }
}

void is_full() {
    if ((rear + 1) % MAX == front) { // if the result of rear + 1 % 10 == current value of front...
        printf("Queue is full.\n");
    }
}

int peek() {
    if (front == rear) {
        printf("Queue is empty.\n");
        exit(1);
    }
    return queue[front];
}

int main() {

    // enqueue elements
    enqueue(5);
    enqueue(10);
    enqueue(15);

    // take the first added
    int first_in = peek();
    printf("First added: %d\n", first_in);

    // dequeue the three elements added
    dequeue();
    dequeue();
    dequeue();

    // verify status
    is_empty();

    return 0;
}