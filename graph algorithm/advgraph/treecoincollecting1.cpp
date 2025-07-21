// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const int MAXN = 2e5 + 5;

int n, q;
vector<vector<int>> adj;
vector<int> coin;
vector<int> coin_dist;

int sz[MAXN], par[MAXN], dep[MAXN], heavy[MAXN];
int head[MAXN], pos[MAXN], timer = 1;
int flat[MAXN];

int st[4 * MAXN];  // segment tree

// ---------- DFS for sizes and heavy child
void dfs1(int u, int p = -1) {
    sz[u] = 1;
    par[u] = p;
    int max_sz = 0;
    for (int &v : adj[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > max_sz) {
            max_sz = sz[v];
            heavy[u] = v;
        }
    }
}

// ---------- HLD Decomposition
void decompose(int u, int h) {
    head[u] = h;
    pos[u] = timer;
    flat[timer++] = u;
    if (heavy[u]) decompose(heavy[u], h);
    for (int v : adj[u]) {
        if (v == par[u] || v == heavy[u]) continue;
        decompose(v, v);
    }
}

// ---------- Segment Tree Build (1-indexed)
void build(int size) {
    for (int i = size + 1; i <= 2 * size; ++i)
        st[i] = coin_dist[flat[i - size]];
    for (int i = size; i >= 1; --i)
        st[i] = min(st[2 * i], st[2 * i + 1]);
}

// ---------- Segment Tree Query
int range_query(int l, int r, int size) {
    int res = INF;
    for (l += size, r += size; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) res = min(res, st[l++]);
        if (r % 2 == 0) res = min(res, st[r--]);
    }
    return res;
}

// ---------- LCA using HLD
int lca(int u, int v) {
    while (head[u] != head[v]) {
        if (dep[head[u]] < dep[head[v]]) swap(u, v);
        u = par[head[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

// ---------- Query minimum distance to coin on path u to v
int path_query(int u, int v, int size) {
    int res = INF;
    while (head[u] != head[v]) {
        if (dep[head[u]] < dep[head[v]]) swap(u, v);
        res = min(res, range_query(pos[head[u]], pos[u], size));
        u = par[head[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    res = min(res, range_query(pos[u], pos[v], size));
    return res;
}

// ---------- Multi-source BFS to compute coin_dist
void bfs() {
    queue<int> q;
    fill(coin_dist.begin(), coin_dist.end(), INF);
    for (int i = 1; i <= n; i++) {
        if (coin[i]) {
            coin_dist[i] = 0;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (coin_dist[v] > coin_dist[u] + 1) {
                coin_dist[v] = coin_dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve() {
    cin >> n >> q;
    
    adj.clear(); adj.resize(n + 1);
    coin.clear(); coin.resize(n + 1);
    coin_dist.clear(); coin_dist.resize(n + 1);
    
    memset(heavy, 0, sizeof(heavy));

    for (int i = 1; i <= n; i++) cin >> coin[i];
    
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    bfs();
    dfs1(1);
    timer = 1;
    decompose(1, 1);

    int size = timer - 1;
    build(size);

    while (q--) {
        int a, b; cin >> a >> b;
        int dist = dep[a] + dep[b] - 2 * dep[lca(a, b)];
        int min_move = path_query(a, b, size);
        if (min_move == 0)
            cout << dist << endl;
        else
            cout << dist + 2 * min_move << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
