#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canFinish(const vector<long long>& cores, long long h, long long r) {
    long long hours = 0;

    for (long long energy : cores) {
        hours += (energy + r - 1) / r;

        if (hours > h) {
            return false;
        }
    }

    return hours <= h;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        long long h;
        cin >> n >> h;

        vector<long long> cores(n);
        long long maxEnergy = 0;

        for (int i = 0; i < n; i++) {
            cin >> cores[i];
            maxEnergy = max(maxEnergy, cores[i]);
        }

        long long left = 1;
        long long right = maxEnergy;
        long long answer = maxEnergy;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (canFinish(cores, h, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}