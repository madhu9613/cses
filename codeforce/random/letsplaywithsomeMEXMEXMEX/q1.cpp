//implementation;
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
const int MAXN=50000;
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

//O(nlog(n)
int mex(vi const& a){
    set<int>b(all(a));
    int res=0;
    while(b.count(res))
    {
    ++res;
    }
    return res;
}

// O(n)

int mex2(vector<int> const& A) {
    static bool used[MAXN + 1] = { 0 };

    for (int x : A) {
        if (x <= MAXN)
            used[x] = true;
    }

    int result = 0;
    while (used[result])
        ++result;

    for (int x : A) {
        if (x <= MAXN)
            used[x] = false;
    }

    return result;
}

class Mex{
    private:
    vi freq;
    set<int>missing;
    vi A;
    int n;
    public:
    Mex(const vi & arr){

        A=arr;
        n=A.size();
        freq.assign(n+1,0);

        for(int i=0;i<=n;i++){
            missing.insert(i);
        }
        for(int x:A){
            if(x<=n){
                freq[x]++;
            missing.erase(x);
            }
        }
    }
    int mex(){
        return *missing.begin();
        }

        void update(int idx,int val){
            int old=A[idx];
            if(old<=n){
                freq[old]--;
                if(freq[old]==0){
                    missing.insert(old);
                }
            }
            A[idx]=val;
            if(val<=n){
                if(freq[val]==0){
                    missing.erase(val);
                }
                freq[val]++;
            }
        }
};
void solve() {
    vector<int> arr = { 0, 1, 2, 4 };

    Mex mexDS(arr);

    cout << mexDS.mex() << endl;   // 3

    mexDS.update(2, 3);            // change index 2 from 2 → 3

    cout << mexDS.mex() << endl;   // 2
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}