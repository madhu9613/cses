// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         sum += a[i];
//     }

//     vector<int>dp(sum+1,false);
//     dp[0]=true; //as sum=0 is alwasys possible;
//     for(int i=0;i<n;i++)
//     {
//         int coin=a[i];
//         for(int j=sum;j>=coin;j--)
//         {
//             if(dp[j-coin])
//             {
//                 dp[j]=true;
//             }
//         }
//     }
//     vector<int>res;
//     for(int i=1;i<=sum;i++)
//     {
//  if(dp[i])
//  {
//     res.push_back(i);
//  }
//     }
// cout<<res.size()<<endl;
// for(auto &i:res)
// {
//     cout<<i<<" ";
// }
// cout<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
        total += coins[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(total + 1, false));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int sum = 1; sum <= total; ++sum)
        {
            // Option 1: don't take the coin
            dp[i][sum] = dp[i - 1][sum];

            // Option 2: take the coin if possible first (i) coin here i-1 means ith position coin in 1 indexing 
            if (sum >= coins[i - 1] && dp[i - 1][sum - coins[i - 1]])
            {
                dp[i][sum] = true;
            }
        }
    }

    vector<int> result;
    for (int sum = 1; sum <= total; ++sum)
    {
        if (dp[n][sum])
            result.push_back(sum);
    }

    cout << result.size() << "\n";
    for (int x : result)
        cout << x << " ";
    cout << "\n";
    return 0;
}
