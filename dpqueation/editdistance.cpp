// #include <bits/stdc++.h>
// using namespace std;

// int editDistance(int i, int j, string &a, string &b, vector<vector<int>> &dp) {
//     if (i == 0) return j; // insert j characters
//     if (j == 0) return i; // delete i characters

//     if (dp[i][j] != -1) return dp[i][j];

//     if (a[i - 1] == b[j - 1]) {
//         // Characters match, no operation needed
//         return dp[i][j] = editDistance(i - 1, j - 1, a, b, dp);
//     } else {
//         // Take min of insert, delete, replace
//         int insertOp = editDistance(i, j - 1, a, b, dp);
//         int deleteOp = editDistance(i - 1, j, a, b, dp);
//         int replaceOp = editDistance(i - 1, j - 1, a, b, dp);
//         return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
//     }
// }

// int main() {
//     string a, b;
//     cin >> a >> b;
//     int n = a.size(), m = b.size();

//     // Initialize memoization table with -1
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//     cout << editDistance(n, m, a, b, dp) << endl;

//     return 0;
// }


 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {

    string a,b;cin>>a>>b;
    int n=a.length();
    int m=b.length();

    vector<vector<int>>dp(n+1,vector<int>(m+1,1e6));
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=i;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                //replace char to match abce abcd replace d with e so adce and abce last match sting dec by 1so i-1 j-1
                dp[i][j]=dp[i-1][j-1]+1;
            }

            dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
        }
    }

    cout<<dp[n][m]<<endl;
    
    return 0;
 }