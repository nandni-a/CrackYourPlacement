// User function Template for C++

class Solution {
  public:
    int solve(int i,int j,vector<vector<int>>& mat, vector<vector<int>>&dp){
        int n=mat.size();
        int m=mat[0].size();
        
        if(j<0 || j>=m) return INT_MIN;
        if(i==n-1){
            return mat[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=solve(i+1,j,mat,dp);
        int left=solve(i+1,j-1,mat,dp);
        int right=solve(i+1,j+1,mat,dp);
        
        return dp[i][j]= mat[i][j]+ max({down,left,right});
        
    }
    int maximumPath(vector<vector<int>>& mat) {
        // code here
         int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=INT_MIN;
        for(int j=0;j<m;j++){
            ans=max(ans,solve(0,j,mat,dp));
        }
        return ans;
        
    }
};