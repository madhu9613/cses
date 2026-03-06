/*
 Intersting;
 need to count subarray with sum(l,r)=s and max(l,r)=x;
 so we will assisgn f(L)=subarrays with sum =s and max is less than <=L;
 so ans is f(x)-f(x-1);


*/
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
//     int n;
//     ll s,x;cin>>n>>s>>x;
//     vll a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     auto f=[&](int X)->ll{

//         ll ans=0;
//         ll prefix=0;
//         map<ll,ll>mp;
//         mp[0]=1;
//         for(ll v:a){
//             if(v>X){
//                 prefix=0;
//                 mp.clear();
//                 mp[0]=1;
//             }
//             else{
//                 prefix+=v;
//                 if(mp.count(prefix-s)){
//                     ans+=mp[prefix-s];
//                 }
//                 mp[prefix]++;
//             }
//         }
//         return ans;
//     };
//     ll ans=f(x)-f(x-1);
//     cout<<ans<<endl;
    
// }

//editorial idea;

void solve(){
    ll n,s,x;cin>>n>>s>>x;
    vll a(n+1),pref(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    map<ll,ll>cnt;
    ll ans=0;
    int lef=0;
    for(int r=1;r<=n;r++){
        if(a[r]>x){
            cnt.clear();
            lef=r+1;
            continue;
        }

        if(a[r]==x){
            while(lef<=r){
                cnt[pref[lef-1]]++;
                lef++;
            }
        }

        ans+=cnt[pref[r]-s];
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