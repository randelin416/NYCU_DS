#include <iostream>
#include <string>
#include <limits>

using namespace std;

// recursive function for decoding
string decodeString(const string& s, int& i) {
    string result;
    int n = s.size();
    
    while (i < n) {
        if (isdigit(s[i])) { 
            // read number k
            int k = 0;
            while (i < n && isdigit(s[i])) {
                k = k * 10 + (s[i] - '0');
                i++;
            }
            i++;
            string decoded = decodeString(s, i);
            i++;
            for (int j = 0; j < k; j++) result += decoded;
        } 
        else if (s[i] == ']') { // return when seeing ']'
            return result;
        }
        else { // char
            result += s[i];
            i++;
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int t = 0; t < T; t++) {
        string s;
        getline(cin, s);
        int idx = 0;
        cout << decodeString(s, idx) << endl;
    }
    return 0;
}