#ifndef MYCALCULATOR_H
#define MYCALCULATOR_H

#include <string>

using namespace std;


class MyCalculator
{
public:
    MyCalculator(const string& infix);
    string infix();
    string postfix();
    string toPostfix();
    int evaluate();

private:
    // Todo: any necessary variables
};

#endif