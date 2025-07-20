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
vector<vector<int>>adj;
vector<int> dfs(int u,int p=-1)
{
   vector<int>dp={0,0};
    for(auto &v:adj[u])
    {
        if(v==p) continue;
        auto child_dp=dfs(v,u);
        dp[1]=max({
            dp[0]+child_dp[0]+1,
            dp[1]+child_dp[1],
            dp[1]+child_dp[0]
        });
        dp[0]+=max(child_dp[0],child_dp[1]);
        
    }
    return dp;
}
void solve() {
int n;cin>>n;
adj.resize(n+1);
for(int i=0;i<n-1;i++)
{
    int a,b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
}

vector<int>ans=dfs(1);
cout<<max(ans[0],ans[1])<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}