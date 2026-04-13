#include <iostream>
#include <string>

using namespace std;

int romanToNum(char c) {
    switch(c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && romanToNum(s[i]) < romanToNum(s[i+1])) {
                num -= romanToNum(s[i]);
            } else {
                num += romanToNum(s[i]);
            }
        }
        cout << num << endl;
    } 
}