#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll pow(ll a,ll b,ll m)
{
if(b==0)
 return 1;
if(b==1) return a%m;
 ll temp=pow(a,b/2,m);
 if(b%2==0)
 {
 return (temp*temp)%m;
}
else
{
return (a*(temp*temp)%m)%m ;
}
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

const int MAXN = 40005;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> seg(m);
    for (int i = 0; i < m; i++) {
        cin >> seg[i].first >> seg[i].second;
    }

    int q;
    cin >> q;

    vi queries(q + 1);
    for (int i = 1; i <= q; i++) cin >> queries[i];

    vi time(n + 1, INT_MAX);
    for (int i = 1; i <= q; i++) {
        time[queries[i]] = i;
    }

    auto good = [&](int k) -> bool {
        vi pref(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int val = (time[i] <= k ? 1 : -1);
            pref[i] = pref[i - 1] + val;
        }

        for (auto [l, r] : seg) {
            if (pref[r] - pref[l - 1] > 0)
                return true;
        }
        return false;
        };

    int ans = -1;
    int low = 1, high = q;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (good(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}