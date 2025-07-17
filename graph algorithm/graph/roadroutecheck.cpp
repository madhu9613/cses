//strongly connected components checking

#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>adj;
vector<vector<int>>rev_adj;
vector<bool>visited;
void dfs1(int node)
{
    visited[node]=true;
    for(auto &u:adj[node])
    {
        if(!visited[u])
        {
            dfs1(u);
        }
    }
}

void dfs2(int node)
{
    visited[node]=true;
    for(auto &u:rev_adj[node])
    {
        if(!visited[u])
        {
            dfs2(u);
        }
    }
}
int main()
{
    cin>>n>>m;
    adj.resize(n+1);
    rev_adj.resize(n+1);
    visited.resize(n+1,false);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
   dfs1(1);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            return 0;
        }
    }
    visited.assign(n+1,false);
    dfs2(1);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    return 0;
}