#include "mycalculator.h"
#include "mystack.h"
#include <iostream>

MyCalculator::MyCalculator(const string& infix) : _infix(infix) {
    _postfix = toPostfix();
}

string MyCalculator::infix() {
    string cleanInfix = "";
    // remove spaces
    for (char c : _infix) if (c != ' ') cleanInfix += c;
    return cleanInfix;
}

string MyCalculator::postfix() {
    return _postfix;
}

string MyCalculator::toPostfix() {
    string res = "";
    string cleanInfix = infix();
    MyStack s(100);

    // infix to postfix
    for (char c : cleanInfix) {
        if (c >= '0' && c <= '9') {
            res += c;
        } else {
            int currP = (c == '*') ? 2 : 1;
            // pop operators
            while (!s.empty()) {
                int topP = (s.top() == '*') ? 2 : 1;
                if (topP >= currP) {
                    res += s.top();
                    s.pop();
                } else break;
            }
            s.push(c);
        }
    }
    while (!s.empty()) { res += s.top(); s.pop(); } // pop remaining operators
    return res;
}

int MyCalculator::evaluate() {
    MyStack s(100);
    // postfix evaluation
    for (char c : _postfix) {
        // evaluate the expression
        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if (c == '+') s.push(a + b);
            else if (c == '-') s.push(a - b);
            else if (c == '*') s.push(a * b);
        }
    }
    return s.top();
}