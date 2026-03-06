#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;

ll modpow(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;

        int size = 2 * n + 1;
        int offset = n;

        bitset<200005> dp0, dp1;
        dp0.reset();
        dp1.reset();
        dp0[offset] = 1;

        for (char c : s) {
            bitset<200005> new0, new1;
            new0.reset();
            new1.reset();

            if (c == '0' || c == '?') {
                new0 |= (dp0 << 1);
                new1 |= (dp1 << 1);
            }

            if (c == '1' || c == '?') {
                bitset<200005> rev0, rev1;

                for (int i = 0; i < size; i++) {
                    rev0[i] = dp0[size - 1 - i];
                    rev1[i] = dp1[size - 1 - i];
                }

                new1 |= rev0;
                new0 |= rev1;
            }

            dp0 = new0;
            dp1 = new1;
        }

        ll inv2x = modpow((2 * x) % MOD, MOD - 2);
        ll ans = 0;

        for (int j = -n; j <= n; j++) {
            int idx = j + offset;

            if (dp0[idx] || dp1[idx]) {
                for (int k = 0; k <= 1; k++) {
                    if ((k == 0 && dp0[idx]) || (k == 1 && dp1[idx])) {
                        ll cn = (((j % MOD + MOD) % MOD) * x) % MOD;
                        if (k == 1) cn = (cn + y) % MOD;

                        ll val = (cn * cn) % MOD;
                        val = (val + ((x - y + MOD) % MOD) * cn) % MOD;
                        val = (val + ((ll)n * x % MOD * y % MOD)) % MOD;
                        val = val * inv2x % MOD;

                        ans = (ans + val) % MOD;
                    }
                }
            }
        }

        cout << ans << "\n";
    }
}