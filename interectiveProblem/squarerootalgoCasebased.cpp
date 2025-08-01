// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

int n, m;
vector<string> grid;

void solve() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    unordered_map<char, vector<pii>> positions;
    int total_cells = n * m;

    // Collect all positions for each letter
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            positions[grid[i][j]].pb({i, j});

    int sqrt_n = sqrt(total_cells);
    int ans = INF;

    for (auto &[ch, pos] : positions) {
        int k = pos.size();

        if (k <= sqrt_n) {
            // Algorithm 1: Brute-force check all pairs
            for (int i = 0; i < k; ++i) {
                for (int j = i + 1; j < k; ++j) {
                    int dist = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
                    ans = min(ans, dist);
                }
            }
        } else {
            // Algorithm 2: Multi-source BFS
            vector<vector<int>> dist(n, vector<int>(m, INF));
            queue<pii> q;

            // Add all same-letter positions as starting points
            for (auto &[x, y] : pos) {
                dist[x][y] = 0;
                q.push({x, y});
            }

            vector<pii> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (auto &[dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if (dist[nx][ny] > dist[x][y] + 1) {
                            dist[nx][ny] = dist[x][y] + 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }

            for (auto &[x, y] : pos) {
                for (auto &[dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == ch) {
                        ans = min(ans, dist[nx][ny] + dist[x][y]);
                    }
                }
            }
        }
    }

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}
