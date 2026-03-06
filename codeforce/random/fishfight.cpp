#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1000000007;
const int MAXN = 3005;

ll dpA[MAXN][MAXN], dpB[MAXN][MAXN];
ll prefB[MAXN], a[MAXN], b[MAXN];

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll modinv(ll x) {
    return modpow(x, MOD - 2);
}

void solve() {

    int n, x, y;
    cin >> n >> x >> y;

    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) cin >> b[i];

    prefB[0] = 0;
    for (int i = 1;i <= n;i++)
        prefB[i] = prefB[i - 1] + b[i];

    memset(dpA, 0, sizeof(dpA));
    memset(dpB, 0, sizeof(dpB));

    dpA[x][x] = 1;
    dpB[y][y] = 1;

    // Phase-1 DP for Alice
    for (int len = 1;len <= n;len++) {
        for (int l = 1;l + len - 1 <= n;l++) {

            int r = l + len - 1;
            if (!(l <= x && x <= r)) continue;

            ll prob = dpA[l][r];
            if (!prob) continue;

            ll size = a[x] + (prefB[r] - prefB[l - 1] - b[x]);

            bool left = (l > 1 && size >= a[l - 1]);
            bool right = (r < n && size >= a[r + 1]);

            int cnt = left + right;
            if (cnt == 0) continue;

            ll inv = modinv(cnt);

            if (left)
                dpA[l - 1][r] = (dpA[l - 1][r] + prob * inv) % MOD;

            if (right)
                dpA[l][r + 1] = (dpA[l][r + 1] + prob * inv) % MOD;
        }
    }

    // Phase-1 DP for Bob
    for (int len = 1;len <= n;len++) {
        for (int l = 1;l + len - 1 <= n;l++) {

            int r = l + len - 1;
            if (!(l <= y && y <= r)) continue;

            ll prob = dpB[l][r];
            if (!prob) continue;

            ll size = a[y] + (prefB[r] - prefB[l - 1] - b[y]);

            bool left = (l > 1 && size >= a[l - 1]);
            bool right = (r < n && size >= a[r + 1]);

            int cnt = left + right;
            if (cnt == 0) continue;

            ll inv = modinv(cnt);

            if (left)
                dpB[l - 1][r] = (dpB[l - 1][r] + prob * inv) % MOD;

            if (right)
                dpB[l][r + 1] = (dpB[l][r + 1] + prob * inv) % MOD;
        }
    }

    ll ans = 0;

    // When Bob dies in Phase-1
    for (int lb = 1;lb <= n;lb++) {
        for (int rb = lb;rb <= n;rb++) {

            if (!(lb <= y && y <= rb)) continue;

            ll probB = dpB[lb][rb];
            if (!probB) continue;

            ll size = a[y] + (prefB[rb] - prefB[lb - 1] - b[y]);

            bool left = (lb > 1 && size >= a[lb - 1]);
            bool right = (rb < n && size >= a[rb + 1]);

            if (left || right) continue; // Bob still alive

            // Bob dies here

            int k = rb - lb; // Bob turns
            int need = k + 1; // Alice turns

            for (int la = 1;la <= n;la++) {
                int ra = la + need;
                if (ra > n) break;

                if (!(la <= x && x <= ra)) continue;

                if (ra <= lb - 2 || la >= rb + 2) {
                    ans = (ans + probB * dpA[la][ra]) % MOD;
                }
            }
        }
    }

    cout << ans % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}