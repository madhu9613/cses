#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll stabilize(ll x) {
    if (x % 10 == 0) return x;
    if (x % 10 == 5) return x + 5;


    while (x % 10 != 2) {
        x += x % 10;
    }
    return x % 20;
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bool has05 = false;
    for (ll x : a) {
        if (x % 10 == 0 || x % 10 == 5) {
            has05 = true;
            break;
        }
    }

    if (has05) {
        for (ll &x : a) {
            if (x % 10 == 5) x += 5; 
        }
        if (all_of(a.begin(), a.end(), [&](ll v){ return v == a[0]; }))
            cout << "Yes\n";
        else
            cout << "No\n";
    } else {
        vector<ll> b;
        for (ll x : a) b.push_back(stabilize(x));
        if (all_of(b.begin(), b.end(), [&](ll v){ return v == b[0]; }))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

