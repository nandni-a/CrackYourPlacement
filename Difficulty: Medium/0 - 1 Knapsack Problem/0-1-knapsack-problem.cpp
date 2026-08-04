class Solution {
  public:
    int solve(int i,int w,vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
        if(i==0){
            if(wt[0]<=w) return val[0];
            else return 0;
        }
        if(dp[i][w]!=-1){
            return dp[i][w];
        }
        
        int nottake= 0 + solve(i-1,w,val,wt,dp);
        int take=INT_MIN;
        if(wt[i]<=w){
            take = val[i]+ solve(i-1,w-wt[i],val,wt,dp);
        }
        return dp[i][w]=max(take,nottake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return solve(n-1,W,val,wt,dp);
        
    }
};