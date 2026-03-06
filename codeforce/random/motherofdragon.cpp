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
double k;cin>>n>>k;
vector<vector<int>>g(n,vector<int>(n));
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>g[i][j];
    }
}
int n1=n/2;
int n2=n-n1;

vll adj(n,0);
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(g[i][j]){
            adj[i]|=(1LL<<j);
        }
    }
}

int N1=1<<n1;
vi dp(N1,0);
for(int mask=1;mask<N1;mask++){
    int v=__builtin_ctz(mask);
    int prev=mask^(1<<v);
    if(prev==0){
        dp[mask]=1;
    }else if(dp[prev] && ((adj[v]&prev)==prev)){
        dp[mask]=dp[prev]+1;
    }
}

for(int mask=0;mask<N1;mask++){
    for(int i=0;i<n1;i++){
        if(mask &(1<<i)){
            dp[mask]=max(dp[mask],dp[mask^(1<<i)]);
        }
    }
}

int best=0;
int N2=1<<n2;
for(int mask=0;mask<N2;mask++){
    bool okay=true;
    for(int i=0;i<n2;i++){
        if(!(mask &(1<<i))) continue;
        for(int j=i+1;j<n2;j++){
            if((mask & (1<<j)) && !g[n1+i][n1+j]){
                okay=false;
                break;
            }
        }
        if(!okay) break;
    }

    if(!okay) continue;

    int common=(1<<n1)-1;
    for(int i=0;i<n2;i++){
        if(mask&(1<<i)){
            common&=(adj[n1+i] & ((1LL<<n1)-1));
        }
    }
    int size2 = __builtin_popcount(mask);

    best = max(best, size2 + dp[common]);
}


double m = best;

double ans = k * k * (m - 1) / (2 * m);

cout << fixed << setprecision(12) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();

    return 0;
}