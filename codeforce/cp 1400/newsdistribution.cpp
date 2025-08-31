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
vi par, dsu;
int find(int x)
{
    if (par[x] != x)
    {

        par[x] = find(par[x]);
    }
    return par[x];
}
void unite(int a, int b)

{
    a = find(a);
    b = find(b);
    if (a != b)

    {

        if (dsu[a] < dsu[b])

        {
            swap(a, b);
        }

        par[b] = a;
        dsu[a] += dsu[b];
    }
}
int n, m;
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)

    {

        par[i] = i;
    }
    while (m--)

    {

        int k;
        cin >> k;
        vi f(k);
        for(int i=0;i<k;i++)
        {
            cin>>f[i];
        }
        for (int i = 0; i < k - 1; i++)
        {
            unite(f[i], f[i + 1]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dsu[find(i)]<<" ";
    }cout<<endl;
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