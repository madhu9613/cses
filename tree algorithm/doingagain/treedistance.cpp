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
vector<vector<int>> adj;
vector<vector<int>> MAXDIST;
void dfs1(int u, int par = -1)
{
    for (auto &v : adj[u])
    {
        if (v == par)
            continue;
        dfs1(v, u); // go to child; bottom up building
        int new_dist = MAXDIST[v][0] + 1;
        if (new_dist > MAXDIST[u][0])
        {
            MAXDIST[u][1] = MAXDIST[u][0];
            MAXDIST[u][0] = new_dist;
        }
        else if (new_dist > MAXDIST[u][1])
        {
            MAXDIST[u][1] = new_dist;
        }
    }
}

void dfs2(int u, int par = -1)
{
    for (auto &v : adj[u])
    {
        if (v == par)
            continue;
        // re-roooting
        if (MAXDIST[u][0] == MAXDIST[v][0] + 1)
        {
            // give him the second best path as this path contrbute u for best ;
            int new_dist = MAXDIST[u][1] + 1;
            if (new_dist > MAXDIST[v][0])
            {
                MAXDIST[v][1] = MAXDIST[v][0];
                MAXDIST[v][0] = new_dist;
            }
            else if (new_dist > MAXDIST[v][1])
            {
                MAXDIST[v][1] = new_dist;
            }
        }
        else
        {
            int new_dist = MAXDIST[u][0] + 1;
            if (new_dist > MAXDIST[v][0])
            {
                MAXDIST[v][1] = MAXDIST[v][0];
                MAXDIST[v][0] = new_dist;
            }
            else if (new_dist > MAXDIST[v][1])
            {
                MAXDIST[v][1] = new_dist;
            }
        }

        dfs2(v,u);
    }
}
void solve()
{

    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    MAXDIST.resize(n + 1, vector<int>(2));
    dfs1(1);
    dfs2(1);
    for(int i=1;i<=n;i++)
    {
        cout<<MAXDIST[i][0]<<" ";
    }cout<<endl;

    // use concept of re-rooting first will calculate for the root=1 and after it using dfs i will propogate it to its child;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}