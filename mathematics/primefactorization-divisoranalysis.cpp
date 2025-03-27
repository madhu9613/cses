#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

// Function to perform (base^exp) % mod
int mod_exponentiation(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) // If exponent is odd
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to compute modular inverse using Fermat's Theorem
int mod_inverse(int a, int mod) {
    return mod_exponentiation(a, mod - 2, mod);
}

int32_t main() {
    int n;
    cin >> n; // Number of prime factors

    int divisor_count = 1, divisor_sum = 1, divisor_product = 1;
    int total_exponents = 0; // Used for product calculation

    for (int i = 0; i < n; i++) {
        int x, k;
        cin >> x >> k; // Prime number and its power

        // Compute number of divisors
        divisor_count = (divisor_count * (k + 1)) % MOD;

        // Compute sum of divisors
        int term = (mod_exponentiation(x, k + 1, MOD) - 1 + MOD) % MOD;
        int inv = mod_inverse(x - 1, MOD);
        divisor_sum = (divisor_sum * term % MOD * inv % MOD) % MOD;

        // Compute exponent sum for product calculation
        int exponent_sum = (k * (k + 1) / 2) % (MOD - 1); // Using MOD-1 for power calculation
        total_exponents = (total_exponents + exponent_sum) % (MOD - 1);

        // Compute product of divisors
        divisor_product = mod_exponentiation(divisor_product, k + 1, MOD);
        divisor_product = (divisor_product * mod_exponentiation(x, total_exponents, MOD)) % MOD;
    }

    // Print results
    cout << divisor_count << " " << divisor_sum << " " << divisor_product << endl;
    return 0;
}
