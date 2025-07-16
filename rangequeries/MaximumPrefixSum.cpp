#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum;
    long long prefix_max;
    Node(long long s = 0, long long p = 0) : sum(s), prefix_max(p) {}
};

class SegmentTree {
    vector<Node> tree;
    int n;

public:
    SegmentTree(const vector<long long> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    Node merge(Node left, Node right) {
        Node res;
        res.sum = left.sum + right.sum;
        res.prefix_max = max(left.prefix_max, left.sum + right.prefix_max);
        return res;
    }

    void build(const vector<long long> &arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = Node(arr[tl], max(0LL, arr[tl]));
        } else {
            int tm = (tl + tr) / 2;
            build(arr, 2*v+1, tl, tm);
            build(arr, 2*v+2, tm+1, tr);
            tree[v] = merge(tree[2*v+1], tree[2*v+2]);
        }
    }

    void update(int idx, long long val, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = Node(val, max(0LL, val));
        } else {
            int tm = (tl + tr) / 2;
            if (idx <= tm)
                update(idx, val, 2*v+1, tl, tm);
            else
                update(idx, val, 2*v+2, tm+1, tr);
            tree[v] = merge(tree[2*v+1], tree[2*v+2]);
        }
    }

    Node query(int l, int r, int v, int tl, int tr) {
        if (l > r) return Node(0, 0);
        if (l == tl && r == tr)
            return tree[v];
        int tm = (tl + tr) / 2;
        Node left = query(l, min(r, tm), 2*v+1, tl, tm);
        Node right = query(max(l, tm+1), r, 2*v+2, tm+1, tr);
        return merge(left, right);
    }

    void update(int idx, long long val) {
        update(idx, val, 0, 0, n - 1);
    }

    long long get_prefix_max(int l, int r) {
        return query(l, r, 0, 0, n - 1).prefix_max;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    SegmentTree st(arr);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            long long u;
            cin >> k >> u;
            --k; // convert to 0-based index
            st.update(k, u);
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            cout << st.get_prefix_max(a, b) << "\n";
        }
    }

    return 0;
}
