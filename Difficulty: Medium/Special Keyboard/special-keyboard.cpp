// User function Template for C++

class Solution {
  public:
    long long solve(int N,vector<long long>&dp){
        if(N<=6) return N;
        if(dp[N]!=-1){
            
            return dp[N];
        }
        long long ans=0;
        for(int i=N-3;i>=0;i--){
            long long curr= solve(i,dp) * (N-i-1);
            ans=max(ans,curr);
        }
        return dp[N]=ans;
    }
    long long int optimalKeys(int N) {
        // code here
        if(N<=6) return N;
        vector<long long>dp(N+1,-1);
        return solve(N,dp);
    }
};