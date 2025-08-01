#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
ll n, m;
vector<vector<int>> adj;
vector<vector<int>> cap;
vector<int> par;
int bfs(int s, int t)
{
    fill(all(par), -1);
    par[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty())
    {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (auto &v : adj[u])
        {
            if (par[v] == -1 && cap[u][v] > 0)
            {
                par[v] = u;
                int new_flow = min(flow, cap[u][v]);
                if (v == t)
                {
                    return new_flow;
                }
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}
int maxflow(int s, int t)
{
    int flow = 0;
    int new_flow;
    while ((new_flow = bfs(s, t)))
    {
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}
void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    cap.resize(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(b);
        adj[b].pb(a);
        cap[a][b] += c;
    }
    par.resize(n + 1);
    cout<<maxflow(1,n)<<endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}