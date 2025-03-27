#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int solve(int target, vector<int> &coins, vector<int> &dp) {
    if (target == 0) {
        return 1; // One way to make sum 0
    }
    if (target < 0) {
        return 0; // No way to make negative sum
    }
    if (dp[target] != -1) {
        return dp[target]; // Return cached result
    }

    int ways = 0;
    for (int c : coins) {
        ways = (ways + solve(target - c, coins, dp)) % MOD;
    }
    return dp[target] = ways;
}

// -- we need ordered pair 
int solveordered(int target, vector<int> &coins, vector<int> &dp) {
    if (target == 0) {
        return 1; // One way to make sum 0
    }

    // if (target < 0) {
    //     return 0; // No way to make negative sum
    // }


    if (dp[target] != -1) {
        return dp[target]; // Return cached result
    }

    int ways = 0;
    for (int c : coins) {
        if(target>=c)
        {
        ways = (ways + solveordered(target - c, coins, dp)) % MOD;
    }
    }
    return dp[target] = ways;
}
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, -1); // Initialize memo table with -1
    int ans = solveordered(x, coins, dp);
    cout << ans << endl;

    return 0;
}
