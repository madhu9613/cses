#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> segTree;
vector<int> h;

void build(int node, int l, int r)
{
    if (l == r)
    {
        segTree[node] = h[l];
    }
    else
    {
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
    }
}

void update(int node, int l, int r, int idx, int val)
{
    if (l == r)
    {
        segTree[node] -= val;
    }
    else
    {
        int mid = l + (r - l) / 2;
        if (idx <= mid)
        {
            update(2 * node, l, mid, idx, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, r, idx, val);
        }

        segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
    }
}

ll query(int node, int l, int r, int val)
{
    if (segTree[node] < val)
        return -1;

    if (l == r)
        return l;
    int mid = l + (r - l) / 2;
    if (segTree[2 * node] >= val)
    {
        return query(2 * node, l, mid, val);
    }
    else
    {
        return query(2 * node + 1, mid + 1, r, val);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    h.resize(n + 1);
    segTree.resize(4 * n);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    build(1, 1, n);
    while (q--)
    {
        int x;
        cin >> x;
        int idx = query(1, 1, n, x);
        if (idx == -1)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << idx << " ";
            update(1, 1, n, idx, x);
        }
    }

    return 0;
}