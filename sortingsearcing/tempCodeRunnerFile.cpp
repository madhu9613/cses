// total subsequeece of length a array of lenth i is 2^j-1 (excluding the empty one): dp[i]=2*dp[i-1] we can derive it if we think dp[i]=valid subsequence using first i element it will be (all valid subsequence)- in those who have duplicate;

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

void solve()
{
    int n;
    cin >> n;
    vll a(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    unordered_map<ll, ll> last;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (2 * dp[i - 1]) % MOD;

        // if a[i] already appear before need to remove all the subsequence that have duplicate;
        if (last.count(a[i]))
        {
            int j = last[a[i]];
            dp[i]=(dp[i]-dp[j-1]+MOD)%MOD;
        }
        last[a[i]]=i;
    }
    cout<<(dp[n]-1+MOD)%MOD<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
