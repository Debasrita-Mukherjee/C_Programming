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
if (head == NULL) {
head = newNode;
head->next = head;
} else {
struct Node* temp = head;
while (temp->next != head)
temp = temp->next;
temp->next = newNode;
newNode->next = head;
}
}
void display() {
if (head == NULL) {
printf("List is empty.\n");
return;
}
struct Node* temp = head;
printf("Circular Linked List: ");
do {
printf("%d -> ", temp->data);
temp = temp->next;
} while (temp != head);
printf("(back to head)\n");
}
void insertAtBeginning(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
if (head == NULL) {
head = newNode;
newNode->next = head;
} else {
struct Node* temp = head;
while (temp->next != head)
temp = temp->next;
newNode->next = head;
temp->next = newNode;
head = newNode;
}
}
void insertAtEnd(int data) {
create(data);
}
void insertAfter(int key, int data) {
if (head == NULL) return;
struct Node* temp = head;
do {
if (temp->data == key) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = temp->next;
temp->next = newNode;
return;
}
temp = temp->next;
} while (temp != head);
printf("Node with data %d not found.\n", key);
}
void insertBefore(int key, int data) {
if (head == NULL) return;
if (head->data == key) {
insertAtBeginning(data);
return;
}
struct Node* prev = NULL;
struct Node* curr = head;
do {
prev = curr;
curr = curr->next;
if (curr->data == key) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = curr;
prev->next = newNode;
return;
}
} while (curr != head);
printf("Node with data %d not found.\n", key);
}
void deleteBeginning() {
if (head == NULL) return;
if (head->next == head) {
free(head);
head = NULL;
} else {
struct Node* temp = head;
while (temp->next != head)
temp = temp->next;
struct Node* del = head;
temp->next = head->next;
head = head->next;
free(del);
}
}
void deleteEnd() {
if (head == NULL) return;
if (head->next == head) {
    free(head);
head = NULL;
} else {
struct Node* temp = head;
struct Node* prev = NULL;
while (temp->next != head) {
prev = temp;
temp = temp->next;
}
prev->next = head;
free(temp);
}
}
void deleteAfter(int key) {
if (head == NULL) return;
struct Node* temp = head;
do {
if (temp->data == key) {
struct Node* del = temp->next;
if (del == head)
head = head->next;
temp->next = del->next;
free(del);
return;
}
temp = temp->next;
} while (temp != head);
printf("Node with data %d not found.\n", key);
}
void deleteAt(int key) {
if (head == NULL) return;
if (head->data == key && head->next == head) {
free(head);
head = NULL;
return;
}
struct Node* curr = head;
struct Node* prev = NULL;
do {
if (curr->data == key) {
if (curr == head) {
struct Node* temp = head;
while (temp->next != head)
temp = temp->next;
temp->next = head->next;
head = head->next;
free(curr);
} else {
prev->next = curr->next;
free(curr);
}
return;
}
prev = curr;
curr = curr->next;
} while (curr != head);
printf("Node with data %d not found.\n", key);
}
int main() {
int choice, data, key;
do {
printf("\n--- Circular Linked List Menu ---\n");
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