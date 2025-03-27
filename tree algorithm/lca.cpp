#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 20; 

vector<int> tree[MAXN];
int up[MAXN][LOG]; 
int depth[MAXN];

void dfs(int v, int parent) {
    up[v][0] = parent;
    for (int j = 1; j < LOG; j++) {
        if (up[v][j - 1] != -1)
            up[v][j] = up[up[v][j - 1]][j - 1];
        else
            up[v][j] = -1;
    }

    for (int u : tree[v]) {
        if (u != parent) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

int getLCA(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);

    for (int j = LOG - 1; j >= 0; j--) {
        if (depth[a] - (1 << j) >= depth[b])
            a = up[a][j];
    }

    if (a == b)
        return a;

    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0]; 
}

int getDistance(int a, int b) {
    int lca = getLCA(a, b);
    return depth[a] + depth[b] - 2 * depth[lca];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    memset(up, -1, sizeof(up));
    depth[1] = 0;
    dfs(1, -1);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << getDistance(a, b) << "\n";
    }

    return 0;
}
