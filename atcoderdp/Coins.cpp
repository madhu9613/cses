// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
int n;cin>>n;
vector<double>p(n+1); //p[i]=>probabiliry that it will be a head';
for(int i=1;i<=n;i++)
{
    cin>>p[i];
}
// n is odd 1,2,3,4,5..numner of head should be more than tail <(n+1)/2;
vector<vector<double>>dp(n+1,vector<double>(n+1,0.0));

dp[0][0]=1.0 ;//coin 0.head also zero; so probalbilit is also 1'

for(int i=1;i<=n;i++)
{
   
    for(int j=0;j<=i;j++)
    { //this coin is a tail
        dp[i][j]+=dp[i-1][j]*(1.0-p[i]);

        if(j>0)
        {
            dp[i][j]+=dp[i-1][j-1]*p[i];
            //preveously their are j-1 head now it become j
        }
    }
}

int mhead=(n+1)/2;
double res=0.0;
for(int k=mhead;k<=n;k++)
{
    res+=dp[n][k];
}
cout<<fixed<<setprecision(10)<<res<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}