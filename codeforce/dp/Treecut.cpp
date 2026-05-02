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

const int MAXN=100005;
vi adj[MAXN];
int n,k;
int cuts;

int dfs(int u,int p,int x){
    int sz=1;
    for(int v:adj[u]){
        if(v==p) continue;
        sz+=dfs(v,u,x);
    }
    if(sz>=x){
        cuts++;
        return 0;
    }
    return sz;
}
bool can(int x){
    cuts=0;
    dfs(1,0,x);
    return (cuts>=k+1);
}
void solve() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) adj[i].clear();

    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(can(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
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