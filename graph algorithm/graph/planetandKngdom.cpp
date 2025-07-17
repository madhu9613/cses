// kingdom a,b belong to a planet if and only if their is a route from a to b and b to a

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj,rev_adj;
vector<int>Kingdom;
vector<bool>visited;
vector<int>topoOrder;
int n,m;

void dfs1(int u)
{
    visited[u]=true;
    for(auto &v:adj[u])
    {
        if(!visited[v])
        {
        dfs1(v);
        }
    }
    topoOrder.push_back(u);
}

 void dfs2(int u,int label)
{
    visited[u]=true;
    Kingdom[u]=label;
    for(auto &v:rev_adj[u])
    {
        if(!visited[v])
        {
        dfs2(v,label);
    }
}

}
int main()
{
    cin>>n>>m;
    adj.resize(n+1);
    rev_adj.resize(n+1);
    Kingdom.resize(n+1,0);
    visited.resize(n+1,false);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs1(i);
        }
    }

    reverse(topoOrder.begin(),topoOrder.end());
    visited.assign(n+1,false);
    int lable=0;
    for(auto &order:topoOrder)
    {
        if(!visited[order])
        {
            dfs2(order,++lable);
        }
    }
   
    cout<<lable<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<Kingdom[i]<<" ";
    }
    cout<<endl;
    return 0;
}