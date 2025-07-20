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
const int MAXN = 1e5 + 5;
int n, q;
vector<vi> g;
vi euler, depth, first;
vector<int> seg;

// segment tree
void build(int node, int l, int r)
{
    if (l == r)
    {
        seg[node] = euler[l];
    }
    else
    {
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        int left = seg[2 * node];
        int right = seg[2 * node + 1];
        seg[node] = (depth[left] < depth[right]) ? left : right;
    }
}

int query(int node, int l, int r, int ql, int qr)
{
    if (qr < l || r < ql)
        return -1;
    if (ql <= l && r <= qr)
        return seg[node];
    int mid = l + (r - l) / 2;
    int left = query(2 * node,l, mid, ql, qr);
    int right = query(2 * node + 1, mid + 1, r, ql, qr);
    if (left == -1)
        return right;
    if (right == -1)
        return left;
    return (depth[left] < depth[right]) ? left : right;
}

void dfs(int u,int d,int p)
{
    depth[u]=d;
    first[u]=euler.size();
    euler.pb(u);
    for(int v:g[u])
    {
        if(v!=p)
        {
            dfs(v,d+1,u);
            euler.pb(u);
        }
    }
}

int lca(int a,int b)
{
    int l=first[a];
    int r=first[b];
    if(l>r) swap(l,r);
    return query(1,0,euler.size()-1,l,r);
}
void solve()
{
    cin>>n>>q;
    g.assign(n+1,{});
    depth.assign(n+1,0);
    first.assign(n+1,0);
    euler.clear();
    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
       
    }
    dfs(1,0,-1);
    int sz=euler.size();
    seg.assign(4*sz,0);
    build(1,0,sz-1);
   while (q--)
   {
    int a,b;cin>>a>>b;
    int x=lca(a,b);
    int ans=abs(depth[a]-depth[x])+abs(depth[b]-depth[x]);
    cout<<ans<<" ";
   }
   
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}