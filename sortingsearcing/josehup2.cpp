// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using namespace std;

// #define int long long

// // Ordered Set from PBDS with indexing
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
//                          tree_order_statistics_node_update>;

// int32_t main() {
//     int n, k;
//     cin >> n >> k;

//     ordered_set<int> circle;
//     for (int i = 1; i <= n; ++i)
//         circle.insert(i);

//     int idx = 0;
//     while (!circle.empty()) {
//         idx = (idx + k) % circle.size();  // New position after k skips
//         auto it = circle.find_by_order(idx);  // Get iterator to idx-th element
//         cout << *it << " ";
//         circle.erase(it);  // Remove from the circle
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int seg[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = 1;  // initially alive
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    seg[id] = seg[2 * id] + seg[2 * id + 1];
}

void update(int id, int l, int r, int pos) {
    if (l == r) {
        seg[id] = 0;  // remove
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(2 * id, l, mid, pos);
    else update(2 * id + 1, mid + 1, r, pos);
    seg[id] = seg[2 * id] + seg[2 * id + 1];
}

// returns index of k-th alive person (1-based)
int query(int id, int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (seg[2 * id] >= k)
        return query(2 * id, l, mid, k);
    else
        return query(2 * id + 1, mid + 1, r, k - seg[2 * id]);
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    build(1, 1, n);

    int alive = n;
    int curr = 0;  // index in alive list (0-based)
    for (int i = 0; i < n; ++i) {
        curr = (curr + k) % alive;
        int pos = query(1, 1, n, curr + 1);  // 1-based
        cout << pos << " ";
        update(1, 1, n, pos);  // mark dead
        alive--;
    }
    cout << '\n';
}
