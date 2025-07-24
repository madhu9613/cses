#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

// Sum of first k numbers: 1 + 2 + ... + k
int sum_upto(int k) {
    k %= MOD;
    return (k * (k + 1) / 2) % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    int i = 1;

    while (i <= n) {
        int val = n / i;
        int j = n / val;

        // i to j all have floor(n/d) = val
        int sum_d = (sum_upto(j) - sum_upto(i - 1) + MOD) % MOD;

        ans = (ans + val % MOD * sum_d % MOD) % MOD;

        i = j + 1;
    }

    cout << ans << '\n';
    return 0;
}
