#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long
vector<vector<pair<ll, ll>>> adj;
int n;
/// shortest path in weighted graph is calculated by dijkastra

void dijkastra()
{
    // (dist,node)
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [nd, topnode] = pq.top();
        pq.pop();

        if (nd > dist[topnode])
            continue;

        for (auto &[n, weight] : adj[topnode])
        {
            if (dist[topnode] + weight < dist[n])
            {
                dist[n] = dist[topnode] + weight;
                pq.push({dist[n], n});
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }cout<<endl;
}

int main()
{
    int m;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dijkastra();
}