#include "mycalculator.h"
#include <iostream>

using namespace std;


void _testInfix(const string& origin, const string& expect)
{
    MyCalculator c(origin);
    if (c.infix() == expect) cout << "Infix Test Passed" << endl;
    else cout << "Infix Test Failed - output: " << c.infix() << ", expect: " << expect << endl;
}

void testInfix()
{
    _testInfix("(1 +2) * 3 ", "(1+2)*3");
    _testInfix("   (1 +2) * 3 + (9 + 8) ", "(1+2)*3+(9+8)");
    _testInfix("  5 * ( 9 - 8 ) * 9 ", "5*(9-8)*9");
}


void _testPostfix(const string& origin, const string& expect)
{
    MyCalculator c(origin);
    if (c.toPostfix() == expect) cout << "Postfix Test Passed" << endl;
    else cout << "Postfix Test Failed - output: " << c.postfix() << ", expect: " << expect << endl;
}

void testPostfix()
{
    _testPostfix("(1 +2) * 3 ", "12+3*");
    _testPostfix("3+2*2", "322*+");
    _testPostfix("   (1 +2) * 3 + (9 + 8) ", "12+3*98++");
    _testPostfix("  5 * (9 - 8) * 9 ", "598-*9*");
}


void _testEvaluate(const string& origin, int expect)
{
    MyCalculator c(origin);
    c.toPostfix();
    int result = c.evaluate();
    if (result == expect) cout << "Evaluate Test Passed" << endl;
    else cout << "Evaluate Test Failed - output: " << result << ", expect: " << expect << endl;
}

void testEvaluate()
{
    _testEvaluate("(1 +2) * 3 ", 9);
    _testEvaluate("3+2*2", 7);
    _testEvaluate("   (1 +2) * 3 + (9 + 8) ", 26);
    _testEvaluate("  5 * (9 - 8) * (0 - 9) ", -45);
    _testEvaluate("4 * (4 + 8) * 2 ", 96);
}


int main()
{
    testInfix();
    testPostfix();
    testEvaluate();
}