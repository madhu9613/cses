#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Node {
    ll sum;       
    ll prefix_sum;  
    Node(ll s=0, ll p=0) : sum(s), prefix_sum(p) {}
};

class SegmentTree {
    vector<Node> tree;
    int n;
    vector<ll> &a;

public:
    SegmentTree(vector<ll> &arr) : a(arr) {
        n = a.size() - 1;
        tree.resize(4 * n);
        build(1, 1, n);
    }

    Node merge(Node left, Node right) {
        Node res;
        res.sum = left.sum + right.sum;
        res.prefix_sum = max(left.prefix_sum, left.sum + right.prefix_sum);
        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(a[l], max(0LL, a[l]));
            return;
        }
        int m = (l + r) / 2;
        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, ll val) {
        if (l == r) {
            a[idx] = val;
            tree[node] = Node(a[idx], max(0LL, a[idx]));
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m) update(2 * node, l, m, idx, val);
        else update(2 * node + 1, m + 1, r, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return Node(0, 0); 
        if (ql <= l && r <= qr) return tree[node]; 
        int m = l+(r-l)/2;
        Node left = query(2 * node, l, m, ql, qr);
        Node right = query(2 * node + 1, m + 1, r, ql, qr);
        return merge(left, right);
    }

    void update(int idx, ll val) {
        update(1, 1, n, idx, val);
    }

    ll get_prefix(int l, int r) {
        return query(1, 1, n, l, r).prefix_sum;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    SegmentTree st(a);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx; ll val;
            cin >> idx >> val;
            st.update(idx, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.get_prefix(l, r) << endl;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}