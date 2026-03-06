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

// # ITS A GOOD Problem on Euclerian cycle or path;

/**
 * lets wirte something why its;
 * in euclerian graph we enter an edge and leave an edge exectly one with start
 * so indegr(X)=outdeg(x);
 * 
 * we can swap(a[i],b[i]) what it means contribution of a[i]; let say;
 *  it will be either a[i] contribute to array a or a[i] contribute to array b
 * 
 * if we swap it will contribute to array b otherwise a;
 * we can check using Euclerian cycle this thing by building a adj list;
 * 
 */


vector<vector<pair<int, int>>> g;
vector<bool> seen;
vector<int> a, b;
vector<int> swaps;

void dfs(int node) {
    while (!g[node].empty()) {
        auto [to, id] = g[node].back();
        g[node].pop_back();

        if (seen[id]) continue;

        seen[id] = true;

        if (a[id] == to && b[id] == node) {
            swaps.push_back(id);
        }

        dfs(to);
    }
}

void solve() {
    int n;
    cin >> n;

    a.assign(n + 1, 0);
    b.assign(n + 1, 0);

    vector<int> cnt(n + 1, 0);

    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 1;i <= n;i++) {
        cin >> b[i];
        cnt[b[i]]++;
    }

    for (int i = 1;i <= n;i++) {
        if (cnt[i] % 2) {
            cout << -1 << "\n";
            return;
        }
    }

    g.assign(n + 1, {});
    seen.assign(n + 1, false);
    swaps.clear();

    for (int i = 1;i <= n;i++) {
        g[a[i]].push_back({ b[i],i });
        g[b[i]].push_back({ a[i],i });
    }

    for (int i = 1;i <= n;i++) {
        dfs(i);
    }

    cout << swaps.size() << "\n";
    for (int x : swaps) cout << x << " ";
    cout << "\n";
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}