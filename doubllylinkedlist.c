#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* head = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void displayList() {
    Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(int data) {
    Node* newNode = createNode(data);
    if (head) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertBeforeAfter(int key, int data, int after) {
    Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) { printf("Node %d not found.\n", key); return; }

    Node* newNode = createNode(data);
    if (after) { // Insert after
        newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    } else { // Insert before
        if (temp == head) { insertAtBeginning(data); return; }
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

void deleteNodeByKey(int key) {
    if (!head) { printf("List is empty.\n"); return; }
    Node* temp = head;
    if (temp->data == key) {
        head = head->next;
        if (head) head->prev = NULL;
        free(temp); return;
    }
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) { printf("Node %d not found.\n", key); return; }
    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;
    free(temp);
}

void deleteFromEnd() {
    if (!head) { printf("List is empty.\n"); return; }
    Node* temp = head;
    if (!temp->next) { free(temp); head = NULL; return; }
    while (temp->next) temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

int main() {
    int ch, data, key;
    while (1) {
        printf("\n--- Menu ---\n"
               "1.Insert Beg  2.Insert End  3.Insert Before  4.Insert After\n"
               "5.Delete Beg  6.Delete End  7.Delete Node    8.Display  9.Exit\n"
               "Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Data: "); scanf("%d", &data); insertAtBeginning(data); break;
            case 2: printf("Data: "); scanf("%d", &data); insertAtEnd(data); break;
            case 3: printf("Key: "); scanf("%d", &key); printf("Data: "); scanf("%d", &data); insertBeforeAfter(key, data, 0); break;
            case 4: printf("Key: "); scanf("%d", &key); printf("Data: "); scanf("%d", &data); insertBeforeAfter(key, data, 1); break;
            case 5: deleteNodeByKey(head ? head->data : 0); break;
            case 6: deleteFromEnd(); break;
            case 7: printf("Key: "); scanf("%d", &key); deleteNodeByKey(key); break;
            case 8: displayList(); break;
            case 9: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
