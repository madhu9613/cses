#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

// Check if 1 + k + k^2 + ... + k^i == n safely without overflow
bool check(ll n, ll k, int i) {
    ll sum = 1;
    ll term = 1;
    for (int j = 0; j < i; j++) {
        if (term > (n - sum) / k) return false; 
        term *= k;
        sum += term;
    }
    return sum == n;
}

void solve() {
    ll n;
    cin >> n;

    if (n == 1) {
        cout << "NO" << endl;
        return;
    }

    for (int i = 2; i <= 60; i++) {
        ll low = 2;
        ll high = pow(n * 1.0, 1.0 / i) + 1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (check(n, mid, i)) {
                cout << "YES" << endl;
                return;
            }
            ll sum = 1, term = 1;
            bool overflow = false;
            for (int j = 0; j < i; j++) {
                if (term > (n - sum) / mid) { overflow = true; break; }
                term *= mid;
                sum += term;
            }

            if (overflow || sum > n) high = mid - 1;
            else low = mid + 1;
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
