// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

int n, m;
vector<vector<int>> adj;
vector<pair<int, int>> res; // To store directed edges
vector<bool> visited;
map<pair<int, int>, bool> used; // To prevent reusing the same edge
int timer = 1;
vector<int> tin, low;

bool dfs(int u, int p = -1) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;

    for (auto v : adj[u]) {
        if (v == p)
            continue;

        if (visited[v]) {
            // Update low-link value
            low[u] = min(low[u], tin[v]);

            // Add edge only if not already used in either direction
            if (!used[{u, v}] && !used[{v, u}]) {
                res.pb({u, v});
                used[{u, v}] = true;
            }
        } else {
            if (!used[{u, v}] && !used[{v, u}]) {
                res.pb({u, v});
                used[{u, v}] = true;
            }

            if (!dfs(v, u))
                return false;

            low[u] = min(low[u], low[v]);

            // Check for bridge
            if (low[v] > tin[u]) {
                return false; // Found a bridge
            }
        }
    }

    return true;
}

void solve() {
    cin >> n >> m;

    // Resize and initialize global containers
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);
    tin.assign(n + 1, 0);
    low.assign(n + 1, 0);
    res.clear();
    used.clear();
    timer = 0;

    // Read the undirected edges
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    // Start DFS from node 1
    if (!dfs(1)) {
        cout << "IMPOSSIBLE" << endl; 
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    for (auto &[u, v] : res) {
        cout << u << " " << v << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
