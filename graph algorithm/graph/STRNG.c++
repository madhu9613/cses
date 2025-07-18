#include <bits/stdc++.h>
using namespace std;

// Map from (n-1)-bit string to list of edges (0 or 1)
unordered_map<string, vector<char>> adj;
string result;
int n;

// Eulerian path DFS
void dfs(string node) {
    while (!adj[node].empty()) {
        char bit = adj[node].back();
        adj[node].pop_back();

        string next = node.substr(1) + bit;
        dfs(next);

        result += bit;
    }
}

int main() {
    cin >> n;
    if(n==1)
    {
        cout<<"10"<<endl;
        return 0;
    }

    // Create all (n-1)-bit nodes
    int total_nodes = 1 << (n - 1);
    for (int i = 0; i < total_nodes; i++) {
        string node;
        for (int j = n - 2; j >= 0; j--) {
            node += ((i >> j) & 1) + '0';
        }

        // Add edges 0 and 1
        adj[node].push_back('1');
        adj[node].push_back('0'); // Important: push 1 first, then 0 to get lexicographically smallest
    }

    string start(n - 1, '0');
    dfs(start);
    reverse(result.begin(), result.end());

    // Add initial (n - 1)-bit prefix
    cout << start + result << endl;

    return 0;
}
