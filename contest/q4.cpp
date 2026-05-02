#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e9;
const int MOD = 1000000007;

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD) {
    return modpow(a, mod - 2, mod);
}

// GCD
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve() {
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vi>dp(n,vi(7,INF));
    for(int v=1;v<=6;v++)
    {
        dp[0][v]=(a[0]!=v);
    }
    for(int i=1;i<n;i++)
    {
        for(int v=1;v<=6;v++)
        {
            for(int u=1;u<=6;u++)
            {
                if(u!=v && u+v!=7)
                {
                    dp[i][v]=min(dp[i][v],dp[i-1][u]+(a[i]!=v));
                }
            }
        }
    }
    int ans=INF;
    for(int v=1;v<=6;v++){
        ans=min(ans,dp[n-1][v]);
    }
    cout<<ans<<endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}