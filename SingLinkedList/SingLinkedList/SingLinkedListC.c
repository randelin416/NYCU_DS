#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Initialize list with a dummy head node
Node* initializeList() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;   // head node does not store real data
    return head;
}

// Insert at beginning
void insertAtBeginning(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head->next;
    head->next = newNode;
}

// Insert at end
void insertAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert after a given value
void insertAfter(Node* head, int target, int value) {
    Node* temp = head->next;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp != NULL) {
        Node* newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else {
        printf("Value %d not found.\n", target);
    }
}

// Delete a node by value
void deleteNode(Node* head, int value) {
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
    else {
        printf("Value %d not found.\n", value);
    }
}

// Display the list
void display(Node* head) {
    Node* temp = head->next;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function for testing
int main() {
    Node* list = initializeList();

    insertAtBeginning(list, 10);
    insertAtBeginning(list, 5);
    insertAtEnd(list, 20);
    insertAfter(list, 10, 15);

    printf("List after insertions:\n");
    display(list);

    deleteNode(list, 10);

    printf("List after deleting 10:\n");
    display(list);

    return 0;
}