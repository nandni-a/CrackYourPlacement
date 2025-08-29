class Solution {
  public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>> &grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i==m-1 && j==n-1 && grid[i][j]==0) return 1;
        if(i>=m || j>=n || grid[i][j]==1) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]= solve(i+1,j,dp,grid) + solve(i,j+1,dp,grid);
    }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,dp,grid);
        
    }
};