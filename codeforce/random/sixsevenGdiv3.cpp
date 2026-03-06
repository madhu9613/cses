#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 4e18;

map<vector<ll>, ll> memo;

ll f(vector<ll> a) {
    if (a.empty()) return 0;

    sort(a.begin(), a.end());
    if (memo.count(a)) return memo[a];

    ll ans = INF;

    for (int k = 0; k < 42; k++) {

        vector<ll> b;
        bool ok = true;

        for (ll x : a) {
            ll val = x + k;

            if (val % 42 != 0) {
                if (val % 6 != 0) {
                    ok = false;
                    break;
                }
            }
            else {
                b.push_back(val / 42);
            }
        }

        if (!ok) continue;

        ll sub = f(b);
        if (sub == INF) continue;

        ans = min(ans, 42LL * sub + k);
    }

    return memo[a] = ans;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    memo.clear();

    ll res = f(a);

    if (res == INF) cout << -1 << "\n";
    else cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}