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

void solve()
{

    int n;
    cin >> n;
    vi a(n + 1), p(n + 1);
    a[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != a[i - 1])
        {

            if (i > 1)
            {
                p[i] = i - 1;
            }
            else
            {
                p[i] = -1;
            }
        }
        else
        {
            p[i] = p[i - 1];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l,r;cin>>l>>r;
        if(p[r]!=-1 && p[r]>=l)
        {

            cout<<p[r]<<" "<<r<<endl;
        }
        else{
       
            cout<<-1<<" "<<-1<<endl;

        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}