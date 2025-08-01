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
ll power(ll a,ll b)
{
ll res=1;
a=a%MOD;
while(b>0)
{
    if(b&1)
    {
        res=(res*a)%MOD ;
    }
    a=(a*a)%MOD;
    b>>=1;
}
return res;
}
void solve() {
    int n;cin>>n;
    cout<<power(2,n)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}