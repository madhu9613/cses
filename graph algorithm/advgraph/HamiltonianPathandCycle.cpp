// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;

bool dfs(int u, int count, int start, bool cycle) {
    visited[u] = true;
    path.pb(u);
    if (count == n) {
        if (cycle) {
            for (int v : adj[u]) {
                if (v == start) return true; // cycle complete
            }
            path.pop_back();
            visited[u] = false;
            return false;
        }
        return true; // Hamiltonian path
    }

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, count + 1, start, cycle)) return true;
        }
    }

    path.pop_back();
    visited[u] = false;
    return false;
}

bool hamiltonian(bool cycle = false) {
    for (int i = 1; i <= n; ++i) {
        visited.assign(n + 1, false);
        path.clear();
        if (dfs(i, 1, i, cycle)) {
            cout << (cycle ? "Hamiltonian Cycle: " : "Hamiltonian Path: ");
            for (int node : path) cout << node << " ";
            if (cycle) cout << path[0]; // to complete the cycle
            cout << endl;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    adj.assign(n + 1, {});
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    if (!hamiltonian(true)) cout << "No Hamiltonian Cycle\n";
    if (!hamiltonian(false)) cout << "No Hamiltonian Path\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
