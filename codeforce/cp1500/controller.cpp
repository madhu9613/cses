#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int p = count(s.begin(), s.end(), '+');
    int m = n - p;
    ll tot = p - m;

    int q;
    cin >> q;
    while (q--) {
        ll x, y;
        cin >> x >> y;

        if(tot == 0) {
            cout << "YES\n";
            continue;
        }

        if(x == y) {
            cout << "NO\n";
            continue;
        }

        if((tot * y) % (y - x) != 0) {
            cout << "NO\n";
            continue;
        }

        ll k = (tot * y) / (y - x);
        if(k >= -m && k <= p)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
