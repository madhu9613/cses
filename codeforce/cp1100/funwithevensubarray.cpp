#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        int i = n - 2;
        int count = 1; // Number of trailing elements equal to a[n-1]

        while (i >= 0) {
            if (a[i] == a[n - 1]) {
                count++;
                i--;
            } else {
                ans++;
                i -= count;
                count *= 2;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
