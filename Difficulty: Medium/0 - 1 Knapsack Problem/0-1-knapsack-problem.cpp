class Solution {
  public:
    int solve(int ind,int cap,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){
        int n=val.size();
        if(ind==n-1){
            if(wt[ind]<=cap){
                return val[ind];
            }
            else{
                return 0;
            }
        }
        
        if(ind>=n) return 0;
        if(dp[ind][cap]!=-1){
            return dp[ind][cap];
        }
        int take=INT_MIN;
        int notTake=solve(ind+1,cap,val,wt,dp);
        if(wt[ind]<=cap){
            take= val[ind]+solve(ind+1,cap-wt[ind],val,wt,dp);
        }
        return dp[ind][cap]=max(take,notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        // code here
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return solve(0,W,val,wt,dp);
        
    }
};