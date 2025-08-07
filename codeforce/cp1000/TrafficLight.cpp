#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    s += s; 
    int res = 0;
    int nextG = -1;

    vector<int> next_g(2 * n, -1);
    for (int i = 2 * n - 1; i >= 0; --i) {
        if (s[i] == 'g') nextG = i;
        next_g[i] = nextG;
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == c) {
            res = max(res, next_g[i] - i);
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
