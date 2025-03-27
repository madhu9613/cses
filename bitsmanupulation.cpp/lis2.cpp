#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;

int seg[4 * MX];  // Segment tree array
int n;

// Function to update the segment tree
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        seg[node] = (seg[node] + val) % MOD;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) 
            update(2 * node, start, mid, idx, val);
        else 
            update(2 * node + 1, mid + 1, end, idx, val);
        seg[node] = (seg[2 * node] + seg[2 * node + 1]) % MOD;
    }
}

// Function to query the segment tree
int query(int node, int start, int end, int l, int r) {
    if (l > end || r < start) return 0;  // Out of range
    if (l <= start && end <= r) return seg[node];  // Fully in range
    int mid = (start + end) / 2;
    return (query(2 * node, start, mid, l, r) + 
            query(2 * node + 1, mid + 1, end, l, r)) % MOD;
}

int main() {
    cin >> n;
    map<int, int> m;
    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        m[ar[i]];
    }

    // Coordinate Compression
    int co = 0;
    for (auto &cur : m) cur.second = ++co;
    for (int &x : ar) x = m[x];

    int sol = 0;
    for (int x : ar) {
        int subseq = 1 + query(1, 1, n, 1, x - 1);  // Count increasing subsequences ending before `x`
        sol = (sol + subseq) % MOD;
        update(1, 1, n, x, subseq);  // Store new subsequences ending at `x`
    }

    cout << sol << '\n';
}
