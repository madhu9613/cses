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

void solve()
{
    int n, k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (k >= 3)
    {
        cout << 0 << endl;
        return;
    }
    sort(all(a));
    ll d = a[0];

    for (int i = 0; i < n - 1; i++)
    {
        d = min(d, a[i + 1] - a[i]);
    }
    if (k == 1)
    {
        cout << d << endl;
        return;
    }
    if (d != 0)
    {
        for (int i = 0; i < n; i++)

        {
            for (int j = 0; j < i; j++)
            {
                ll v = a[i] - a[j];
                int p = lower_bound(all(a), v) - a.begin();
                if (p < n)
                    d = min(d, a[p] - v);
                if (p > 0)
                    d = min(d, v - a[p - 1]);
               
            }
        }
    }
    cout << d << endl;
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