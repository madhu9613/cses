#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<int> segTree;
vector<int> a;

void build(int node, int l, int r) {
    if (l == r) {
        segTree[node] = 1;  // All elements are alive
    } else {
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

void update(int node, int l, int r, int idx) {
    if (l == r) {
        segTree[node] = 0;  // Mark as deleted
    } else {
        int mid = l + (r - l) / 2;
        if (idx <= mid)
            update(2 * node, l, mid, idx);
        else
            update(2 * node + 1, mid + 1, r, idx);
        // propagate changes
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

int query(int node, int l, int r, int k) {
    if (l == r) return l;
    int mid = l + (r - l) / 2;
    if (segTree[2 * node] >= k)
        return query(2 * node, l, mid, k);
    else
        return query(2 * node + 1, mid + 1, r, k - segTree[2 * node]);
}

int main() {
    int n;
    cin >> n;

    a.resize(n + 1);
    segTree.resize(4 * n);

    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int idx = query(1, 1, n, k);
        cout << a[idx] << " ";
        update(1, 1, n, idx);
    }

    return 0;
}
