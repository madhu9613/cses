#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

inline int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

inline int sub(int a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

inline int mul(long long a, long long b)
{
    return (a * b) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    // dp[l][r] = number of DISTINCT palindromic subsequences in s[l..r]
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // nextPos[i][c] = first occurrence of char c strictly AFTER index i
    // prevPos[i][c] = last occurrence of char c strictly BEFORE index i
    vector<vector<int>> nextPos(n, vector<int>(26, n));
    vector<vector<int>> prevPos(n, vector<int>(26, -1));

    // -------- build nextPos --------
    vector<int> last(26, n);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int c = 0; c < 26; c++)
        {
            nextPos[i][c] = last[c];
        }
        last[s[i] - 'a'] = i;
    }

    // -------- build prevPos --------
    fill(last.begin(), last.end(), -1);
    for (int i = 0; i < n; i++)
    {
        for (int c = 0; c < 26; c++)
        {
            prevPos[i][c] = last[c];
        }
        last[s[i] - 'a'] = i;
    }

    // -------- base case: length = 1 --------
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1; // single character palindrome
    }

    // -------- interval DP --------
    for (int len = 2; len <= n; len++)
    {
        for (int l = 0; l + len - 1 < n; l++)
        {
            int r = l + len - 1;

            if (s[l] != s[r])
            {
                dp[l][r] = sub(
                    add(dp[l + 1][r], dp[l][r - 1]),
                    dp[l + 1][r - 1]);
            }
            else
            {
                int c = s[l] - 'a';
                int nl = nextPos[l][c];
                int pr = prevPos[r][c];

                if (nl > pr)
                {
                    // no same char inside
                    dp[l][r] = add(mul(2, dp[l + 1][r - 1]), 2);
                }
                else if (nl == pr)
                {
                    // exactly one same char inside
                    dp[l][r] = add(mul(2, dp[l + 1][r - 1]), 1);
                }
                else
                {
                    // duplicates inside
                    dp[l][r] = sub(
                        mul(2, dp[l + 1][r - 1]),
                        dp[nl + 1][pr - 1]);
                }
            }
        }
    }

    // total DISTINCT palindromic subsequences
    cout << dp[0][n - 1] << "\n";
    return 0;
}
