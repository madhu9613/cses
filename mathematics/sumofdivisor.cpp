#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

// Function to compute the sum of divisors sum(σ(i)) efficiently
int sum_of_divisors(int n) {
    int total = 0;
    
    for (int i = 1; i * i <= n; i++) {
        int quotient = n / i;
        int next_i = n / quotient + 1;  // The next distinct quotient
        
        // Contribution of the range [i, next_i - 1]
        int sum_range = (quotient % MOD) * ((next_i - i) % MOD) % MOD;
        total = (total + sum_range) % MOD;
        
        i = next_i - 1; // Move to the next unique divisor
    }

    return total;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    cout << sum_of_divisors(n) << '\n';

    return 0;
}
