#include "mycalculator.h"
#include "mystack.h"
#include <iostream>

int MyCalculator::getPriority(char c) {
    switch(c) {
        case '*':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        default:
            return 0;
    };
}

MyCalculator::MyCalculator(const string& infix)
    :_infix(infix), _postfix("")
{
    // Todo: any necessary code
    string s = "";
    for(int i = 0; i < infix.length(); i++) {
        if(infix[i] != ' ')
            s += infix[i];
    }
    _infix = s;
    toPostfix();
}


string MyCalculator::infix()
{
    // Todo: Return the infix expression
    return _infix;
}


string MyCalculator::postfix()
{
    // Todo: Return the postfix expression
    return _postfix;
}


string MyCalculator::toPostfix()
{
    // Todo: Finish this function
    string res = "";
    string infixS = infix();
    MyStack s(100);

    for (int i = 0; i < infixS.length(); i++) {
        if (isdigit(infixS[i])) {
            res += infixS[i];
        } else {
            while (!s.empty() && getPriority(infixS[i]) <= getPriority(s.top())) {
                res += s.top();
                s.pop();
            }
            s.push(infixS[i]);
        }
    }
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    _postfix = res;
    return res;
}

int MyCalculator::evaluate()
{
    // Todo: Finish this function
    MyStack s(100);
    for (char c: _postfix) {
        if(isdigit(c)) {
            s.push(c - '0'); // turn to int
        } else {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            switch (c) {
                case '*':
                    s.push(a * b);
                    break;
                case '+':
                    s.push(a + b);
                    break;
                case '-':
                    s.push(b - a);
                    break;
                default:
                    break;
            }
        }
    }
    return s.top();
}

