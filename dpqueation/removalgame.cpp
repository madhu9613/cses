// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//     int n;
//     cin >> n;
//     vector<ll> x(n);
//     for (int i = 0; i < n; ++i) cin >> x[i];

//     vector<vector<ll>> dp(n, vector<ll>(n));


//     // here dp[l][r]=>maximum difference current player archieeve if alice pick x[l] then he will try then its not it 
//     // Loop for increasing l from n-1 to 0
//     for (int l = n - 1; l >= 0; --l) {
//         for (int r = l; r < n; ++r) {
//             if (l == r) {
//                 dp[l][r] = x[l];  // base case
//             } else {
//                 dp[l][r] = max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
//             }
//         }
//     }

//     ll totalSum = accumulate(x.begin(), x.end(), 0LL);
//     ll firstPlayer = (dp[0][n - 1] + totalSum) / 2;
//     cout << firstPlayer << endl;

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + x[i];
    }

    auto rangeSum = [&](int l, int r) -> ll {
        return prefix[r + 1] - prefix[l];
    };

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (int l = n - 1; l >= 0; --l) {
        for (int r = l; r < n; ++r) {
            if (l == r) {
                dp[l][r] = x[l];
            } else {
                dp[l][r] = max(
                    x[l] + (rangeSum(l + 1, r) - dp[l + 1][r]),
                    x[r] + (rangeSum(l, r - 1) - dp[l][r - 1])
                );
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}
