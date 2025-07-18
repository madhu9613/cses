// Author: Madhujya Rajkhowa
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    // Your code here
    int n;cin>>n;
    vll a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    unordered_set<int>seen;
    ll ans=0;
    ll r=1;
    for(int l=1;l<=n;l++)
    {
        while (r<=n && !seen.count(a[r]))
        {
            seen.insert(a[r]);
            ++r;
        }
        ans+=r-l;
        seen.erase(a[l]);
        
    }

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}