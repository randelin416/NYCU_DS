#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> partitionSignal(string s) {
    vector<int> last(26, 0);

    // 記錄每個字母最後一次出現的位置
    for (int i = 0; i < s.length(); i++) {
        last[s[i] - 'a'] = i;
    }

    vector<int> ans;
    int start = 0;
    int end = 0;

    // 掃描字串並決定切割點
    for (int i = 0; i < s.length(); i++) {
        end = max(end, last[s[i] - 'a']);

        if (i == end) {
            ans.push_back(end - start + 1);
            start = i + 1;
        }
    }

    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        vector<int> result = partitionSignal(s);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i != result.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}