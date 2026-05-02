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

struct S
{
    int pa, pb, x, y;
};

void solve()
{
    ll x, y;
    cin >> x >> y;

    ll dp[32][3][3];
    S pr[32][3][3];

    for (int i = 0; i < 32; i++)
        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                dp[i][a][b] = INF;

    auto nxt = [&](int s, int b, int t)
    {
        if (s != 1)
            return s;
        if (b < t)
            return 0;
        if (b > t)
            return 2;
        return 1;
    };

    auto cst = [&](int s, int b, int t, ll w)
    {
        if (s == 0)
            return (ll)(t - b) * w;
        if (s == 2)
            return (ll)(b - t) * w;
        return 0LL;
    };

    dp[31][1][1] = 0;

    for (int i = 30; i >= 0; i--)
    {
        int xb = (x >> i) & 1;
        int yb = (y >> i) & 1;
        ll w = 1LL << i;

        for (int a = 0; a < 3; a++)
        {
            for (int b = 0; b < 3; b++)
            {
                if (dp[i + 1][a][b] == INF)
                    continue;

                for (int p = 0; p < 2; p++)
                {
                    for (int q = 0; q < 2; q++)
                    {
                        if (p & q)
                            continue;

                        int na = nxt(a, p, xb);
                        int nb = nxt(b, q, yb);

                        ll v = dp[i + 1][a][b] + cst(a, p, xb, w) + cst(b, q, yb, w);

                        if (v < dp[i][na][nb])
                        {
                            dp[i][na][nb] = v;
                            pr[i][na][nb] = {a, b, p, q};
                        }
                    }
                }
            }
        }
    }

    ll best = INF;
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (dp[0][i][j] < best)
                best = dp[0][i][j], a = i, b = j;

    ll p = 0, q = 0;
    for (int i = 0; i <= 30; i++)
    {
        S &s = pr[i][a][b];
        if (s.x)
            p |= (1LL << i);
        if (s.y)
            q |= (1LL << i);
        a = s.pa;
        b = s.pb;
    }

    cout << p << " " << q << "\n";
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
