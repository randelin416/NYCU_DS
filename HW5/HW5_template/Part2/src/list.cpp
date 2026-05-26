#include "list.h"
#include <sstream>

// my code
// Check if list is empty
bool List::empty()
{
    return _head == nullptr;
}

// Return the pointer to the head node
Node* List::head()
{
    return _head;
}

List::~List()
{
    // Todo: clear the list. 
    // Please release the memory properly.
    Node* curr = _head;
    while (curr)
    {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    _head = nullptr;
}

void List::remove(Node* node)
{
    // Todo: Find the corresponding position in the list and remove it.
    if (!_head) return;

    if (_head == node)
    {
        Node* tmp = _head;
        _head = _head->next;
        delete tmp;
        return;
    }

    Node* prev = _head;
    Node* curr = _head->next;

    while (curr)
    {
        if (curr == node)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void List::insert(Node* node)
{
    // dummy
    node->next = _head;
    _head = node;
}

// std::string Node::toString()
// {
//     std::stringstream ss; ss << "Node address: " << this;
//     return ss.str();
// }