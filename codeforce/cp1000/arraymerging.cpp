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
    int n;
    cin >> n;

    vi maxa(2 * n + 1);
    vi maxb(2 * n + 1);
    vi a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    int last = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] != a[i - 1])
        {
            maxa[a[i - 1]] = max(maxa[a[i - 1]], i - last);
            last = i;
        }
    }
maxa[a[n]] = max(maxa[a[n]], n - last + 1);

     last = 1;
    for (int i = 2; i <= n; i++)
    {
        if (b[i] != b[i - 1])
        {
            maxb[b[i - 1]] = max(maxb[b[i - 1]], i - last);
            last = i;
        }
    }
maxb[b[n]] = max(maxb[b[n]], n - last + 1);

    int ans=0;
    for(int i=1;i<=2*n;i++)
    {
        ans=max(ans,maxa[i]+maxb[i]);
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