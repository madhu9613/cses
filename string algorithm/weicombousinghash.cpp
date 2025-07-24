// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll Z = 1111111111111111111;  // large prime
const ll C = uniform_int_distribution<ll>(Z / 10, Z / 10 * 9)(rng);  // random base

struct HashString {
    ll mul(ll a, ll b) { return __int128(a) * b % Z; }

    int n;
    vector<ll> pows, sums;

    HashString(const string& s) : n(s.size()), pows(n + 1, 1), sums(n + 1) {
        for (int i = 1; i <= n; i++) {
            pows[i] = mul(pows[i - 1], C);
            sums[i] = (mul(sums[i - 1], C) + s[i - 1]) % Z;
        }
    }

    // Hash of substring [l, r)
    ll hash(int l, int r) {
        ll h = sums[r] - mul(sums[l], pows[r - l]);
        return (h % Z + Z) % Z;
    }
};

void solve() {

    string s;
    cin>>s;
    int n=s.size();
    HashString hs(s);
    unordered_set<ll>hashes; //its here to store the hash value of dictionary word;
    vector<bool>lengths(n+1);
    int k;cin>>k;
    while (k--)
    {
        string w;cin>>w;
        HashString hw(w);
        int m=w.size();
        hashes.insert(hw.hash(0,m));
        lengths[m]=true;
    }


    // dp[i] = # of ways to split s[0..i)
    vector<int>dp(n+1);
    dp[0]=1;
     for (int i = 0; i < n; ++i) {
        if (dp[i] == 0) continue;
        for (int len = 1; i + len <= n; ++len) {
            if (!lengths[len]) continue;
            ll h = hs.hash(i, i + len);
            if (hashes.count(h)) {
                dp[i + len] = (dp[i + len] + dp[i]) % MOD;
            }
        }
    }
    cout << dp[n] << endl;
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}