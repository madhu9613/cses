#include <bits/stdc++.h>
#define INF 1e18
#define int long long
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj; // adj[node] = {weight, neighbor}
vector<int> dist;

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // {distance, node}
    dist[1] = 0;

    while (!pq.empty()) {
        auto [nodedist, node] = pq.top();
        pq.pop();

        if (nodedist > dist[node]) continue;

        for (auto &[weight, neigh] : adj[node]) {
            if (dist[node] + weight < dist[neigh]) {
                dist[neigh] = dist[node] + weight;
                pq.push({dist[neigh], neigh});
            }
        }
    }

    // Print distances from source node 1
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    cin >> n >> m;
    adj.resize(n + 1); // 1-based indexing
    dist.assign(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b}); // storing as {weight, node}
        // If undirected, also add: adj[b].push_back({w, a});
    }

    dijkstra();
    return 0;
}
