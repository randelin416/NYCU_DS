#include <iostream>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <vector>
using namespace std;

double findMedian(int* nums1, int m, int* nums2, int n) {
    if (m > n) return findMedian(nums2, n, nums1, m);
    int low = 0, high = m;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = (m + n + 1)/2 - i;

        int A_left = (i == 0) ? INT_MIN : nums1[i-1];
        int A_right = (i == m) ? INT_MAX : nums1[i];
        int B_left = (j == 0) ? INT_MIN : nums2[j-1];
        int B_right = (j == n) ? INT_MAX : nums2[j];

        if (A_left <= B_right && B_left <= A_right) {
            if ((m + n) % 2 == 1) return max(A_left, B_left);
            else return (max(A_left, B_left) + min(A_right, B_right)) / 2.0;
        } else if (A_left > B_right) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }
    return 0.0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m;
        vector<int> nums1(m);
        for (int i = 0; i < m; i++) cin >> nums1[i];
        cin >> n;
        vector<int> nums2(n);
        for (int i = 0; i < n; i++) cin >> nums2[i];

        double median = findMedian(nums1.data(), m, nums2.data(), n);
        cout << fixed << setprecision(1) << median << "\n";
    }
    return 0;
}