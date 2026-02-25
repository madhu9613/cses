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

const int MAXN=2e6+5;
int n,k;
vector<int>adj[MAXN];
ll dp[MAXN][5];
ll s=0;
ll extra=0;

int dfs1(int u,int p=-1){
    int sz=1;
    for(int v:adj[u]){
        if(v==p) continue;
        int sub=dfs1(v,u);
        s+=1ll*sub*(n-sub);
        sz+=sub;
    }
    return sz;
}

void dfs(int u,int p=-1){
    dp[u][0]=1;
    for(int v :adj[u]){
        if(v==p) continue;

        dfs(v,u);
        ll ndp[5]={0};
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++){
                ll cnt=dp[u][i]*dp[v][j];
                int rem=(i+j+1)%k;
                extra+=cnt*((k-rem)%k);
            }
        }
        for (int i = 0; i < k; i++)
            ndp[i] = dp[u][i];

        for (int j = 0; j < k; j++)
            ndp[(j + 1) % k] += dp[v][j];

        for (int i = 0; i < k; i++)
            dp[u][i] = ndp[i];
    }
     

    }

void solve() {
    cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1);
    dfs(1);
    cout<<(s+extra)/k<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}