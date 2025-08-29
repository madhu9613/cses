#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For std::ceil

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long ops = 0;
    long long x = 0;
    int i = 0, j = n - 1;

    while (i < j) {
        if (x >= a[j]) {
            ops++;
            x -= a[j];
            j--;
        } else {
            long long needed = a[j] - x;
            if (i < j) {
                long long take = min(a[i], needed);
                x += take;
                ops += take;
                a[i] -= take;
                if (a[i] == 0) {
                    i++;
                }
            } else { // This case handles i == j after one loop
                ops += needed;
                x += needed;
            }
        }
    }

    if (x >= a[i]) {
        ops++;
    } else {
        long long needed_final = a[i] - x;
        ops += needed_final;
        ops++; // For the ultimate attack
    }
    
    cout << ops << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}