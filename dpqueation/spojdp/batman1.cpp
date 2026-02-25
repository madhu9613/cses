// // https://www.spoj.com/problems/BAT1/

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define pb push_back
// #define vi vector<int>
// #define vll vector<ll>
// #define max3(a, b, c) max(max(a, b), c)
// #define max4(a, b, c, d) max(max(a, b), max(c, d))
// #define pii pair<int, int>
// #define pll pair<ll, ll>
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define endl '\n'

// const int NEG = INT_MIN;

// void solve()
// {
//     int n, m, k;
//     cin >> n >> m >> k;

//     vector<int> open(n);
//     for (int i = 0; i < n; i++)
//         cin >> open[i];

//     vector<vector<int>> cost(n, vector<int>(m));
//     vector<vector<int>> rating(n, vector<int>(m));

//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             cin >> cost[i][j];

//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             cin >> rating[i][j];

//     vector<vector<int>> best(n, vector<int>(k + 1, 0));

//     for (int i = 0; i < n; i++)
//     {
//         for (int c = 0; c <= k; c++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (c >= cost[i][j])
//                 {
//                     best[i][c] = max(
//                         best[i][c],
//                         best[i][c - cost[i][j]] + rating[i][j]);
//                 }
//             }
//         }
//     }

//     vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

//     for (int i = 1; i <= n; i++)
//     {
//         for (int c = 0; c <= k; c++)
//         {
//             dp[i][c] = dp[i - 1][c]; // skip batch
//             for (int w = 0; w + open[i - 1] <= c; w++)
//             {
//                 dp[i][c] = max(
//                     dp[i][c],
//                     dp[i - 1][c - open[i - 1] - w] + best[i - 1][w]);
//             }
//         }
//     }

//     cout << dp[n][k] << "\n";
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// https://www.spoj.com/problems/BAT1/

#include <bits/stdc++.h>
using namespace std;

const int NEG = -1e9;

int dp[21][21][1001][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> open(n);
        for (int i = 0; i < n; i++)
            cin >> open[i];

        vector<vector<int>> cost(n, vector<int>(m));
        vector<vector<int>> rating(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> cost[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> rating[i][j];

        // initialize
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                for (int c = 0; c <= k; c++)
                    dp[i][j][c][0] = dp[i][j][c][1] = NEG;

        dp[0][0][0][0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int c = 0; c <= k; c++)
                {
                    for (int b = 0; b <= 1; b++)
                    {
                        if (dp[i][j][c][b] == NEG)
                            continue;

                        // skip weapon
                        dp[i][j + 1][c][b] = max(
                            dp[i][j + 1][c][b],
                            dp[i][j][c][b]);

                        // take weapon
                        if (b == 1)
                        {
                            if (c + cost[i][j] <= k)
                            {
                                dp[i][j][c + cost[i][j]][1] = max(
                                    dp[i][j][c + cost[i][j]][1],
                                    dp[i][j][c][1] + rating[i][j]);
                            }
                        }
                        else
                        {
                            if (c + open[i] + cost[i][j] <= k)
                            {
                                dp[i][j][c + open[i] + cost[i][j]][1] = max(
                                    dp[i][j][c + open[i] + cost[i][j]][1],
                                    dp[i][j][c][0] + rating[i][j]);
                            }
                        }
                    }
                }
            }

            // move to next batch
            for (int c = 0; c <= k; c++)
            {
                dp[i + 1][0][c][0] = max({dp[i + 1][0][c][0],
                                          dp[i][m][c][0],
                                          dp[i][m][c][1]});
            }
        }

        int ans = 0;
        for (int c = 0; c <= k; c++)
            ans = max({ans, dp[n][0][c][0], dp[n][0][c][1]});

        cout << ans << "\n";
    }
    return 0;
}
