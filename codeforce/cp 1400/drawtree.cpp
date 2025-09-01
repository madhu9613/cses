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
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

vector<vector<pair<int, int>>> adj;
vector<int> dp, edgeidx;

void dfs(int u, int p = -1)
{
    for (auto [v, idx] : adj[u])

    {
        if (v == p)
            continue;
        if (idx >= edgeidx[u])
        {
            dp[v] = dp[u];
            edgeidx[v] = idx;
        }
        else
        {
            dp[v] = dp[u] + 1;

            edgeidx[v] = idx;
        }
        dfs(v,u);
    }

}
    void solve()
    {
        int n;
        cin >> n;
        adj.assign(n + 1, {});
        dp.assign(n + 1, 0);
        edgeidx.assign(n + 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].pb({v, i});
            adj[v].pb({u, i});
        }
        dp[1] = 1;
        edgeidx[1] = -1;
        dfs(1);
        cout<<*max_element(all(dp))<<endl;
    }

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int t = 1;
        cin >> t;
        while (t--)
            solve();
        return 0;
    }