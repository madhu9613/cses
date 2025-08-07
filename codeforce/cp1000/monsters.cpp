#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> monsters;

    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        ll rem = x % k;
        if (rem == 0) rem = k;
        monsters.pb({rem, -i});  
    }

    sort(all(monsters), greater<>());  

    for (auto [rem, idx] : monsters) {
        cout << -idx << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
