#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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
    int n, k;cin >> n >> k;
    vi a(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    auto check = [&](int v, int& L, int& R)->bool {
        vi pref(n + 1, 0);
        for (int i = 1;i <= n;i++) {
            if (a[i] >= v) pref[i] = pref[i - 1] + 1;
            else pref[i] = pref[i - 1] - 1;
        }
        int minpref = 0;
        int minpos = 0;
        for (int r = k;r <= n;r++) {
            if (pref[r - k] < minpref) {
                minpref = pref[r - k];
                minpos = r - k;
            }
            if (pref[r] - minpref >= 0) {
                L = minpos + 1;
                R = r;
                return true;
            }
        }
        return false;
        };

    int low = 1, high = n;
    int v = 1, l = 1, r = k;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int L = -1, R = -1;
        if (check(mid, L, R)) {
            v = mid;
            l = L;
            r = R;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << v << " " << l << " " << r << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}