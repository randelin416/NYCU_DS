#include <iostream>
#include <string>
using namespace std;

int romanCharToInt(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}

int romanToInt(const string& s) {
    int total = 0;
    for (int i = 0; i < s.size(); i++) {
        int value = romanCharToInt(s[i]);
        if (i + 1 < s.size() && romanCharToInt(s[i]) < romanCharToInt(s[i + 1])) {
            total -= value;
        } else {
            total += value;
        }
    }
    return total;
}

int main() {
    int T;
    cin >> T;
    string s;
    for (int i = 0; i < T; i++) {
        cin >> s;
        cout << romanToInt(s) << endl;
    }
    return 0;
}

