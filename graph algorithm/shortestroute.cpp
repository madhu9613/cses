#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define int long long

void dijkstra(int n, vector<vector<pair<int, int>>> &adj) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1}); // {distance, node}

    while (!pq.empty()) {
        auto [nodedistance, topnode] = pq.top();
        pq.pop();

        if (nodedistance > dist[topnode]) continue;

        for (auto &[neighbor, weight] : adj[topnode]) {
            if (dist[topnode] + weight < dist[neighbor]) {
                dist[neighbor] = dist[topnode] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dijkstra(n, adj);

    return 0;
}
