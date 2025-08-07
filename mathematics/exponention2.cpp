#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
 return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
ll power(ll a,ll b,ll m)
{
ll res=1;
a=a%m;
while(b>0)
{
    if(b&1)
    {
        res=(res*a)%m ;
    }
    a=(a*a)%m;
    b>>=1;
}
return res;
}
void solve() {
    ll a,b,c;cin>>a>>b>>c;
    cout<<power(a,power(b,c,MOD-1),MOD)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}