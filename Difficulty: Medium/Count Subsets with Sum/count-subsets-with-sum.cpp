class Solution {
  public:
    int solve(int i,int s,vector<int>&arr,vector<vector<int>>&dp){
        if (i == 0) {
            if (s == 0 && arr[0] == 0) return 2;
            if (s == 0 || arr[0] == s) return 1;
            return 0;
        }
        if(dp[i][s]!=-1){
            return dp[i][s];
        }
        int notPick=solve(i-1,s,arr,dp);
        int pick=0;
        if(arr[i]<=s){
            pick = solve(i-1,s-arr[i],arr,dp);
        }
        return dp[i][s]=pick+notPick;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,arr,dp);
        
    }
};