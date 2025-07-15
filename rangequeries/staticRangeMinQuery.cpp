#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 20;
int st[MAXN][LOG];
int log_table[MAXN];

void buildSparseTable(const vector<int>& arr) {
    int n = arr.size();
    
    // Precompute logs
    log_table[1] = 0;
    for (int i = 2; i <= n; ++i)
        log_table[i] = log_table[i / 2] + 1;

    // Initialize sparse table
    for (int i = 0; i < n; ++i)
        st[i][0] = arr[i];

    // Build sparse table
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// O(1) RMQ
int query(int l, int r) {
    int len = r - l + 1;
    int k = log_table[len];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    buildSparseTable(arr);

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based
        cout << query(a, b) << "\n";
    }

    return 0;
}
