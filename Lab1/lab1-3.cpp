#include <iostream>
#include <string>

using namespace std;

string decode(string s, int &pos) { // pos用傳址
    string res = "";
    // s[pos] is a number
    while (pos < s.length()) {
        // count number k
        if (isdigit(s[pos])) {
            int k = 0;
            while (pos < s.length() && isdigit(s[pos])) {
                k = k * 10 + (s[pos] - '0');
                pos++;
            }
            // pass '['
            pos++;
            // recurse to deal with [input]
            string input = decode(s, pos);
            // get res of []
            while (k--)
                res += input;
        } else if (s[pos] == ']') { // meet ] return
            pos++;
            return res;
        } else { // meet char which means print ine time
            res += s[pos];
            pos++;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int pos = 0;
        cout << decode(s, pos) << endl;
    }
}