#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1}; // right, left, down, up
char dirchar[] = {'D', 'U', 'R', 'L'};

// Using map instead of unordered_map for pair keys
map<pair<int, int>, pair<int, int>> parent;
map<pair<int, int>, bool> visited;

void bfs(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    int x = start.first, y = start.second;
    q.push({x, y});

    visited[{x, y}] = true;
    parent[start] = {-1, -1};

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (x == end.first && y == end.second) break; // Stop if we reach 'B'

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !visited[{nx, ny}]) {
                parent[{nx, ny}] = {x, y};
                visited[{nx, ny}] = true;
                q.push({nx, ny});
            }
        }
    }

    if (!visited[end]) {
        cout << "NO" << endl;
        return;
    }

    // Backtrack to find the path
    string path;
    pair<int, int> cur = end;
    while (cur != start) {
        pair<int, int> prev = parent[cur];
        for (int d = 0; d < 4; d++) {
            if (prev.first + dx[d] == cur.first && prev.second + dy[d] == cur.second) {
                path += dirchar[d];
                break;
            }
        }
        cur = prev;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.length() << "\n";
    cout << path << "\n";
}

int main() {
    cin >> n >> m;
    pair<int, int> start, end;
    grid.resize(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    bfs(start, end);

    return 0;
}
