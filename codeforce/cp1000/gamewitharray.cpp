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
int mini=INT_MAX;
vi min2;
while (n--)
{
    int m;cin>>m;
    vi a(m);
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
        
    }
   int miniele=*min_element(all(a));
   mini=min(mini,miniele);
   a.erase(find(all(a),miniele));
   min2.push_back(*min_element(all(a)));

}

cout<<mini+(ll)accumulate(all(min2),0LL)-*min_element(all(min2))<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}