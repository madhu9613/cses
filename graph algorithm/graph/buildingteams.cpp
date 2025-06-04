#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> adj;
vector<bool>visited;
vector<int> team;

bool bfs(int i)
{
    
queue<int> q;
q.push(i);
visited[i]=true;
team[i]=1;
while (!q.empty())
{
    int node=q.front();
    q.pop();

    for(auto n:adj[node])
    {
      if(!visited[n])
      {
       team[n]=3-team[node];
       visited[n]=true;
       q.push(n);
      }
      else if(team[node]==team[n])
      {
        return false;
      }
    
    }
    
}
return true;

}
int main()
{
cin>>n>>m;
adj.resize(n+1);
visited.assign(n+1,false);
team.resize(n+1);
for(int i=0;i<m;i++)
{
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
//now do bfs;

for(int i=1;i<=n;i++)

{
    if(!visited[i])
    {
       if(!bfs(i))
       {
        cout<<"IMPOSSIBLE\n";
        return 0;
       }
    }
}


for(int i=1;i<=n;i++)
{
    cout<<team[i]<<" ";
}
cout<<endl;

    return 0;
}