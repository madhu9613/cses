#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;


int32_t main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);  // 1-based indexing: a[1..n]
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> dp(n + 1, 0);        // dp[i] = number of ways to split a[1..i]
    vector<int> prefix(n + 2, 0);    // prefix[i] = dp[0] + ... + dp[i - 1]
    unordered_map<int, int> freq;    // frequency of elements in current window

    dp[0] = 1;
    prefix[1] = 1;

    int l = 1;  // sliding window left pointer

    for (int r = 1; r <= n; ++r) {
        freq[a[r]]++;

        // shrink window from the left to remove duplicates
        while (freq[a[r]] > 1) {
            freq[a[l]]--;
            l++;
        }

        // dp[r] = sum of dp[l-1] to dp[r-1] = prefix[r] - prefix[l-1]
        dp[r] = (prefix[r] - prefix[l - 1] + MOD) % MOD;

        // update prefix sum for next step
        prefix[r + 1] = (prefix[r] + dp[r]) % MOD;
    }

    cout << dp[n] << '\n';
    return 0;
}
