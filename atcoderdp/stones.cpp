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

//dp[i]=if current player forces opponnt for a losse'


void solve() {
int n,k;cin>>n>>k;
vi a(n);
for(int i=0;i<n;i++)
{
    cin>>a[i];
}

vector<bool>dp(k+1,false);

for(int i=1;i<=k;i++)
{
    for(int x:a)
    {
        if(i-x>=0 && !dp[i-x])
        {
            dp[i]=true;
            break;
        }
    }
}

cout<<(dp[k]?"First":"Second")<<endl;

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   
    while (t--) solve();
    return 0;
}