#ifndef __LIST_H__
#define __LIST_H__

#include <string>

class Node 
{
private:
    Node* _next;

public:
    Node();
    virtual ~Node();
    inline Node* next() { return _next; }
    inline void setNext(Node* ptr) { _next = ptr; }
    virtual std::string toString();
    virtual bool operator==(const Node& other) = 0;
    virtual bool operator!=(const Node& other) = 0;
};


class List 
{
public:
    List();
    virtual ~List();
    virtual void insert(Node* node);
    inline Node* head() { return _head; }
    inline bool empty() { return _head == nullptr; }
    void remove(Node* node);
protected:
    Node* _head;
};


#endif