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
vi parent,depth,jump,jump_size;
vector<vector<int>>g;

void dfs(int u)
{
    for(int c:g[u])
    {
        depth[c]=depth[u]+1;
        parent[c]=u;
        jump[c]=u;
        jump_size[c]=1;
        if(jump[u] && jump[jump[u]] && jump_size[u]==jump_size[jump[u]])
        {
            jump[c]=jump[jump[u]];
            jump_size[c]=jump_size[u]*2+1;
        }
        dfs(c);
    }

}

int make_jump(int x,int k)
{
    if(depth[x]<k){
        return -1;
    }
    while (k)
    {
        if(jump_size[x]<=k)
        {
            k-=jump_size[x];
            x=jump[x];
        }else{
            k--;
            x=parent[x];
        }
    }
    return x;
    
}
void solve() {
   int q;
    cin>>n>>q;
    g.resize(n+1);
    for(int i=2;i<=n;i++)
    {
        int p;cin>>p;
        g[p].push_back(i);
    }
    depth.resize(n+1);
    parent.resize(n+1);
    jump.resize(n+1);
    jump_size.resize(n+1);

    dfs(1);

    while (q--)
    {
        int x,k;
        cin>>x>>k;
        cout<<make_jump(x,k)<<endl;
    }
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}
