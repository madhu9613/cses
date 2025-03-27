#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
vector<int> graph[MAX_N];
vector<int> visited(MAX_N, 0);
vector<int> parent(MAX_N, -1);
vector<int> cycle;
int cycle_start = -1, cycle_end = -1;

bool dfs(int node) {
    visited[node] = 1; // Mark as currently in recursion stack

    for (int next : graph[node]) {
        if (visited[next] == 0) { // Not visited, continue DFS
            parent[next] = node;
            if (dfs(next)) return true;
        } 
        else if (visited[next] == 1) { // Found back edge (cycle detected)
            cycle_start = next;
            cycle_end = node;
            return true;
        }
    }

    visited[node] = 2; // Mark as fully processed
    return false;
}

void find_cycle(int n) {
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            if (dfs(i)) break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    // Reconstruct cycle path
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());

    // Print the cycle
    cout << cycle.size() << "\n";
    for (int v : cycle) cout << v << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    find_cycle(n);
    return 0;
}
