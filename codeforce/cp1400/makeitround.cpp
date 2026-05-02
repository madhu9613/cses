#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll powerOfPrime(ll n, ll p) {
    ll cnt = 0;
    while (n % p == 0) {
        cnt++;
        n /= p;
    }
    return cnt;
}

void solve() {
  ll n, m; cin >> n >> m;
        ll orig = n;
        int c2 = 0, c5 = 0;
        ll tmp = n;
        while (tmp % 2 == 0) { c2++; tmp /= 2; }
        tmp = n;
        while (tmp % 5 == 0) { c5++; tmp /= 5; }

        ll k = 1;
        while (c2 < c5 && k * 2 <= m) {
            k *= 2;
            c2++;
        }
        while (c5 < c2 && k * 5 <= m) {
            k *= 5;
            c5++;
        }
        while (k * 10 <= m) k *= 10;

        k *= (m / k);

        cout << orig * k << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
