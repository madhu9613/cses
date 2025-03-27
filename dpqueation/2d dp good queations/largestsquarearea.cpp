class Solution {
    public:
      int solve(vector<vector<int>>&mat,int i,int j,int &maxi)
      {
          if(i>=mat.size() || j>=mat[0].size())
          {
              return 0;
          }
          int right=solve(mat,i+1,j,maxi);
          int down=solve(mat,i,j+1,maxi);
          int diag=solve(mat,i+1,j+1,maxi);
          if(mat[i][j]==1)
          {
              int ans=1+min(right,min(down,diag));
              maxi=max(maxi,ans);
              return ans;
          }
          else{
              return 0;
          }
      }
      int maxSquare(vector<vector<int>>& mat) {
          // code here
          int maxi=0;
          int solve(mat,0,0,maxi);
          return maxi;
      }
  };
  