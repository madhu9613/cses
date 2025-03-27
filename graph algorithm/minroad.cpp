// Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
// Your task is to find out the minimum number of roads required, and also determine which roads should be built.
// Input

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;  // Adjacency list
vector<bool> visited;
vector<int> components;
int n, m;

// DFS to find connected components
void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    visited.assign(n + 1, false);

    // Read input roads
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Find connected components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components.push_back(i); 
            dfs(i);
        }
    }

    // We need (components.size() - 1) roads to connect them
    int k = components.size() - 1;
    cout << k << "\n";

    for (int i = 1; i <= k; i++) {
        cout << components[i - 1] << " " << components[i] << "\n";
    }

    return 0;
}
