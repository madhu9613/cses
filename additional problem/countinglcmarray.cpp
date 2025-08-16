#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

// Multiply two 2x2 matrices modulo MOD
array<array<ll, 2>, 2> matmul(const array<array<ll, 2>, 2> &A, const array<array<ll, 2>, 2> &B) {
    array<array<ll, 2>, 2> C{};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// Fast exponentiation of 2x2 matrix to power n
array<array<ll, 2>, 2> matpow(array<array<ll, 2>, 2> base, ll n) {
    array<array<ll, 2>, 2> result = {{{1, 0}, {0, 1}}}; // Identity matrix
    while (n > 0) {
        if (n & 1) result = matmul(result, base);
        base = matmul(base, base);
        n >>= 1;
    }
    return result;
}

// Calculate D(n) for prime exponent X using matrix exponentiation
ll count_sequences(ll n, ll X) {
    if (n == 1) return (X + 1) % MOD;
    if (n == 2) return (2 * X + 1) % MOD;

    // Recurrence:
    // D(n)   = 1*D(n-1) + X*D(n-2)
    // D(n-1) = 1*D(n-2) + 0*D(n-3)
    //
    // Matrix form:
    // |D(n)  |   |1  X| |D(n-1)|
    // |D(n-1)| = |1  0| |D(n-2)|
    array<array<ll, 2>, 2> M = {{{1, X}, {1, 0}}};

    array<array<ll, 2>, 2> Mn = matpow(M, n - 2);

    // Base vector for n=2: D(2) = 2X + 1, D(1) = X + 1
    ll D2 = (2 * X + 1) % MOD;
    ll D1 = (X + 1) % MOD;

    // D(n) = Mn[0][0]*D(2) + Mn[0][1]*D(1)
    ll res = (Mn[0][0] * D2 + Mn[0][1] * D1) % MOD;
    return res;
}

// Prime factorization of k
vector<pair<ll, ll>> prime_factorize(ll k) {
    vector<pair<ll, ll>> factors;
    for (ll i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            ll count = 0;
            while (k % i == 0) {
                k /= i;
                count++;
            }
            factors.emplace_back(i, count);
        }
    }
    if (k > 1) factors.emplace_back(k, 1);
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;

        auto factors = prime_factorize(k);

        ll answer = 1;
        for (auto &[p, X] : factors) {
            ll ways = count_sequences(n, X);
            answer = (answer * ways) % MOD;
        }

        cout << answer << "\n";
    }

    return 0;
}
