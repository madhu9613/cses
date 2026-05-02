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
const int MAXN=150000+5;
vi adj[MAXN];
bool used[MAXN];
bool seen[MAXN];
int par[MAXN];

pair<int,int>dfs(int u,int p=-1){
    seen[u]=true;
    par[u]=p;
    pair<int,int>res={1,u}; //dist and node;;
    for(int v:adj[u]){
        if(v==p || used[v]) continue;
        auto cur=dfs(v,u);
        cur.first+=1; 
        res=max(res,cur);
    }
    return res;
}

void solve() {
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        adj[i].clear();
        used[i]=false;
    }
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<array<int,3>>ans;
    while(true){
        bool done=true;
        for(int i=1;i<=n;i++){
            if(!used[i]){
                done=false;
                break;
            }
        }
        if(done )break;

        for(int i=1;i<=n;i++) seen[i]=false;

        for(int i=1;i<=n;i++){
            if(used[i] || seen[i]) continue;
            auto [d1,x]=dfs(i);
            for(int j=1;j<=n;j++) seen[j]=false;
            auto [d2,y]=dfs(x);
            int u=max(x,y);
            int v=min(x,y);
            ans.push_back({d2,u,v});
            int cur=y;
            while(cur!=-1){
                used[cur]=true;
                cur=par[cur];
            }
        }
    }

    sort(all(ans),greater<>());
    for(auto [d,u,v]:ans){
        cout<<d<<" "<<u<<" "<<v<<" ";
    }
    cout<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}