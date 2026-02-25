#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll get(const vector<ll>& v, ll need) {
    ll res = 0;
    for (ll len : v)
        if (len >= need) res += (len - need + 1);
    return res;
}

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    vector<ll> cnta, cntb;

    // runs in a
    for (int i = 0; i < n; ) {
        if (a[i] == 0) { i++; continue; }
        int j = i;
        while (j < n && a[j] == 1) j++;
        cnta.push_back(j - i);
        i = j;
    }

    // runs in b
    for (int i = 0; i < m; ) {
        if (b[i] == 0) { i++; continue; }
        int j = i;
        while (j < m && b[j] == 1) j++;
        cntb.push_back(j - i);
        i = j;
    }

    ll ans = 0;

    for (ll h = 1; h * h <= k; h++) {
        if (k % h == 0) {
            ll w = k / h;

            ans += get(cnta, h) * get(cntb, w);
            if (h != w)
                ans += get(cnta, w) * get(cntb, h);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
