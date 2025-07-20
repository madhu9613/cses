// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define endl '\n'

const int MAXN = 2e5 + 5;

int n, q;
vector<int> adj[MAXN];
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], subtree[MAXN];
int curr_pos = 1;

int dfs(int u, int p = -1) {
    parent[u] = p;
    subtree[u] = 1;
    int max_subtree = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        subtree[u] += dfs(v, u);

        if (subtree[v] > max_subtree) {
            max_subtree = subtree[v];
            heavy[u] = v;
        }
    }
    return subtree[u];
}

void decompose(int u, int h) {
    head[u] = h;
    pos[u] = curr_pos++;

    if (heavy[u]) {
        decompose(heavy[u], h);  // continue same chain
    }

    for (int v : adj[u]) {
        if (v == parent[u] || v == heavy[u]) continue;
        decompose(v, v);  // new chain
    }
}

int lca(int u, int v) {
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]])
            swap(u, v);
        u = parent[head[u]];
    }
    return (depth[u] < depth[v]) ? u : v;
}

void solve() {
    cin >> n >> q;

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].pb(i);
        adj[i].pb(p);
    }

    dfs(1);
    decompose(1, 1);

  
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
