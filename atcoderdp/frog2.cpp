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
    int n, k;
    cin >> n >> k;
    vi h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> dp(n, INF);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
            }
        }
    }
    cout << dp[n - 1] << endl;
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
