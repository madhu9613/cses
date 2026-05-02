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
ll l,r,ans;
};

unordered_map<long long, node> memo;

node f(ll n, ll k) {

    if (n <= 0) return { 0,0,0 };
    if (k < 0) return { 0,0,0 };
    if (n == 1) return { 1,1,1 };

    long long key = (n << 6) | k;
    if (memo.count(key)) return memo[key];

    ll p = 1LL << __lg(n);
    if (p == n) p >>= 1;

    node left = f(p, k);
    node right = f(n - p, k - 1);

    ll ans = (left.ans + right.ans) % MOD;
    ans = (ans + left.r * right.l % MOD) % MOD;

    ll l = left.l;
    if (left.l == p) l += right.l;

    ll r = right.r;
    if (right.r == (n - p)) r += left.r;

    node res = { l,r,ans };

    if ((p << 1) == n) memo[key] = res;

    return res;
}
void solve() {
    ll n,k;cin>>n>>k;
    memo.clear();
    node res=f(n,k);
    cout<<res.ans%MOD<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}