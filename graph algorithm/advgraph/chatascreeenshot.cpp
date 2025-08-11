#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
 return b == 0 ? a : gcd(b, a % b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<set<int>> adj(n + 1);  
    vi inorder(n + 1, 0);  

    for (int i = 0; i < k; i++) {
        vi a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        for (int j = 1; j < n - 1; j++) {
            if (adj[a[j]].insert(a[j + 1]).second) {
                inorder[a[j + 1]]++;
            } 
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inorder[i] == 0) q.push(i); 
    }

    vi topo_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.pb(u);

        for (int v : adj[u]) {
            inorder[v]--;
            if (inorder[v] == 0) {
                q.push(v);
            }
        }
    }

    if ((int)topo_order.size() == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}