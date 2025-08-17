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
//child i can get 0 to a[i] number of candies : no of diff way to distribute k candys;
//d1,d2,d3,d4....dn ans=#possible mno of seq; 

void solve() {

 int n,k;cin>>n>>k;

 vi a(n+1);
 for(int i=1;i<=n;i++)
 {
    cin>>a[i];
 }
 vector<vector<int>>dp(n+1,vector<int>(k+1,0));
 dp[0][0]=1;
 for(int i=1;i<=n;i++)
 {
    vector<int>prefix(k+1,0);
    prefix[0]=dp[i-1][0];
    for(int j=1;j<=k;j++)
    {
        prefix[j]=(prefix[j-1]+dp[i-1][j])%MOD;
    }
    for(int j=0;j<=k;j++)
    {
        int left=j-a[i]-1;
        if(left>=0)
        {
            dp[i][j]=(prefix[j]-prefix[left]+MOD)%MOD;
        }else{
            dp[i][j]=prefix[j];
        }
    }
 }

 cout<<dp[n][k]<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}