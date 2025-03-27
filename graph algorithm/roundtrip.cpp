#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
vector<int> adj[MAX_N];
vector<int> parent(MAX_N, -1);
vector<bool> visited(MAX_N, false);
int start = -1;
int endi = -1;

bool dfs(int node, int par) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (neighbor == par) continue;
        if (visited[neighbor]) { 
            // Cycle detected
            start = neighbor;
            endi = node;
            return true; 
        }
        parent[neighbor] = node;
        if (dfs(neighbor, node)) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i =1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1)) break;
    }

    if (start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(start);
        for (int v = endi; v != start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(start);
        
        cout << cycle.size() << "\n";
        for (int city : cycle) cout << city << " ";
        cout << "\n";
    }

    return 0;
}
