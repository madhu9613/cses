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

// Compute the number of unique strings
long long count_permutations(const string &s) {
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    long long result = fact[s.size()];
    for (int f : freq) {
        if (f > 0) result = (result * inv[f]) % MOD;
    }
    return result;
}

int main() {
    preprocess();
    
    string s;
    cin >> s;
    
    cout << count_permutations(s) << "\n";
    return 0;
}
