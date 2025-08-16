// #include <bits/stdc++.h>
// using namespace std;

// struct MergeSortTree {
//     int n;
//     vector<vector<int>> tree;

//     MergeSortTree(const vector<int> &arr) {
//         n = arr.size();
//         tree.resize(4 * n);
//         build(arr, 1, 0, n - 1);
//     }

//     void build(const vector<int> &arr, int node, int l, int r) {
//         if (l == r) {
//             tree[node] = {arr[l]};
//             return;
//         }
//         int mid = (l + r) / 2;
//         build(arr, node * 2, l, mid);
//         build(arr, node * 2 + 1, mid + 1, r);
//         merge(tree[node * 2].begin(), tree[node * 2].end(),
//               tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),
//               back_inserter(tree[node]));
//     }

//     int query(int node, int l, int r, int ql, int qr, int c, int d) {
//         if (qr < l || r < ql) return 0; 
//         if (ql <= l && r <= qr) {
//             auto &v = tree[node];
//             int left = lower_bound(v.begin(), v.end(), c) - v.begin();
//             int right = upper_bound(v.begin(), v.end(), d) - v.begin();
//             return right - left;
//         }
//         int mid = (l + r) / 2;
//         return query(node * 2, l, mid, ql, qr, c, d) +
//                query(node * 2 + 1, mid + 1, r, ql, qr, c, d);
//     }

//     int query(int ql, int qr, int c, int d) {
//         return query(1, 0, n - 1, ql, qr, c, d);
//     }
// };

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, q;
//     cin >> n >> q;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) cin >> arr[i];

//     MergeSortTree seg(arr);

//     while (q--) {
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;
      
//         a--; b--;
//         cout << seg.query(a, b, c, d) << "\n";
//     }
// }


#include <bits/stdc++.h>
using namespace std;

struct IterativeMergeSortTree {
    int n;
    vector<vector<int>> tree;

    IterativeMergeSortTree(const vector<int> &arr) {
        n = arr.size();
        tree.resize(2 * n);
        for (int i = 0; i < n; i++)
            tree[i + n] = {arr[i]};
        for (int i = n - 1; i > 0; i--) {
            tree[i].resize(tree[i << 1].size() + tree[i << 1 | 1].size());
            merge(tree[i << 1].begin(), tree[i << 1].end(),
                  tree[i << 1 | 1].begin(), tree[i << 1 | 1].end(),
                  tree[i].begin());
        }
    }

    int query(int l, int r, int c, int d) {
        int res = 0;
        l += n; r += n + 1;
        while (l < r) {
            if (l & 1) {
                res += countRange(tree[l], c, d);
                l++;
            }
            if (r & 1) {
                --r;
                res += countRange(tree[r], c, d);
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }

    static int countRange(const vector<int> &v, int c, int d) {
        auto left = lower_bound(v.begin(), v.end(), c);
        auto right = upper_bound(v.begin(), v.end(), d);
        return right - left;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    IterativeMergeSortTree seg(arr);

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; // 0-based
        cout << seg.query(a, b, c, d) << "\n";
    }
}
