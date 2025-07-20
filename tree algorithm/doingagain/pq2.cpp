#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using graph = vector<vi>;

const int INF = INT_MAX;

// --------------------- Segment Tree (Max Query) ---------------------
struct SegmentTree
{
    int n;
    vi tree;

    SegmentTree(vi &v)
    {
        n = 1;
        while (n < v.size())
            n *= 2;
        tree.assign(2 * n, 0);
        for (int i = 0; i < v.size(); ++i)
            tree[i + n] = v[i];
        for (int i = n - 1; i > 0; --i)
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    void set(int k, int x)
    {
        k += n;
        tree[k] = x;
        while (k > 1)
        {
            k /= 2;
            tree[k] = max(tree[2 * k], tree[2 * k + 1]);
        }
    }

    int query(int l, int r)
    {
        int res = 0;
        l += n, r += n;
        while (l <= r)
        {
            if (l % 2 == 1)
                res = max(res, tree[l++]);
            if (r % 2 == 0)
                res = max(res, tree[r--]);
            l /= 2, r /= 2;
        }
        return res;
    }
};

// ------------------------ Heavy-Light Decomposition ------------------------
struct HLD
{
    int n;
    graph &g;
    vi parent, heavy, head, depth, size, pos;
    int cur_pos = 0;

    HLD(graph &graph) : n(graph.size()), g(graph)
    {
        parent.assign(n, -1);
        heavy.assign(n, -1);
        head.assign(n, 0);
        depth.assign(n, 0);
        size.assign(n, 0);
        pos.assign(n, 0);

        dfs_size(0);
        decompose(0, 0);
    }

    void dfs_size(int u)
    {
        size[u] = 1;
        for (int &v : g[u])
        {
            if (v == parent[u])
                continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            dfs_size(v);
            size[u] += size[v];
            if (heavy[u] == -1 || size[v] > size[heavy[u]])
                heavy[u] = v;
        }
    }

    void decompose(int u, int h)
    {
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1)
            decompose(heavy[u], h);
        for (int v : g[u])
        {
            if (v != parent[u] && v != heavy[u])
                decompose(v, v);
        }
    }

    // For any function f(l, r), apply it over all ranges in path u-v
    template <typename F>
    void path_query(int u, int v, F f)
    {
        while (head[u] != head[v])
        {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);
            f(pos[head[u]], pos[u]);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        f(pos[u], pos[v]);
    }

    int position(int u) const { return pos[u]; }

    pair<int, int> subtree(int u) const
    {
        return {pos[u], pos[u] + size[u] - 1};
    }
};

// ---------------------------- Main Logic ----------------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vi values(n);
    for (int &x : values)
        cin >> x;

    graph g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    HLD hld(g);

    vi flat(n);
    for (int i = 0; i < n; ++i)
        flat[hld.position(i)] = values[i];

    SegmentTree seg(flat);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int s, x;
            cin >> s >> x;
            --s;
            seg.set(hld.position(s), x);
        }
        else
        {
            int u, v;
            cin >> u >> v;
            --u, --v;
            int res = 0;
            hld.path_query(u, v, [&](int l, int r)
                           { res = max(res, seg.query(l, r)); });
            cout << res << '\n';
        }
    }

    return 0;
}
