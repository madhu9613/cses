#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 2e6;  // To cover (n + m - 1) up to 10^6 + 10^6 - 1

vector<long long> fact(MAXN + 1), inv(MAXN + 1);

// Fast exponentiation (modular inverse using Fermat's theorem)
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Precompute factorials and inverses
void preprocess() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    inv[MAXN] = power(fact[MAXN], MOD - 2, MOD);
    for (int i = MAXN - 1; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
}

// Compute binomial coefficient C(n, k)
long long binomial(int n, int k) {
    if (k > n || k < 0) return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
    preprocess();
    
    int n, m;
    cin >> n >> m;
    
    cout << binomial(n + m - 1, m) << "\n";
    return 0;
}
