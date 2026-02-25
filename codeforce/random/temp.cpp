#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<ll>> h(n, vector<ll>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> h[i][j];

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int j = 0; j < n; j++) cin >> b[j];

        auto solve_line = [&](bool is_row) -> ll {
            int m = n;
            vector<vector<bool>> allowed(m - 1, vector<bool>(3, true));
            // 0 => -1, 1 => 0, 2 => +1

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - 1; j++) {

                    ll d;
                    if (is_row)
                        d = h[j][i] - h[j + 1][i];
                    else
                        d = h[i][j] - h[i][j + 1];

                    if (d >= -1 && d <= 1) {
                        allowed[j][d + 1] = false;
                    }
                }
            }

            vector<vector<ll>> dp(m, vector<ll>(2, INF));
            dp[0][0] = 0;
            dp[0][1] = is_row ? a[0] : b[0];

            for (int i = 0; i < m - 1; i++) {
                for (int cur = 0; cur <= 1; cur++) {
                    if (dp[i][cur] == INF) continue;

                    for (int nxt = 0; nxt <= 1; nxt++) {
                        int diff = nxt - cur;
                        if (allowed[i][diff + 1]) {
                            ll cost = dp[i][cur] + (nxt ? (is_row ? a[i + 1] : b[i + 1]) : 0);
                            dp[i + 1][nxt] = min(dp[i + 1][nxt], cost);
                        }
                    }
                }
            }

            return min(dp[m - 1][0], dp[m - 1][1]);
            };

        ll row_cost = solve_line(true);
        ll col_cost = solve_line(false);

        if (row_cost == INF || col_cost == INF)
            cout << -1 << "\n";
        else
            cout << row_cost + col_cost << "\n";
    }
}
