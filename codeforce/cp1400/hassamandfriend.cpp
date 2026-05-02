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
int n,m;cin>>n>>m;
vi nearestenemy(n+1,0);

for(int i=0;i<m;i++)
{
    int a,b;cin>>a>>b;

    if(a>b) swap(a,b);

    nearestenemy[b]=max(nearestenemy[b],a);


}
vi dp(n+1);
dp[1]=1;

ll ans=1;

for(int i=2;i<=n;i++)
{
    dp[i]=max(dp[i-1],nearestenemy
    [i]+1);
    ans+=i-dp[i]+1;
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