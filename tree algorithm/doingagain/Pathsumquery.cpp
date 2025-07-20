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

ll n, q;
vll value;
vll pathsum;
vll tin, tout;
vector<ll> segment;
vll lazy;
ll timer = 1;
vll flat;
vector<vll> adj;

void dfs(ll u, int par = -1)
{
    tin[u] = timer;
    flat[timer++] = u;
    for (int v : adj[u])
    {
        if (v == par)
            continue;
        pathsum[v] += pathsum[u] + value[v];
        dfs(v, u);
    }
    tout[u] = timer - 1;
}

void build(ll node, ll l, ll r)
{
    if (l == r)
    {
        segment[node] = pathsum[flat[l]];
        return;
    }
    ll mid = l + (r - l) / 2;
    build(2 * node, l, mid);
    build(2 * node+1, mid + 1, r);
    segment[node] = segment[2 * node] + segment[2 * node + 1];
}

void propagate(ll node, ll l, ll r)
{
    if (lazy[node] != 0)
    {
        segment[node] += (r - l + 1) * lazy[node];
        if (l != r)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(ll node, ll l, ll r, ll ql, ll qr, ll val)
{
    propagate(node, l, r);

    // No overlap
    if (qr < l || ql > r)
        return;

    // Total overlap
    if (ql <= l && r <= qr)
    {
        lazy[node] += val;
        propagate(node, l, r);
        return;
    }

    // Partial overlap
    ll mid = (l + r) / 2;
    update_range(2 * node, l, mid, ql, qr, val);
    update_range(2 * node + 1, mid + 1, r, ql, qr, val);
    segment[node] = segment[2 * node] + segment[2 * node + 1];
}

ll query(ll node, ll l, ll r, ll k)
{
    propagate(node, l, r);

    if (l == r)
        return segment[node];

    ll mid = (l + r) / 2;
    if (k <= mid)
        return query(2 * node, l, mid, k);
    else
        return query(2 * node + 1, mid + 1, r, k);
}

void solve()
{

    cin >> n >> q;
    value.resize(n + 1);
    pathsum.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    flat.resize(n + 1);
    lazy.resize(4*n);
    segment.resize(4 * n);
    adj.resize(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> value[i];
    }
    for (ll i = 1; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    pathsum[1] = value[1];
    dfs(1);
    build(1, 1, n);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll a, x;
            cin >> a >> x;
            ll diff = x - value[a];
            value[a]=x;
            update_range(1, 1, n, tin[a], tout[a], diff);
        }else{
            ll a;cin>>a;
            cout<<query(1,1,n,tin[a])<<endl;
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