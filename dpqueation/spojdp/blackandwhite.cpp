#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

const int INF = INT_MAX;

static int dp[205][205][205];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int n;
        cin >> n;
        if (n == -1)
            break;

        vi a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // Base case
        for (int b = 0; b <= n; b++)
        {
            for (int w = 0; w <= n; w++)
            {
                dp[n][b][w] = 0;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int b = 0; b <= n; b++)
            {
                for (int w = 0; w <= n; w++)
                {

                    int res = dp[i + 1][b][w];

                    int lastB = (b == n) ? INT_MIN : a[b];
                    if (a[i] > lastB)
                    {
                        res = max(res, 1 + dp[i + 1][i][w]);
                    }

                    int lastW = (w == n) ? INT_MAX : a[w];
                    if (a[i] < lastW)
                    {
                        res = max(res, 1 + dp[i + 1][b][i]);
                    }

                    dp[i][b][w] = res;
                }
            }
        }

        cout << n - dp[0][n][n] << endl;
    }

    return 0;
}
