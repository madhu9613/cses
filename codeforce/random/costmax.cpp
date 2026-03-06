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

struct node{
  ll cost,best,sum,depth;  
};

vector<vi>adj;
vll a;
vector<node>dp;

node dfs(int u, int p = -1) {
   
    ll sum=a[u];
    ll cost=0;
    ll maxdepth=0;
    ll secdepth=0;
    ll bestinc=0;
    for(int v:adj[u]){
        if(v==p) continue;
        node child=dfs(v,u);
        sum+=child.sum;
        cost+=child.cost+child.sum;
        bestinc=max(bestinc,child.best-child.cost);
        ll d=child.depth+1;
        if(d>=maxdepth){
            secdepth=maxdepth;
            maxdepth=d;
        }
        else if(d>secdepth){
            secdepth=d;
        }
    }
    ll best=cost+bestinc;
    for(int v:adj[u]){
        if(v==p) continue;
        node child=dp[v];
        ll d=child.depth+1;
        ll usedepth=maxdepth;
        if(d==maxdepth){
            usedepth=secdepth;
        }
        best=max(best,cost+usedepth*child.sum);
    }
    dp[u]={cost,best,sum,maxdepth};
    return dp[u];
}

void solve() {
    int n;
    cin >> n;

    adj.assign(n + 1, {});
    a.assign(n + 1, 0);
    dp.assign(n + 1, {});

    for (int i = 1;i <= n;i++)
        cin >> a[i];

    for (int i = 0;i < n - 1;i++)
    {
        int u, v;
        cin >> u >> v;

    adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1;i <= n;i++)
        cout << dp[i].best << " ";

    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}