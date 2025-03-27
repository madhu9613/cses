#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // Using only two pairs instead of full DP table to save memory
        long long prev0 = 1, prev1 = 1, cur0, cur1;
        
        for (int i = n - 1; i >= 1; i--) {
            cur0 = (2LL * prev0 + prev1) % MOD;
            cur1 = (4LL * prev1 + prev0) % MOD;
            
            prev0 = cur0;
            prev1 = cur1;
        }
        
        cout << (prev0 + prev1) % MOD << endl;
    }
    
    return 0;
}
