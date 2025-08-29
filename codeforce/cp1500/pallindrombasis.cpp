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

const int MAXN = 40005;

bool ispal(int x)
{
    int original = x, rev = 0;
    while (x)
    {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev == original;
}


ll dp[MAXN];


void precompute()
{
    vi pal;
    for(int i=1;i<MAXN;i++)
    {
        if(ispal(i))
        {
            pal.pb(i);
        }
    }
    dp[0]=1;
    for(int p:pal)
    {
        for(int i=p;i<MAXN;i++)
        {
            dp[i]=(dp[i]+dp[i-p])%MOD;
        }
    }

}
void solve()
{

    int n;cin>>n;
    cout<<dp[n]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    precompute();
    cin >> t;
    while (t--)
        solve();
    return 0;
}
