//its basically queation related to topological sort

#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >adj;
vector<int> topo_order;
int n,m;
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

    //now printing this topological order;
    if(topo_order.size()!=n)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    for(auto &c:topo_order)
   {
    cout<<c<<" ";
   }
   cout<<endl;
 }
int main()
{
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
    }
    topologicalsort();
    return 0;
}