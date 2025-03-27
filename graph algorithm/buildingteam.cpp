#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1e5 + 5;
vector<int> adj[MAX_N];
int team[MAX_N]; // 0: unvisited, 1 or 2: assigned teams

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    team[start] = 1; // Assign team 1 to start

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (team[neighbor] == 0) { 
                // Assign opposite team to neighbor
                team[neighbor] = 3 - team[node]; 
                q.push(neighbor);
            } else if (team[neighbor] == team[node]) {
                return false; // Conflict found, not bipartite
            }
        }
    }
    return true;
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

    for (int i = 1; i <= n; i++) {
        if (team[i] == 0) { // If not visited
            if (!bfs(i)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << team[i] << " ";
    }
    cout << "\n";

    return 0;
}
