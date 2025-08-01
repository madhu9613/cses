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

void solve() {
int n;cin>>n;
vll p(n);
ll total=0;
for(int i=0;i<n;i++)
{
     cin>>p[i];
    total+=p[i];
}
ll ans=LLONG_MAX;
for(int mask=0;mask<(1<<n);++mask)
{
    ll g1=0;
    for(int i=0;i<n;++i)
    {
        if(mask&(1<<i))
        {
            g1+=p[i];
        }
    }
    ll g2=total-g1;
    ans=min(ans,abs(g1-g2));

}

cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}