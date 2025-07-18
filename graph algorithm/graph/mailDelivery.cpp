#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<multiset<int>> adj;
vector<int> path;

void dfs(int u) {
    while (!adj[u].empty()) {
        int v = *adj[u].begin();
        adj[u].erase(adj[u].begin());
        adj[v].erase(adj[v].find(u)); // erase the reverse edge
        dfs(v);
    }
    path.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
        degree[a]++;
        degree[b]++;
    }

    // Check all vertices have even degree
    for (int i = 1; i <= n; ++i) {
        if (degree[i] % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    // Check connectivity (only over nodes with non-zero degree)
    vector<bool> visited(n + 1, false);
    function<void(int)> mark = [&](int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) mark(v);
        }
    };

    mark(1);

    for (int i = 1; i <= n; ++i) {
        if (degree[i] > 0 && !visited[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    dfs(1);

    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        reverse(path.begin(), path.end());
        for (int v : path) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
