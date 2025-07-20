#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
int n, q;
vector<int> tree[N];
int parent[N], depth[N], heavy[N], head[N], pos[N], sz[N];
int cur_pos = 0;
 
int a[N];          // Original values
int flat[N];       // Flattened tree
int seg[2 * N];    // Iterative segment tree
 
// DFS to calculate sizes and heavy child
int dfs(int u, int p) {
    parent[u] = p;
    sz[u] = 1;
    int max_size = 0;
    for (int v : tree[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        int sub = dfs(v, u);
        sz[u] += sub;
        if (sub > max_size) {
            max_size = sub;
            heavy[u] = v;
        }
    }
    return sz[u];
}
 
// Decompose into chains
void decompose(int u, int h) {
    head[u] = h;
    pos[u] = ++cur_pos;
    if (heavy[u]) decompose(heavy[u], h);
    for (int v : tree[u]) {
        if (v != parent[u] && v != heavy[u])
            decompose(v, v);
    }
}
 
void build() {
    for (int i = n + 1; i <= 2 * n; ++i) seg[i] = flat[i - n];
    for (int i = n; i >= 1; --i)
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}
 
void point_update(int i, int val) {
    seg[i += n] = val;
    for (i /= 2; i >= 1; i /= 2)
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
}
 
int range_query(int l, int r) {
    int res = INT_MIN;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) res = max(res, seg[l++]);
        if (r % 2 == 0) res = max(res, seg[r--]);
    }
    return res;
}
 
int path_query(int u, int v) {
    int res = INT_MIN;
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        res = max(res, range_query(pos[head[u]], pos[u]));
        u = parent[head[u]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    res = max(res, range_query(pos[u], pos[v]));
    return res;
}
 
int main() {
    cin>>n>>q;
    for (int i = 1; i <= n; ++i) cin>>a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
 
    dfs(1, 0);
    decompose(1, 1);
 
    for (int i = 1; i <= n; ++i)
        flat[pos[i]] = a[i];
 
    build();  // iterative build
 
    while (q--) {
        int type;
       cin>>type;
        if (type == 1) {
            int u, val;
          cin>>u>>val;
            point_update(pos[u], val);
        } else {
            int u, v;
          cin>>u>>v;
            printf("%d\n", path_query(u, v));
        }
    }
 
    return 0;
}
