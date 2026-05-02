#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

const int INF = INT_MAX;

struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree(vi &a) {
        n = a.size();
        tree.assign(4*n + 5, 0);
        if(n > 0) build(1, 0, n-1, a);
    }

    void build(int node, int l, int r, vi &a) {
        if (l == r) {
            tree[node] = a[l];
        } else {
            int m = l + (r - l) / 2;
            build(2*node, l, m, a);
            build(2*node+1, m+1, r, a);
            tree[node] = tree[2*node] & tree[2*node+1];
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return ~0; 
        if (ql <= l && r <= qr) return tree[node];
        int m = l + (r - l) / 2;
        int s1 = query(2*node, l, m, ql, qr);
        int s2 = query(2*node+1, m+1, r, ql, qr);
        return s1 & s2;
    }
};

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    SegmentTree st(a);

    int q; cin >> q;
    while (q--) {
        int l, k; cin >> l >> k;
        l--; 

        int low = l, high = n-1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int f = st.query(1, 0, n-1, l, mid); 
            if (f >= k) {
                ans = mid;         
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (ans != -1) ans++; 
        cout << ans << " ";
    }cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
