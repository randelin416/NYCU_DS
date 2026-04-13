#include <iostream>
#include <string>
#include "mycalculator.h"

using namespace std;


int main(int argc, char* argv[])
{
    // Todo: Finish this function

    // check if there is parameter input
    if (argc < 2) return 0;

    // argv[1]: string input
    MyCalculator calc(argv[1]);

    // output infix, postfix and evaluation
    cout << "Infix: " << calc.infix() << endl;
    cout << "Postfix: " << calc.postfix() << endl;
    cout << "Evaluate: " << calc.evaluate() << endl;
    
    return 0;
}