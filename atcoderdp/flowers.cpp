#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;
struct SegTree
{
    int n;
    vector<ll> st;
    SegTree(int _n = 0) { init(_n); }
    void init(int _n)
    {
        n = _n;
        st.assign(4 * n + 5, 0);
    }
    void update(int idx, int l, int r, int pos, ll val)
    {
        if (l == r)
        {
            st[idx] = max(st[idx], val);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(idx << 1, l, mid, pos, val);
        else
            update(idx << 1 | 1, mid + 1, r, pos, val);
        st[idx] = max(st[idx << 1], st[idx << 1 | 1]);
    }
    ll query(int idx, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return st[idx];
        int mid = (l + r) >> 1;
        return max(query(idx << 1, l, mid, ql, qr),
                   query(idx << 1 | 1, mid + 1, r, ql, qr));
    }
};

void solve()
{
    int n;cin>>n;
    vll h(n),a(n);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    SegTree st(n);
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        int hi=h[i];
        ll best=0;
        if(hi>1) best =st.query(1,1,n,1,hi-1);
        ll cur=best+a[i];
        st.update(1,1,n,hi,cur);
        ans=max(ans,cur);
    }

    cout<<ans<<endl;
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