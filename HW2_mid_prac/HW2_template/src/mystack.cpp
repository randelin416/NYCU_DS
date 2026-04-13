#include "mystack.h"
#include <iostream>

using namespace std;


MyStack::MyStack(int capacity)
    : _capacity(capacity)
{
    _top = -1; // empty
    _arr = new char[capacity];
}


MyStack::~MyStack()
{
    delete[] _arr;
}


int MyStack::size()
{   
    // Todo: Return the number of elements in the array
    return _top + 1;
}


void MyStack::push(char ch)
{
    // Todo: Append the element to the end of the array
    if (!full()) {
        _arr[++_top] = ch;
    }
}


char MyStack::top()
{
    // Todo: Return the top element without removing it
    if (!empty()) {
        return _arr[_top];
    }
    return '\0';
}


void MyStack::pop()
{
    // Todo: Remove the top element if the stack is not empty 
    if (!empty()) {
        --_top;
    }
}


bool MyStack::full()
{
    // Todo: Check if the stack is full
    return _top == _capacity - 1;
}


bool MyStack::empty()
{
    // Todo: Check if the stack is empty
    return _top == -1;
}


string MyStack::toString()
{
    // Todo: 
    // hint: char array to std::string
    string s = "";
    for (int i = 0; i <= _top; i++) {
        s += _arr[i];
    }
    return s;
}