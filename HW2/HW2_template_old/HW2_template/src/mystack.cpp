#include "mystack.h"
#include <iostream>

using namespace std;


MyStack::MyStack(int capacity)
    : _capacity(capacity)
{
    _arr = new char[capacity];
}


MyStack::~MyStack()
{
    delete[] _arr;
}


int MyStack::size()
{   
    // Todo: Return the number of elements in the array
}


void MyStack::push(char ch)
{
    // Todo: Append the element to the end of the array
}


char MyStack::top()
{
    // Todo: Return the top element without removing it
}


void MyStack::pop()
{
    // Todo: Remove the top element if the stack is not empty 
}


bool MyStack::full()
{
    // Todo: Check if the stack is full
}


bool MyStack::empty()
{
    // Todo: Check if the stack is empty
}


string MyStack::toString()
{
    // Todo: 
    // hint: char array to std::string
}