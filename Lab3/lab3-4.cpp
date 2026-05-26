#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int maximumGap(vector<int>& nums) {
    int n = nums.size();

    if (n < 2) return 0;

    int minVal = nums[0];
    int maxVal = nums[0];

    for (int x : nums) {
        minVal = min(minVal, x);
        maxVal = max(maxVal, x);
    }

    if (minVal == maxVal) return 0;

    int bucketSize = max(1, (maxVal - minVal) / (n - 1));
    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    vector<int> bucketMin(bucketCount, INT_MAX);
    vector<int> bucketMax(bucketCount, INT_MIN);
    vector<bool> used(bucketCount, false);

    for (int x : nums) {
        int idx = (x - minVal) / bucketSize;

        bucketMin[idx] = min(bucketMin[idx], x);
        bucketMax[idx] = max(bucketMax[idx], x);
        used[idx] = true;
    }

    int answer = 0;
    int prevMax = minVal;

    for (int i = 0; i < bucketCount; i++) {
        if (!used[i]) continue;

        answer = max(answer, bucketMin[i] - prevMax);
        prevMax = bucketMax[i];
    }

    return answer;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> distances(n);

        for (int i = 0; i < n; i++) {
            cin >> distances[i];
        }

        cout << maximumGap(distances) << '\n';
    }

    return 0;
}