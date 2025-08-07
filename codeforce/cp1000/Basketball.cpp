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

    int n;ll d;cin>>n>>d;
    vll power(n);
    for(int i=0;i<n;i++)
    {
        cin>>power[i];
    }
  sort(all(power));
  int ans=0;
  int l=0,r=n-1;
while (l <= r)
{
    if (power[r] > d)
    {
        ans++;
        r--;
    }
    else
    {
        int required = (d+1 + power[r] - 1) / power[r]; 

        if (r - l + 1 >= required) {
            ans++;
            l += required - 1; 
            r--;
        } else {
            break;
        }
    }
}

cout<<ans<<endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
  
    while (t--) solve();
    return 0;
}