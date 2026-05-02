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

void solve() {
   int n, k;
    cin >> n >> k;
    vll a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vi good(n, 0);
    for(int i = 1; i < n; i++) {
        if(2 * a[i] > a[i-1]) good[i] = 1;
    }

    int cnt = 0, s = 0;
    for(int i = 1; i < n; i++) {
        s += good[i];
        if(i >= k) s -= good[i - k];
        if(i >= k && s == k) cnt++;
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}