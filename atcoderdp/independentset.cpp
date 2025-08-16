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

const int MAXN = 1e5 + 5;
int n;
vector<vector<int>> adj;
ll dp[MAXN][2];

void dfs(int u, int p = -1)
{
    dp[u][0] = dp[u][1] = 1;

    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs(v, u);

        dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1]) % MOD) % MOD;

        dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
    }
}
void solve()
{
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1);
    cout<<(dp[1][0]+dp[1][1])%MOD<<endl;

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