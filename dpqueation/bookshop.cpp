#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    // Base Case: If only the first book is available
    
    for (int j = 0; j <= x; j++) {
        if (price[0] <= j) dp[0][j] = pages[0];
    }

    // Fill DP table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            // Exclude book i
            dp[i][j] = dp[i - 1][j];

            // Include book i if possible
            if (price[i] <= j) {
                dp[i][j] = max(dp[i][j], pages[i] + dp[i - 1][j - price[i]]);
            }
        }
    }

    cout << dp[n - 1][x] << endl; // Maximum pages we can get
    return 0;
}
