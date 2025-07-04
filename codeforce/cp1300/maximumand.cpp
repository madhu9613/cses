#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_BITS = 31;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        int initial_and = (1LL << MAX_BITS) - 1;  
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            initial_and &= a[i]; 
        }

        vector<int> bitCount(MAX_BITS, 0);

        for (int x : a) {
            for (int b = 0; b < MAX_BITS; ++b) {
                if (x & (1LL << b)) {
                    bitCount[b]++;
                }
            }
        }

        // Try to maximize the AND by setting bits that can be made common using <= k operations
        for (int b = MAX_BITS - 1; b >= 0; --b) {
            if (bitCount[b] + k >= n && bitCount[b] != n) {
                initial_and |= (1LL << b);  
                k -= (n - bitCount[b]);    
            }
        }

        cout << initial_and << '\n';
    }

    return 0;
}
