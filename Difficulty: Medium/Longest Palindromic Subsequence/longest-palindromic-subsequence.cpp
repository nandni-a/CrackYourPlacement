// User function Template for C++

class Solution {
  public:
    int solve(int i,int j,string &s , string &t,vector<vector<int>>&dp){
        int n=s.length();
        if(i==n || j==n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j] ){
            return dp[i][j]=1+solve(i+1,j+1,s,t,dp);
        }
        return dp[i][j]=max(solve(i+1,j,s,t,dp),solve(i,j+1,s,t,dp));
    }
    int longestPalinSubseq(string &s) {
        // code here
        string t=s;
        int n=s.length();
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,s,t,dp);
    }
};