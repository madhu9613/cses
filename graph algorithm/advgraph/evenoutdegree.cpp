#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

vector<int> adj[MAXN];
bool visited[MAXN];
int entry[MAXN], odd[MAXN], timer = 1;
vector<pair<int, int>> result;

void dfs(int u, int parent = 0) {
    visited[u] = true;
    entry[u] = timer++;

    for (int v : adj[u]) {
        if (v == parent) continue;

        if (!visited[v]) {
            dfs(v, u);
            if (odd[v]) {
                result.emplace_back(v, u);  // child → parent
                odd[v] = 0;
            } else {
                result.emplace_back(u, v);  // parent → child
                odd[u] ^= 1;
            }
        } else if (entry[u] > entry[v]) {  // back edge to ancestor
            result.emplace_back(u, v);
            odd[u] ^= 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if (m % 2 != 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        if (!visited[i])
            dfs(i);

    if (accumulate(odd + 1, odd + n + 1, 0) != 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (auto [u, v] : result)
            cout << u << " " << v << "\n";
    }

    return 0;
}
