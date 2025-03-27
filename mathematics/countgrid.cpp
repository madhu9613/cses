#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Modular exponentiation: (base^exp) % mod
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;

    long long total = mod_exp(2, n * n, MOD);
    long long rot90 = mod_exp(2, (n * n) / 4, MOD);
    long long rot180 = mod_exp(2, (n * n) / 2, MOD);

    long long result = (total + 2 * rot90 + rot180) % MOD;
    result = (result * 250000002) % MOD; // 1/4 mod 10^9+7 using Fermat's Theorem

    cout << result << endl;
    return 0;
}
