// we need to cheoose subsets for ridres

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int total = 1 << n;
    vector<pair<int, int>> dp(total, {n + 1, 0}); // total rides,last_wieght
    // inittially
    dp[0] = {1, 0};
    for (int mask = 0; mask < total; ++mask)
    {
        for (int i = 0; i < n; i++)
        {
            // we havenot include i then only we will proceed;
            if (!(mask & (1 << i)))
            {
                auto [rides, weight] = dp[mask];
                if (weight + w[i] <= x)
                {
                    dp[mask | (1 << i)] = min(dp[mask | (1 << i)], {rides, weight + w[i]});
                }
                else
                {
                    dp[mask | (1 << i)] = min(dp[mask | (1 << i)], {rides + 1, w[i]});
                }
            }
        }
    }

    cout<<dp[total-1].first<<endl;

    return 0;
}

