#include <bits/stdc++.h>
using namespace std;
// very good queation  remember it forever
#define int long long
const int mxN = 1 << 21; // 2^21 = 2097152

int freq[mxN]; // Frequency array

// Recursive function to count numbers y such that x | y = x
int countNumbers(int x, int bit) {
    if (bit < 0) return freq[x]; // Base case: If no more bits, return frequency of x

    int ans = countNumbers(x, bit - 1); // Include numbers where this bit stays the same

    // If the `bit` position is set in `x`, check numbers where this bit was flipped
    if (x & (1 << bit)) {
        ans += countNumbers(x ^ (1 << bit), bit - 1);
    }

    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        freq[x]++;
    }

    // Compute results for each number
    for (int i = 0; i < n; i++) {
        cout << countNumbers(a[i], 20) << endl;
    }

    return 0;
}
