#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int n, m;
vector<int> arr;
vector<vector<int>> dp;

int solve(int i, int prev_value) {
    // Base case: If we filled all elements, return 1 valid array
    if (i == n) return 1;

    // Check memoization table
    if (dp[i][prev_value] != -1) return dp[i][prev_value];

    int count = 0;
    
    // If the current value is fixed
    if (arr[i] != 0) {
        if (abs(arr[i] - prev_value) > 1) return dp[i][prev_value] = 0;
        return dp[i][prev_value] = solve(i + 1, arr[i]);
    }

    // If current value is unknown, try all valid values
    for (int val = max(1, prev_value - 1); val <= min(m, prev_value + 1); val++) {
        count = (count + solve(i + 1, val)) % MOD;
    }

    return dp[i][prev_value] = count;
}

int main() {
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Memoization table initialized to -1
    dp.assign(n, vector<int>(m + 1, -1));

    int result = 0;
    if (arr[0] == 0) {
        for (int j = 1; j <= m; j++) {
            result = (result + solve(1, j)) % MOD;
        }
    } else {
        result = solve(1, arr[0]);
    }

    cout << result << endl;
    return 0;
}
