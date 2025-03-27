// A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?

//its a queation where DAG is given and we need to find no of ways to reach 1 to n so we are  using dp
//dp[i] = its represent no of ways to reach i from 1;

//here are no directed cycles in the flight network.
//here its DAG in this type of graph we found topological order and 
//dp[i] = max number of city between city 1 and ith we need to maximise it so we are inititialising them with -infinity



#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>adj;
vector<int>topo_order,dp,parent;
const int INF=-1e9;
const int MOD=1e9+7;
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

 void noofways()
 {
    //lets say i am at u so no of ways to reahc v is dp[v]=(dp[u]+dp[v])%MOD
    dp[1]=1; //no of ways to reach 1 is 1
    for(auto &u:topo_order)
    {
       
        for(auto &v:adj[u])
        {
         dp[v]=(dp[u]+dp[v])%MOD; 
        }
    }
   
    cout<<dp[n]<<endl;
   
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
    dp.resize(n+1,0);
    parent.resize(n+1,-1);
    topologicalsort();
   noofways();
return 0;
}