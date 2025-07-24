#include <bits/stdc++.h>
using namespace std;

const int N = 2505;
vector<int> adj[2 * N];
unordered_map<int, vector<int>> memo; // memo[u] = dist from (u,0)

vector<int> bfs(int src, int n) {
    vector<int> dist(2 * n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v + n);
        adj[v].push_back(u + n);
        adj[u + n].push_back(v);
        adj[v + n].push_back(u);
    }

    while (q--) {
        int u, v;
        long long x;
        cin >> u >> v >> x;
        --u; --v;

        if (!memo.count(u)) {
            memo[u] = bfs(u, n);
        }

        int to = v + n * (x % 2);
        if (memo[u][to] != -1 && memo[u][to] <= x)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
