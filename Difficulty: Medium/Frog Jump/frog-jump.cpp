class Solution {
  public:
    int fun(int ind,vector<int>&height,vector<int>&dp){
        if(ind==0) return 0;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int left=fun(ind-1,height,dp) + abs(height[ind] - height[ind-1]);
        int right=INT_MAX;
        if(ind>1) right=fun(ind-2,height,dp) + abs(height[ind]-height[ind-2]);
        return dp[ind]=min(left,right);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n,-1);
        return fun(n-1,height,dp);
    }
};