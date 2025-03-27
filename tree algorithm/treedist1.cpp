#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// BFS function to calculate distances from a given start node
vector<int> bfs(int start, int n, const vector<vector<int>>& adj) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {  // Not visited
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return dist;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    // Input edges and construct adjacency list
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // First BFS from an arbitrary node (node 1)
    vector<int> dist_from_any = bfs(1, n, adj);
    int farthest_node_A = max_element(dist_from_any.begin() + 1, dist_from_any.end()) - dist_from_any.begin();

    // Second BFS from the farthest node A
    vector<int> dist_from_A = bfs(farthest_node_A, n, adj);
    int farthest_node_B = max_element(dist_from_A.begin() + 1, dist_from_A.end()) - dist_from_A.begin();

    vector<int> dist_from_B = bfs(farthest_node_B, n, adj);

    for (int i = 1; i <= n; i++) {
        cout << max(dist_from_A[i], dist_from_B[i]) << " ";
    }
    cout << endl;

    return 0;
}
