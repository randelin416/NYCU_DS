#ifndef __TEMPLATE_VECTOR_H__
#define __TEMPLATE_VECTOR_H__

#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T v) : data(v), next(nullptr) {}
};

template <typename T>
class MyVector {
public:
    MyVector() : _head(nullptr), _tail(nullptr), _size(0) {}
    
    // TODO: Implement destructor to clean up memory
    ~MyVector() {
        
    }

    // TODO: Implement push_back
    void push_back(T value) {
        
    }

    // TODO: Implement operator[]
    T& operator[](int index) {
        
    }

    int size() const { return _size; }

private:
    Node<T>* _head;
    Node<T>* _tail;
    int _size;
};

#endif