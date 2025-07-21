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
//i have already solved it using Two pointer (additional problem :distinct)
//lets try to solve using dp; dp[i]=total subarray ending at i;

ll n;cin>>n;vll a(n+1); for(ll i=1;i<=n;i++) cin>>a[i];
unordered_map<ll,ll>last;
vll dp(n+1);
ll start=1,total=0;
for(int i=1;i<=n;i++)
{
    if(last.count(a[i]))
    {
        start=max(start,last[a[i]]+1);
    }
    dp[i]+=i-start+1;
    total+=dp[i];
     last[a[i]] = i;

}
cout<<total<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}