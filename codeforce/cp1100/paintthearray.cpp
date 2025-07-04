#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool valid(const vector<int>& a, int g, int start) {
    for (int i = start; i < a.size(); i += 2) {
        if (a[i] % g == 0)
            return false;
    }
    return true;
}

int solve(vector<int>& a) {
    int g1 = a[0];
    for (int i = 2; i < a.size(); i += 2)
        g1 = gcd(g1, a[i]);

    int g2 = a[1];
    for (int i = 3; i < a.size(); i += 2)
        g2 = gcd(g2, a[i]);

    if (valid(a, g1, 1))
        return g1;
    if (valid(a, g2, 0))
        return g2;

    return 0;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        cout << solve(a) << "\n";
    }
}
