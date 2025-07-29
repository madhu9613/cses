#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
bool dp[1 << 20][20];
int parent[1 << 20][20]; // to reconstruct the path

void solve() {
    cin >> n >> m;
    adj.assign(n, {});

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u, --v; // 0-based
        adj[u].push_back(v);
        adj[v].push_back(u); // remove this if graph is directed
    }

    memset(parent, -1, sizeof(parent));

    // Start from every node
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = true;
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u))) continue;
            if (!dp[mask][u]) continue;

            for (int v : adj[u]) {
                if (mask & (1 << v)) continue;
                int next_mask = mask | (1 << v);
                if (!dp[next_mask][v]) {
                    dp[next_mask][v] = true;
                    parent[next_mask][v] = u;
                }
            }
        }
    }

    int full_mask = (1 << n) - 1;
    int end_node = -1;

    for (int u = 0; u < n; ++u) {
        if (dp[full_mask][u]) {
            end_node = u;
            break;
        }
    }

    if (end_node == -1) {
        cout << "No Hamiltonian Path exists\n";
    } else {
        cout << "Hamiltonian Path exists:\n";
        // Reconstruct path
        vector<int> path;
        int mask = full_mask;
        int curr = end_node;
        while (curr != -1) {
            path.push_back(curr);
            int prev = parent[mask][curr];
            mask ^= (1 << curr);
            curr = prev;
        }
        for (int x : path) {
            cout << (x + 1) << " "; // convert back to 1-based
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
