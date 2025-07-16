#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;

int start, last;

bool dfs(int node, int par) {
    visited[node] = true;
    for (auto n : adj[node]) {
        if (n == par) continue;
        if (!visited[n]) {
            parent[n] = node;
            if (dfs(n, node)) return true;
        } else {
            // cycle found
            start = node;
            last = n;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    visited.assign(n + 1, false);
    parent.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
             
                vector<int> cycle;
                cycle.push_back(last);
                for (int v = start; v != last; v = parent[v]) {
                    cycle.push_back(v);
                }
                cycle.push_back(last); // To complete the cycle
                reverse(cycle.begin(), cycle.end());
                cout << cycle.size() << endl;
                for (int x : cycle) {
                    cout << x << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
