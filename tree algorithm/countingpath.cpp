#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> tree[MAXN];
int subtree[MAXN], parent[MAXN][20], depth[MAXN];
int pathCount[MAXN];
int n, m;

void dfs(int node, int par) {
    parent[node][0] = par;
    depth[node] = (par == -1) ? 0 : depth[par] + 1;
    
    for (int i = 1; i < 20; i++) {
        if (parent[node][i - 1] != -1) 
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        else 
            parent[node][i] = -1;
    }
    
    for (int child : tree[node]) {
        if (child != par) dfs(child, node);
    }
}

int findLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    int diff = depth[u] - depth[v];
    for (int i = 0; i < 20; i++)
        if ((diff >> i) & 1) u = parent[u][i];

    if (u == v) return u;

    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

void propagatePaths(int node, int par) {
    for (int child : tree[node]) {
        if (child != par) {
            propagatePaths(child, node);
            pathCount[node] += pathCount[child];  
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, -1);

    while (m--) {
        int a, b;
        cin >> a >> b;
        pathCount[a]++;
        pathCount[b]++;
        int lca = findLCA(a, b);
        pathCount[lca]--;
        if (parent[lca][0] != -1) pathCount[parent[lca][0]]--;
    }

    propagatePaths(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << pathCount[i] << " ";
    }
    cout << "\n";

    return 0;
}
