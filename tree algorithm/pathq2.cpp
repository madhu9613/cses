#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const int MAXN = 2e5 + 5;

int n, q;
vector<int> tree[MAXN];
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], sz[MAXN];
int cpos = 0;
int a[MAXN];
int flat[MAXN];
int segtree[2 * MAXN];

int dfs1(int u, int p)
{
    parent[u] = p;
    sz[u] = 1;
    heavy[u] = 0;  // ✅ FIXED
    int maxsize = 0;

    for (int v : tree[u])
    {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        int sub = dfs1(v, u);
        sz[u] += sub;
        if (sub > maxsize)
        {
            maxsize = sub;
            heavy[u] = v;
        }
    }
    return sz[u];
}

void decompose(int u, int h)
{
    head[u] = h;
    pos[u] = ++cpos;

    if (heavy[u])
        decompose(heavy[u], h);

    for (auto &v : tree[u])
    {
        if (v != parent[u] && v != heavy[u])
            decompose(v, v);
    }
}

void build()
{
    // Assign values to leaves
    for (int i = 1; i <= n; ++i)
        segtree[i + n] = flat[i];

    // Build segment tree
    for (int i = n - 1; i >= 1; --i)
        segtree[i] = max(segtree[2 * i], segtree[2 * i + 1]);
}

void point_update(int i, int val)
{
    i += n;
    segtree[i] = val;
    for (i /= 2; i >= 1; i /= 2)
        segtree[i] = max(segtree[2 * i], segtree[2 * i + 1]);
}

int range_query(int l, int r)
{
    int res = INT_MIN;
    l += n;
    r += n;
    while (l <= r)
    {
        if (l % 2 == 1)
            res = max(res, segtree[l++]);
        if (r % 2 == 0)
            res = max(res, segtree[r--]);
        l /= 2;
        r /= 2;
    }
    return res;
}

int path_query(int u, int v)
{
    int res = INT_MIN;
    while (head[u] != head[v])
    {
        if (depth[head[u]] < depth[head[v]])
            swap(u, v);
        res = max(res, range_query(pos[head[u]], pos[u]));
        u = parent[head[u]];
    }
    if (depth[u] > depth[v])
        swap(u, v);
    res = max(res, range_query(pos[u], pos[v]));
    return res;
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    dfs1(1, 0);
    decompose(1, 1);

    for (int i = 1; i <= n; i++)
        flat[pos[i]] = a[i];

    build();

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int u, val;
            cin >> u >> val;
            point_update(pos[u], val);
        }
        else
        {
            int u, v;
            cin >> u >> v;
            cout << path_query(u, v) << " ";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
