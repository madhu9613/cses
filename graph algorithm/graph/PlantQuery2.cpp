// it was a hard problem for me its toughest one till now to understamd some point i have understand from this i write it down fro
// future help

#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> tele;
vector<bool> visited;
vector<int> len;
const int LOG = 20;
vector<vector<int>> up;

int lift(int a, int x)
{

    if (x < 0)
        return 0;

    for (int j = 0; j < LOG; j++)
    {
        if (x & (1 << j))
        {
            a = up[a][j];
        }
    }
    return a;
}

void dfs(int node)
{
    if(visited[node]) return;

    visited[node]=true;
    dfs(tele[node]);
    len[node]=len[up[node][0]]+1;
}
int main()
{
    int n, q;
    cin >> n >> q;
    tele.resize(n + 1);
    visited.resize(n + 1, false);
    len.resize(n + 1, 0);
    up.resize(n + 1, vector<int>(20));
    for (int i = 1; i <= n; i++)
    {
        cin >> tele[i];
        up[i][0] = tele[i];
    }
    // contruct binary lifting table;

    for (int j = 1; j < LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }

    while (q--)
    {
        int a,b;cin>>a>>b;
        int cycle_entry_a=lift(a,len[a]);
        int ans;
        // case 1 :if b in the path of a;
        if(lift(a,len[a]-len[b])==b)
        {
            ans=len[a]-len[b];
        }
        // case 2: if a and b on same cycle
        else if(lift(cycle_entry_a,len[cycle_entry_a]-len[b])==b)
        {
            ans=(len[cycle_entry_a]-len[b])+len[a];
        }
        else{
            ans=-1;
        }

        cout<<ans<<endl;
    }
    

    return 0;
}