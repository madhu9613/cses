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

vector<int>ask(int k) {
    cout << "? " << k << endl;
    cout.flush();
    int len;
    cin >> len;
    if (len == -1) {
        exit(0);
    }

    vi res(len);
    for (int i = 0;i < len;i++) {
        cin >> res[i];
    }
    return res;
}

void solve() {
    int n;cin>>n;
    vector<vector<int>>g(n+1);
    vi cnt(n+1,-1);
    int m=0;
    function<void(int)> calc=[&](int v){
        if(cnt[v]!=-1) return ;
        cnt[v]=1;
        for(int u:g[v]){
            calc(u);
            cnt[v]+=cnt[u];
        }
    };

    vi prev={1};
    int k=2;
    while (true) {
        auto cur = ask(k);
        if (cur.empty()) break;

        int common = 0;
        for (int i = 0; i < min(prev.size(), cur.size()); i++) {
            if (cur[i] != prev[i]) break;
            common++;
        }

        if ((int)prev.size() > common) {
            calc(prev[common]);
        }

        if (common > 0 && common < cur.size()) {
            int u = cur[common - 1];
            int v = cur[common];
            g[u].push_back(v);
            m++;
        }

        if (common < cur.size()) {
            int v = cur[common];
            if (cnt[v] == -1) k++;
            else k += cnt[v];
        }
        else {
            k++;
        }

        prev = cur;
    }
    cout<<"! "<<m<<endl;
    for(int i=1;i<=n;i++){
        for(int u:g[i]){
            cout<<i<<" "<<u<<endl;
        }
    }
    cout.flush();

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}