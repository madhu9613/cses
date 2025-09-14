#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl "\n"
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;
const int MAXN = 2e5 + 5;
using namespace std;

struct node
{
    ll sum = 0;
    ll lazy_add = 0;
    ll lazy_set = 0;
    bool toset = false;
};

node tree[4 * MAXN];
int n, q;
vll a;
void build(int n, int l, int r)
{
    if (l == r)
    {
        tree[n].sum = a[l];
        return;
    }

    int m = l + (r - l) / 2;
    build(2 * n, l, m);
    build(2 * n + 1, m + 1, r);
    tree[n].sum = tree[2 * n].sum + tree[2 * n + 1].sum;
}

void push(int n, int l, int r)
{
    if (tree[n].toset)
    {
        tree[n].sum = (r - l + 1) * tree[n].lazy_set;
        if (l != r)
        {
            int left = 2 * n, right = 2 * n + 1;
            tree[left].lazy_set = tree[right].lazy_set = tree[n].lazy_set;
            tree[left].lazy_add = tree[right].lazy_add = tree[n].lazy_add;
            tree[left].toset = tree[right].toset = true;
        }
        tree[n].lazy_set = 0;
        tree[n].toset = false;
    }
    if (tree[n].lazy_add != 0)
    {
        tree[n].sum += (r - l + 1) * tree[n].lazy_add;
        if (l != r)
        {
            int left = 2 * n, right= 2 * n + 1;
            tree[left].lazy_add += tree[n].lazy_add;
            tree[right].lazy_add += tree[n].lazy_add;
        }
        tree[n].lazy_add = 0;
    }
}

void update_add(int n, int l, int r, int ql, int qr, ll val)
{
    push(n, l, r);
    if (r < ql || l > qr)
        return;
    if (ql <= l && r <= qr)
    {
        tree[n].lazy_add += val;
        push(n, l, r);
        return;
    }
    int m = l + (r - l) / 2;
    update_add(2 * n, l, m, ql, qr, val);
    update_add(2 * n + 1, m + 1, r, ql, qr, val);
    tree[n].sum = tree[2 * n].sum + tree[2 * n + 1].sum;
}

void update_set(int n, int l, int r, int ql, int qr, ll val)

{
    push(n, l, r);
    if (r < ql || l > qr)
        return;
    if (ql <= l && r <= qr)
    {
        tree[n].toset = true;
        tree[n].lazy_set = val;
        tree[n].lazy_add = 0;
        push(n, l, r);
        return;
    }

    int m = l + (r - l) / 2;
    update_set(2 * n, l, m, ql, qr, val);
    update_set(2 * n + 1, m + 1,r, ql, qr, val);
    tree[n].sum = tree[2 * n].sum + tree[2 * n + 1].sum;
}

ll query(int n, int l, int r, int ql, int qr)
{
    push(n, l, r);

    if (r < ql || l > qr)
        return 0;
    if (ql <= l && r <= qr)
        return tree[n].sum;

    int m = l + (r - l) / 2;
    return query(2 * n, l, m, ql, qr) + query(2 * n + 1, m + 1, r, ql, qr);
}
void solve()
{
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1);
    while (q--)
    {
        int type, a, b;
        cin >> type >> a >> b;
        a--, b--;
        if (type == 1)
        {
            ll x;
            cin >> x;
            update_add(1, 0, n - 1, a, b, x);
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            update_set(1, 0, n - 1, a, b, x);
        }
        else
        {
            cout << query(1, 0, n - 1, a, b) << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}