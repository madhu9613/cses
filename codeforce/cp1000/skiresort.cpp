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
    ll n, k, q;
    cin >> n >> k >> q;
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll res = 0;
    int left = 0, right = 0;
    while (left <= right && right < n)
    {
        if (a[right] <= q)
        {
            right++;
        }
        else
        {
            ll l = right - left;
            if (l >= k)
            {
                res += (l + 1 - k) * (l + 2 - k) / 2;
            }
            left = right + 1;
            right++;
        }
    }

    ll l = right - left;
    if (l >= k)
    {
        res += (l + 1 - k) * (l + 2 - k) / 2;
    }

    cout << res << endl;
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