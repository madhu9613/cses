#include <bits/stdc++.h>
#define ll long long
const int MOD = 1e9 + 7;
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;
    if (sum % 2 == 1) {
        cout << 0 << endl;
    } else {
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;  // Base case

        for (int i = 1; i <= n; i++) {
            for (int t = target; t >= i; t--) {
                dp[t] = (dp[t] + dp[t - i]) % MOD;
            }
        }

        int inverse_2 = (MOD + 1) / 2;
        cout << 1LL * dp[target] * inverse_2 % MOD << endl;
    }

    return 0;
}
