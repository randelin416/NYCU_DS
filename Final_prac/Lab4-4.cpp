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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (int i=0; i<m; i++) {
            int t, d;
            cin >> t >> d;

            adj[d].push_back(t);
            indegree[t]++;
        }

        queue<int> q;

        for (int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;

            for (int v: adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if(count == n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}