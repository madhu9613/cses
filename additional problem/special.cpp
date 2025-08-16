#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    string S;
    if (!(cin >> S)) return;
    int N = (int)S.size();

    bool seen[26] = {false};
    unordered_map<char,int> idx;
    int M = 0;
    for (char c : S) {
        int ci = c - 'a';
        if (!seen[ci]) {
            seen[ci] = true;
            idx[c] = M++;
        }
    }

    vector<int> freq(M, 0);

    map<vector<int>, ll> dp;
    dp[freq] = 1; 

    auto containsEach = [&](const vector<int>& V)->bool {
        for (int x : V) if (x <= 0) return false;
        return true;
    };

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        int c = idx[S[i]];
        freq[c]++;

        if (containsEach(freq)) {
            for (int j = 0; j < M; ++j) freq[j]--;
        }

        ans += dp[freq];
        dp[freq]++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;

    while (t--) solve();
    return 0;
}
