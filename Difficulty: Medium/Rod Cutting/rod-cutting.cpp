// User function Template for C++

class Solution {
    
  public:
    int solve(int i,int n,vector<int> &price, vector<vector<int>>&dp ){
        if(i==0){
            return n*price[0];
        }
        if(dp[i][n]!=-1) return dp[i][n];
        int notTake=0+solve(i-1,n,price,dp);
        int take=INT_MIN;
        int len=i+1;
        if(len<=n){
            take= price[i]+solve(i,n-len,price,dp);
        }
        return dp[i][n]=max(take,notTake);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n-1,n,price,dp);
    }
};