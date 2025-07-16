// need to find cycle in directed graph
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<bool> dfsvisited;
vector<bool> visited;
vector<int> cycle;
vector<int> parent;
int cycle_start = -1, cycle_end = -1;

bool dfs(int node)
{
    visited[node] = true;
    dfsvisited[node]=true;
    for (auto &neighb : adj[node])
    {
        if (!visited[neighb])
        {
            parent[neighb] = node;
            if (dfs(neighb))
            {
                return true;
            }
        }
        else if (dfsvisited[neighb])
        { // cycle detected;
            cycle_start = neighb;
            cycle_end = node;
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

void findcycle()
{
    for(int i=1;i<n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i)) //if cycle detected then early exist;
            {
                break;
            }
        }

    }
    if(cycle_start==-1)
    {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cycle.push_back(cycle_start);
    for(int v=cycle_end;v!=cycle_start;v=parent[v])
    {
        cycle.push_back(v);
    }
    cycle.push_back(cycle_start);
    reverse(cycle.begin(),cycle.end());

    // print the cycle;
    cout<<cycle.size()<<endl;
    for(int p:cycle)
    {
        cout<<p<<" ";
    }
    cout<<endl;
}


int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    dfsvisited.resize(n + 1, false);
    visited.resize(n + 1, false);
    parent.resize(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    findcycle();
    return 0;
}