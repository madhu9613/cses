#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 1e6;
vector<long long> fact(MAXN + 1), inv(MAXN + 1);

// Binary exponentiation
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

int main() {
    preprocess();  // Important!

    int t;
    cin >> t;
    while (t--) {
        
        string s;
        cin >> s;
        int n=s.size();
        vector<int> groups;
        int count = 1;
        int total_chars = 0;

        // Group consecutive characters
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                groups.push_back(count);
                total_chars += count;
                count = 1;
            }
        }
        groups.push_back(count);
        total_chars += count;

        // Number of deletions needed
       

        // Calculate product of factorials modulo MOD
        long long ans2 = 1;
        for (int i = 0; i < groups.size(); i++) {
            ans2 = (ans2 * fact[groups[i]]) % MOD;
        }
        cout << total_chars - groups.size() << " "<<ans2<<endl;
     
    }
    return 0;
}
