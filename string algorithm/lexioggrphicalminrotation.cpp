// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const ll Z = 1e9 + 7;  // large prime for mod
const ll C = 911;      // fixed base (avoid random for speed)

// Hashing struct using 64-bit rolling hash
struct HashString {
    int n;
    vector<ll> pows, sums;

    HashString(const string& s) : n(s.size()), pows(n + 1, 1), sums(n + 1) {
        for (int i = 1; i <= n; i++) {
            pows[i] = (pows[i - 1] * C) % Z;
            sums[i] = (sums[i - 1] * C + s[i - 1]) % Z;
        }
    }

    // Hash of substring [l, r)
    ll hash(int l, int r) {
        ll h = (sums[r] - (sums[l] * pows[r - l]) % Z + Z) % Z;
        return h;
    }
};

// Compares s2[a..a+len) vs s2[b..b+len) using hash + binary search
bool is_less(HashString& hs, const string& s2, int a, int b, int len) {
    int low = 0, high = len;
    while (low < high) {
        int mid = (low + high) / 2;
        ll ha = hs.hash(a, a + mid + 1);
        ll hb = hs.hash(b, b + mid + 1);
        if (ha == hb)
            low = mid + 1;
        else
            high = mid;
    }
    if (low == len) return false;
    return s2[a + low] < s2[b + low];
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    string s2 = s + s;  // double the string to simulate rotations
    HashString hs(s2);

    int best = 0;
    for (int i = 1; i < n; ++i) {
        if (is_less(hs, s2, i, best, n)) {
            best = i;
        }
    }

    // Print rotation directly (avoid substr overhead)
    for (int i = best; i < best + n; ++i) {
        cout << s2[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
