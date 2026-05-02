#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Efficient solution using DP with sets
int countDistinctPalindromicSubseqEvenPosEfficient(const string &s)
{
    int n = s.length();
    if (n == 0)
        return 0;

    // dp[i][j] = set of distinct palindromes in s[i..j]
    vector<vector<unordered_set<string>>> dp(n, vector<unordered_set<string>>(n));

    // Initialize
    for (int i = 0; i < n; i++)
    {
        dp[i][i].insert(string(1, s[i]));
    }

    // Fill DP table
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;

            // Copy palindromes from smaller intervals
            for (const auto &pal : dp[i][j - 1])
                dp[i][j].insert(pal);
            for (const auto &pal : dp[i + 1][j])
                dp[i][j].insert(pal);

            // Handle palindromes formed with s[i] and s[j]
            if (s[i] == s[j])
            {
                if (len == 2)
                {
                    dp[i][j].insert(string(2, s[i]));
                }
                else
                {
                    for (const auto &pal : dp[i + 1][j - 1])
                    {
                        dp[i][j].insert(s[i] + pal + s[j]);
                    }
                }
            }
        }
    }

    // Count distinct palindromes ending at even positions
    unordered_set<string> result;
    for (int j = 0; j < n; j++)
    {
        if (j % 2 == 0)
        { // Even position (0-based)
            for (int i = 0; i <= j; i++)
            {
                for (const auto &pal : dp[i][j])
                {
                    result.insert(pal);
                }
            }
        }
    }

    return result.size();
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = countDistinctPalindromicSubseqEvenPosEfficient(s);
    cout << "Number of distinct palindromic subsequences ending at even positions: " << result << endl;

    return 0;
}