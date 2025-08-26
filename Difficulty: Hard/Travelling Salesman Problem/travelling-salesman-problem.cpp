class Solution {
  public:
    int solve(int ind,int mask,vector<vector<int>>& cost,vector<vector<int>>&dp){
        int n=cost.size();
        if(mask==(1<<n)-1){
            return cost[ind][0];
        }
        if(dp[ind][mask]!=-1){
            return dp[ind][mask];
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i))){
                int num=cost[ind][i] + solve(i,(mask|(1<<i)),cost,dp);
                ans=min(ans,num);
            }
        }
        return dp[ind][mask]=ans;
    }
    int tsp(vector<vector<int>>& cost) {
        // Code here
        int n=cost.size();
        vector<vector<int>>dp(n+1,vector<int>(1<<n,-1));
        int ans=solve(0,1,cost,dp);
        return ans;
        
    }
};