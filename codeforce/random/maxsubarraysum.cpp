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
    int n;
    ll k;cin>>n>>k;
    string s;cin>>s;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll maxi=LLONG_MIN;
    ll cur=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            cur=max(a[i],cur+a[i]);
            maxi=max(maxi,cur);
        }else{
            cur=0;
        }
    }

    if(maxi==LLONG_MIN) maxi=0;
    if(maxi>k){
        cout<<"No"<<endl;
        return;

    }
    bool zero=false;
    for(int i=0;i<n;i++){
        if(s[i]=='0')
        {
            zero=true;
        }
    }
    if(!zero){
        if(maxi==k){
            cout<<"Yes"<<endl;
            for(auto x:a)cout<<x<<" ";
            cout<<endl;
        }else{
            cout<<"No"<<endl;
        }
        return;
    }

    int pos=-1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            pos = i;
            break;
        }
    }
    ll L=0,sum=0;
    for(int i=pos-1;i>=0 && s[i]=='1';i--){
        sum+=a[i];
       L=max(L,sum);
    }

    ll R=0;
    sum=0;
    for(int i=pos+1;i<n && s[i]=='1' ;i++){
        sum+=a[i];
        R=max(R,sum);
    }
    a[pos]=k-L-R;
    for(int i=0;i<n;i++){
        if(s[i]=='0' && i!=pos){
            a[i]=-1e17;
        }
    }
    cout<<"Yes"<<endl;
    for(auto x:a) cout<<x<<" ";
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