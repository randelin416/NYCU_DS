#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // sort
    sort(a.begin(), a.end());

    // build queue
    queue<int> q;
    for(int i = 0; i < n; i++) {
        q.push(i);
    }

    vector<int> res(n);
    for(int i = 0; i < n; i++) {
        res[q.front()] = a[i];
        q.pop();
        if(!q.empty()) {
            q.push(q.front());
            q.pop();
        }
    }

    for(int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        solve();
    }
}