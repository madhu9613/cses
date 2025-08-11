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

ll gcdll(ll a, ll b) {
    return b == 0 ? a : gcdll(b, a % b);
}
ll lcmll(ll a, ll b) {
    return a / gcdll(a, b) * b;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll cycler = 2 * (n - 1);
    ll cyclec = 2 * (m - 1);

    ll period = lcmll(cycler, cyclec);

    ll p = n - 1;
    ll q = m - 1;
    ll g = gcdll(p, q);
    ll p1 = p / g;
    ll q1 = q / g;

    ll A0 = p1 / 2 + 1;
    ll Ag = (p1 + 1) / 2;
    ll B0 = q1 / 2 + 1;
    ll Bg = (q1 + 1) / 2;

    ll visited = (g - 1) * p1 * q1 + (A0 * B0 + Ag * Bg);

    cout << period << " " << visited << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
