#ifndef __LIST_H__
#define __LIST_H__

#include <string>

struct Node 
{
    Node* next;
    Node() : next(nullptr) {}
};


class List 
{
protected:
    Node* _head;

public:
    List(): _head(nullptr) {}
    virtual ~List();
    
    virtual void insert(Node* node);

    Node* head();
    bool empty();
    void remove(Node* node);
};


#endif