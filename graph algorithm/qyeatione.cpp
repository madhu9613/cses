#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
ll pow(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % m;
    ll temp = pow(a, b / 2, m);
    if (b % 2 == 0)
    {
        return (temp * temp) % m;
    }
    else
    {
        return (a * (temp * temp) % m) % m;
    }
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

const int MAXN = 40005;

const ll LINF = 1e18;

struct HLD
{
    int n, timer;
    vector<vector<int>> tree;
    vector<int> parent, depth, heavy, head, pos, sz;

    HLD(int n) : n(n), timer(0)
    {
        tree.resize(n + 1);
        parent.resize(n + 1);
        depth.resize(n + 1);
        heavy.assign(n + 1, -1);
        head.resize(n + 1);
        pos.resize(n + 1);
        sz.resize(n + 1);
    }

    int dfs(int u)
    {
        sz[u] = 1;
        int mx = 0;
        for (int v : tree[u])
        {
            depth[v] = depth[u] + 1;
            parent[v] = u;
            int sub = dfs(v);
            sz[u] += sub;
            if (sub > mx)
            {
                mx = sub;
                heavy[u] = v;
            }
        }
        return sz[u];
    }

    void decompose(int u, int h)
    {
        head[u] = h;
        pos[u] = ++timer;
        if (heavy[u] != -1)
            decompose(heavy[u], h);
        for (int v : tree[u])
        {
            if (v != heavy[u])
                decompose(v, v);
        }
    }
};

struct SegTree
{
    int n;
    vector<ll> tree, lazy;

    SegTree(int n) : n(n)
    {
        tree.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
    }

    void push(int i, int l, int r)
    {
        if (!lazy[i])
            return;
        int m = (l + r) >> 1;
        tree[i << 1] += lazy[i] * (m - l + 1);
        tree[i << 1 | 1] += lazy[i] * (r - m);
        lazy[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i];
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int ql, int qr, ll v)
    {
        if (ql > r || qr < l)
            return;
        if (ql <= l && r <= qr)
        {
            tree[i] += v * (r - l + 1);
            lazy[i] += v;
            return;
        }
        push(i, l, r);
        int m = (l + r) >> 1;
        update(i << 1, l, m, ql, qr, v);
        update(i << 1 | 1, m + 1, r, ql, qr, v);
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    ll query(int i, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return tree[i];
        push(i, l, r);
        int m = (l + r) >> 1;
        return query(i << 1, l, m, ql, qr) + query(i << 1 | 1, m + 1, r, ql, qr);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vi r(n + 1);
    for (int i = 1; i < n; i++)
        r[i] = i + 1;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        r[u] = max(r[u], v);
    }

    HLD hld(n);
    for (int i = 1; i < n; i++)
    {
        hld.tree[r[i]].push_back(i);
    }

    hld.dfs(n);
    hld.decompose(n, n);

    vector<vi> byDepth(n + 1);
    for (int i = 1; i <= n; i++)
        byDepth[hld.depth[i]].push_back(i);

    SegTree st(n);
    ll answer = 0, sd = 0, cnt = 0;

    for (int d = 0; d <= n; d++)
    {
        for (int u : byDepth[d])
        {
            sd += d;
            cnt++;
            int x = u;
            while (x)
            {
                st.update(1, 1, n,
                          hld.pos[hld.head[x]],
                          hld.pos[x], 1);
                x = hld.parent[hld.head[x]];
            }
        }
        for (int u : byDepth[d])
        {
            ll covered = 0;
            int x = u;
            while (x)
            {
                covered += st.query(1, 1, n,
                                    hld.pos[hld.head[x]],
                                    hld.pos[x]);
                x = hld.parent[hld.head[x]];
            }
            answer += sd - (covered - cnt);
        }
    }

    cout << answer << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
