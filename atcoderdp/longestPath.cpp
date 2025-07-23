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
//doesnot contain directed circle means DAG, toposort+dp

void solve() {
int n,m;cin>>n>>m;
vector<vector<int>>adj(n+1);
vector<int>indegree(n+1);
for(int i=0;i<m;i++)
{
    int x,y;cin>>x>>y;
    adj[x].pb(y);
    indegree[y]++;
}
queue<int>q;
for(int i=1;i<=n;i++)
{
    if(indegree[i]==0)
    {
        q.push(i);
    }
}
vector<int>order;
while (!q.empty())
{
    int node=q.front();q.pop();
    order.pb(node);
    for(auto &v:adj[node])
    {
     if(--indegree[v]==0)
     {
        q.push(v);
     }
    }
}

vector<int>dp(n+1,0);
for(auto u:order)
{
   for(auto &v:adj[u])
   {
    dp[v]=max(dp[v],dp[u]+1);
   }
}
cout<<*max_element(all(dp))<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}