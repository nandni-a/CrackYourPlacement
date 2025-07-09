class Solution {
  public:
    int solve(int n,int x,int m,vector<vector<int>>&dp){
        if(n==0 && x==0){
            return 1;
        }
        if(n==0 || x<0){
            return 0;
        }
        if(dp[n][x]!=-1){
            return dp[n][x];
        }
        int ways=0;
        for(int i=1;i<=m;i++){
            ways= ways+ solve(n-1,x-i,m,dp);
        }
        return dp[n][x]=ways;
    }
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
        return solve(n,x,m,dp);
    }
};