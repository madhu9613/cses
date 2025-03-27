#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> prefix(n + 1, 0); // Prefix sum array initialized to 0

    // Build the prefix sum array
    for (int i = 1; i <= n; i++) {
        long long d;
        cin >> d;
        prefix[i] = prefix[i - 1] + d;
    }

    // Process each query
    vector<long long> result;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        // Compute sum for the range [a, b]
        long long ans = prefix[b] - prefix[a - 1];
        result.push_back(ans);
    }

    // Output results
    for (long long i : result) {
        cout << i << endl;
    }

    return 0;
}
