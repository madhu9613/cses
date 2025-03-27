#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int target;
    cin >> target;
    
    vector<int> dp(target + 1, 0);
    dp[0] = 1;  // There is one way to achieve sum 0: do nothing.

    for (int i = 1; i <= target; i++) {
        for (int dice = 1; dice <= 6; dice++) {
            if (i >= dice) {
                dp[i] = (dp[i] + dp[i - dice]) % MOD;
            }
        }
    }

    cout << dp[target] << endl;
    return 0;
}
