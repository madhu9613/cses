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
const ll LIM=1e12;
const int MAXN = 40005;
void solve() {
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<vector<int>> lst(n, vector<int>(26, -1));
    for (int i = 0; i < n; i++) {
        if (i > 0) lst[i] = lst[i - 1];
        lst[i][s[i] - 'a'] = i;
    }

    vector<vector<ll>> dp(n, vector<ll>(n + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][1] = 1;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i < n; i++) {
            ll sum = 0;
            for (int c = 0; c < 26; c++) {
                int pos = lst[i - 1][c];
                if (pos != -1) {
                    sum += dp[pos][len - 1];
                    if (sum > LIM) {
                        sum = LIM;
                        break;
                    }
                }
            }
            dp[i][len] = sum;
        }
    }

    ll ans = 0;

    for (int len = n; len >= 1 && k > 0; len--) {
        ll cnt = 0;
        for (int c = 0; c < 26; c++) {
            int pos = lst[n - 1][c];
            if (pos != -1) {
                cnt += dp[pos][len];
                if (cnt > LIM) {
                    cnt = LIM;
                    break;
                }
            }
        }

        if (cnt >= k) {
            ans += k * (n - len);
            k = 0;
        }
        else {
            ans += cnt * (n - len);
            k -= cnt;
        }
    }

    if (k > 0) {
        ans += n;
        k--;
    }

    if (k > 0) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}