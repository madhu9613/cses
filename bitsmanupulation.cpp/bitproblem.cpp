#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1 << 21; // Max limit for bitwise operations
int freq[mxN];
int dp1[mxN][21], dp2[mxN][21];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n];

    // Read input and update frequency array
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        freq[x]++;
    }

    // Precompute dp1: Counting for x | y = x
    // from i=1 to 1023
    for (int i = 1; i < mxN >> 1; i++) {
        dp1[i][0] = freq[i];
        //if this is set bit then we add the elenets count if its flip also present 
        if (i & 1)
            dp1[i][0] += freq[i ^ 1];// Adding complement if needed
        
        for (int k = 1; k < 21; k++) {
            dp1[i][k] = dp1[i][k - 1];
            if (i >> k & 1)
                dp1[i][k] += dp1[i ^ (1 << k)][k - 1];
        }
    }

    // Precompute dp2: Counting for x & y = x
    for (int i = mxN >> 1; i > 0; i--) {
        dp2[i][0] = freq[i];
        if ((i & 1) == 0) // Ensure even check
            dp2[i][0] += freq[i ^ 1];

        for (int k = 1; k < 21; k++) {
            dp2[i][k] = dp2[i][k - 1];
            if ((i >> k & 1) == 0)
                dp2[i][k] += dp2[i ^ (1 << k)][k - 1];
        }
    }

    // Print results for each element in a[]
    for (int i = 0; i < n; i++) {
        cout << dp1[a[i]][20] << ' ' << dp2[a[i]][20] << ' '
             << (n - dp1[a[i] ^ ((mxN >> 1) - 1)][20]) << endl;
    }

    return 0;
}
