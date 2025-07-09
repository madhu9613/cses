#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

struct Node {
    ll sum = 0;
    ll lazy_add = 0;
    ll lazy_set = 0;
    bool to_set = false;
};

Node tree[4 * N];
int n, q;
vector<ll> arr;

void build(int node, int l, int r) {
    if (l == r) {
        tree[node].sum = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
}

void push(int node, int l, int r) {
    if (tree[node].to_set) {
        tree[node].sum = (r - l + 1) * tree[node].lazy_set;
        if (l != r) {
            int left = 2*node, right = 2*node+1;
            tree[left].lazy_set = tree[right].lazy_set = tree[node].lazy_set;
            tree[left].lazy_add = tree[right].lazy_add = 0;
            tree[left].to_set = tree[right].to_set = true;
        }
        tree[node].lazy_set = 0;
        tree[node].to_set = false;
    }

    if (tree[node].lazy_add != 0) {
        tree[node].sum += (r - l + 1) * tree[node].lazy_add;
        if (l != r) {
            int left = 2*node, right = 2*node+1;
            tree[left].lazy_add += tree[node].lazy_add;
            tree[right].lazy_add += tree[node].lazy_add;
        }
        tree[node].lazy_add = 0;
    }
}

void update_add(int node, int l, int r, int ql, int qr, ll val) {
    push(node, l, r);
    if (r < ql || l > qr) return;
    if (ql <= l && r <= qr) {
        tree[node].lazy_add += val;
        push(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update_add(2*node, l, mid, ql, qr, val);
    update_add(2*node+1, mid+1, r, ql, qr, val);
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
}

void update_set(int node, int l, int r, int ql, int qr, ll val) {
    push(node, l, r);
    if (r < ql || l > qr) return;
    if (ql <= l && r <= qr) {
        tree[node].to_set = true;
        tree[node].lazy_set = val;
        tree[node].lazy_add = 0;
        push(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update_set(2*node, l, mid, ql, qr, val);
    update_set(2*node+1, mid+1, r, ql, qr, val);
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
}

ll query(int node, int l, int r, int ql, int qr) {
    push(node, l, r);
    if (r < ql || l > qr) return 0;
    if (ql <= l && r <= qr) return tree[node].sum;
    int mid = (l + r) / 2;
    return query(2*node, l, mid, ql, qr) + query(2*node+1, mid+1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    build(1, 0, n - 1);

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        a--, b--;  // convert to 0-based indexing

        if (type == 1) {
            ll x;
            cin >> x;
            update_add(1, 0, n - 1, a, b, x);
        } else if (type == 2) {
            ll x;
            cin >> x;
            update_set(1, 0, n - 1, a, b, x);
        } else if (type == 3) {
            cout << query(1, 0, n - 1, a, b) << "\n";
        }
    }

    return 0;
}
