#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    ll x, a, b, c;
    cin >> n >> k;
    cin >> x >> a >> b >> c;

    vector<ll> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; ++i) {
        arr[i] = (a * arr[i - 1] + b) % c;
    }

    vector<ll> prefix(n), suffix(n);
    
    // Process each block of size k
    for (int i = 0; i < n; i += k) {
        int block_end = min(n, i + k);
        
        // Prefix OR in block
        prefix[i] = arr[i];
        for (int j = i + 1; j < block_end; ++j) {
            prefix[j] = prefix[j - 1] | arr[j];
        }

        // Suffix OR in block
        suffix[block_end - 1] = arr[block_end - 1];
        for (int j = block_end - 2; j >= i; --j) {
            suffix[j] = suffix[j + 1] | arr[j];
        }
    }

    // Calculate result by combining prefix[i] | suffix[i - k + 1]
    ll result = 0;
    for (int i = k - 1; i < n; ++i) {
        result ^= (prefix[i] | suffix[i - k + 1]);
    }

    cout << result << "\n";
    return 0;
}
