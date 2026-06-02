#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canWin(int n, vector<int>& moves) {
    vector<bool> dp(n + 1, false);

    // dp[0] = false
    // 沒有石頭可拿，輪到的人輸

    for (int stones = 1; stones <= n; stones++) {
        for (int move : moves) {
            if (stones >= move && dp[stones - move] == false) {
                dp[stones] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int m;
        cin >> m;

        vector<int> moves(m);

        for (int i = 0; i < m; i++) {
            cin >> moves[i];
        }

        if (canWin(n, moves)) {
            cout << "Win" << endl;
        } else {
            cout << "Loss" << endl;
        }
    }

    return 0;
}