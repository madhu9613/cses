#include <bits/stdc++.h>
using namespace std;

long long solvememo(int dice, int face, int target, vector<vector<long long>>& dp) {
    if (dice == 0 && target == 0) return 1;
    if (target < 0 || dice == 0) return 0;

    // Check if the subproblem is already solved
    if (dp[dice][target] != -1) return dp[dice][target];

    long long ans = 0;
    for (int i = 1; i <= face; i++) {
        ans += solvememo(dice - 1, face, target - i, dp);
    }

    return dp[dice][target] = ans; // Store the result
}

long long countways(int dice,int face,int target)
{
    vector<long long> prev(target+1);
    vector<long long> curr(target+1);
    //if dice and target both are zero then its one way
    prev[0]=1;
    for(int d=1;d<=dice;d++)
    {
        for(int t=0;t<=target;t++)
        {
            long long ans=0;
            for(int i=1;i<=face;i++)
            {
                if(t-i >=0)
                {
                    ans+=prev[t-i];

                }
                curr[t]=ans;
            }
        }
        prev=curr;
    }
    return prev[target];

}

int main() {
    int m, n, x;
    cin >> m >> n >> x;

    // Initialize dp with -1
    vector<vector<long long>> dp(m + 1, vector<long long>(x + 1, -1));

    cout << countways(m, n, x) << endl;
    return 0;
}
