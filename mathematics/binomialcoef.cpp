#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6;

vector<long long> fact(MAXN + 1), inv(MAXN + 1);

// Fast exponentiation to calculate (base^exp) % MOD
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Precompute factorials and modular inverses
void preprocess() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    inv[MAXN] = power(fact[MAXN], MOD - 2, MOD);
    for (int i = MAXN - 1; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
}

// Compute binomial coefficient C(a, b) mod MOD
long long binomial_coefficient(int a, int b) {
    if (b > a) return 0;
    return ((fact[a] * inv[b]) % MOD * inv[a - b]) % MOD;
}

int main() {
    preprocess();

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << binomial_coefficient(a, b) << "\n";
    }

    return 0;
}
