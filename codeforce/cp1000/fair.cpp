#include <bits/stdc++.h>
using namespace std;

bool is_fair(long long x) {
    long long original = x;
    while (x > 0) {
        int digit = x % 10;
        if (digit != 0 && original % digit != 0)
            return false;
        x /= 10;
    }
    return true;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        while (!is_fair(n)) {
            n++;
        }
        cout << n << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
