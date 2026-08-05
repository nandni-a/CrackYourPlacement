class Solution {
  public:
    int solve(int i,int n,vector<int>&price,vector<vector<int>>&dp){
        if(i==0){
            return n*price[0];
        }
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        int notake= solve(i-1,n,price,dp);
        int take=-1e9;
        if(i+1 <= n){
            take= price[i] + solve(i,n-(i+1),price,dp);
        }
        return dp[i][n]=max(take,notake);
        
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,price,dp);
    }
};