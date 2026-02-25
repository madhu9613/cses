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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll pow(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    if (b == 1) return a % m;
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
const ll LINF = 1e18;

const int MAXN = 40005;

vector<vector<int>>adj;
vector<array<ll, 2>>dp;
vector<pair<int, int>>range;

void dfs(int u, int p = -1)
{
    dp[u][0] = dp[u][1] = 0;

    for (int v : adj[u])
    {
        if (v == p) continue;

        dfs(v, u);

        dp[u][0] += max(
            dp[v][0] + llabs(range[u].first - range[v].first),
            dp[v][1] + llabs(range[u].first - range[v].second)
        );

        dp[u][1] += max(
            dp[v][0] + llabs(range[u].second - range[v].first),
            dp[v][1] + llabs(range[u].second - range[v].second)
        );
    }
}

void solve() {
    int n;
    cin >> n;

    range.assign(n + 1, { 0, 0 });
    for (int i = 1; i <= n; i++) {
        cin >> range[i].first >> range[i].second;
    }

    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dp.assign(n + 1, { 0, 0 });

    dfs(1);

    cout << max(dp[1][0], dp[1][1]) << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}