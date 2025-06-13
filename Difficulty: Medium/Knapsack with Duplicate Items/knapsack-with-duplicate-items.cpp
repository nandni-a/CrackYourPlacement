// User function Template for C++

class Solution {
  public:
    int solve(int i,int cap, vector<int>& val, vector<int>& wt, vector<vector<int>>&dp){
        int n=val.size();
        if(i==0){
            if(cap>=wt[i]){
                return (cap / wt[0]) * val[0];
            }
            else{
                return 0;
            }
        }
        
        if(dp[i][cap]!=-1){
            return dp[i][cap];
        }
        int take=INT_MIN;
        if(cap >= wt[i])
            take= val[i]+ solve(i,cap-wt[i],val,wt,dp);
        int notTake= solve(i-1,cap,val,wt,dp);
        return dp[i][cap]=max(take,notTake);
        
        
        
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return solve(n-1,capacity,val,wt,dp);
        
    }
};