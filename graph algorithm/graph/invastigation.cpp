#include <bits/stdc++.h>
#define ll long long
#define INF LLONG_MAX
using namespace std;
const int MOD= 1e9 + 7;
int n, m;
vector<vector<pair<ll, ll>>> adj;
vector<ll> dist;
vector<ll> ways;
vector<ll> minFlights;
vector<ll> maxFlights;
// dist[i]: minimum cost to reach city
// ways[i]=number of minimum cost path :[path with cost dist[i]]
// minFlights[i]=min flights with dist[i]
// maxFlights[i]=max flights with dist[i]

void findAll()

{

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[1] = 0;
    ways[1] = 1;
    minFlights[1] = 0;
    maxFlights[1] = 0;
    pq.push({0, 1}); //{cost,city}
    while (!pq.empty())
    {
        auto [cost, city] = pq.top();
        pq.pop();
        if (cost > dist[city])
        {
            continue;
        }

        for(auto &[v,w]:adj[city])
         {
            ll newcost=cost+w;
            if(newcost<dist[v])
            {
                dist[v]=newcost;
                ways[v]=ways[city];
                minFlights[v]=1+minFlights[city];
                maxFlights[v]=1+maxFlights[city];
                pq.push({newcost,v});
            }
            else if(newcost==dist[v])
            {
                ways[v]=(ways[city]+ways[v])%MOD;
                minFlights[v]=min(minFlights[v],minFlights[city]+1);
                maxFlights[v]=max(maxFlights[v],maxFlights[city]+1);

            }
         }
        
    }

    cout<<dist[n]<<" "<<ways[n]<<" "<<minFlights[n]<<" "<<maxFlights[n]<<endl;
}
int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dist.resize(n+1,INF);
    ways.resize(n+1,0);
    minFlights.resize(n+1,INF);
    maxFlights.resize(n+1,0);
 findAll();
    return 0;
}