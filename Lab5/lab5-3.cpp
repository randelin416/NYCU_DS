#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestIncreasingSubsequence(vector<int>& heights) {
    int n = heights.size();

    vector<int> dp(n, 1);

    int answer = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (heights[j] < heights[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        answer = max(answer, dp[i]);
    }

    return answer;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> heights(n);

        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        cout << longestIncreasingSubsequence(heights) << endl;
    }

    return 0;
}