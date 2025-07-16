#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
int n, m;
vector<vector<pair<int, int>>> adj;
vector<long long> dist;

void find_negative_cycle(vector<int>& parent, int start) {
    int x = start;
    for (int i = 0; i < n; i++) {
        x = parent[x];  // Move `n` times to ensure we are inside the cycle
    }

    vector<int> cycle;
    for (int v = x;; v = parent[v]) {
        cycle.push_back(v);
        if (v == x && cycle.size() > 1)
            break;
    }
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int v : cycle)
        cout << v << " ";
    cout << endl;
}

bool bellman_ford(int source, vector<int>& parent) {
    dist[source] = 0;
    int x = -1;

    for (int i = 1; i <= n; i++) {
        x = -1;
        for (int u = 1; u <= n; u++) {
            for (auto [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    x = v;  // Track last updated node
                }
            }
        }
    }

    if (x != -1) {
        find_negative_cycle(parent, x);
        return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    dist.resize(n + 1, 0);  // Initialize dist with 0 for all nodes
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> parent(n + 1, -1);
    
    // Run Bellman-Ford from each unvisited node to check all components
    if (!bellman_ford(1, parent)) {
        cout << "NO\n";
    }

    return 0;
}