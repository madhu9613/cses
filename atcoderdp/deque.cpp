#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
 
    vector<vector<ll>> dp(n, vector<ll>(n));
 
 
    // here dp[l][r]=>maximum difference current player archieeve if alice pick x[l] then he will try then its not it 
    // Loop for increasing l from n-1 to 0
    for (int l = n - 1; l >= 0; --l) {
        for (int r = l; r < n; ++r) {
            if (l == r) {
                dp[l][r] = x[l];  // base case
            } else {
                dp[l][r] = max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
            }
        }
    }
 
  cout<<dp[0][n-1];
    return 0;
}
