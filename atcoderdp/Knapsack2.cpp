// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

//here after reading i found one constraint that (W) can be 10^9 it may leads to TLE for the current one 

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    ll n,w;cin>>n>>w;
    vector<array<ll,2>>knap(n+1);
    ll mval=0;
    for(int i=1;i<=n;i++)
    {
        cin>>knap[i][0]>>knap[i][1];
        mval+=knap[i][1];
    }
  
    //dp[v]=minimum total weight needed to achieve total value=v;
    vector<ll>dp(mval+1,INF);
    dp[0]=0;
    for(auto &[wt,val]:knap)
    {
        for(ll v=mval;v>=val;v--)
        {
            dp[v]=min(dp[v],dp[v-val]+wt);

        }
    }

    for(ll v=mval;v>=0;v--)
    {
        if(dp[v]<=w)
        {
            cout<<v<<endl;
             return;
        }
    }
   
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}