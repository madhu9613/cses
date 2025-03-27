/**need to review this
 * its ordered pair ...
 */

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // dp[i] will store the number of ways to form sum i
    vector<int> dp(x + 1, 0);
    dp[0] = 1;  // There's one way to form 0 sum, which is by using no coins.

    // Process each coin
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
        }
    }

    // The result is the number of ways to form sum x
    for(int i=0;i<x+1;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    cout << dp[x] << endl;

    return 0;
}
