#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

ll cal(vi &a) {
    sort(all(a));
    ll res = 0;
    int k = a.size();
    for (int i = 0; i < k; i++) {
        res += 1LL * a[i] * (2LL * i - k + 1);
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    map<int, vi> row, col;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c;
            cin >> c;
            row[c].push_back(i);
            col[c].push_back(j);
        }
    }

    ll ans = 0;
    for (auto &[color, rlist] : row) {
        ans += cal(rlist);         
        ans += cal(col[color]);   
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
