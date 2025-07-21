#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, int> freq;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }

    ll ans = 1;
    for (auto [val, count] : freq) {
        ans = (ans * (count + 1)) % MOD;
    }

    // Subtract 1 to exclude empty subsequence
    ans = (ans - 1 + MOD) % MOD;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t; 
    while (t--) solve();

    return 0;
}
