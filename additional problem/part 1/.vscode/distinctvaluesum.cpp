#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int &val : x) cin >> val;

    // unordered_map<int, int> last_occurrence;
    // ll ans = 0;
    // int l = 0;

    // for (int r = 0; r < n; ++r) {
    //     if (last_occurrence.count(x[r])) {
    //         l = max(l, last_occurrence[x[r]] + 1);
    //     }
    //     ans += (r - l + 1);f
    //     last_occurrence[x[r]] = r;
    // }

    // This counts subarrays with all distinct elements

    // But we need sum over all subarrays of number of distinct elements

    // Correct optimized approach:

    
    unordered_map<int, int> last;
    ll res = 0;
    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        int p = -1;
        if (last.count(x[i])) p = last[x[i]];
        cur += (i - p);
        res += cur;
        last[x[i]] = i;
    }
    cout << res << "\n";
}
