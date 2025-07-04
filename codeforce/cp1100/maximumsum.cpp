#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        sort(arr.begin(), arr.end());

        int total_sum = accumulate(arr.begin(), arr.end(), 0LL);

        // prefix_sum[i] = sum of first i elements
        vector<int> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + arr[i];
        }

        // suffix_sum[i] = sum of last i elements
        vector<int> suffix_sum(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix_sum[n - i] = suffix_sum[n - i - 1] + arr[i];
        }

        int ans = 0;
        for (int x = 0; x <= k; x++) {
            int y = k - x;
            if (2 * x > n || y > n) continue;

            int deleted = prefix_sum[2 * x] + suffix_sum[y];
            int remaining = total_sum - deleted;
            ans = max(ans, remaining);
        }

        cout << ans << '\n';
    }

    return 0;
}
