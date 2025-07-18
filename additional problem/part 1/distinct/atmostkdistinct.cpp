// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    int n, k;
    cin >> n >> k;
    vll a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    unordered_map<ll, ll,custom_hash> freq;
    ll l = 1, ans = 0, distinct = 0;

    for (ll r = 1; r <= n; r++) {
        if (freq[a[r]] == 0) distinct++;
        freq[a[r]]++;

        while (distinct > k) {
            freq[a[l]]--;
            if (freq[a[l]] == 0) distinct--;
            l++;
        }

        ans += (r - l + 1);  // all subarrays ending at r and starting between l and r
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
