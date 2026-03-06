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

void solve() {
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vi cntp(n+1,0),cnts(n+1,0);
    for(int i=0;i<n;i++){
        cnts[a[i]]++;
    }
    int smex=0;
    while (smex <= n && cnts[smex] > 0) {
        smex++;
    }
    int pmex=0;
    for(int i=0;i<n-1;i++){
        int x=a[i];
        cntp[x]++;
        cnts[x]--;
        while(cntp[pmex]>0){
            pmex++;
        }
        if(cnts[x]==0 && x<smex){
            smex=x;
        }

        while(smex>0 && cnts[smex-1]==0){
            smex--;
        }
        if(pmex==smex){
            cout<<2<<endl;
            cout<<1<<" "<<i+1<<endl;
            cout<<i+2<<" "<<n<<endl;
            return;
        }


    }
    cout<<-1<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}