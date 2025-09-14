#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5 + 5;
struct segtree {
    ll tree[4*MAX];
    void init() { memset(tree, 0, sizeof(tree)); }

    void update(int node,int l,int r,int pos,ll val){
        if(l==r){
            tree[node]=max(tree[node],val);
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(node*2,l,mid,pos,val);
        else update(node*2+1,mid+1,r,pos,val);
        tree[node]=max(tree[node*2],tree[node*2+1]);
    }

    ll query(int node,int l,int r,int ql,int qr){
        if(r<ql||l>qr) return 0;
        if(ql<=l&&r<=qr) return tree[node];
        int mid=(l+r)/2;
        return max(query(node*2,l,mid,ql,qr), query(node*2+1,mid+1,r,ql,qr));
    }
} tree;

int N,M;
vector<int> add[MAX];
vector<pair<int,int>> sub[MAX];

void solve(){
    cin>>N>>M;
    for(int i=0;i<=N+2;i++){
        add[i].clear();
        sub[i].clear();
    }
    while(M--){
        int l,r,a;
        cin>>l>>r>>a;
        l++; r++;
        add[l].push_back(a);
        sub[r+1].push_back({a,l});
    }

    tree.init();
    vector<ll> dp(N+5,0);

    for(int p=1;p<=N+1;p++){
        ll sum_add=0;
        for(int cost:add[p]) sum_add+=cost;
        ll sum_sub=0;
        for(auto [cost,l]:sub[p]) sum_sub+=cost;

        // Apply all previous additions/subtractions to dp
        // For this simple point update tree, we can use an aux variable
        dp[p]=tree.query(1,1,N,1,p-1)+sum_add-sum_sub;
        tree.update(1,1,N,p,dp[p]);
    }

    cout<<*max_element(dp.begin(),dp.end())<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
