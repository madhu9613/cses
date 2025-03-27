/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

*/
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int solvememo(vector<int> dice, int target,vector<int> &dp)
{

    if (target == 0)
    {
        return 1; // onw way completed
    }
    if (target < 0)
    {
        return 0;
    }
    if(dp[target]!=-1)
    {
        return dp[target];
    }
    int ans = 0;
    for (int i = 0; i < 6; i++)
    {

        ans = (ans + solvememo(dice, target - dice[i],dp)) % MOD;
    }
    dp[target]=ans;
    return dp[target];
}

int main()
{
    int n;
    cin >> n;
    vector<int> disc;
    for (int i = 1; i <= 6; i++)
    {
        disc.push_back(i); // creating dics
    }
    vector<int> dp(n+1,-1);
    int ans = solvememo(disc, n,dp);
    cout << ans << endl;
    return 0;
}