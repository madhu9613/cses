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
    ll l, r;
    cin >> l >> r;

    string a = to_string(l);
    string b = to_string(r);

    ll cnt = 0;
    int n = a.size();

    for (int i = 0; i < n; i++) {

        if (a[i] == b[i]) {
            cnt += 2;
        }
        else if (a[i] + 1 < b[i]) {
            break;
        }
        else { // difference == 1
            cnt += 1;
            i++;

            while (i < n && a[i] == '9' && b[i] == '0') {
                cnt += 1;
                i++;
            }
            break;
        }
    }

    cout << cnt << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}