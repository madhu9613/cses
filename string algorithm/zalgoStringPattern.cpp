// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

vector<int> compute_z(const string &s) {
    int n = s.length();
    vector<int> Z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= r)
            Z[i] = min(r - i + 1, Z[i - l]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            ++Z[i];
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return Z;
}

void solve() {
    string s, p;
    cin >> s >> p;
    int n = s.size();
    int m = p.size();
    string t = p + "$" + s;

    vi z = compute_z(t);
    int count = 0;

    for (int i = m + 1; i < z.size(); i++) {
        if (z[i] == m)
            count++;
    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
