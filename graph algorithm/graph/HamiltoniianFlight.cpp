// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr1(i, n) for (ll i = 0; i < n; i++)
#define fr2(i, k, n) for (ll i = k; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

int n, m;
vector<vi> adj;
ll dp[1 << 20][20]; // dp[mask][u]: number of ways to reach city u with visited mask

void solve() {
    cin >> n >> m;
    adj.assign(n, vi()); // reset adjacency list

    fr1(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--; // convert to 0-based
        adj[a].pb(b);
    }

    dp[1][0] = 1; // start from city 0 with only city 0 visited

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            if (dp[mask][u] == 0) continue; // skip if no path ends at u with mask

            for (int v : adj[u]) {
                if (mask & (1 << v)) continue; // already visited
                int new_mask = mask | (1 << v);
                dp[new_mask][v] = (dp[new_mask][v] + dp[mask][u]) % MOD;
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}
