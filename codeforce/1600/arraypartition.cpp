#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define endl '\n'

const ll LINF = (ll)2e18;

void solve() {
    int n, q;
    cin >> n >> q;

    vll dp(n + 1, 0);
    vll last(n + 1, 0);      
    vi rep_pos;              

    bool track = true;

    for (int i = 1; i <= n; i++) {
        int type;
        ll x;
        cin >> type >> x;

        if (type == 1) {
            dp[i] = min(LINF, dp[i - 1] + 1);
            last[i] = x;
        }
        else {
            dp[i] = (dp[i - 1] > LINF / (x + 1))
                ? LINF
                : dp[i - 1] * (x + 1);
            last[i] = last[i - 1];

            if (track)
                rep_pos.push_back(i);
        }

        if (dp[i] == LINF)
            track = false;
    }

    while (q--) {
        ll k;
        cin >> k;

        for (int i = (int)rep_pos.size() - 1; i >= 0; i--) {
            int idx = rep_pos[i];

            if (dp[idx] > k && dp[idx - 1] < k) {
                if (k % dp[idx - 1] == 0) {
                    k = dp[idx - 1];
                    break;
                }
                k %= dp[idx - 1];
            }
        }

        int pos = lower_bound(dp.begin() + 1, dp.begin() + n + 1, k) - dp.begin();
        cout << last[pos] << " ";
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
