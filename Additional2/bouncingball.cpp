#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

ll gcd(ll a, ll b)
{
 return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a,ll b)

{
    return a*b/gcd(a,b);
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    ll n,m,k;cin>>n>>m>>k;
    ll cycler=2*(n-1);
    ll tempr=k%cycler;
    ll row;
    if(tempr<=n-1) row=1+tempr;
    else row=n-(tempr-(n-1));

    ll cyclec=2*(m-1);
    ll tempc=k%cyclec;
    ll col;
    if(tempc<=m-1) col=1+tempc;
    else col=m-(tempc-(m-1));

    ll vdir=k/(n-1);
    ll hdir=k/(m-1);
    ll corners = k / lcm(n - 1, m - 1);

    ll change=vdir+hdir-corners;
    cout<<row<<" "<<col<<" "<<change<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}