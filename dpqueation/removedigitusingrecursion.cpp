#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum steps
int solve(int n, vector<int>& dp)
{
    if (n == 0)
    {
        return 0; // no steps needed to reach 0
    }

    if (dp[n] != -1)
    {
        return dp[n]; // return if already computed
    }

    int mini = INT_MAX;

    int temp = n;
    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit > 0)
        {
            mini = min(mini, solve(n - digit, dp) + 1); // +1 for the current step
        }
        temp /= 10; // remove the last digit
    }

    return dp[n] = mini; // store the result
}

// Function to calculate the number of ways
int noofways(int n, vector<int>& dp)
{
    if (n == 0)
    {
        return 1; // Only one way to reach 0 (do nothing)
    }
    if (n < 0)
    {
        return 0; // No valid way to reduce a negative number to zero
    }

    if (dp[n] != -1)
    {
        return dp[n]; // return if already computed
    }

    int count = 0;
    int temp = n;

    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit > 0)
        {
            count += noofways(n - digit, dp); // Add the ways to reduce n - digit
        }
        temp /= 10; // remove the last digit
    }

    return dp[n] = count; // store the result
}

int main()
{
    int n;
    cin >> n;

    // Create dp array initialized to -1 (uncomputed states)
    vector<int> dp(n + 1, -1);

    // Calculate the number of ways to reduce n to 0
    int c = noofways(n, dp);
    
    // Output the result
    cout << c << endl;

    return 0;
}
