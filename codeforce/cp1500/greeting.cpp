#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
 
class SegmentTree
{
    vector<int> tree;
    int size;
 
public:
    SegmentTree(int n)
    {
        size = n;
        tree.resize(4 * n, 0);
    }
 
    void update(int node, int l, int r, int idx)
    {
        if (l == r)
        {
            tree[node]++;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid)
        {
            update(2 * node, l, mid, idx);
        }
        else
        {
            update(2 * node + 1, mid + 1, r, idx);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
 
    int query(int node,int l,int r,int ql,int qr)
    {
        if(qr<l || r<ql)
        {
            return 0;
        }
        if(ql<=l && r<=qr)
        {
            return tree[node];
        }
        int mid=l+(r-l)/2;
        return query(2*node,l,mid,ql,qr)+query(2*node+1,mid+1,r,ql,qr);
    }
 
    void update(int idx)
    {
        update(1,1,size,idx);
    }
 
    int query_range(int l,int r)
    {
      return  query(1,1,size,l,r);
    }
};
 
typedef struct
{
    ll l;
    ll r;
    int idx;
} Range;
 
void solve()
{
    int n;
    cin >> n;
    vector<Range> range(n);
    vector<int> r_val;
    for (int i = 0; i < n; i++)
    {
        cin >> range[i].l >> range[i].r;
        range[i].idx = i;
        r_val.pb(range[i].r);
    }
    sort(all(r_val));
    r_val.erase(unique(all(r_val)), r_val.end());
    auto get_compressed_r = [&](int r)
    {
        return lower_bound(all(r_val), r) - r_val.begin() + 1;
    };
 
    for (auto &ran : range)
    {
        ran.r = get_compressed_r(ran.r);
    }
 
    {
 
        sort(all(range), [](const Range &a, const Range &b)
             {
            if(a.l==b.l) return a.r<b.r;
            return a.l>b.l; });
 
        SegmentTree seg1(r_val.size());
        vector<int>contains(n);
        for(auto &ran:range)
        {
            contains[ran.idx]=seg1.query_range(1,ran.r);
            seg1.update(ran.r);
 
        }
        ll ans=0;
        for(auto i:contains)
        {
           ans+=i;
        }

        cout<<ans<<endl;
 
    }
 
   
 
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    
    while (t--)
        solve();
    return 0;
}
