#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return a[i] > a[j];
        });

    
    vector<vector<int>> mn(m, vector<int>(n + 1, n));

    for (int i = 0; i < m; i++) {
        int r = 0;
        for (int l = 0; l < n; l++) {
            r = max(r, l);  

            while (r < n && 1LL * a[ord[r]] * (r - l + 1) < b[i]) {
                r++;
            }

            mn[i][l] = r;  
        }
    }

    int FULL = (1 << m);
    vector<int> dp(FULL, n + 1);
    vector<int> parent(FULL, -1);

    dp[0] = 0; 

    for (int mask = 0; mask < FULL; mask++) {
        if (dp[mask] > n) continue;

        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) continue;

            int l = dp[mask];
            if (l < n && mn[i][l] < dp[mask | (1 << i)]) {
                dp[mask | (1 << i)] = mn[i][l] + 1;
                parent[mask | (1 << i)] = mask;
            }
        }
    }

    if (dp[FULL - 1] > n) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<vector<int>> ans(m);
    int mask = FULL - 1;

    while (mask) {
        int prev = parent[mask];
        int proj = __builtin_ctz(mask ^ prev);

        for (int i = dp[prev]; i < dp[mask]; i++) {
            ans[proj].push_back(ord[i] + 1); // +1 for 1-based output
        }
        mask = prev;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i].size();
        for (int x : ans[i]) cout << " " << x;
        cout << "\n";
    }

    return 0;
}
