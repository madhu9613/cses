#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m;
vector<int> adj[N];
vector<pair<int,int>> result;
map<pair<int,int>, bool> used;
int indeg[N];

int main() {
    cin >> n >> m;
    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 1: Topological sort using BFS (lex smallest)
    vector<int> in(n+1, 0);
    vector<int> topo_order;
    vector<bool> visited(n+1, false);
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                topo_order.push_back(u);
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    // Assign topological index
    vector<int> topo_idx(n+1);
    for (int i = 0; i < topo_order.size(); ++i) {
        topo_idx[topo_order[i]] = i;
    }

    // Step 2: Orient edges according to topological order
    for (auto [u, v] : edges) {
        if (topo_idx[u] < topo_idx[v]) {
            result.push_back({u, v});
        } else {
            result.push_back({v, u});
        }
    }

    // Output
    for (auto [u, v] : result) {
        cout << u << " " << v << "\n";
    }

    return 0;
}

///shoking Solution is min(u,v)=>max(u,v) (shoking right>)