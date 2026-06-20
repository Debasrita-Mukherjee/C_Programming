#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Size of the circular queue

// Declare the queue
int queue[SIZE];
int front = -1, rear = -1;

// Function to check if queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Function to check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Enqueue operation
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full (Overflow).\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue operation
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty (Underflow).\n");
        return -1;
    }

    int value = queue[front];

    if (front == rear) {
        // Only one element was in queue
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return value;
}

// Peek operation
int peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    }

    return queue[front];
}

// Display operation
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;

            case 3:
                value = peek();
                if (value != -1)
                    printf("Front element: %d\n", value);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
