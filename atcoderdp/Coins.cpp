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
#define ld long double
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<ld> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    vector<vector<ld>> dp(n + 1, vector<ld>(n + 1, 0.0));
    dp[0][0] = 1.0;

    // dp[i][j]=>i have j heads and proceed i coins till now;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] += dp[i - 1][j] * (1.0 - p[i]);
            if (j > 0)
            {
                dp[i][j] += dp[i - 1][j - 1] * p[i];
            }
        }
    }

    int mhead = (n + 1) / 2;
    ld res = 0;
    for (int k = mhead; k <= n; k++)
    {
        res += dp[n][k];
    }

    cout << fixed << setprecision(10) << res << endl;
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