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

vll value;
vll segment;
vll flat, tin, tout;
ll timer = 1;
ll n, q;
vector<vll> adj;

void dfs1(ll u, ll par = -1) {
    tin[u] = timer;
    flat[timer] = u;
    timer++;
    for (int v : adj[u]) {
        if (v == par) continue;
        dfs1(v, u);
    }
    tout[u] = timer - 1;
}

void build(ll node, ll l, ll r) {
    if (l == r) {
        segment[node] = value[flat[l]];
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    segment[node] = segment[2 * node] + segment[2 * node + 1];
}

ll query(ll node, ll l, ll r, ll ql, ll qr) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && r <= qr) return segment[node];
    ll mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
}

void update(ll node, ll l, ll r, ll idx, ll val) {
    if (l == r) {
        segment[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
        update(2 * node, l, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, r, idx, val);
    segment[node] = segment[2 * node] + segment[2 * node + 1];
}

void solve() {
    cin >> n >> q;
    flat.resize(n + 1);
    value.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    adj.resize(n + 1);
    segment.resize(4 * n);

    for (ll i = 1; i <= n; i++) {
        cin >> value[i];
    }

    for (ll i = 1; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs1(1);
    build(1, 1, n);

    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll a, val;
            cin >> a >> val;
            update(1, 1, n, tin[a], val);
        } else {
            ll b;
            cin >> b;
            cout << query(1, 1, n, tin[b], tout[b]) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
