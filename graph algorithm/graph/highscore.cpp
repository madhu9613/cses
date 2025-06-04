#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

struct Edge {
    int u, v, w;
};

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        edges.push_back({a, b, -x}); // negate weight
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    // Bellman-Ford
    for (int i = 1; i <= n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] < INF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Check for negative cycles
    vector<bool> affected(n + 1, false);
    for (int i = 1; i <= n; i++) {
        for (auto &e : edges) {
            if (dist[e.u] < INF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                affected[e.v] = true;
            }
            if (affected[e.u]) affected[e.v] = true;
        }
    }

    if (affected[n]) {
        cout << -1 << "\n";
    } else {
        cout << -dist[n] << "\n"; // negate again to get max score
    }

    return 0;
}
