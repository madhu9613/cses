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
    ll l;cin>>n>>l;
    vector<pair<ll,ll>>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(all(v),[](auto &x,auto &y){
        return x.second<y.second;
    });

    int ans=0;
    for(int i=0;i<n;i++){
        multiset<ll>st;
        ll sum=0;
        for(int j=i;j<n;j++){
            st.insert(v[j].first);
            sum+=v[j].first;

            ll cost =sum+(v[j].second-v[i].second);
            while(!st.empty() && cost>l){
                auto it=prev(st.end());
                sum-=*it;
                st.erase(it);
                cost=sum+(v[j].second-v[i].second);
            }

            ans=max(ans,(int)st.size());
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