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
        Node<T>* curr = _head;
        while (curr) {
            Node<T>* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    // TODO: Implement push_back
    void push_back(T value) {
        Node<T>* node = new Node<T>(value);

        if (!_head) {
            _head = node;
            _tail = node;
        } else {
            _tail->next = node;
            _tail = node;
        }

        _size++;
    }

    // TODO: Implement operator[]
    T& operator[](int index) {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index out of range");
        }

        Node<T>* curr = _head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->data;
    }

    int size() const { return _size; }

private:
    Node<T>* _head;
    Node<T>* _tail;
    int _size;
};

#endif