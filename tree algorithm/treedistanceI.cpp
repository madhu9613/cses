/*
You are given a tree consisting of n nodes.
Your task is to determine for each node the maximum distance to another node.
*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
int  bfs(int start,int n)
{   
    int maxdistance=0;
    vector<bool> visited(n+1,false);
    vector<int> distance(n+1,-1);
    queue<int> q;
    q.push(start);
    //distance from start to start node is definetly 0
    visited[start]=true; distance[start]=0; 
    while(!q.empty())
    {
        int node=q.front(); q.pop();
        for(auto &neighbour: adj[node])
        {
            if(visited[neighbour]!=true)
            {

                distance[neighbour]=1+distance[node];
                visited[neighbour]=true;
                q.push(neighbour);
                if(distance[neighbour]>maxdistance)
                {
                    maxdistance=distance[neighbour];
                    // farthestnode=neighbour;
                }
            }
        }
    }
    return maxdistance; 
}
int main()
{
    int n;
    cin>>n;
    adj.resize(n + 1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    vector<int>result;

   for(int i=1;i<=n;i++)
   {
       
int ans=bfs(i,n);
result.push_back(ans);

   }

for(auto i:result)
{
    cout<<i<<" ";
}

    return 0;
}