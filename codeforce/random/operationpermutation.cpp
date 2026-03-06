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
    int n;
    ll x;cin>>n>>x;
    vll  mult;
    ll plus=0;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        char op=s[0];
        ll val=stoll(s.substr(1));
        if(op=='+'){
            plus=(plus+val)%MOD;
        }else if(op=='-'){
            plus=(plus-val+MOD)%MOD;
        }
        else if(op=='x'){
            mult.push_back(val%MOD);
        }else{
            mult.push_back(modinv(val));
        }
    }
    int m=mult.size();
    vector<vll>dp(m+1,vll(m+1,0));
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        dp[i][0]=1;
        for(int j=1;j<=i;j++){
            dp[i][j]=(dp[i-1][j]+mult[i-1]*dp[i-1][j-1])%MOD;
        }
    }
    vll fact(m+1,1),invfact(m+1,1);
    for(int i=1;i<=m;i++){
        fact[i]=fact[i-1]*i%MOD;
    }
    invfact[m]=modinv(fact[m]);
    for(int i=m;i>0;i--){
        invfact[i-1]=invfact[i]*i%MOD;
    }

    auto c=[&](int n,int r){
      return fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;
    };

    ll S=0;
    for(int k=0;k<=m;k++){
        ll term=dp[m][k]*modinv(c(m,k))%MOD;
        S=(S+term)%MOD;
    }
    S=S*modinv(m+1)%MOD;
    ll ans=0;
    ans=x%MOD*dp[m][m]%MOD;

    ans=(ans+plus*S)%MOD;
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