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
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    int n;cin>>n;
    for(ll k=1;k<=n;k++)
    {
        ll total=k*k*(k*k-1)/2;
        ll attacking=4*(k-1)*(k-2);
        cout<<total-attacking<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;

    while (t--) solve();
    return 0;
}