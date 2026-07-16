#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* head = NULL;

void create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void insertBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int data) {
    create(data); // already implemented
}

void insertAfter(int key, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node %d not found.\n", key);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Insert before given value
void insertBefore(int key, int data) {
    if (head == NULL) return;
    if (head->data == key) {
        insertBeginning(data);
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;
    if (temp->next == NULL) {
        printf("Node %d not found.\n", key);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// Delete specific node by value
void deleteNode(int key) {
    if (head == NULL) return;
    if (head->data == key) {
        deleteBeginning();
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Node %d not found.\n", key);
        return;
    }

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

// Main menu-driven function
int main() {
    int choice, data, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create node\n");
        printf("2. Display list\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at end\n");
        printf("5. Insert after a node\n");
        printf("6. Insert before a node\n");
        printf("7. Delete from beginning\n");
        printf("8. Delete from end\n");
        printf("9. Delete a specific node\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                create(data);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 5:
                printf("Enter key to insert after: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAfter(key, data);
                break;
            case 6:
                printf("Enter key to insert before: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertBefore(key, data);
                break;
            case 7:
                deleteBeginning();
                break;
            case 8:
                deleteEnd();
                break;
            case 9:
                printf("Enter node value to delete: ");
                scanf("%d", &key);
                deleteNode(key);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
