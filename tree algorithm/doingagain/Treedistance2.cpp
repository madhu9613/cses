// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

vector<vector<int>>adj;
vector<int>subtree_size; 
vector<int>sub_dis;
vector<int>dp;
int n;
void dfs1(int u,int par=-1)
{
    subtree_size[u]=1;
    sub_dis[u]=0;
    for(auto &v:adj[u])
    {
        if(v==par) continue;
         dfs1(v,u);
         subtree_size[u]+=subtree_size[v];
         sub_dis[u]+=subtree_size[v]+sub_dis[v];
    }
} 

void dfs2(int u,int par=-1)
{
    for(auto &v:adj[u])
    {
        if(v==par) continue;
        dp[v]=dp[u]+n-2*subtree_size[v];
        dfs2(v,u);
    }
}
void solve() {
 
    cin>>n;
    adj.resize(n+1);
    subtree_size.resize(n+1);
    sub_dis.resize(n+1);
    for(int i=1;i<n;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp.resize(n+1);
    dfs1(1);
    dp[1]=sub_dis[1];
    dfs2(1);
    for(int i=1;i<=n;i++)
    {
        cout<<dp[i]<<" ";

    }cout<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}