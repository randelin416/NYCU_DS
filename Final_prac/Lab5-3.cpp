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

        vector<int> h(n);

        for (int i=0; i<n; i++) {
            cin >> h[i];
        }

        vector<int> dp(n, 1);
        int ans = 1;

        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (h[i]>h[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}