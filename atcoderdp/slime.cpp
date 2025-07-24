// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (int l = n - 1; l >= 0; --l) {
        for (int r = l; r < n; ++r) {
            if (l == r) {
                dp[l][r] = 0;
                continue;
            }

            dp[l][r] = INF;
            for (int k = l; k < r; ++k) {
                ll cost = dp[l][k] + dp[k + 1][r] + prefix[r + 1] - prefix[l];
                dp[l][r] = min(dp[l][r], cost);
            }
        }
    }

    cout << dp[0][n - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
