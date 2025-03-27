#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<pair<int, int>>> graph;
int n, m,k;
vector<priority_queue<int>> dist;
struct node {
    int cost, city, used;
    bool operator>(const node &other) const {
        return cost > other.cost; // min heap
    }
};

int dijkstra() {
    vector<vector<int>> dist(n + 1, vector<int>(2, LLONG_MAX));
    priority_queue<node, vector<node>, greater<node>> pq;

    dist[1][0] = 0; // Start from node 1 without a discount
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [cur_cost, city, used] = pq.top();
        pq.pop();

        if (cur_cost > dist[city][used]) {
            continue;
        }

        for (auto &[neigh, weight] : graph[city]) {
            // Case 1: Move to `neigh` without using discount
            if (cur_cost + weight < dist[neigh][used]) {
                dist[neigh][used] = cur_cost + weight;
                pq.push({dist[neigh][used], neigh, used});
            }

            // Case 2: Use discount (only if not used before)
            if (!used) {
                int new_cost = cur_cost + weight / 2; // Integer division
                if (new_cost < dist[neigh][1]) {
                    dist[neigh][1] = new_cost;
                    pq.push({new_cost, neigh, 1});
                }
            }
        }
    }

    return min(dist[n][0], dist[n][1]); 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m>>k;
    graph.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c}); // Directed edge
    }

    int ans = dijkstra();
    cout << ans << endl;

    return 0;
}
