// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(x) (x).begin(), (x).end()

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

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z = compute_z(s);
    vector<int> res;

    for (int i = 1; i < n; ++i) {
        if (z[i] == n - i) {
            res.push_back(i);
        }
    }
    res.push_back(n); 

    for (int len : res) cout << len << " ";
    cout << "\n";
    return 0;
}
