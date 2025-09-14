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
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int all = 1 << n;
    //if i consider a subset what will be the score i mean cost of choosing rabbit {1,2,3,5} in same group let say
    vll score(all, 0);
    for (int mask = 0; mask < all; mask++)
    {
        ll s = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                for (int j = i + 1; j < n; j++)

                {
                    if (mask & (1 << j))
                    {
                        s += a[i][j];
                    }
                }
            }
        }
        score[mask] = s;
    }


    /*
    
    story:
    =================>
    can we archive mask using this submask ; consider each sub as a group of rabbit ;if consider this sub mask as a group what will be the my score.
    means best possible way to get {mask } is calculated here
    
    */
    vector<ll>dp(all,-LINF);
    dp[0]=0;
    for(int mask=1;mask<all;mask++)
    {
        for(int sub=mask;sub; sub=(sub-1)&mask)
        {
            dp[mask]=max(dp[mask],dp[mask^sub]+score[sub]);
        }
    }
    cout<<dp[all-1]<<endl;
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