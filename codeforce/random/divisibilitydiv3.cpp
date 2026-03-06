#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1000000;

vector<int> spf(MAXA + 1);

// Precompute smallest prime factor
void sieve() {
    for (int i = 1; i <= MAXA; i++)
        spf[i] = i;

    for (int i = 2; i * i <= MAXA; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j <= MAXA; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

// Count prime factors with multiplicity
int countPrimeFactors(int x) {
    int cnt = 0;
    while (x > 1) {
        cnt++;
        x /= spf[x];
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        // Step 1: check if already non-decreasing
        bool sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                sorted = false;
                break;
            }
        }

        if (sorted) {
            cout << "Bob\n";
            continue;
        }

        // Step 2: count total moves
        long long totalMoves = 0;

        for (int i = 0; i < n; i++) {
            int pf = countPrimeFactors(a[i]);
            totalMoves += (pf - 1);
        }

        // Step 3: decide winner
        if (totalMoves % 2 == 1)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }

    return 0;
}