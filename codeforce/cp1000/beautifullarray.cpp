#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;

    ll min_sum = b * k;
    ll max_sum = b * k + (k - 1) * n;

    if (s < min_sum || s > max_sum) {
        cout << -1 << endl;
        return;
    }

    vll a(n, 0);
    a[0] = min(s, b * k + (k - 1)); 

    s -= a[0];

    for (int i = 1; i < n; i++) {
        if (s == 0) break;
        ll give = min(s, k - 1);  
        a[i] = give;
        s -= give;
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
