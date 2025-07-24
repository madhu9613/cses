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

// count the number of one bits in the binary representations of integers between 1 and n

void solve() {
ll n;
cin>>n;
ll total = 0;
    for (int i = 0; i < 60; ++i) {
        ll full = (n / (1LL << (i + 1))) * (1LL << i);
        ll rem = n % (1LL << (i + 1));
        ll extra = max(0LL, rem - (1LL << i) + 1);
        total += full + extra;
    }
    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}