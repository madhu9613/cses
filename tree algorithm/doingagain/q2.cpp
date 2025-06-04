#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<vector<int>>dp;

void dfs(int u,int p)
{
    for(int v:adj[u]) 
    {
        if(v!=p)
        {
            dfs(v,u);
            dp[u][0]+=max(dp[v][0],dp[v][1]);

        }
    }
    for(int v:adj[u])
    {
        if(v!=p)
        {
            dp[u][1]=max(dp[u][1],1+dp[u][0]+dp[v][0]-max(dp[v][0],dp[v][1]));
        }
    }
}
int main()
{
    int n;
    cin>>n;
    adj.resize(n+1);
    dp.resize(n+1,vector<int>(2));
    for(int i=1;i<n;i++)
    {

        int u,v;cin>>u>>v;  cout<<max(dp[1][0],dp[1][1]);

    return 0;
}