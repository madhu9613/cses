#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 5;

vector<long long> fact(MAX_N), inv_fact(MAX_N);

// Modular exponentiation
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Precompute factorials and modular inverses
void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[MAX_N - 1] = mod_pow(fact[MAX_N - 1], MOD - 2, MOD); // Fermat's theorem
    for (int i = MAX_N - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

// Compute nCr % MOD
long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

// Compute Catalan number C(n) = nCr(2n, n) / (n+1)
long long catalan(int n) {
    if (n == 0) return 1;
    return (nCr(2 * n, n) * mod_pow(n + 1, MOD - 2, MOD)) % MOD;
}

int main() {
    precompute_factorials();
    
    int n;
    string prefix;
    cin >> n >> prefix;
    
    int k = prefix.size();
    int open = 0, close = 0, min_open_needed = 0;
    
    // Validate prefix and count brackets
    for (char c : prefix) {
        if (c == '(') open++;
        else close++;
        min_open_needed = max(min_open_needed, close - open); // Unbalanced tracking
    }

    int remaining = n - k;
    if (remaining % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    int rem_open = remaining / 2;
    int rem_close = remaining / 2;

    // We must have at least min_open_needed open brackets
    if (rem_open < min_open_needed) {
        cout << 0 << endl;
        return 0;
    }

    // Count valid sequences
    cout << (nCr(rem_open + rem_close, rem_open) - nCr(rem_open + rem_close, rem_open + 1) + MOD) % MOD << endl;
    return 0;
}
