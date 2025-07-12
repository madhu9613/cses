#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> rem(m, 0); // Count frequency of each remainder

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            rem[a[i] % m]++;
        }

        int ans = 0;

        if (rem[0] > 0) ans++; // Only one zero remainder allowed

        for (int r = 1; r <= m / 2; r++) {
            int x = rem[r];
            int y = rem[m - r];

            if (r == m - r) {
                // Special case: only one group, like rem[2] and rem[2] when m=4
                if (x > 0) ans++;
            } else {
                if (x == 0 && y == 0) continue;
                int mini = min(x, y);
                int maxi = max(x, y);
                if (maxi <= mini + 1)
                    ans += 1;
                else
                    ans += maxi - (mini + 1) + 1;
            }

            // Mark both as processed
            rem[r] = 0;
            rem[m - r] = 0;
        }

        cout << ans << "\n";
    }

    return 0;
}
