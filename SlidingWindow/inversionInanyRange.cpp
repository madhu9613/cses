#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> tree[4 * MAXN];
vector<int> a;

// Build segment tree with sorted vectors
void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = {a[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    merge(tree[2 * node].begin(), tree[2 * node].end(),
          tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
          back_inserter(tree[node]));
}

// Count number of elements < x in range [ql, qr]
int countLess(int node, int l, int r, int ql, int qr, int x) {
    if (qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr) {
        return lower_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();
    }
    int mid = (l + r) / 2;
    return countLess(2 * node, l, mid, ql, qr, x)
         + countLess(2 * node + 1, mid + 1, r, ql, qr, x);
}

long long countInversions(int l, int r, int n) {
    long long ans = 0;
    for (int i = l; i < r; ++i) {
        // Count how many elements < a[i] in range (i+1 to r)
        ans += countLess(1, 0, n - 1, i + 1, r, a[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    build(1, 0, n - 1);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--; // 0-based
        cout << countInversions(l, r, n) << '\n';
    }

    return 0;
}
