// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

int n, m;
vector<vector<int>> adj;
vector<int> indegree;
vector<int> outdegree;
vector<int> path;

void dfs(int u)
{
    while (outdegree[u] > 0)
    {
        int v = adj[u].back();
        adj[u].pop_back();
        outdegree[u]--;
        dfs(v);
    }
    path.pb(u);
}

void solve()
{
    cin >> n >> m;
    adj.assign(n + 1, {});
    indegree.assign(n + 1, 0);
    outdegree.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);    
        outdegree[a]++;
        indegree[b]++;
    }

    for (int i = 2; i <= n - 1; i++)
    {
        if (indegree[i] != outdegree[i])
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    if (outdegree[1] - indegree[1] != 1 || indegree[n] - outdegree[n] != 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    dfs(1);
    reverse(path.begin(), path.end());

    if ((int)path.size() != m + 1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
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
