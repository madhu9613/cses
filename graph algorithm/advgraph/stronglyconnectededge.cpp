#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int,int>> adj[N];
vector<pair<int,int>> res;
bool visited[N];
int tin[N], low[N], timer;
map<pair<int,int>, bool> used;

bool dfs(int u, int parent) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;

    for (auto [v, id] : adj[u]) {
        if (v == parent) continue;

        if (visited[v]) {
            // Back edge
            low[u] = min(low[u], tin[v]);

            if (!used[{u, v}] && !used[{v, u}]) {
                res.push_back({u, v});
                used[{u, v}] = true;
            }
        } else {
            // Tree edge
            if (!used[{u, v}] && !used[{v, u}]) {
                res.push_back({u, v});
                used[{u, v}] = true;
            }

            if (!dfs(v, u)) return false;
            low[u] = min(low[u], low[v]);

            // Check bridge
            if (low[v] > tin[u]) {
                // (u,v) is a bridge
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }

    if (!dfs(1, -1)) {
        cout << "0\n";
        return 0;
    }

    // Check if disconnected
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "0\n";
            return 0;
        }
    }

    for (auto [u, v] : res)
        cout << u << " " << v << "\n";
}
