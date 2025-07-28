#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<pair<int, int>> bridges;
int timer = 0;
int tin[N], low[N];
bool visited[N];

void dfs(int u, int parent) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;

    for (int v : adj[u]) {
        if (v == parent) continue;
        if (visited[v]) {
            // back edge
            low[u] = min(low[u], tin[v]);
        } else {
            // tree edge
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                bridges.push_back({min(u, v), max(u, v)});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.emplace_back(a, b);
    }

    // Run DFS from every component (though the graph is connected in this problem)
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs(i, -1);
    }

    cout << bridges.size() << "\n";
    for (auto& bridge : bridges) {
        cout << bridge.first << " " << bridge.second << "\n";
    }

    return 0;
}
