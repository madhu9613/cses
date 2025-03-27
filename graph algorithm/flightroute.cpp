#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int INF = 1e18;

struct Edge {
    int to, cost;
};

int n, m, k;
vector<vector<Edge>> adj;
vector<priority_queue<int>> dist; // Max-heap for storing k shortest distances

void findKShortestPaths() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});  // {cost, node}
    dist[1].push(0);
    
    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();
        
        if (dist[node].top() < cost) continue;  // Ignore outdated paths

        for (auto &[next, price] : adj[node]) {
            int new_cost = cost + price;

            if (dist[next].size() < k) {
                dist[next].push(new_cost);
                pq.push({new_cost, next});
            } else if (new_cost < dist[next].top()) {
                dist[next].pop();
                dist[next].push(new_cost);
                pq.push({new_cost, next});
            }
        }
    }
    
    vector<int> result;
    while (!dist[n].empty()) {
        result.push_back(dist[n].top());
        dist[n].pop();
    }
    reverse(result.begin(), result.end());

    for (int cost : result)
        cout << cost << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;
    adj.resize(n + 1);
    dist.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    findKShortestPaths();
    return 0;
}
