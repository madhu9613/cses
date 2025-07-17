#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> teleport(MAXN), ans(MAXN), vis(MAXN);

void dfs(int u, vector<int>& path) {
    vis[u] = 1;
    path.push_back(u);

    int next = teleport[u];
    if (!vis[next]) {
        dfs(next, path);
    } else if (ans[next] == 0) {
        // Cycle detected
        int len = 1;
        for (int i = path.size() - 1; i >= 0 && path[i] != next; --i) len++;
        for (int i = path.size() - 1; i >= 0; --i) {
            ans[path[i]] = len;
            if (path[i] == next) break;
        }
    }

    // Fill values for nodes before the cycle
    if (ans[u] == 0) ans[u] = ans[next] + 1;
    path.pop_back();
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> teleport[i];

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            vector<int> path;
            dfs(i, path);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
}
