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

#define int ll


vector<int>ask(int k){
    cout<<"? "<<k<<endl;
    cout.flush();
    int len;
    cin>>len;
    if (len==-1) {
         exit(0);
    }

    vi res(len);
    for(int i=0;i<len;i++){
        cin>>res[i];
    }
    return res;
}

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> edges;

    for (int i = 1; i <= n; i++) {
        int prev = -1;

        while (true) {
            int l = 1, r = (1LL << 30);
            int pos = -1;
            vector<int> best;

            while (l <= r) {
                int mid = (l + r) / 2;
                auto path = ask(mid);

                if (path.empty() || path[0] > i) {
                    r = mid - 1;
                }
                else if (path[0] < i) {
                    l = mid + 1;
                }
                else {
                    if (path.size() > 1 && path[1] > prev) {
                        pos = mid;
                        best = path;        
                        r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
            }

            if (pos == -1) break;

            edges.push_back({ best[0], best[1] });
            prev = best[1];
        }
    }

    cout << "! " << edges.size() << endl;
    for (auto& e : edges) {
        cout << e.first << " " << e.second << endl;
    }
    cout.flush();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}