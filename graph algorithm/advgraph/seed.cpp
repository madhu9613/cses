#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int parent[N], sz[N];

// DSU initialization
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

// DSU find
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(v);
}

// DSU union
bool union_sets(int a, int b, ll w, ll &res) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        res += w * 1LL * sz[a] * sz[b];
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> edges;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(w, u, v);
    }

    sort(edges.begin(), edges.end());  // Sort by weight increasing

    for (int i = 1; i <= n; ++i)
        make_set(i);

    ll res = 0;
    for (auto &[w, u, v] : edges) {
        union_sets(u, v, w, res);
    }

    cout << res << '\n';
    return 0;
}
