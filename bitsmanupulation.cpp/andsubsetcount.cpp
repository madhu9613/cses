#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int MAX_BITS = 18;
const int MAX_MASK = 1 << MAX_BITS;

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> freq(MAX_MASK, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }

    // f[mask] = number of elements a[i] such that (a[i] & mask) == mask
    vector<int> f(freq);
    for (int i = 0; i < MAX_BITS; ++i) {
        for (int mask = 0; mask < MAX_MASK; ++mask) {
            if ((mask & (1 << i)) == 0) {
                f[mask] += f[mask | (1 << i)];
                if (f[mask] >= MOD) f[mask] -= MOD;
            }
        }
    }

    // res[mask] = number of subsets with AND == mask
    vector<int> res(MAX_MASK, 0);
    for (int mask = 0; mask < MAX_MASK; ++mask) {
        if (f[mask] > 0) {
            res[mask] = (power(2, f[mask]) - 1 + MOD) % MOD;
        }
    }

    // Inclusion-Exclusion (Möbius Inversion on superset lattice)
    for (int i = 0; i < MAX_BITS; ++i) {
        for (int mask = 0; mask < MAX_MASK; ++mask) {
            if ((mask & (1 << i)) == 0) {
                res[mask] = (res[mask] - res[mask | (1 << i)] + MOD) % MOD;
            }
        }
    }

    // Print answers for k = 0 to n
    for (int k = 0; k <= n; ++k) {
        cout << res[k] << " ";
    }
    cout << "\n";
    return 0;
}
