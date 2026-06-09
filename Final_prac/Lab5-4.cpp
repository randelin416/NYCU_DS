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
        int n;
        cin >> n;

        int m;
        cin >> m;

        vector<int> move(m);
        for (int i=0; i<m; i++) {
            cin >> move[i];
        }

        sort(move.begin(), move.end());

        vector<int> dp(n+1, 0);

        for (int stones=0; stones<=n; stones++) {
            for (int k: move) {
                if (k > stones) break;

                if (dp[stones-k] == 0) {
                    dp[stones] = 1;
                    break;
                }
            }
        }
        if (dp[n] == 1) {
            cout << "Win\n";
        } else {
            cout << "Lose\n";
        }
        
    }
    return 0;
}