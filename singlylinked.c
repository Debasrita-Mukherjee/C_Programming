#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* head = NULL;
void create(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
if (head == NULL)
head = newNode;
else {
struct Node* temp = head;
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
}
}
void display() {
struct Node* temp = head;
printf("Linked List: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
void insertAtBeginning(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = head;
head = newNode;
}
void insertAtEnd(int data) {
create(data);
}
void insertAfter(int key, int data) {
struct Node* temp = head;
while (temp != NULL && temp->data != key)
temp = temp->next;
if (temp == NULL) {
printf("Node with data %d not found.\n", key);
return;
}
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = temp->next;
temp->next = newNode;
}
void insertBefore(int key, int data) {
if (head == NULL) return;
if (head->data == key) {
insertAtBeginning(data);
return;
}
struct Node* prev = NULL;
struct Node* curr = head;
while (curr != NULL && curr->data != key) {
prev = curr;
curr = curr->next;
}
if (curr == NULL) {
printf("Node with data %d not found.\n", key);
return;
}
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = curr;
prev->next = newNode;
}
void deleteBeginning() {
if (head == NULL) return;
struct Node* temp = head;
head = head->next;
free(temp);
}
void deleteEnd() {
if (head == NULL) return;
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
void deleteAfter(int key) {
struct Node* temp = head;
while (temp != NULL && temp->data != key)
temp = temp->next;
if (temp == NULL || temp->next == NULL) {
printf("No node to delete after %d\n", key);
return;
}
struct Node* nodeToDelete = temp->next;
temp->next = nodeToDelete->next;
free(nodeToDelete);
}
void deleteAt(int key) {
if (head == NULL) return;
if (head->data == key) {
struct Node* temp = head;
head = head->next;
free(temp);
return;
}
struct Node* prev = NULL;
struct Node* curr = head;
while (curr != NULL && curr->data != key) {
prev = curr;
curr = curr->next;
}
if (curr == NULL) {
printf("Node with data %d not found.\n", key);
return;
}
prev->next = curr->next;
free(curr);
}
int main() {
int choice, data, key;
do {
printf("\n--- Singly Linked List Menu ---\n");
printf("1. Create Node\n2. Display\n3. Insert at Beginning\n4. Insert at End\n");
printf("5. Insert After\n6. Insert Before\n7. Delete from Beginning\n");
printf("8. Delete from End\n9. Delete After\n10. Delete At\n0. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter data: "); scanf("%d", &data);
create(data);
break;
case 2:
display();
break;
case 3:
printf("Enter data: "); scanf("%d", &data);
insertAtBeginning(data);
break;
case 4:
printf("Enter data: "); scanf("%d", &data);
insertAtEnd(data);
break;
case 5:
printf("Insert after node with data: "); scanf("%d", &key);
printf("Enter new data: "); scanf("%d", &data);
insertAfter(key, data);
break;
case 6:
printf("Insert before node with data: "); scanf("%d", &key);
printf("Enter new data: "); scanf("%d", &data);
insertBefore(key, data);
break;
case 7:
deleteBeginning();
break;
case 8:
deleteEnd();
break;
case 9:
printf("Delete node after data: "); scanf("%d", &key);
deleteAfter(key);
break;
case 10:
printf("Delete node with data: "); scanf("%d", &key);
deleteAt(key);
break;
case 0:
printf("Exiting...\n");
break;
default:
printf("Invalid choice!\n");
}
} while (choice != 0);
return 0;
}