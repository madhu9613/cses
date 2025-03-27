#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<int> dists;

void dfs(int node, int parent, int dist, pair<int, int> &farthest) {
    dists[node] = dist; 
    if (dist > farthest.second) {
        farthest = {node, dist}; 
    }
    for (int neighbor : tree[node]) {
        if (neighbor != parent) { 
            dfs(neighbor, node, dist + 1, farthest);
        }
    }
}

int main() {
    int n;
    cin >> n;

    tree.resize(n + 1); 
    dists.resize(n + 1, 0); 

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    pair<int, int> farthest = {1, 0}; 
    dfs(1, -1, 0, farthest);

    // Step 2: Perform the second DFS from the farthest node found
    int start = farthest.first;
    farthest = {start, 0};
    dfs(start, -1, 0, farthest);

    // The diameter of the tree is the maximum distance found
    cout << farthest.second << endl;

    return 0;
}
