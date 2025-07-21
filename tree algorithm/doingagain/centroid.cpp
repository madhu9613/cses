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
int n;
vector<vi>adj;
vi sub;
void dfs(int u,int par=-1)
{
    sub[u]=1;
    for(int v:adj[u])
    {
        if(v==par) continue;
        dfs(v,u);
        sub[u]+=sub[v];
    }
}

int dfs2(int u,int par=-1)
{
    for(int c:adj[u])
    {
        if(c==par) continue;
        if(sub[c]>n/2)
        {
            return dfs2(c,u);
        }
    }
    return u;
}
void solve() {

cin>>n;adj.resize(n+1);
for(int i=1;i<n;i++)
{
    int a,b;cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
}
sub.resize(n+1);
dfs(1);
int centroid=dfs2(1);
cout<<centroid<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}