#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    int n, q;
    cin >> n >> q;
    vll a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    ll def = -1;
    vector<bool> ischanged(n, false);

    while (q--) {
        int type;
        cin >> type;

        if (type == 2) {
            int x;
            cin >> x;
            sum = 1LL * n * x;
            def = x;
            fill(ischanged.begin(), ischanged.end(), false);
            cout << sum << endl;
        } else {
            int i, x;
            cin >> i >> x;
            i--; // convert to 0-based

            if (def == -1) {
                sum -= a[i];
                sum += x;
                a[i] = x;
                cout << sum << endl;
            } else {
                if (!ischanged[i]) {
                    sum -= def;
                } else {
                    sum -= a[i];
                }
                sum += x;
                a[i] = x;
                ischanged[i] = true;
                cout << sum << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}
