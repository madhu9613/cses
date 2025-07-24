#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> basis(64, 0); // basis[i] stores vector with highest bit at position i
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        for (int j = 60; j >= 0; --j) {
            if ((x >> j) & 1) {
                if (!basis[j]) {
                    basis[j] = x;
                    break;
                }
                x ^= basis[j];
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i <= 60; ++i)
        if (basis[i]) cnt++;

    cout << (1LL << cnt) << "\n"; // Total distinct XORs
    return 0;
}
