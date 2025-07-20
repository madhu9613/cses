// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int LOG = 20;  // For n <= 2e5, log2(2e5) ≈ 18, so LOG = 20 is safe

vector<vector<int>> up;

int lift(int x, int level) {
    for (int j = 0; j < LOG; j++) {
        if (x == -1) break;
        if (level & (1 << j)) {
            x = up[x][j];
        }
    }
    return x;
}

void solve() {
    int n, q;
    cin >> n >> q;

    up.assign(n + 1, vector<int>(LOG, -1));

    for (int i = 2; i <= n; i++) {
        cin >> up[i][0]; 
    }

    // Build binary lifting table
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != -1)
                up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int x, level;
        cin >> x >> level;
        int ans = lift(x, level);
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
