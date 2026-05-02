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

struct DSU{

    vi p;
    DSU(int n){
        p.resize(n);
        iota(all(p),0);
    }
    int find(int x){
        return (p[x]==x?x:p[x]=find(p[x]));
    }

    bool unite(int a,int b){
        a=find(a),b=find(b);
        if(a==b) return false;
        p[b]=a;
        return false;
    }
};
void solve() {
    int n;cin>>n;
    vector<vi>adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi mn(n+1),mx(n+1);
    function<void(int,int)> dfs=[&](int u,int p){
      mn[u]=mx[u]=u;
      for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
        mn[v]=min(mn[v],mn[u]);
        mx[v]=max(mx[v],mx[u]);
      }  
    };

    dfs(1,0);

    for(int v=1;v<=n;v++){
        int deg=adj[v].size();
        if(deg==0){
            cout << "0 0\n\n";
            continue;
        }
        DSU dsu(deg);
        vector<pair<int,int>>edges;
        ll cost=0;

        function<int(int, int)> get_comp = [&](int node, int parent) {
            for (int i = 0; i < deg; i++) {
                int u = adj[v][i];
                if (u == parent) continue;

                
                if (mn[u] <= node && node <= mx[u]) {
                    return i;
                }
            }
            return -1;
            };
        

            auto try_add=[&](int a,int b){
                if (a < 1 || b < 1 || a > n || b > n || a == v || b == v) return;

                int ca = get_comp(a, v);
                int cb = get_comp(b, v);

                if (ca == -1 || cb == -1) return;

                if (dsu.unite(ca, cb)) {
                    edges.push_back({ a, b });
                    cost += abs(a - b);
                }
            }



    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}