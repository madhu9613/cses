#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

// Segment tree for range max query and point update
struct SegmentTree {
    vector<int> tree;
    int size;

    SegmentTree(int n) {
        size = n;
        tree.assign(4 * n, 0);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2 * node, l, mid, pos, val);
        else update(2 * node + 1, mid + 1, r, pos, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int pos, int val) {
        update(1, 0, size - 1, pos, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return max(query(2 * node, l, mid, ql, qr),
                   query(2 * node + 1, mid + 1, r, ql, qr));
    }

    int query(int ql, int qr) {
        if (ql > qr) return 0;
        return query(1, 0, size - 1, ql, qr);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    vector<int> L(n, -1), R(n, n);  // Nearest greater on left and right
    stack<int> st;

    // Compute L[i] (nearest greater to the left)
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && h[st.top()] <= h[i]) st.pop();
        if (!st.empty()) L[i] = st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Compute R[i] (nearest greater to the right)
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && h[st.top()] <= h[i]) st.pop();
        if (!st.empty()) R[i] = st.top();
        st.push(i);
    }

    // Sort indices by increasing height
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return h[a] < h[b];
    });

    vector<int> dp(n, 1);
    SegmentTree seg(n);

    int i = 0;
    while (i < n) {
        int j = i;
        // Group same-height values
        while (j < n && h[idx[i]] == h[idx[j]]) j++;

        // Compute dp[i] for this height group
        for (int k = i; k < j; ++k) {
            int pos = idx[k];
            int l = L[pos] + 1;
            int r = R[pos] - 1;
            dp[pos] = 1 + seg.query(l, r);
        }

        // Update segment tree after processing group
        for (int k = i; k < j; ++k) {
            seg.update(idx[k], dp[idx[k]]);
        }

        i = j;
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
