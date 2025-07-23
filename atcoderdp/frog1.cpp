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
int n;cin>>n;
vi h(n);for(int i=0;i<n;i++) cin>>h[i];
// dp[i]->i can come from i-1 and or i can come from i-2;

vector<int>dp(n,INF);
dp[0]=0; //initially cost 0
dp[1]=abs(h[1]-h[0]);
for(int i=2;i<n;i++)
{
    dp[i]=min(dp[i-1]+abs(h[i-1]-h[i]),dp[i-2]+abs(h[i-2]-h[i]));
}
cout<<dp[n-1]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}