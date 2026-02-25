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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll pow(ll a,ll b,ll m)
{
if(b==0)
 return 1;
if(b==1) return a%m;
 ll temp=pow(a,b/2,m);
 if(b%2==0)
 {
 return (temp*temp)%m;
}
else
{
return (a*(temp*temp)%m)%m ;
}
}
// You are given a sequence A of N(N ≤ 50000) integers between -
//  10000 and 10000. On this sequence you have to apply
//   M(M ≤ 50000) operations: modify the i - th element
//    in the sequence or for given x y print 
//    max{ Ai + Ai + 1 + .. + Aj | x ≤ i ≤ j ≤ y }. maximum subarray sum of the subarry[x..y]


const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

const int MAXN = 50005;
const long long NEG_INF = -1000000000000000000LL;

struct node {
    long long sum, pref, suff, best;
};

node seg[4*MAXN];
int arr[MAXN];
int n;
node merge(node a,node b)
{
    node res;
    res.sum=a.sum+b.sum;
    res.pref=max(a.pref,a.sum+b.pref);
    res.suff=max(b.suff,b.sum+a.suff);
    res.best=max(max(a.best,b.best),a.suff+b.pref);
    return res;
}

node initialize(int val)
{
    node res;
    res.sum=val;
    res.pref=res.suff=res.best=val;
    return res;
}

void build(int idx,int l,int r)
{
    if(l==r)
    {
        seg[idx]=initialize(arr[l]);
        return;
    }
    int mid=l+(r-l)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    seg[idx]=merge(seg[2*idx],seg[2*idx+1]);
}

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r)
    {
        arr[l]=val;
        seg[idx]=initialize(arr[l]);
        return;
    }
    int mid=l+(r-l)/2;
    if(pos<=mid)
    {
        update(2*idx,l,mid,pos,val);
    }else{
        update(2*idx+1,mid+1,r,pos,val);
    }
    seg[idx]=merge(seg[2*idx],seg[2*idx+1]);
}
node query(int idx, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
        node neutral;
        neutral.sum = 0;
        neutral.pref = neutral.suff = neutral.best = NEG_INF;
        return neutral;
    }
    if (ql <= l && r <= qr) return seg[idx];
    int m = (l + r) / 2;
    node left = query(2 * idx, l, m, ql, qr);
    node right = query(2 * idx + 1, m + 1, r, ql, qr);
    return merge(left, right);
}

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build(1,1,n);
    int m;
    cin>>m;
    while(m--)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==0)
        {
            update(1,1,n,x,y);
        }else{
            node res=query(1,1,n,x,y);
            cout<<res.best<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   
    while (t--)
        solve();

    return 0;
}