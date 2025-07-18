#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

vector<vector<int>> adj, rev_adj;
vector<bool> visited;
vector<int> coin;
vector<int> order;
int n, m;
vector<int> scc_id;
vector<vector<int>> scc_graph;
vector<int> scc_coin;

void dfs1(int u) {
    visited[u] = true;
    for (auto &v : adj[u])
        if (!visited[v])
            dfs1(v);
    order.push_back(u);
}

void dfs2(int u, int id) {
    scc_id[u] = id;
    scc_coin[id] += coin[u];  
    for (auto &v : rev_adj[u])
        if (scc_id[v] == -1)
            dfs2(v, id);
}

int32_t main() {
    cin >> n >> m;
    adj.resize(n + 1);
    coin.resize(n + 1);
    rev_adj.resize(n + 1);
    visited.resize(n + 1, false);
    
    for (int i = 1; i <= n; i++) cin >> coin[i];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs1(i);

    reverse(order.begin(), order.end());
    
    scc_id.resize(n + 1, -1);
    int id = 1;  // Start SCC ids from 1
    scc_coin.resize(n + 1, 0);  // Room for SCC coin totals

    for (auto &u : order)
        if (scc_id[u] == -1)
            dfs2(u, id++);

    scc_graph.resize(id + 1);  // DAG of SCCs
    vector<int> indegree(id + 1, 0);

    for (int u = 1; u <= n; u++) {
        for (auto &v : adj[u]) {
            if (scc_id[u] != scc_id[v]) {
                scc_graph[scc_id[u]].push_back(scc_id[v]);
                indegree[scc_id[v]]++;
            }
        }
    }

    vector<ll> dp(id + 1, 0);
    queue<int> q;

    for (int u = 1; u < id; u++) {
        if (indegree[u] == 0) {
            dp[u] = scc_coin[u];
            q.push(u);
        }
    }

    ll ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans = max(ans, dp[u]);
        for (auto &v : scc_graph[u]) { 
            dp[v] = max(dp[v], dp[u] + scc_coin[v]);
            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    cout << ans << endl;
    return 0;
}
