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

void solve(){
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vi par(n,-1),left(n,-1),right(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        int last=-1;
        while(!st.empty() && a[st.top()]<a[i]){
            last=st.top();
            st.pop();
        }
        if(!st.empty()){
            par[i]=st.top();
            right[st.top()]=i;

        }
        if(last!=-1){
            par[last]=i;
            left[i]=last;
        }
        st.push(i);
    }
    int root=-1;
    for(int i=0;i<n;i++){
        if(par[i]==-1){
            root=i;
            break;
        }
    }

    int depth=0;
    function<void(int,int)>dfs=[&](int u,int d){

        if(u==-1)return;
        depth=max(depth,d);
        dfs(left[u],d+1);
        dfs(right[u],d+1);

    };
    dfs(root,1);
    cout<<n-depth<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}