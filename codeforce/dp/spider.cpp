#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MOD = 1000000007;

// Fast exponentiation (a^b % mod)
ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD) {
    return modpow(a, mod - 2, mod);
}

// GCD
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// LCM
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

const int MAXB=30;


struct Node {
    int child[2];
    int mx;
    Node() {
        child[0] = child[1] = -1;
        mx = 0;
    }
};

vector<Node> trie;

void insert(int x, int dp_val) {
    int node = 0;
    for (int b = MAXB; b >= 0; b--) {
        int bit = (x >> b) & 1;
        if (trie[node].child[bit] == -1) {
            trie[node].child[bit] = trie.size();
            trie.push_back(Node());
        }
        node = trie[node].child[bit];
        trie[node].mx = max(trie[node].mx, dp_val);
    }
}

int query(int x, int k) {
    int node = 0;
    int res = 0;

    for (int b = MAXB; b >= 0; b--) {
        if (node == -1) break;

        int xb = (x >> b) & 1;
        int kb = (k >> b) & 1;

        if (kb == 1) {
            node = trie[node].child[xb ^ 1];
        } else {
            int other = trie[node].child[xb ^ 1];
            if (other != -1) {
                res = max(res, trie[other].mx);
            }
            node = trie[node].child[xb];
        }
    }

    if (node != -1) {
        res = max(res, trie[node].mx);
    }

    return res;
}
void solve() {
     int n, k;
    cin >> n >> k;

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    vector<int> dp(n, 1), parent(n, -1);

    trie.clear();
    trie.push_back(Node());

    int best_len = 0, best_idx = -1;

    for (int i = 0; i < n; i++) {
        int val = a[i].first;

        int best = query(val, k);

        dp[i] = best + 1;

        insert(val, dp[i]);

        if (dp[i] > best_len) {
            best_len = dp[i];
            best_idx = i;
        }
    }

    if (best_len < 2) {
        cout << -1 << "\n";
        return ;
    }

    vector<int> res;
    int cur = best_len;
    int last_val = a[best_idx].first;

    for (int i = best_idx; i >= 0; i--) {
        if (dp[i] == cur && (res.empty() || (a[i].first ^ last_val) >= k)) {
            res.push_back(a[i].second + 1);
            last_val = a[i].first;
            cur--;
        }
    }

    reverse(res.begin(), res.end());

    cout << res.size() << "\n";
    for (int x : res) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}