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

int n;
vll color;
vector<vi> adj;
vector<int> uni;

set<ll> dfs(int u, int par = -1)
{
    set<ll> s;
    s.insert(color[u]);

    for (int v : adj[u])
    {
        if (v == par)
            continue;
        set<ll> child = dfs(v, u);
        if (child.size() > s.size())
            swap(s, child);
        s.insert(all(child));
    }

    uni[u] = s.size();
    return s;
}

void solve()
{
    cin >> n;
    color.resize(n + 1);
    adj.resize(n + 1);
    uni.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1); // assuming 1 is root

    for (int i = 1; i <= n; i++)
    {
        cout << uni[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
