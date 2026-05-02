#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b)
{
 return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

void solve() {
    int n;cin>>n;
    vector<pair<ll,ll>>segs(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>segs[i].first>>segs[i].second;
    }
    auto can=[&](ll k)

    {
        ll low=0,high=0;
        for(auto [l,r]:segs)
        {
            low-=k; 

            high+=k;
            low=max(low,l);

            high=min(high,r);
            if(low>high) return false;
        }
        return true;
    };
    ll l=0,r=1e9,ans=-1;
    while (l<=r)
    {
        ll m=l+(r-l)/2;
        if(can(m))
        {
            ans=m;
            r=m-1;
        }
        else{
            l=m+1;
        }
        
    }

    cout<<ans<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}