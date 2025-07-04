#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll getSum(ll k, ll m) {
    if (m <= k) {
        return m * (m + 1) / 2;
    } else {
        ll d = m - k;
        ll sum1 = k * (k + 1) / 2;
        ll sum2 = d * (2 * k - 1 - d) / 2;
        return sum1 + sum2;
    }
}
 
void solve() {
    int t;
    cin >> t;
    while (t--) {
        ll k, x;
        cin >> k >> x;
        ll l = 1, r = 2 * k - 1, ans = 2 * k - 1;
        while (l <= r) {
            ll m = (l + r) / 2;
            if (getSum(k, m) >= x) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << ans << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}