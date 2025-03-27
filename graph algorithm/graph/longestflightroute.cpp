//here are no directed cycles in the flight network.
//here its DAG in this type of graph we found topological order and 
//dp[i] = max number of city between city 1 and ith we need to maximise it so we are inititialising them with -infinity



#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>adj;
vector<int>topo_order,dp,parent;
const int INF=-1e9;
void topologicalsort()
{
    vector<int> indegree(n+1,0);
    queue<int>q;
    for(int u=1;u<=n;u++)
    {
        for(auto &v :adj[u])
        { 
            indegree[v]++;
        
        }
    }

    for(int u=1;u<=n;u++)
    {
        if(indegree[u]==0)
        {
            q.push(u);
        }
    }
    while(!q.empty())
    {
        int node=q.front(); q.pop();
        topo_order.push_back(node);
        for(auto v:adj[node])
        {
            indegree[v]--;
            if(indegree[v]==0)
            {
                q.push(v);
            }
        }

    }

 }

 void find_longest_route()
 {
    dp[1]=1; //maxima city between 1 and 1 is 1
    for(auto &u:topo_order)
    {
        if(dp[u]==INF)
        {
            continue;
        }
        for(auto &v:adj[u])
        {
            if(dp[u]+1>dp[v])
            {
                dp[v]=dp[u]+1;
                parent[v]=u;

            }
        }
    }
    if(dp[n]==INF)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<dp[n]<<endl;
    // Reconstruct path
    vector<int> path;
    for (int v = n; v != -1; v = parent[v])
        path.push_back(v);
    
    reverse(path.begin(), path.end());
    for (int v : path) cout << v << " ";
    cout << "\n";
 }

int main()
{
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++)
    {   
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    
    }
    dp.resize(n+1,INF);
    parent.resize(n+1,-1);
    topologicalsort();
   find_longest_route();
return 0;
}