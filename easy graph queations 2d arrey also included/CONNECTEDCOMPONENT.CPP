#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int countComponents(int n, vector<pair<int, int>>& edges) {
    vector<int> adj[n + 1]; 
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    vector<bool> visited(n + 1, false);
    int components = 0;

    for (int i = 1; i <= n; ++i) { 
        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }
    return components;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edges.emplace_back(a, b);
    }

    cout << "Number of Connected Components: " << countComponents(n, edges) << endl;
    return 0;
}
