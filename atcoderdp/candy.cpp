#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1); // 1-based indexing
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    vector<vector<int>> prefix(n + 1, vector<int>(k + 1, 0));

    // Base Case:
    dp[0][0] = 1;
    prefix[0][0] = 1;
    for (int j = 1; j <= k; ++j)
        prefix[0][j] = 1; // since dp[0][j>0] = 0, so prefix is just prefix[0][j-1]

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            int left = j - a[i] - 1;
            int add = prefix[i - 1][j];
            int sub = (left >= 0) ? prefix[i - 1][left] : 0;
            dp[i][j] = (add - sub + MOD) % MOD;

            if (j == 0)
                prefix[i][j] = dp[i][j];
            else
                prefix[i][j] = (prefix[i][j - 1] + dp[i][j]) % MOD;
        }
    }

    cout << dp[n][k] << '\n';
}
