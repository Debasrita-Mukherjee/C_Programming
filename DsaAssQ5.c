#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Check if deque is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Check if deque is empty
int isEmpty() {
    return (front == -1);
}

// Insert at front
void insertFront(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at front\n", value);
        return;
    }
    if (front == -1) { // First element
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = value;
    printf("%d inserted at front\n", value);
}

// Insert at rear
void insertRear(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at rear\n", value);
        return;
    }
    if (front == -1) { // First element
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
    printf("%d inserted at rear\n", value);
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow! Cannot delete from front\n");
        return;
    }
    printf("%d deleted from front\n", deque[front]);
    if (front == rear) { // Only one element
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow! Cannot delete from rear\n");
        return;
    }
    printf("%d deleted from rear\n", deque[rear]);
    if (front == rear) { // Only one element
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Display elements
void display() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFront(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertRear(value);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
