#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6;

long long fact[MAXN + 1], invFact[MAXN + 1];

// Function to calculate (base^exp) % MOD using fast exponentiation
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Precompute factorials and modular inverses
void precompute() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN] = modPow(fact[MAXN], MOD - 2, MOD); // Using Fermat's theorem
    for (int i = MAXN - 1; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
    invFact[0] = 1;
}

// Function to compute C(n, k) % MOD
long long binomialCoeff(int n, int k) {
    if (k > n || k < 0) return 0;
    return (fact[n] * invFact[k] % MOD) * invFact[n - k] % MOD;
}

int main() {
    precompute();
    int n;
    cin >> n;

    if (n % 2 != 0) {
        cout << 0 << endl;
    } else {
        int k = n / 2;
        cout << (binomialCoeff(2 * k, k) * modPow(k + 1, MOD - 2, MOD)) % MOD << endl;
    }

    return 0;
}
