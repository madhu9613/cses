#include <bits/stdc++.h>
using namespace std;
 
const int LOG = 20;
const int MAXN = 200005;
 
vector<int> tree[MAXN];
int up[MAXN][LOG], depth[MAXN];
 
void dfs(int v, int parent) {
    up[v][0] = parent;  
    depth[v] = depth[parent] + 1;
    
    for (int j = 1; j < LOG; j++) {
        up[v][j] = up[up[v][j-1]][j-1];
    }
    
    for (int child : tree[v]) {
        if (child != parent) {
            dfs(child, v);
        }
    }
}


int getLCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    
    for (int j = LOG - 1; j >= 0; j--) {
        if (depth[a] - (1 << j) >= depth[b]) {
            a = up[a][j];
        }
    }
    
    if (a == b) return a;  
    
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    
    return up[a][0];  
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, q;
    cin >> n >> q;
 
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
        tree[i].push_back(boss);
    }
 
    depth[0] = -1;
    dfs(1, 0);
 
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << getLCA(a, b) << "\n";
    }
 
    return 0;

}
