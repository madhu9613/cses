#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> segTree;
vector<ll> arr;

void BuildTree(int node, int l, int r)
{
    if (l == r)
    {
        segTree[node] = arr[l];
    }
    else
    {
        int mid = l + (r - l) / 2;
        BuildTree(2 * node, l, mid);
        BuildTree(2 * node + 1, mid + 1, r);
        segTree[node] = min(segTree[2 * node] , segTree[2 * node + 1]);
    }
}
void update(int node, int l, int r, int index, ll val)
{
    if (l == r)
    {
        segTree[node] = val;
    }
    else
    {
        int mid = l + (r - l) / 2;
        if (index <= mid)
        {
            update(2 * node, l, mid, index, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, r, index, val);
        }
        segTree[node] = min(segTree[2 * node] ,segTree[2 * node + 1]);
    }
}

ll query(int node, int l, int r, int ql, int qr)
{
    if (ql > r || qr < l)
        return INT_MAX; // here its out of bound
    if (ql <= l && r <= qr)
    {
        // conpletly overlapping
        return segTree[node];
    }
    int mid = l + (r - l) / 2;
    return min(query(2 * node, l, mid, ql, qr) ,
           query(2 * node + 1, mid + 1, r, ql, qr));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    segTree.resize(4 * n);
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    BuildTree(1, 1, n);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int k;
            ll val;
            cin >> k >> val;
            update(1, 1, n, k, val);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }

    return 0;
}