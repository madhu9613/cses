// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
int n, q;
const int MAXN = 200005;
int up[MAXN][20];
vector<vi> adj;
vi starting;
vi ending;

vi depth;
void dfs1(int node, int par = -1)
{
    up[node][0] = par;
    for (int j = 1; j < 20; j++)
    {
        if (up[node][j - 1] != -1)
            up[node][j] = up[up[node][j - 1]][j - 1];
        else
            up[node][j] = -1;
    }
    for (int c : adj[node])
    {
        if (c == par)
            continue;
        depth[c] = depth[node] + 1;
        dfs1(c, node);
    }
}

int lift(int node, int d)
{
    for (int i = 0; i < 20; i++)
    {
        if ((d >> i) & 1)
        {
            node = up[node][i];
        }
       
    }
     return node;
}
int lca(int u,int v)
{
    if(depth[u]<depth[v]) swap(u,v);
    u=lift(u,depth[u]-depth[v]);
    if(u==v) return u;
    for(int i=19;i>=0;i--)
    {
        if(up[u][i]!=up[v][i])
        {
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}

vi dp;

int dfs2(int u,int par=-1)
{
    int current_path=starting[u];
    for(auto v:adj[u])
    {
        if(v==par) continue;
        current_path+=dfs2(v,u);
    }
   
    dp[u]=current_path-ending[u];
    return current_path-2*ending[u];
}

void solve()
{
    cin >> n >> q;
    adj.resize(n + 1);
    starting.resize(n + 1,0);
    ending.resize(n + 1,0);
    depth.resize(n+1,0);
    dp.resize(n+1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs1(1);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        starting[a]++;
        starting[b]++;
       ending[lca(a,b)]++;
    }
    dfs2(1);
    for(int i=1;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}