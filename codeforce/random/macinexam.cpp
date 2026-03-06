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

const int MAXN = 200000 + 5;
const int B = 30;

int n;
ll L[MAXN], R[MAXN], W[MAXN];
int bits[B][MAXN];

struct SegTree {

    vector<ll> tree;
    int n;

    SegTree(int n) {
        this->n = n;
        tree.resize(4 * n);
    }

    void build(int node, int l, int r) {

        if (l == r) {
            tree[node] = W[l];
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = tree[node * 2] | tree[node * 2 + 1];
    }

    ll query(int node, int l, int r, int ql, int qr) {

        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return query(node * 2, l, mid, ql, qr) |
            query(node * 2 + 1, mid + 1, r, ql, qr);
    }

};


void fix(){

    for(int i=0;i<n;i++){
        if(L[i]==R[i]){
            W[i]=L[i];
            L[i]=R[i]=0;
            continue;
        }
        int diff=L[i]^R[i];
        int mask=(1<<(__lg(diff)+1))-1;
        W[i]=R[i]-(R[i]&mask);
        L[i]&=mask;
        R[i]&=mask;
    }
}

void solve() {
cin>>n;
for(int i=0;i<n;i++){
    cin>>L[i]>>R[i];

}
fix();

SegTree seg(n);
seg.build(1,0,n-1);

for(int b=0;b<B;b++){
    bits[b][0]=0;
}
for(int i=0;i<n;i++){
    for(int b=0;b<B;b++){
        bits[b][i+1]=bits[b][i];
        if((R[i]>>b)&1){
            bits[b][i+1]++;
        }
    }
}

int q;cin>>q;
while(q--){
    int l,r;
    cin>>l>>r;
    l--;r--;

    ll ans=seg.query(1,0,n-1,l,r);
    for(int b=B-1;b>=0;b--){
        int cnt=bits[b][r+1]-bits[b][l]+((ans>>b)&1);
        if(cnt>1){
            ans|=(2LL<<b)-1;
            break;
        }

        else if(cnt==1){
            ans|=(1ll<<b);
        }
    }
    cout<<ans<<" ";
}
cout<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}