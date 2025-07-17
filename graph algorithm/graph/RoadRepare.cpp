// we need to build minimum spannning tree we can use Prims algo which is easy for this

#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<vector<pair<ll, ll>>> adj;
vector<bool> visited;
int n, m;

ll mst()
{
    ll totalcost = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1}); // cost,node
    while (!pq.empty())
    {
        auto [cost, city] = pq.top();
        pq.pop();
        if (visited[city])
            continue;

        visited[city] = true;
        totalcost += cost;
        for (auto &[n, w] : adj[city])
        {
            if (!visited[n])
            {
                pq.push({w, n});
            }
        }
    }
    return totalcost;
}
int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    ll totalcost=mst();

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }

    cout<<totalcost<<endl;

    return 0;
}