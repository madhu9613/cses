#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];

bool is_cycle(int u, int parent) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (!is_cycle(v, u)) return false;
        } else if (v != parent) {
            // Found back edge
            return true;
        }
    }
    return true;
}

bool check_cycle(int start) {
    int nodes = 0;
    int degree_sum = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        nodes++;
        degree_sum += adj[u].size();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return degree_sum == 2 * nodes;  // Every node degree 2 ⇒ cycle
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // Clear graph
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            visited[i] = false;
        }

        // Build undirected graph
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }

        int c = 0, k = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                k++;
                if (check_cycle(i)) {
                    c++;
                }
            }
        }

        int b = k - c;
        int min_dances = c + (b > 0 ? 1 : 0);
        int max_dances = c + b;

        cout << min_dances << " " << max_dances << '\n';
    }

    return 0;
}
