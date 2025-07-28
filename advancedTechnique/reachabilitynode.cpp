


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

const int MAXN = 50005;

int n, m;
vector<int> rev_adj[MAXN]; 
vector<int> out_deg(MAXN, 0);
bitset<MAXN> reachable[MAXN];

void solve() {
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);          // original graph
        rev_adj[b].push_back(a);      // reverse graph
        out_deg[a]++;
    }

    queue<int> q;
    // Start from nodes with 0 out-degree (in original graph)
    for (int i = 1; i <= n; ++i) {
        if (out_deg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        // A node can always reach itself
        reachable[u][u] = 1;

        for (int v : rev_adj[u]) { // for each parent
            reachable[v] |= reachable[u]; // merge reachable sets
            out_deg[v]--;
            if (out_deg[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << reachable[i].count() << " ";
    }
    cout << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}