#ifndef MYSTACK_H
#define MYSTACK_H

#include <string>

class MyStack 
{
public:
    MyStack(int capacity = 10);
    ~MyStack();

    int size();
    void push(char ch);
    char top();
    void pop();
    bool full();
    bool empty();
    std::string toString();

private:
    char *_arr;
    int _capacity;
    // Todo: any necessary variables
    int _top;
};


#endif