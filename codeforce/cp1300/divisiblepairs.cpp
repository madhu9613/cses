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
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<pair<ll, ll>, ll> cnt;
    ll ans = 0;

    for (int val : a)
    {

        ll rx = val % x;
        ll ry = val % y;
        ll needx = (x - rx) % x;
        ll needy = ry;

        pair<ll, ll> need = {needx, needy};
        if (cnt.count(need))
            ans += cnt[need];
        cnt[{rx, ry}]++;
    }

    cout<<ans<<endl;
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