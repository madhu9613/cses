#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;
int main ()
{
    cin>>n>>m;
    adj.resize(n+1);
    parent.resize(n+1);
    visited.assign(n+1,false);
   
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //now do bfs;
    queue<int> q;
    q.push(1);
    parent[1]=-1;
    visited[1]=true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int n:adj[node])
        {
         if(!visited[n])
         {
            visited[n]=true;
            parent[n]=node;
            q.push(n);
         }   
        }
    }

    //check if i reach n and reconstruct the path
    if(!visited[n])
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    vector<int> path;
    int cur=n;
    path.push_back(cur);
    while(cur!=1)
    {   
  
        int prev=parent[cur];
        path.push_back(prev);
        cur=prev;
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(auto i: path)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}