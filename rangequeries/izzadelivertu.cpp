#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SegmentTree {
    vector<ll> tree;
    int n;

public:
    SegmentTree(const vector<ll> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1); // 0-based index
    }

    void build(const vector<ll> &arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(arr, 2 * node, l, mid);
            build(arr, 2 * node + 1, mid + 1, r);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int idx, ll val, int node, int l, int r) {
        if (l == r) {
            tree[node] = val;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid)
                update(idx, val, 2 * node, l, mid);
            else
                update(idx, val, 2 * node + 1, mid + 1, r);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    ll query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return LLONG_MAX; // completely outside
        if (ql <= l && r <= qr) return tree[node]; // completely inside
        int mid = (l + r) / 2;
        return min(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }

    void update(int idx, ll val) {
        update(idx, val, 1, 0, n - 1);
    }

    ll range_min(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main()
{
    int n,q;cin>>n>>q;
    vector<ll>left(n),right(n),p(n);
    for(int i=0;i<n;i++)
    {

        cin>>p[i];
        left[i]=p[i]-i;
        right[i]=p[i]+i;
    }
 SegmentTree LeftTree(left);
 SegmentTree RightTree(right);

 while (q--)
 {
    int type;
    cin>>type;
    if(type==1)
    {
        int k;
        ll val;
        cin>>k>>val;
        k--;
        p[k]=val;
        LeftTree.update(k,val-k);
        RightTree.update(k,val+k);
    }
    else{
        int k;cin>>k;k--;
        ll ans=min(LeftTree.range_min(0,k)+k,RightTree.range_min(k,n-1)-k);
        cout<<ans<<endl;
    }
 }
 

    return 0;
}