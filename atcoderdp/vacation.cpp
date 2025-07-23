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

typedef struct 
{
    int a;
    int b;
    int c;
}day;

void solve() {
int n; 
cin>>n;
vector<day>happy(n+1);
for(int i=1;i<=n;i++)
{
    cin>>happy[i].a>>happy[i].b>>happy[i].c;
}
vector<vector<int>>dp(n+1,vector<int>(3,0));
dp[1][0]=happy[1].a;
dp[1][1]=happy[1].b;
dp[1][2]=happy[1].c;

for(int i=2;i<=n;i++)
{
    dp[i][0]=happy[i].a+max(dp[i-1][1],dp[i-1][2]);
    dp[i][1]=happy[i].b+max(dp[i-1][0],dp[i-1][2]);
    dp[i][2]=happy[i].c+max(dp[i-1][0],dp[i-1][1]);

}
cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}