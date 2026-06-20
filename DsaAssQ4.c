#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

// Check if deque is full
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

// Check if deque is empty
int isEmpty() {
    return (front == -1);
}

// Insert at rear
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert at rear.\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;  // Wrap around
    } else {
        rear++;
    }

    deque[rear] = value;
    printf("Inserted %d at rear.\n", value);
}

// Insert at front
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert at front.\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;  // Wrap around
    } else {
        front--;
    }

    deque[front] = value;
    printf("Inserted %d at front.\n", value);
}

// Delete from front
int deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from front.\n");
        return -1;
    }

    int value = deque[front];

    if (front == rear) {
        front = rear = -1;  // Only one element
    } else if (front == SIZE - 1) {
        front = 0;  // Wrap around
    } else {
        front++;
    }

    return value;
}

// Delete from rear
int deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from rear.\n");
        return -1;
    }

    int value = deque[rear];

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }

    return value;
}

// Get front element
int getFront() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return -1;
    }
    return deque[front];
}

// Get rear element
int getRear() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return -1;
    }
    return deque[rear];
}

// Display deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
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
        printf("\nDeque Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Get Front Element\n");
        printf("6. Get Rear Element\n");
        printf("7. Display Deque\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                value = deleteFront();
                if (value != -1)
                    printf("Deleted from front: %d\n", value);
                break;

            case 4:
                value = deleteRear();
                if (value != -1)
                    printf("Deleted from rear: %d\n", value);
                break;

            case 5:
                value = getFront();
                if (value != -1)
                    printf("Front element: %d\n", value);
                break;

            case 6:
                value = getRear();
                if (value != -1)
                    printf("Rear element: %d\n", value);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
