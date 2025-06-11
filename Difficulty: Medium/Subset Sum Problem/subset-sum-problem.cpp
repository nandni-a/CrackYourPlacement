class Solution {
  public:
    bool solve(int i,int sum,vector<int>& arr,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(sum<0 ) return false;
        if(i>= arr.size()) return false;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        bool inc= solve(i+1,sum-arr[i],arr,dp);
        bool exc=solve(i+1,sum,arr,dp);
        return dp[i][sum]=(inc || exc);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(0,sum,arr,dp);
    }
};