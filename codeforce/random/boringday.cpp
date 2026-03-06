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

// void solve() {
//     ll n,l,r;cin>>n>>l>>r;
//     vll a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int cnt=0;
//     int i=0;
//     ll sum=0;
//     for(int j=0;j<n;j++){
//         sum+=a[j];
//         while(sum>r){
//             sum-=a[i];
//             i++;
//         }
//         if(sum>=l && sum<=r){
//             cnt++;
//             sum=0;
//             i=j+1;
//         }
//     }
//     cout<<cnt<<endl;

// }

void solve(){
    ll n,l,r;cin>>n>>l>>r;
    vll a(n+1), pref(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    vi dp(n+1,0);
    for(int i=0;i<n;i++){
        dp[i+1]=max(dp[i+1],dp[i]);

        ll t=pref[i]+l;
        int j=lower_bound(pref.begin()+i+1,pref.end(),t)-pref.begin();
        if(j<=n){
            ll sum=pref[j]-pref[i];
            if(sum<=r){
                dp[j]=max(dp[j],dp[i]+1);
            }
        }

    }
    cout<<*max_element(all(dp))<<endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}