#include <bits/stdc++.h>
using namespace std;

const int MAXX = 5000;
const int MOD = 1e9 + 7;
const int MAXP = 669;

vector<int> primes;
bitset<MAXP> basis[MAXP]; 

void sieve() {
    vector<bool> is_prime(MAXX + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAXX; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= MAXX; j += i)
                is_prime[j] = false;
        }
    }
}

bitset<MAXP> factor_mask(int x) {
    bitset<MAXP> mask;
    for (int i = 0; i < (int)primes.size(); i++) {
        int p = primes[i];
        if (p * p > x) break;
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt ^= 1;
        }
        if (cnt) mask.set(i);
    }
    if (x > 1) {
        auto it = lower_bound(primes.begin(), primes.end(), x);
        if (it != primes.end() && *it == x) {
            int idx = it - primes.begin();
            mask.set(idx);
        }
    }
    return mask;
}

void insert_basis(bitset<MAXP> x) {
    for (int i = MAXP - 1; i >= 0; i--) {
        if (!x[i]) continue;
        if (basis[i].none()) {
            basis[i] = x;
            return;
        }
        x ^= basis[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n; cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    for (int i = 0; i < MAXP; i++)
        basis[i].reset();

    for (int x : arr) {
        insert_basis(factor_mask(x));
    }

    int rank = 0;
    for (int i = 0; i < MAXP; i++)
        if (basis[i].any()) rank++;

    long long ans = 1;
    for (int i = 0; i < n - rank; i++)
        ans = (ans * 2) % MOD;

    cout << ans << "\n";

    return 0;
}
