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


    }

    int size() { return _size; }

    void push_back(T value)
    {
        auto p = new MyNode<T>(value);

    }

    T front()
    {
        if (???) throw std::runtime_error("this vector is empty!"); 
        


    }
    
    T back()
    {


    }
    
    void pop_front()
    {


    }

    void pop_back()
    {

    }

    T& operator[] (int index)
    {
        if (???) throw std::out_of_range("The index is out of range!"); 


    }

    void remove(T value)
    {
        // Note: if there is no data matched, do nothing. 

    }


    void insert(int index, T value) 
    {
        if (???) throw std::out_of_range("The index is out of range!"); 
        
        auto p = new MyNode<T>(value);


    }


private:
    /**
     * Note: You CANNOT add more data member of this class 
     */
    int _size;
};



#endif