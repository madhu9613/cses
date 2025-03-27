#include <bits/stdc++.h>
using namespace std;
#define int long long

const int64_t INF = 1e18;  // Max limit

// Function to compute gcd
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to compute lcm safely (avoiding overflow)
int safe_lcm(int a, int b) {
    if (a > INF / b) return INF;  // Avoid overflow
    return (a / gcd(a, b)) * b;
}

int count_divisible(int n, vector<int>& primes) {
    int k = primes.size();
    int total = 0;
    
    // Iterate over all subsets using bitmasking
    for (int mask = 1; mask < (1 << k); mask++) {
        int subset_lcm = 1;
        int bits = __builtin_popcount(mask); // Count primes in subset
        bool overflow = false;
        
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) { // If i-th prime is included
                subset_lcm = safe_lcm(subset_lcm, primes[i]);
                if (subset_lcm > n) {
                    overflow = true;
                    break;  // Stop early if LCM exceeds n
                }
            }
        }

        if (!overflow) {
            if (bits % 2 == 1) total += n / subset_lcm;  // Inclusion
            else total -= n / subset_lcm;  // Exclusion
        }
    }
    
    return total;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> primes(k);
    for (int i = 0; i < k; i++) {
        cin >> primes[i];
    }

    cout << count_divisible(n, primes) << '\n';
    
    return 0;
}