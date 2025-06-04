#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    bool operator!=(const point &other) const {
        return x != other.x || y != other.y;
    }
};

int INF = 1e9;
int n, m;
vector<string> grid;
vector<vector<int>> monstertime, playertime;
vector<vector<point>> parent;
queue<point> monster_queue, player_queue;
vector<point> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<char> dirchar = {'U', 'D', 'L', 'R'};
point start;

bool isvalid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#';
}

void bfsmonster() {
    while (!monster_queue.empty()) {
        point cur = monster_queue.front(); monster_queue.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cur.x + direction[d].x;
            int ny = cur.y + direction[d].y;
            if (isvalid(nx, ny) && monstertime[nx][ny] == INF) {
                monstertime[nx][ny] = 1 + monstertime[cur.x][cur.y];
                monster_queue.push({nx, ny});
            }
        }
    }
}

bool bfsplayer() {
    while (!player_queue.empty()) {
        point cur = player_queue.front(); player_queue.pop();
        int x = cur.x;
        int y = cur.y;

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            // Escape possible
            string path = "";
            point c = cur;
            while (c != start) {
                point p = parent[c.x][c.y];
                for (int d = 0; d < 4; d++) {
                    if (p.x + direction[d].x == c.x && p.y + direction[d].y == c.y) {
                        path += dirchar[d];
                        break;
                    }
                }
                c = p;
            }
            reverse(path.begin(), path.end());
            cout << "YES\n";
            cout << path.length() << "\n";
            cout << path << "\n";
            return true;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + direction[d].x;
            int ny = y + direction[d].y;
            if (isvalid(nx, ny) && playertime[nx][ny] == INF) {
                if (playertime[x][y] + 1 < monstertime[nx][ny]) {
                    playertime[nx][ny] = playertime[x][y] + 1;
                    parent[nx][ny] = {x, y};
                    player_queue.push({nx, ny});
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    monstertime.assign(n, vector<int>(m, INF));
    playertime.assign(n, vector<int>(m, INF));
    parent.assign(n, vector<point>(m, {-1, -1}));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                monster_queue.push({i, j});
                monstertime[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                player_queue.push({i, j});
                playertime[i][j] = 0;
                start = {i, j};
            }
        }
    }

    bfsmonster();
    if (!bfsplayer()) {
        cout << "NO\n";
    }

    return 0;
}