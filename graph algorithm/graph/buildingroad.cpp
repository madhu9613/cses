#include<bits/stdtr1c++.h>
using namespace std;
int n,m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int>citys;

void dfs(int node)
{
    visited[node]=true;
    for(int n:adj[node])
    {
        if(!visited[n])
        {
            dfs(n);
        }
    }
}
int main()
{
    cin>>n>>m;
    adj.resize(n+1);
    visited.assign(n+1,false);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
       {
        citys.push_back(i);
        dfs(i);
        c++;
       }
    }

    cout<<c-1<<endl;

    for(int i=1;i<c;i++)
    {
        cout<<citys[i-1]<<" "<<citys[i]<<endl;
    }
    return 0;
}