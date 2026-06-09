#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int main() {
    int T;
    cin >> T;

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while(T--) {
        int r, c;
        cin >> r >> c;

        vector<string> board(c);

        for (int i=0; i<c; i++) {
            cin >> board[i];
        }

        queue<pair<int, int>> q;

        // add function
        auto add = [&](int m, int n) {
            if (m<0 || m>=r || n<0 || n>=c) return;
            if (board[m][n] != 'O') return;

            board[m][n] = '#';
            q.push({m, n});
        };

        // check bound 'O'
        for (int i=0; i<r; i++) {
            add(i, 0);
            add(i, c-1);
        }
        for (int j=0; j<c; j++) {
            add(0, j);
            add(r-1, j);
        }
        
        // BFS
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int m = cur.first;
            int n = cur.second;

            for (int k=0; k<4; k++) {
                add(m+dr[k], n+dc[k]);
            }
        }

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }

        // print output
        for (int i=0; i<r; i++) {
            cout << board[i] << "\n";
        }
    }
}