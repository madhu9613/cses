#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> tree(4 * MAXN);

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        tree[node] += val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
        update(2 * node, l, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, r, idx, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return tree[node];
    int mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];  // for compression
    }

    // Coordinate compression
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;  // 1-indexed
    }

    int max_val = b.size();  // maximum compressed value
    long long inversions = 0;

    // First window
    for (int i = 0; i < k; i++) {
        inversions += query(1, 1, max_val, a[i] + 1, max_val);
        update(1, 1, max_val, a[i], 1);
    }
    cout << inversions << " ";

    // Slide the window
    for (int i = k; i < n; i++) {
        // Remove a[i - k]
        update(1, 1, max_val, a[i - k], -1);
        inversions -= query(1, 1, max_val, 1, a[i - k] - 1);  // count how many less than removed element before it

        // Add a[i]
        inversions += query(1, 1, max_val, a[i] + 1, max_val);  // count how many greater
        update(1, 1, max_val, a[i], 1);

        cout << inversions << " ";
    }
    cout << "\n";

    return 0;
}
