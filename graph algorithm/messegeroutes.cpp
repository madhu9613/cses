#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<int> dist;
int n, m;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 1;  // Distance from start node
    parent[start] = -1; // Mark start node with no parent

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == 0) {  // Not visited
                dist[neighbor] = dist[node] + 1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    parent.assign(n + 1, -1);
    dist.assign(n + 1, 0);

    // Read connections
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Run BFS from node 1
    bfs(1);

    // If node n is not reachable
    if (dist[n] == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Construct shortest path from 1 to n
    vector<int> path;
    for (int v = n; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    
    // Reverse the path to get correct order
    reverse(path.begin(), path.end());

    // Output result
    cout << path.size() << "\n";
    for (int node : path) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}
