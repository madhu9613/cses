// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// const int N = 2e5 + 5;
// int parent[N], sz[N];

// // DSU initialization
// void make_set(int v) {
//     parent[v] = v;
//     sz[v] = 1;
// }

// // DSU find
// int find_set(int v) {
//     if (v == parent[v])
//         return v;
//     return parent[v] = find_set(v);
// }

// // DSU union
// bool union_sets(int a, int b, ll w, ll &res) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         res += w * 1LL * sz[a] * sz[b];
//         if (sz[a] < sz[b])
//             swap(a, b);
//         parent[b] = a;
//         sz[a] += sz[b];
//         return true;
//     }
//     return false;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     vector<tuple<int, int, int>> edges;
//     for (int i = 1; i < n; ++i) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edges.emplace_back(w, u, v);
//     }

//     sort(edges.begin(), edges.end());  

//     for (int i = 1; i <= n; ++i)
//         make_set(i);

//     ll res = 0;
//     for (auto &[w, u, v] : edges) {
//         union_sets(u, v, w, res);
//     }

//     cout << res << '\n';
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int,int>> adj[N];
vector<pair<int,int>> res;
bool visited[N];
int tin[N], low[N], timer;
map<pair<int,int>, bool> used;

bool dfs(int u, int parent) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;

    for (auto [v, id] : adj[u]) {
        if (v == parent) continue;

        if (visited[v]) {
            // Back edge
            low[u] = min(low[u], tin[v]);

            if (!used[{u, v}] && !used[{v, u}]) {
                res.push_back({u, v});
                used[{u, v}] = true;
            }
        } else {
            // Tree edge
            if (!used[{u, v}] && !used[{v, u}]) {
                res.push_back({u, v});
                used[{u, v}] = true;
            }

            if (!dfs(v, u)) return false; 
            low[u] = min(low[u], low[v]);

            // Check bridge
            if (low[v] > tin[u]) {
                // (u,v) is a bridge
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }

    if (!dfs(1, -1)) {
        cout << "0\n";
        return 0;
    }

    // Check if disconnected
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "0\n";
            return 0;
        }
    }

    for (auto [u, v] : res)
        cout << u << " " << v << "\n";
}

