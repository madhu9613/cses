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

void solve()
{
    ll n;
    cin >> n;
    ll target = (n * n + 1) / 2;

    ll l = 1, r = n * n, ans = 0;
    while (l <= r)
    {
        ll m = l + (r - l) / 2;
        ll count = 0;
        for (ll i = 1; i <=n; i++)
        {
            count += min(n, m / i);
        }
        if (count >= target)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout<<ans<<endl;
    
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