class Solution {
  public:
    int solve(vector<int>& arr,int i,int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int op1=arr[i]+ min(solve(arr,i+2,j,dp),solve(arr,i+1,j-1,dp));
        int op2=arr[j]+ min(solve(arr,i+1,j-1,dp),solve(arr,i,j-2,dp));
        return dp[i][j]=max(op1,op2);
    }
    int maxCoins(vector<int>& arr, int n) {
        // Write your code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(arr,0,n-1,dp);
        
    }
};