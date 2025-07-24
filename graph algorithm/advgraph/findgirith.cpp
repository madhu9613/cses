#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 2505;

vector<int> adj[N];
int dist[N], par[N];

int find_girth(int n) {
    int girth = INF;

    for (int start = 1; start <= n; ++start) {
        fill(dist, dist + n + 1, INF);
        queue<int> q;
        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    par[v] = u;
                    q.push(v);
                } else if (par[u] != v) {
                    // Found a cycle
                    girth = min(girth, dist[u] + dist[v] + 1);
                }
            }
        }
    }

    return (girth == INF ? -1 : girth);
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << find_girth(n) << endl;

    return 0;
}
