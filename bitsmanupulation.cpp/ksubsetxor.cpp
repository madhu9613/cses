#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    // Step 1: Build XOR basis
    vector<long long> basis;
    for (long long x : a) {
        for (long long b : basis) x = min(x, x ^ b);
        if (x) basis.push_back(x);
    }

    // Step 2: Generate XORs using basis
    vector<long long> res = {0};
    for (long long b : basis) {
        int sz = res.size();
        for (int i = 0; i < sz; ++i) {
            if ((int)res.size() >= k) break;
            res.push_back(res[i] ^ b);
        }
        if ((int)res.size() >= k) break;
    }

    while ((int)res.size() < k) res.push_back(0); // pad with zeros if needed

    sort(res.begin(), res.end()); // get smallest k

    for (int i = 0; i < k; ++i) cout << res[i] << " ";
    cout << '\n';
    return 0;
}
