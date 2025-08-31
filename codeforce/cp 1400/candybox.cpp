#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vi a(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    vi freqs;
    for (auto &[type, f] : freq) {
        freqs.pb(f);
    }

    sort(rall(freqs));

    int ans = 0;
    int last_taken = INT_MAX;

    for (int f : freqs) {
        int take = min(f, last_taken - 1);
        if (take <= 0) break;
        ans += take;
        last_taken = take;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
