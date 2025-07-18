#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> shops(k);
    for (int i = 0; i < k; i++) {
        cin >> shops[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dist[v][0] = best distance, dist[v][1] = second-best
    vector<array<int, 2>> dist(n + 1, {INF, INF});
    vector<array<int, 2>> shop(n + 1, {0, 0});

    deque<pair<int,int>> dq;
    for (int s : shops) {
        dist[s][0] = 0;
        shop[s][0] = s;
        dq.emplace_back(s, 0);
    }

    while (!dq.empty()) {
        auto [v, idx] = dq.front();
        dq.pop_front();
        for (int u : adj[v]) {
            int newd = dist[v][idx] + 1;

            // 1️⃣ Try to update u's best distance
            if (newd < dist[u][0]) {
                // Shift best → second-best
                if (shop[v][idx] != shop[u][0]) {
                    dist[u][1] = dist[u][0];
                    shop[u][1] = shop[u][0];
                }
                // Update best
                dist[u][0] = newd;
                shop[u][0] = shop[v][idx];
                dq.emplace_back(u, 0);
            }
            // 2️⃣ Try to update u's second-best distance
            else if (shop[v][idx] != shop[u][0] && newd < dist[u][1]) {
                dist[u][1] = newd;
                shop[u][1] = shop[v][idx];
                dq.emplace_back(u, 1);
            }
        }
    }

    // Output result
    for (int v = 1; v <= n; v++) {
        int ans = INF;

        if (shop[v][0] != v && dist[v][0] < INF) {
            ans = min(ans, dist[v][0]);
        }
        if (dist[v][1] < INF) {
            ans = min(ans, dist[v][1]);
        }

        cout << (ans == INF ? -1 : ans) << " ";
    }

    cout << "\n";
    return 0;
}
