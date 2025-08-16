#include <bits/stdc++.h>
using namespace std;

int n, m;
bool adj[16][16];
bool independentSet[1 << 16];
int dp[1 << 16], choice[1 << 16];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    memset(adj, 0, sizeof(adj));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a][b] = adj[b][a] = true;
    }

    // Precompute independent sets
    for (int mask = 0; mask < (1 << n); mask++) {
        bool ok = true;
        for (int i = 0; i < n && ok; i++) {
            if (!(mask & (1 << i))) continue;
            for (int j = i + 1; j < n; j++) {
                if ((mask & (1 << j)) && adj[i][j]) {
                    ok = false;
                    break;
                }
            }
        }
        independentSet[mask] = ok;
    }

    // DP
    dp[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = n + 1; // large
        int sub = mask;
        while (sub) {
            if (independentSet[sub]) {
                if (1 + dp[mask ^ sub] < dp[mask]) {
                    dp[mask] = 1 + dp[mask ^ sub];
                    choice[mask] = sub;
                }
            }
            sub = (sub - 1) & mask; // iterate subsets
        }
    }

    cout << dp[(1 << n) - 1] << "\n";

    // Reconstruct coloring
    vector<int> color(n, 0);
    int curMask = (1 << n) - 1, c = 1;
    while (curMask) {
        int sub = choice[curMask];
        for (int i = 0; i < n; i++) {
            if (sub & (1 << i)) color[i] = c;
        }
        curMask ^= sub;
        c++;
    }

    for (int i = 0; i < n; i++) cout << color[i] << " ";
    cout << "\n";

    return 0;
}
