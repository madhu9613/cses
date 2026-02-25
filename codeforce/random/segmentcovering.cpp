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
    int n,m;cin>>n>>m;
    vector<vector<pair<int,ll>>>seg(m+1);
    ll base=1;
    for(int i=0;i<n;i++){
        int l,r;ll p,q;
        cin>>l>>r>>p>>q;
        ll take=p*modpow(q,MOD-2,MOD)%MOD;
        ll not_take=(1-take+MOD)%MOD;
        base=base*(not_take)%MOD;
        ll w=take*modpow(not_take,MOD-2,MOD)%MOD;
        seg[r].push_back({l,w});
    }
    vll dp(m+1,0);
    dp[0]=1;
    for(int r=1;r<=m;r++){
        for(auto [l,w]:seg[r]){
            dp[r]=(dp[r]+dp[l-1]*w)%MOD;
        }
    }
    cout<<base*dp[m]%MOD<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();

    return 0;
}