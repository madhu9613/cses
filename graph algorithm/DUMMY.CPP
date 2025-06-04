#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge &other) const {
        return cost < other.cost;
    }
};

struct DSU {
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false;
        if (rank[rootX] > rank[rootY]) swap(rootX, rootY);
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY]) rank[rootY]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }
    
    sort(edges.begin(), edges.end()); // Sort edges by cost
    DSU dsu(n);
    
    long long total_cost = 0;
    int edges_used = 0;
    
    for (const auto &edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            total_cost += edge.cost;
            edges_used++;
            if (edges_used == n - 1) break;
        }
    }
    
    if (edges_used == n - 1)
        cout << total_cost << "\n";
    else
        cout << "IMPOSSIBLE\n";
    
    return 0;
}
