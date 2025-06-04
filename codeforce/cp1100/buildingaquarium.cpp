#include <bits/stdc++.h>
#define int long long
using namespace std;

bool verify(int h, vector<int> &a, int x) {
    long long sum = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < h) {
            sum += (h - a[i]);
        }
    }
    return sum <= x;
}

int32_t main() {
    int t; cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> ar(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
            sum += ar[i];
        }

        int low = 1;
        int high = (x + sum) / n;
        int ans = low;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (verify(mid, ar, x)) {
                ans = mid; // try for a higher valid height
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
