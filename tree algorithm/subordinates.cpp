// Author: Madhujya Rajkhowa
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
vector<vector<int>> adj;
vector<int> sub;
void dfs(int u,int par=-1)
{

    sub[u] = 0;
    for (auto &v : adj[u])
    {
        if(v==par) continue;
        dfs(v);
        sub[u] += sub[v] + 1;
    }
}

void solve()
{
    // Your code here
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    sub.resize(n + 1);
    dfs(1);
    
    for (int i = 1; i <= n; i++)
    {
        cout << sub[i] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}