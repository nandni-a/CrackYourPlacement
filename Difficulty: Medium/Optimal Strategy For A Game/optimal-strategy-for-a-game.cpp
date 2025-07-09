class Solution {
  public:
  int solve(vector<int>&arr, int i,int j,vector<vector<int>>&dp){
      if(i>j){
          return 0;
      }
      if(i==j){
          return arr[i];
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      int a= arr[i]+ min(solve(arr,i+2,j,dp),solve(arr,i+1,j-1,dp));
      int b=arr[j] + min(solve(arr,i,j-2,dp),solve(arr,i+1,j-1,dp));
      return dp[i][j]=max(a,b);
  }
    int maximumAmount(vector<int> &arr) {
        int n=arr.size();
        // code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(arr,0,arr.size()-1,dp);
    }
};