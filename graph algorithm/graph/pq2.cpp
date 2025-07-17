#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int LOG;

vector<int> next_arr, visited, depth, entry_node, index_in_cycle, comp_id;
unordered_map<int, int> cycle_length;
vector<vector<int>> up;

int n, q, comp_count = 0;

void dfs(int u, vector<int>& path, vector<int>& pos) {
    visited[u] = 1;
    path.push_back(u);
    pos[u] = path.size() - 1;

    int v = next_arr[u];
    if (visited[v] == 0) {
        dfs(v, path, pos);
    } else if (visited[v] == 1) {
        // Found a cycle
        int start = pos[v];
        vector<int> cycle(path.begin() + start, path.end());
        int L = cycle.size();
        for (int i = 0; i < L; ++i) {
            int node = cycle[i];
            depth[node] = 0;
            entry_node[node] = node;
            index_in_cycle[node] = i;
            comp_id[node] = comp_count;
        }
        cycle_length[comp_count] = L;
        comp_count++;
    }

    if (depth[u] == -1) {
        depth[u] = depth[next_arr[u]] + 1;
        entry_node[u] = entry_node[next_arr[u]];
        comp_id[u] = comp_id[next_arr[u]];
    }

    visited[u] = 2;
    path.pop_back();
}

int lift(int u, int k) {
    for (int i = 0; i < LOG; ++i) {
        if (k & (1 << i)) {
            u = up[i][u];
        }
    }
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    next_arr.resize(n);
    visited.assign(n, 0);
    depth.assign(n, -1);
    entry_node.assign(n, -1);
    index_in_cycle.assign(n, -1);
    comp_id.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        cin >> next_arr[i];
        next_arr[i]--; // 0-based
    }

    // Step 1: DFS to build depth, entry_node, cycle info
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> path, pos(n, -1);
            dfs(i, path, pos);
        }
    }

    // Step 2: Build Binary Lifting Table
    LOG = 0;
    while ((1 << LOG) <= n) LOG++;
    up.assign(LOG, vector<int>(n));

    for (int i = 0; i < n; ++i) up[0][i] = next_arr[i];

    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }

    // Step 3: Process Queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        if (comp_id[a] != comp_id[b]) {
            cout << -1 << '\n';
        } else {
            if (depth[b] == 0) {
                // b is in cycle
                int u = entry_node[a];
                int v = b;
                int idx_u = index_in_cycle[u];
                int idx_v = index_in_cycle[v];
                int L = cycle_length[comp_id[a]];
                int d = (idx_v - idx_u + L) % L;
                cout << depth[a] + d << '\n';
            } else {
                if (depth[a] < depth[b]) {
                    cout << -1 << '\n';
                } else {
                    int steps = depth[a] - depth[b];
                    int x = lift(a, steps);
                    cout << (x == b ? steps : -1) << '\n';
                }
            }
        }
    }

    return 0;
}
