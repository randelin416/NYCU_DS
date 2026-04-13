#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;   // dummy head node

public:
    // Constructor
    LinkedList() {
        head = new Node(0);   // dummy head (data unused)
        head->next = nullptr;
    }

    // Destructor (free memory)
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head->next;
        head->next = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert after a given value
    void insertAfter(int target, int value) {
        Node* temp = head->next;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }

        if (temp != nullptr) {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else {
            cout << "Value " << target << " not found." << endl;
        }
    }

    // Delete a node by value
    void deleteNode(int value) {
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
        else {
            cout << "Value " << value << " not found." << endl;
        }
    }

    // Display the list
    void display() {
        Node* temp = head->next;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(20);
    list.insertAfter(10, 15);

    cout << "List after insertions:" << endl;
    list.display();

    list.deleteNode(10);

    cout << "List after deleting 10:" << endl;
    list.display();

    return 0;
}