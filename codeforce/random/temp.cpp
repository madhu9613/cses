#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int dp[31][31][51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int n = 1;n <= 30;n++) {
        for (int m = 1;m <= 30;m++) {

            for (int k = 0;k <= 50;k++) {

                if (k == 0 || k == n * m) {
                    dp[n][m][k] = 0;
                    continue;
                }

                dp[n][m][k] = INF;

                // vertical cuts
                for (int i = 1;i < m;i++) {
                    for (int x = 0;x <= k;x++) {
                        if (x <= n * i && k - x <= n * (m - i)) {
                            dp[n][m][k] = min(
                                dp[n][m][k],
                                n * n + dp[n][i][x] + dp[n][m - i][k - x]
                            );
                        }
                    }
                }

                // horizontal cuts
                for (int i = 1;i < n;i++) {
                    for (int x = 0;x <= k;x++) {
                        if (x <= i * m && k - x <= (n - i) * m) {
                            dp[n][m][k] = min(
                                dp[n][m][k],
                                m * m + dp[i][m][x] + dp[n - i][m][k - x]
                            );
                        }
                    }
                }
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << dp[n][m][k] << "\n";
    }

    return 0;
}