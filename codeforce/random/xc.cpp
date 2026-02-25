#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t;
    cin >> n >> m >> t;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    vector<vector<ll>> dist(n, vector<ll>(m, -1));
    queue<pair<int, int>> q;

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    // Step 1: Find all initially good cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if (grid[ni][nj] == grid[i][j]) {
                        dist[i][j] = 0;
                        q.push({ i,j });
                        break;
                    }
                }
            }
        }
    }

    // Step 2: Multi-source BFS
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({ nx,ny });
                }
            }
        }
    }

    // Step 3: Answer queries
    while (t--) {
        int i, j;
        ll p;
        cin >> i >> j >> p;
        i--; j--;

        if (dist[i][j] == -1 || p <= dist[i][j]) {
            cout << grid[i][j] << "\n";
        }
        else {
            ll diff = p - dist[i][j];
            if (diff % 2 == 1)
                cout << (grid[i][j] == '0' ? '1' : '0') << "\n";
            else
                cout << grid[i][j] << "\n";
        }
    }
}
