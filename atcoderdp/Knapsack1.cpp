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
    ll n,w;cin>>n>>w;
    vector<array<ll,2>>knap(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>knap[i][0]>>knap[i][1];
    }
    vector<vector<ll>>dp(n+1,vector<ll>(w+1,0));
    
    for(int j=0;j<=w;j++)
    {
        if(knap[1][0]<=j) dp[1][j]=knap[1][1];
    }
     
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(knap[i][0]<=j)
            {
                dp[i][j]=max(dp[i][j],knap[i][1]+dp[i-1][j-knap[i][0]]);
            }
        }
    }

    cout<<dp[n][w]<<endl;
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}