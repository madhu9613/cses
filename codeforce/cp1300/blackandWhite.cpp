#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> nodes;

int dfs(int node, string s, int &ans)
{
    if (adj[node].size() == 0)
    {
        return s[node - 1] == 'W' ? 1 : -1;
    }

    int count = 0;
    for (auto &child : adj[node])
    {
        count += dfs(child, s, ans);
    }

    // Add the current node's color
    count += (s[node - 1] == 'W' ? 1 : -1);

    if (count == 0)
    {
        ans++;
        nodes.push_back(node);
    }

    return count;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        // Clear global data
        adj.clear();
        nodes.clear();

        int n;
        cin >> n;
        adj.resize(n + 1);
        for (int i = 2; i <= n; i++)
        {
            int a;
            cin >> a;
            adj[a].push_back(i);
        }

        string s;
        cin >> s;
        int ans = 0;
        dfs(1, s, ans);
        cout << ans << endl;
    }
    return 0;
}
