#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);

        for (auto &x : a)
            cin >> x;

        vector<long long> dp(n + 2, 0);

        for (int i = n - 2; i >= 0; --i)
        {
            dp[i] = max(
                a[i] + dp[i + 1],
                -a[i + 1] + dp[i + 2]);
        }

        cout << dp[0] << "\n";
    }

    return 0;
}
