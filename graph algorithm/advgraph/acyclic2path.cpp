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
int n,m;
vector<vector<int>>adj;
vector<vector<int>>rev_adj;
vector<int>topo;
vector<int>indegree;
vector<int>outdegre;
void solve() {
    cin>>n>>m;
    adj.resize(n+1);
    indegree.resize(n+1);
   outdegre.resize(n+1);
    for(int i=0;i<m;i++)
{
    int a,b;cin>>a>>b;
    adj[a].pb(b);
    rev_adj[b].pb(a);
    indegree[b]++;
    outdegre[a]++;
}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}