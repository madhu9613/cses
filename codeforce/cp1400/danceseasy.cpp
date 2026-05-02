#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vll a(n);
//     multiset<ll> b;
//     a[0]=1;
//     for (int i = 1; i < n; i++) {
//         cin >> a[i];
//     }
//     for (int i = 0; i < n; i++) {
//         ll x; cin >> x;
//         b.insert(x);
//     }
//     sort(all(a));
//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         auto idx = b.upper_bound(a[i]);
             
//         if (idx == b.end()) {
//             break;
//         } else {
//             ans++;
//             b.erase(idx);
//         }
//     }
//     cout << n - ans << endl;
// }

void solve() {
    int n, m;
    cin >> n >> m;
    vll a(n);

    a[0]=1;
    for (int i = 1; i < n; i++) cin >> a[i];
    
    vll b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(all(a));
    sort(all(b));

    int ans = 0, j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && b[j] <= a[i]) j++;
        if (j < n) {
            ans++;
            j++;
        }
    }
    cout << n - ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}

struct SegmentTree {
    int size;
    vector<long long> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0LL);
    }

    void build(const vector<long long>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) tree[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(const vector<long long>& a) {
        build(a, 0, 0, size);
    }

    void set(int i, long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, long long v) {
        set(i, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return LLONG_MIN;
        if (lx >= l && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        long long s1 = query(l, r, 2 * x + 1, lx, m);
        long long s2 = query(l, r, 2 * x + 2, m, rx);
        return max(s1, s2);
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};