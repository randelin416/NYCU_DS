#include <iostream>
#include <sstream>
#include "mystack.h"

using namespace std;


void testPush() 
{
    MyStack s(5);
    s.push('A');
    if (s.top() == 'A') cout << "Push Test Passed" << endl;
    else cout << "Push Test Failed - s.top(): \'" << s.top() << "\'" << endl;

    s.push('B');
    if (s.top() == 'B') cout << "Push Test Passed" << endl;
    else cout << "Push Test Failed - s.top(): \'" << s.top() << "\'" << endl;
}


void testPop() 
{
    MyStack s(5);
    s.push('X');
    s.push('Y');
    
    s.pop();
    if (s.top() == 'X') cout << "Pop Test Passed" << endl;
    else cout << "Pop Test Failed - s.top(): \'" << s.top() << "\'" << endl;
    s.pop();
    if (s.top() == '\0') cout << "Pop Test Passed" << endl;
    else cout << "Pop Test Failed - s.top(): \'" << s.top() << "\'" << endl;
}


void testPeek() 
{
    MyStack s(5);
    if (s.top() == '\0') cout << "Peek Test Passed" << endl;
    else cout << "Peek Test Failed - s.top(): \'" << s.top() << "\'" << endl;
    s.push('Z');
    if (s.top() == 'Z') cout << "Peek Test Passed" << endl;
    else cout << "Peek Test Failed - s.top(): \'" << s.top() << "\'" << endl;

    s.pop();
    if (s.top() == '\0') cout << "Peek Test Passed" << endl;
    else cout << "Peek Test Failed - s.top(): \'" << s.top() << "\'" << endl;
}


void testEmpty() 
{
    MyStack s(5);
    if (s.empty()) cout << "Empty Test Passed" << endl;
    else cout << "Empty Test Failed" << endl;

    s.push('M');
    if (!s.empty()) cout << "Empty Test Passed" << endl;
    else cout << "Empty Test Failed" << endl;

    s.pop();
    if (s.empty()) cout << "Empty Test Passed" << endl;
    else cout << "Empty Test Failed" << endl;
}


void testFull()
{
    MyStack s1(5);
    for (int i = 0; i < 5; ++i) { s1.push(i + 'a'); }
    if (s1.full()) cout << "Full Test Passed" << endl;
    else cout << "Full Test Failed" << endl;

    MyStack s2(10);
    for (int i = 0; i < 5; ++i) { s2.push(i + 'a'); }
    if (!s2.full()) cout << "Full Test Passed" << endl;
    else cout << "Full Test Failed" << endl;
}


void testSize() 
{
    MyStack s1(5);
    for (int i = 0; i < 5; ++i) s1.push(i + 'a');
    if (s1.size() == 5) cout << "Size Test Passed" << endl;
    else cout << "Size Test Failed - s1.size(): " << s1.size() << endl;
    for (int i = 0; i < 5; ++i) s1.pop();
    if (s1.size() == 0) cout << "Size Test Passed" << endl;
    else cout << "Size Test Failed - s1.size(): " << s1.size() << endl;

    MyStack s2(13);
    for (int i = 0; i < 10; ++i) s2.push(i + 'a');
    if (s2.size() == 10) cout << "Size Test Passed" << endl;
    else cout << "Size Test Failed - s2.size(): " << s2.size() << endl;
    for (int i = 0; i < 5; ++i) s2.pop();
    if (s2.size() == 5) cout << "Size Test Passed" << endl;
    else cout << "Size Test Failed - s2.size(): " << s2.size() << endl;
}


void testCapacity() 
{
    MyStack s1(5);
    for (int i = 0; i < 10; ++i) { s1.push(i + 'a'); }
    if (s1.size() == 5) cout << "Capacity Test Passed" << endl;
    else cout << "Capacity Test Failed - s1.size(): " << s1.size() << endl;

    MyStack s2(3);
    for (int i = 0; i < 10; ++i) s2.push(i + 'a');
    if (s2.size() == 3) cout << "Capacity Test Passed" << endl;
    else cout << "Capacity Test Failed - s2.size(): " << s2.size() << endl;
}


void testPrint() 
{
    MyStack s1(10);
    for (int i = 0; i < 10; ++i) s1.push(i + 'a');

    if (s1.toString() == "abcdefghij") cout << "Print Test Passed" << endl;
    else cout << "Print Test Failed, s1.toString(): " << s1.toString() << endl;

    MyStack s2(5);
    for (int i = 0; i < 3; ++i) s2.push(i + 'X');

    if (s2.toString() == "XYZ") cout << "Print Test Passed" << endl;
    else cout << "Print Test Failed s2.toString(): " << s2.toString() << endl;
}


int main() 
{
    testPush();
    testPop();
    testPeek();
    testEmpty();
    testFull();
    testSize();
    testCapacity();
    testPrint();
    return 0;
}
