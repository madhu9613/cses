#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
vector<string> grid;
vector<vector<int> > dp;
int solve(int i,int j)
{
    if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]=='*' )
    {
        return 0;
    }

    if(i==0 && j==0)
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    //count the path when it reach from top
    int up=solve(i-1,j)%MOD;
    int right=solve(i,j-1)%MOD;

    dp[i][j]= (up+right)%MOD;
    return dp[i][j];

    //current cell;

}
int solve_tab()
{
 int n=grid.size();
 dp.assign(n,vector<int>(n,0));
 if(grid[0][0]=='*')
 {
  
    return 0;
 }

 dp[0][0]=1; //path to reach 0,0 is 1
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<n;j++)
    {
        if(grid[i][j]=='*')
        {
            dp[i][j]=0;
        }
        else{
            //cont if its can come from top
            if(i>0) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            if(j>0) dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
        }
    }
 }
 return dp[n-1][n-1];
}

int main()
{
    int n;cin>>n;
    grid.resize(n);
   
    for(int i=0;i<n;i++)
    {
        cin>>grid[i];
    }
    // dp.assign(n,vector<int>(n,-1));

  
//    int ans= solve(n-1,n-1); //no of ways to reach bottom right cell is
  int ans=solve_tab(); 
   cout<<ans<<endl;
    return 0;
}