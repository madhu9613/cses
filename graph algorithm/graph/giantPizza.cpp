// THis is a very special problem .2-SAT problem
// every member has 2 wises (x V y) we will implement a graph -x->y and -y->x it means if not x then y and if not y then xor
// like this we will construct an graph and apply scc:kasuraju algorithm

#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj, rev_adj;
vector<bool> visited;
vector<int> component;
vector<bool> asignment;
vector<int> TopoOrder;
int n, m;
int negation(int x)
{
    return x < n ? x + n : x - n;
}

void addClause(int x, int y)
{
    adj[negation(x)].push_back(y);
    adj[negation(y)].push_back(x);
    rev_adj[y].push_back(negation(x));
    rev_adj[x].push_back(negation(y));
}

void dfs1(int u)
{
    visited[u] = true;
    for (int &v : adj[u])
    {
        if (!visited[v])
        {
            dfs1(v);
        }
    }
    TopoOrder.push_back(u);
}
void dfs2(int u, int comp)
{
    component[u] = comp;
    for (int v : rev_adj[u])
    {
        if (component[v] == -1)
        {
            dfs2(v, comp);
        }
    }
}
int main()
{
    cin >> m >> n;
    adj.resize(2 * n + 1);
    rev_adj.resize(2 * n + 1);
    for (int i = 0; i < m; i++)

    {
        string sign1, sign2;
        int x, y;
        cin >> sign1 >> x >> sign2 >> y;
        if (sign1 == "-")
            x = negation(x);
        if (sign2 == "-")
            y = negation(y);
        addClause(x, y);
    }

    visited.resize(2 * n + 2, false);
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }

reverse(TopoOrder.begin(),TopoOrder.end());

    component.resize(2*n+1,-1);
    int comp=0;
    for(auto &order:TopoOrder)
    {
        if(component[order]==-1)
        {
            dfs2(order,++comp);
        }
    }

    asignment.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        if(component[i]==component[negation(i)])
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        asignment[i]=component[i]>component[negation(i)];
    }

    for(int i=1;i<=n;i++)
    {
        cout<<(asignment[i] ?"+":"-")<<" ";
    }cout<<endl;

    return 0;
}