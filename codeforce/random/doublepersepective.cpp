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
    int n;cin>>n;
    vector<tuple<int,int,int>>segs;
    for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        segs.push_back({a,b,i});
    }
    sort(all(segs),[](auto &x,auto &y){
        if(get<0>(x)==get<0>(y)){
            return get<1>(x) > get<1>(y);
        }
        return get<0>(x)<get<0>(y);
    });

    vi ans;
    int maxr=-1;
    for(auto &s:segs){
        int a=get<0>(s);
        int b=get<1>(s);
        int idx=get<2>(s);
        if(b<=maxr){
            continue;
        }
        ans.push_back(idx);
        maxr=b;
    }

    cout<<ans.size()<<endl;
    for(int x:ans){
        cout<<x<<" ";
    }cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}