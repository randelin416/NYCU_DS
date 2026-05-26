#include "list.h"
#include <sstream>
#include <string>

Node::Node() : _next(nullptr) {}

Node::~Node() {}

List::List() : _head(nullptr) {}

List::~List() {}

std::string Node::toString()
{
    std::stringstream ss; ss << "Node address: " << this;
    return ss.str();
}

void List::insert(Node* node)
{
    // dummy
    node->setNext(_head);
    _head = node;
}

void List::remove(Node* node)
{
    if (!_head) return;

    if (_head == node) {
        _head = _head->next();
        delete node;
        return;
    }

    Node* prev = _head;
    Node* curr = _head->next();

    while (curr) {
        if (curr == node) {
            prev->setNext(curr->next());
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next();
    }
}


/**
 * TODO: complete this file
 *  - You CANNOT modify list.h.
 */
