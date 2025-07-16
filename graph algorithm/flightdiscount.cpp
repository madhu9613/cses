#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> graph;
int n, m;

struct node {
    ll cost, city, used;
    bool operator>(const node &other) const {
        return cost > other.cost;
    }
};

ll dijkstra() {
    vector<vector<ll>> dist(n + 1, vector<ll>(2, LLONG_MAX));
    vector<vector<bool>> visited(n + 1, vector<bool>(2, false));
    priority_queue<node, vector<node>, greater<node>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [cur_cost, city, used] = pq.top();
        pq.pop();

        if (visited[city][used]) continue;
        visited[city][used] = true;

        for (auto &[neigh, weight] : graph[city]) {
            // Without using coupon
            if (cur_cost + weight < dist[neigh][used]) {
                dist[neigh][used] = cur_cost + weight;
                pq.push({dist[neigh][used], neigh, used});
            }

            // With coupon
            if (!used) {
                ll new_cost = cur_cost + weight / 2;
                if (new_cost < dist[neigh][1]) {
                    dist[neigh][1] = new_cost;
                    pq.push({new_cost, neigh, 1});
                }
            }
        }
    }

    return min(dist[n][0], dist[n][1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    cout << dijkstra() << '\n';
    return 0;
}
