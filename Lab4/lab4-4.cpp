#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < m; i++) {
            int t, d;
            cin >> t >> d;

            // d must be visited before t
            graph[d].push_back(t);
            indegree[t]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited++;

            for (int next : graph[cur]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (visited == n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}