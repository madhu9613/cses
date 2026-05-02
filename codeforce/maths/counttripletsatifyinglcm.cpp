#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e6 + 5;
int spf[MAXN];

// compute SPF
void compute() {
    for (int i = 1; i < MAXN; i++) spf[i] = i;

    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) { // FIXED
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

// factorization using SPF
map<int, int> factor(int x) {
    map<int, int> f;
    while (x > 1) {
        f[spf[x]]++;
        x /= spf[x];
    }
    return f;
}

void solve() {
    int x, y, z;
    cin >> x >> y >> z;

    auto fx = factor(x);
    auto fy = factor(y);
    auto fz = factor(z);

    set<int> primes;
    for (auto& p : fx) primes.insert(p.first);
    for (auto& p : fy) primes.insert(p.first);
    for (auto& p : fz) primes.insert(p.first);

    ll ans = 1;

    for (auto p : primes) {
        int X = fx[p];
        int Y = fy[p];
        int Z = fz[p];

        int mx = max({ X, Y, Z });
        int cnt = (X == mx) + (Y == mx) + (Z == mx);

        // invalid case
        if (cnt == 1) {
            ans = 0;
            break;
        }

        // all equal
        if (X == Y && Y == Z) {
            ans *= (3LL * X + 1);   // ✅ CORRECT FIX
        }
        // exactly two max
        else if (X == Y && X > Z) {
            ans *= (2LL * Z + 1);
        }
        else if (Y == Z && Y > X) {
            ans *= (2LL * X + 1);
        }
        else if (Z == X && Z > Y) {
            ans *= (2LL * Y + 1);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    compute();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}