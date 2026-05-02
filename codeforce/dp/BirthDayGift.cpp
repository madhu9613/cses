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
    ll x;
    cin >> n >> x;

    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    x++; // convert ≤ x into < x

    int ans = -1;

    for (int b = 30; b >= 0; b--) {
        vll next;
        bool open = false;
        int cnt = 0;

        for (int i = 0; i < (int)a.size(); i++) {

            if (!open) {
                next.push_back(a[i]);
            }
            else {
                next.back() ^= a[i];
            }

            if (a[i] & (1LL << b)) {
                open = !open;
                cnt++;
            }
        }

        // Case: x has 0 at this bit → must eliminate it
        if ((x & (1LL << b)) == 0) {
            if (cnt % 2 == 1) {
                cout << ans << '\n';
                return;
            }
            a = next;
        }
        // Case: x has 1 → optional
        else {
            if (cnt % 2 == 0) {
                ans = max(ans, (int)next.size());
                cout<<ans<<endl;
                return;
            }
        }
    }

    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}