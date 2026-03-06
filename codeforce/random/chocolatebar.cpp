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

ll dp[31][31][51];
void solve() {

   
int n,m,k;cin>>n>>m>>k;
cout<<dp[n][m][k]<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int n = 1;n <= 30;n++) {
        for (int m = 1;m <= 30;m++) {
            for (int k = 0;k <= 50;k++) {
                if (k == 0 || k == n * m) {
                    dp[n][m][k] = 0;
                    continue;
                }
                dp[n][m][k] = INF;


                for (int i = 1;i < m;i++) {
                    for (int x = 0;x <= k;x++) {
                        if (x <= n * i && k - x <= n * (m - i)) {
                            dp[n][m][k] = min(dp[n][m][k],
                                n * n + dp[n][i][x] + dp[n][m - i][k - x]);
                        }
                    }
                }

                for (int i = 1;i < n;i++) {
                    for (int x = 0;x <= k;x++) {
                        if (x <= i * m && k - x <= (n - i) * m) {
                            dp[n][m][k] = min(dp[n][m][k],

                                m * m + dp[i][m][x] + dp[n - i][m][k - x]);
                        }
                    }
                }

            }
        }
    }
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}