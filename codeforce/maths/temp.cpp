#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1000000; // adjust based on constraints
int spf[N + 1];

// Precompute SPF
void compute_spf() {
    for (int i = 1; i <= N; i++) spf[i] = i;

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) { // prime
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

// Factorization using SPF
map<int, int> factor(int x) {
    map<int, int> f;
    while (x > 1) {
        f[spf[x]]++;
        x /= spf[x];
    }
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    compute_spf();

    int t;
    cin >> t;

    while (t--) {
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

            if (cnt == 1) {
                ans = 0;
                break;
            }

            if (X == Y && Y == Z) {
                ans *= (3LL * X * X + 3LL * X + 1);
            }
            else {
                int mn = min({ X, Y, Z });
                ans *= (2LL * mn + 1);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}