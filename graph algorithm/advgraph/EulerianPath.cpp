// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, m;
vector<vector<int>> adj;
vector<int> path;
vector<bool> visited;

void dfs(int u) {
    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
        // Remove v → u (undirected edge)
        auto it = find(adj[v].begin(), adj[v].end(), u);
        if (it != adj[v].end()) adj[v].erase(it);
        dfs(v);
    }
    path.pb(u);
}

void dfs2(int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v])
            dfs2(v);
    }
}

void solve() {
    cin >> n >> m;
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);
    vector<pair<int, int>> originalEdges; // for edge count

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        originalEdges.pb({a, b});
    }

    // Check if the graph is connected (excluding isolated vertices)
    int startNode = 1;
    while (startNode <= n && adj[startNode].empty()) startNode++;

    if (startNode > n) {
        cout << "Graph has no edges.\n";
        return;
    }

    dfs2(startNode);
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && !adj[i].empty()) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    int oddcount = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2 != 0) {
            oddcount++;
            startNode = i; // use odd-degree node as start
        }
    }

    if (oddcount != 0 && oddcount != 2) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    dfs(startNode);
    reverse(all(path));

    if ((int)path.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    if (oddcount == 0) cout << "eulerian cycle" << endl;
    else cout << "eulerian path" << endl;

    for (int v : path) cout << v << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
