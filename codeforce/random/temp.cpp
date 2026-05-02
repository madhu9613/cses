#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 150000 + 5;

vector<int> adj[MAXN];
bool used[MAXN];   // removed nodes
bool seen[MAXN];   // visited in DFS
int parent[MAXN];  // to reconstruct path

// DFS to find farthest node and distance
pair<int,int> dfs(int u, int p) {
    seen[u] = true;
    parent[u] = p;

    pair<int,int> res = {1, u}; // (distance, node)

    for (int v : adj[u]) {
        if (v == p || used[v]) continue;

        auto cur = dfs(v, u);
        cur.first += 1;

        // take lexicographically maximum
        res = max(res, cur);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // reset graph
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            used[i] = false;
        }

        // input
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<array<int,3>> ans;

        while (true) {
            // check if all nodes removed
            bool done = true;
            for (int i = 1; i <= n; i++) {
                if (!used[i]) {
                    done = false;
                    break;
                }
            }
            if (done) break;

            // reset seen
            for (int i = 1; i <= n; i++) seen[i] = false;

            // process each component
            for (int i = 1; i <= n; i++) {
                if (used[i] || seen[i]) continue;

                // 1st DFS → get one endpoint
                auto [d1, x] = dfs(i, -1);

                // reset seen for second DFS
                for (int j = 1; j <= n; j++) seen[j] = false;

                // 2nd DFS → get actual diameter
                auto [d2, y] = dfs(x, -1);

                int u = max(x, y);
                int v = min(x, y);

                ans.push_back({d2, u, v});

                // remove path from y to x
                int cur = y;
                while (cur != -1) {
                    used[cur] = true;
                    cur = parent[cur];
                }
            }
        }

        // sort lexicographically decreasing
        sort(ans.begin(), ans.end(), greater<>());

        // output
        for (auto &t : ans) {
            cout << t[0] << " " << t[1] << " " << t[2] << " ";
        }
        cout << "\n";
    }

    return 0;
}