#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    // Step 1: Push all 0s into the queue and initialize distances
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    // Step 2: BFS directions (Up, Down, Left, Right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Step 3: Process the queue
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    return dist;
}
