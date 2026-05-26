#include "mycalculator.h"
#include "mystack.h"
#include <iostream>

MyCalculator::MyCalculator(const string& infix) : _infix(infix) {
    _infix = infix;
    _postfix = toPostfix();
}

string MyCalculator::infix() {
    string res = "";
    for (char c : _infix) {
        if (c != ' ') res += c;
    }
    return res;
}

string MyCalculator::postfix() {
    return _postfix;
}

string MyCalculator::toPostfix() {
    string res = "";
    string s = infix();
    MyStack opStack(100);

    // infix to postfix
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            res += c;
        }
        else if (c == '(') {
            opStack.push(c);
        }
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                res += opStack.top();
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop(); // pop '('
        }
        else if (c == '+' || c == '-' || c == '*') {
            int currP = (c == '*') ? 2 : 1;

            while (!opStack.empty() && opStack.top() != '(') {
                char top = opStack.top();
                int topP = (top == '*') ? 2 : 1;

                if (topP >= currP) {
                    res += top;
                    opStack.pop();
                } else break;
            }
            opStack.push(c);
        }
    }
    // pop remaining operators
    while (!opStack.empty()) {
        res += opStack.top();
        opStack.pop();
    }
    return res;
}

int MyCalculator::evaluate() {
    // postfix evaluation
    int valStack[100];
    int top = -1;
    

    for (char c : _postfix) {

        // number
        if (c >= '0' && c <= '9') {
            valStack[++top] = c - '0';
        }

        // operator
        else {
            int b = valStack[top--];
            int a = valStack[top--];

            if (c == '+') valStack[++top] = a + b;
            else if (c == '-') valStack[++top] = a - b;
            else if (c == '*') valStack[++top] = a * b;
        }
    }

    return valStack[top];
}