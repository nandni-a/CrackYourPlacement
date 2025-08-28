class Solution {
  public:
    int solve(vector<int> &coins, int target,vector<int>&dp){
        if(target==0) return 0;
        if(target<0) return 1e9;
        if(dp[target]!=-1){
            return dp[target];
        }
        int ans=1e9;
        for(int i:coins){
            int coin=1+ solve(coins,target-i,dp);
            ans=min(ans,coin);
        }
        return dp[target]=ans;
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        if(coins.empty() && sum>0) return -1;
        if(sum==0) return 0;
        int n=coins.size();
        vector<int>dp(sum+1,-1);
        int ans=solve(coins,sum,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
    
};