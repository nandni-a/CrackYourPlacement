class Solution {
  public:
    int solve(int i,int t,vector<int>& val, vector<int>& wt,vector<vector<int>>&dp){
        if(i==0){
            return (int)(t/wt[0])*val[0];
        }
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        int take=INT_MIN;
        if(wt[i]<=t){
            take=val[i]+ solve(i,t-wt[i],val,wt,dp);
        }
        int notake= solve(i-1,t,val,wt,dp);
        return dp[i][t]=max(take,notake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return solve(n-1,capacity,val,wt,dp);
        
    }
};