//
// good queation important;
/*
  max(c0,c1)=(c0+c1+abs(c0-c1))/2;
  co+c1=L (length of the subsegment);
  ineed sigma (L) sum of all subsegments;
  its i*(n-i+1)  i times as rigt end and (n-i+1) times as left;
  it classic=>n*(n+1)*(n+2)/6;

  and abs(c0-c1) prefix sum ->0->-1 and 1-> +1; sort it and i need to find
  absolute difference abs(aj-ai) j>i after sorting it ai*(2*i-n);

*/
//
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
 ll n;
 cin>>n;
 string s;
 cin>>s;
 vll prefix(n+1);
 prefix[0]=0;
 for(int i=1;i<=n;i++){
    prefix[i]=(prefix[i-1]+(s[i-1]=='1'?1:-1));

 }

 ll total=1LL*(n)*(n+1)*(n+2)/6;
 
 sort(all(prefix));
 ll sum=0;
 for (int i = 0; i <= n; i++) {
     sum += (ll)prefix[i] * (i - (n - i));
 }

 ll ans=(total+sum)/2;
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
