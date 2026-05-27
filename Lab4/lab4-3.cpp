#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        string board[500];

        for (int i = 0; i < n; i++) {
            cin >> board[i];
        }

        queue<pair<int, int>> q;

        // Put boundary O cells into queue
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = '#';
                q.push({i, 0});
            }

            if (board[i][m - 1] == 'O') {
                board[i][m - 1] = '#';
                q.push({i, m - 1});
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                board[0][j] = '#';
                q.push({0, j});
            }

            if (board[n - 1][j] == 'O') {
                board[n - 1][j] = '#';
                q.push({n - 1, j});
            }
        }

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        // BFS from boundary O cells
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int r = cur.first;
            int c = cur.second;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                if (board[nr][nc] == 'O') {
                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }

        // Final conversion
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << board[i] << '\n';
        }
    }

    return 0;
}