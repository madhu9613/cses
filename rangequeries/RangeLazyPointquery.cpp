#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> segTree;
vector<ll> lazy;
vector<ll> arr;

void BuildTree(int node, int l, int r) {
    if (l == r) {
        segTree[node] = arr[l];
    } else {
        int mid = (l + r) / 2;
        BuildTree(2 * node, l, mid);
        BuildTree(2 * node + 1, mid + 1, r);
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

void propagate(int node, int l, int r) {
    if (lazy[node] != 0) {
        segTree[node] += (r - l + 1) * lazy[node];
        if (l != r) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int l, int r, int ql, int qr, ll val) {
    propagate(node, l, r);

    // No overlap
    if (qr < l || ql > r) return;

    // Total overlap
    if (ql <= l && r <= qr) {
        lazy[node] += val;
        propagate(node, l, r);
        return;
    }

    // Partial overlap
    int mid = (l + r) / 2;
    update_range(2 * node, l, mid, ql, qr, val);
    update_range(2 * node + 1, mid + 1, r, ql, qr, val);
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

ll query(int node, int l, int r, int k) {
    propagate(node, l, r);

    if (l == r) return segTree[node];

    int mid = (l + r) / 2;
    if (k <= mid)
        return query(2 * node, l, mid, k);
    else
        return query(2 * node + 1, mid + 1, r, k);
}

int main() {
    int n, q;
    cin >> n >> q;

    arr.resize(n + 1);
    segTree.resize(4 * n);
    lazy.resize(4 * n);

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    BuildTree(1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            ll val;
            cin >> a >> b >> val;
            update_range(1, 1, n, a, b, val);
        } else {
            int k;
            cin >> k;
            cout << query(1, 1, n, k) << "\n";
        }
    }

    return 0;
}
