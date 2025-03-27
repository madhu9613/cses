// loyd-Warshall Algorithm here we need to find distance for quearies here most optimal solution is given by this algo
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

void floyd_warshall(int n, vector<vector<int>> &dist) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) { 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // Distance to self is 0
    for (int i = 1; i <= n; i++) dist[i][i] = 0;

   
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);  // Since it's an undirected graph
    }

    // Compute shortest paths
    floyd_warshall(n, dist);

    // Process queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << "\n";
    }

    return 0;
}
