#include <bits/stdc++.h>
#define ll long long
#define INF LLONG_MAX
using namespace std;
int n, m, k;
vector<vector<pair<int, int>>> adj;
vector<priority_queue<ll>> dist;

void findKshortestPath()
{

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[1].push(0);
    pq.push({0, 1}); //{cost,city}
    while (!pq.empty())
    {

        auto [cost, city] = pq.top();
        pq.pop();
        if (dist[city].top() < cost)
        {
            continue;
        }
        for (auto &[neighbour, weight] : adj[city])
        {
            ll new_cost = cost + weight;
            if (dist[neighbour].size() < k)
            {

                dist[neighbour].push(new_cost);
                pq.push({new_cost, neighbour});
            }
            else if (new_cost < dist[neighbour].top())
            {
                dist[neighbour].pop();
                dist[neighbour].push(new_cost);
                pq.push({new_cost, neighbour});
            }
        }
    }
    vector<ll>res;
    while (!dist[n].empty())
    {
        res.push_back(dist[n].top());
        dist[n].pop();
    }
    reverse(res.begin(),res.end());
    for(auto &c:res)
    {
        cout<<c<<" ";
    }cout<<endl;
    

}
int main()
{
    cin >> n >> m >> k;
    adj.resize(n + 1);
    dist.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    findKshortestPath();

    return 0;
}