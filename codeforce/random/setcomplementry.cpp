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

const ll INF = 1e18;
const int MOD = 998244353;

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
    ll n,x;cin>>n>>x;
    if(n==1){
        cout<<x%MOD<<endl;
        return;
    }
    ll M0=(n)*(n+1)/2-1;
    if(M0>x){
        cout<<0<<endl;
        return ;
    }
    ll limit = x - M0;
    vll dp(limit+1,0);
    dp[0]=1;
    for(int w=1;w<=n-1;w++){
        for(int s=w;s<=limit;s++){
            dp[s]=(dp[s]+dp[s-w])%MOD;
        }
    }
    for(int i=1;i<=limit;i++){

        dp[i]=(dp[i]+dp[i-1])%MOD;
    }
    cout<<dp[limit]<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}