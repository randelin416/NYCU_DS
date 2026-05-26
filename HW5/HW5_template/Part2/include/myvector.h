#ifndef __MYVECTOR__
#define __MYVECTOR__

#include "list.h"
#include <iostream>

using namespace std;


template <typename T>
struct MyNode : public Node {
    MyNode(T data) : Node(), data(data) {}
    T data;
};


template <typename T>
class MyVector : public List
{
public:

    MyVector() : List(), _size(0) {}

    ~MyVector() 
    {
        // my code
        Node* curr = _head;
        while (curr)
        {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        _head = nullptr;
        _size = 0;
    }

    int size() { return _size; }

    void push_back(T value)
    {
        auto p = new MyNode<T>(value);
        // my code
        if (!_head)
        {
            _head = p;
        }
        else
        {
            Node* curr = _head;
            while (curr->next)
                curr = curr->next;

            curr->next = p;
        }

        _size++;
    }

    T front()
    {
        if (!_head) // my code
            throw std::runtime_error("this vector is empty!"); 
        // my code
        return static_cast<MyNode<T>*>(_head)->data;

    }
    
    T back()
    {
        // my code
        if (!_head)
            throw std::runtime_error("this vector is empty!");

        Node* curr = _head;
        while (curr->next)
            curr = curr->next;

        return static_cast<MyNode<T>*>(curr)->data;

    }
    
    void pop_front()
    {
        // my code
        if (!_head) return;

        Node* tmp = _head;
        _head = _head->next;
        delete tmp;
        _size--;
    }

    void pop_back()
    {
        // my code
        if (!_head) return;

        if (!_head->next)
        {
            delete _head;
            _head = nullptr;
            _size--;
            return;
        }

        Node* prev = nullptr;
        Node* curr = _head;

        while (curr->next)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;
        delete curr;
        _size--;
    }

    T& operator[] (int index)
    {
        if (index < 0 || index >= _size) // my code
            throw std::out_of_range("The index is out of range!"); 
        // my code
        Node* curr = _head;
        for (int i = 0; i < index; i++)
            curr = curr->next;

        return static_cast<MyNode<T>*>(curr)->data;
    }

    void remove(T value)
    {
        // Note: if there is no data matched, do nothing. 
        if (!_head) return;

        if (static_cast<MyNode<T>*>(_head)->data == value)
        {
            Node* tmp = _head;
            _head = _head->next;
            delete tmp;
            _size--;
            return;
        }

        Node* prev = _head;
        Node* curr = _head->next;

        while (curr)
        {
            if (static_cast<MyNode<T>*>(curr)->data == value)
            {
                prev->next = curr->next;
                delete curr;
                _size--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }


    void insert(int index, T value) 
    {
        if (index < 0 || index > _size) // my code
            throw std::out_of_range("The index is out of range!"); 
        
        auto p = new MyNode<T>(value);
        // my code
        if (index == 0)
        {
            p->next = _head;
            _head = p;
            _size++;
            return;
        }

        Node* curr = _head;
        for (int i = 0; i < index - 1; i++)
            curr = curr->next;

        p->next = curr->next;
        curr->next = p;
        _size++;
    }


private:
    /**
     * Note: You CANNOT add more data member of this class 
     */
    int _size;
};



#endif