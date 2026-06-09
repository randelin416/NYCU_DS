#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        vector<int> last(26, 0);

        for (int i=0; i<s.size(); i++) {
            last[s[i]-'a'] = i;
        }

        int start = 0;
        int end = 0;

        for (int i=0; i<s.size(); i++) {
            end = max(end, last[s[i]-'a']);
            if  (end == i) {
                cout << end-start+1 << " ";
                start = i + 1;
            }
        }
        cout << endl;
    }
    return 0;
}