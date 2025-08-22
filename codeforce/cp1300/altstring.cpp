#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 998244353;
const int MAXN = 2e5 + 5;

vector<ll> fact(MAXN);

void preprocess() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = (fact[i-1] * i) % MOD;
}

void solve() {
    int n;
    string s;
    cin >> s;
    n = s.size();

    vector<int> group;
    for (int l = 0; l < n;) {
        int r = l+1;
        while (r < n && s[r] == s[l]) r++;
        group.push_back(r-l);
        l = r;
    }

    int total_ops = n - group.size();
    ll ways = 1;
    for (auto len : group) ways = (ways * len) % MOD;

    ways = (ways * fact[total_ops]) % MOD;

    cout << total_ops << " " << ways << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    preprocess();
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
