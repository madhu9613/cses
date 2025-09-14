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
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
// const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;
const int MAXN = 1e5 + 5;
int n;
ll MOD;
vector<vector<int>> adj;
ll dp[MAXN], up[MAXN], ans[MAXN];

void dfs1(int u, int p = -1)
{
    dp[u] = 1;
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs1(v, u);
        dp[u] = (dp[u] * (1 + dp[v])) % MOD;
    }
}

void dfs2(int u, int p = -1)
{
    vi children;
    for (int v : adj[u])
        if (v != p)
            children.pb(v);

    int sz = children.size();
    vll prefix(sz), suffix(sz);

    for (int i = 0; i < sz; i++) {
        prefix[i] = (1 + dp[children[i]]) % MOD;
        if (i > 0) prefix[i] = (prefix[i] * prefix[i - 1]) % MOD;
    }

    for (int i = sz - 1; i >= 0; i--) {
        suffix[i] = (1 + dp[children[i]]) % MOD;
        if (i + 1 < sz) suffix[i] = (suffix[i] * suffix[i + 1]) % MOD;
    }

    for (int i = 0; i < sz; i++) {
        int v = children[i];
        ll exv = 1;
        if (i > 0) exv = (exv * prefix[i - 1]) % MOD;
        if (i + 1 < sz) exv = (exv * suffix[i + 1]) % MOD;

        up[v] = (1 + up[u]) * exv % MOD;
        dfs2(v, u);
    }
}

void solve()
{
    cin >> n >> MOD;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs1(1);
    up[1] = 0;
    dfs2(1);
    for (int i = 1; i <= n; i++)
    {
        ll ans = dp[i] * (1 + up[i]) % MOD;
        cout << ans << endl;
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