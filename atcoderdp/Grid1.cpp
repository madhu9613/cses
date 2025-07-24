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
int n,m;cin>>n>>m;
vector<string>grid(n);
for(int i=0;i<n;i++)
{
cin>>grid[i];
//dp[i][j]=no of ways to reach i,j from 1,1
}

vector<vector<ll>>dp(n,vector<ll>(m,0));
dp[0][0]=1;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]=='#') continue;
        if(i>0) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
        if(j>0) dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;

    }
}

cout<<dp[n-1][m-1]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}