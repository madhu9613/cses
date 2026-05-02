/***
 * 
 * this problem is created by me donot know actual solution till now and also donot kknow is this correct or wrong;
 * 
 * need to cound distinct subsequence ending at even positions and condition is the subsequnce must be pallindrom;
 * ..
 * this pallindrom condition adding extra complexity;
 * 
 */

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

    int n = (int)s.size();

    // dp[l][r] = number of DISTINCT palindromic subsequences in s[l..r]
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // endAt[l][r] = number of DISTINCT palindromic subsequences
    // in s[l..r] that END EXACTLY at r
    vector<vector<int>> endAt(n, vector<int>(n, 0));

    // next / prev occurrence arrays
    vector<vector<int>> nextPos(n, vector<int>(26, n));
    vector<vector<int>> prevPos(n, vector<int>(26, -1));

    // build nextPos
    vector<int> last(26, n);
    for (int i = n - 1; i >= 0; i--)
    {
        last[s[i] - 'a'] = i;
        for (int c = 0; c < 26; c++)
        {
            nextPos[i][c] = last[c];
        }
    }

    // build prevPos
    fill(last.begin(), last.end(), -1);
    for (int i = 0; i < n; i++)
    {
        last[s[i] - 'a'] = i;
        for (int c = 0; c < 26; c++)
        {
            prevPos[i][c] = last[c];
        }
    }

    // length = 1
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;    // single character palindrome
        endAt[i][i] = 1; // ends at i
    }

    // length >= 2
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

                endAt[l][r] = endAt[l + 1][r];
            }
            else
            {
                int c = s[l] - 'a';
                int nl = nextPos[l][c];
                int pr = prevPos[r][c];

                if (nl > pr)
                {
                    dp[l][r] = add(mul(2, dp[l + 1][r - 1]), 2);
                }
                else if (nl == pr)
                {
                    dp[l][r] = add(mul(2, dp[l + 1][r - 1]), 1);
                }
                else
                {
                    dp[l][r] = sub(
                        mul(2, dp[l + 1][r - 1]),
                        dp[nl + 1][pr - 1]);
                }

                // palindromes ending exactly at r
                endAt[l][r] = add(1, dp[l + 1][r - 1]);
            }
        }
    }

    // sum palindromes ending at EVEN indices
    int ans = 0;
    for (int r = 0; r < n; r++)
    {
        if (r % 2 == 0)
        {
            for (int l = 0; l <= r; l++)
            {
                ans = add(ans, endAt[l][r]);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
