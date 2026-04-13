#include <iostream>
#include <string>

using namespace std;

// ==========================================
// Template Code 
// ==========================================

// Node structure for Circular Doubly-Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;   // Dummy head node

public:
    CircularLinkedList();
    ~CircularLinkedList();

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAfter(int target, int value);
    void insertBefore(int target, int value);
    void deleteNode(int value);
    void display() const;
    
    // Operator Overloading for concatenation (Deep Copy)
    CircularLinkedList operator+(const CircularLinkedList& other) const;
};

int main() {
    CircularLinkedList listA, listB;
    CircularLinkedList* currentList = &listA; 
    
    string command;
    while (cin >> command) {
        if (command == "switch") {
            char listName;
            cin >> listName;
            currentList = (listName == 'A') ? &listA : &listB;
        } 
        else if (command == "insertAtBeginning") {
            int val; cin >> val;
            currentList->insertAtBeginning(val);
        } 
        else if (command == "insertAtEnd") {
            int val; cin >> val;
            currentList->insertAtEnd(val);
        } 
        else if (command == "insertAfter") {
            int target, val; cin >> target >> val;
            currentList->insertAfter(target, val);
        } 
        else if (command == "insertBefore") {
            int target, val; cin >> target >> val;
            currentList->insertBefore(target, val);
        } 
        else if (command == "deleteNode") {
            int val; cin >> val;
            currentList->deleteNode(val);
        } 
        else if (command == "display") {
            currentList->display();
        } 
        else if (command == "concat") {
            CircularLinkedList listC = listA + listB;
            listC.display();
        }
    }
    return 0;
}
// Constructor: Initialize an empty list with a dummy head node.
CircularLinkedList::CircularLinkedList() {
    // TODO: Allocate memory for the dummy head node.
    // Hint: In an empty CDLL, where should the 'prev' and 'next' pointers of the head point to?
    head = new Node(0);
    head -> prev = head;
    head -> next = head;
}

// Destructor: Free the memory of all nodes (including the dummy head node).
CircularLinkedList::~CircularLinkedList() {
    // TODO: Traverse the list and use delete to free memory.
    // Hint: A circular list has no nullptr. What is your loop termination condition?
    Node* cur = head -> next;
    while (cur != head) {   
        Node* temp = cur -> next;
        delete cur;
        cur = temp;
    }
    delete head;
}

// Insert a new node at the beginning (immediately after the dummy head).
void CircularLinkedList::insertAtBeginning(int value) {
    // TODO: Implement the insertion logic. Make sure to properly update the prev and next pointers.
    Node* newNode = new Node(value);
    newNode -> next = head -> next;
    newNode -> prev = head;
    head -> next -> prev = newNode;
    head -> next = newNode;
      
}

// Insert a new node at the end of the list.
void CircularLinkedList::insertAtEnd(int value) {
    // TODO: Implement the insertion logic.
    // Hint: Leverage the circular and doubly-linked properties; you don't need O(N) time to find the tail!
    Node* newNode = new Node(value);
    head -> prev -> next = newNode;
    newNode -> prev = head -> prev;
    newNode -> next = head;
    head -> prev = newNode;
}

// Insert a new node immediately after the first node containing the target value.
void CircularLinkedList::insertAfter(int target, int value) {
    // TODO: Find the target node and insert the new node after it.
    // If the target is not found, print: cout << "Value " << target << " not found." << endl;
    Node* cur = head -> next;
    while (cur != head) {
        if (cur -> data == target) {
            Node* newNode = new Node(value);
            newNode -> next = cur -> next;
            newNode -> prev = cur;
            cur -> next -> prev = newNode;
            cur -> next = newNode;
            return; // exit whole func
        } else
            cur = cur -> next;
    }
    cout << "Value " << target << " not found." << endl;
}

// Insert a new node immediately before the first node containing the target value.
void CircularLinkedList::insertBefore(int target, int value) {
    // TODO: Find the target node and insert the new node before it.
    // If the target is not found, print: cout << "Value " << target << " not found." << endl;
    Node* cur = head -> next;
    while (cur != head) {
        if (cur -> data == target) {
            Node* newNode = new Node(value);
            newNode -> prev = cur -> prev;
            newNode -> next = cur;
            cur -> prev -> next = newNode;
            cur -> prev = newNode;
            return;
        }
        cur = cur -> next;  
    }
    cout << "Value " << target << " not found." << endl;
}

// Delete the first node containing the target value.
void CircularLinkedList::deleteNode(int value) {
    // TODO: Find the target node, delete it, reconnect the surrounding nodes, and free the memory.
    // If the value is not found, print: cout << "Value " << value << " not found." << endl;
    Node* cur = head -> next;
    while (cur != head) {
        if (cur -> data == value) {
            cur -> next -> prev = cur -> prev;
            cur -> prev -> next = cur -> next;
            delete cur;
            return;
        }
        cur = cur -> next;
    }
    cout << "Value " << value << " not found." << endl;
}

// own practice
// void CircularLinkedList::deleteAllNodes(int value) {
//     Node* cur = head->next;
//     bool found = false;

//     while (cur != head) {
//         if (cur->data == value) {
//             found = true;
//             Node* nextNode = cur->next; // 先記住下一站

//             // 接線：繞過 cur
//             cur->prev->next = cur->next;
//             cur->next->prev = cur->prev;

//             delete cur;     // 刪除目前節點
//             cur = nextNode; // 讓 cur 指向剛才記住的下一站
//         } else {
//             // 如果沒刪除，就正常往後走一步
//             cur = cur->next;
//         }
//     }

//     if (!found) {
//         cout << "Value " << value << " not found." << endl;
//     }
// }

// Print the list contents.
void CircularLinkedList::display() const {
    // TODO: Traverse the list from start to finish and print its contents in the format: "val1 -> val2 -> val3 -> HEAD"
    // Print a newline at the end. If the list is empty, just print "HEAD\n".
    Node* cur = head -> next;
    while (cur != head) {
        cout << cur -> data << " -> " ;
        cur = cur -> next;
    }
    cout << "HEAD\n";
}

// Operator Overloading: Concatenate two linked lists (Deep Copy).
CircularLinkedList CircularLinkedList::operator+(const CircularLinkedList& other) const {
    CircularLinkedList result;
    
    // TODO: Implement the logic for list_c = this + other.
    // 'result' must be a completely new list containing all elements from 'this' list followed by 'other' list.
    // Note: Do NOT modify the original structures of 'this' and 'other'.
    Node* cur = this -> head -> next;
    while (cur != this -> head) {
        result.insertAtEnd(cur -> data);
        cur = cur -> next;
    }
    cur = other.head -> next;
    while (cur != other.head) {
        result.insertAtEnd(cur -> data);
        cur = cur -> next;
    }
    return result;
}
