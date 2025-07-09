class Solution {
  public:
  int solve(int i,int j,string& s1, string& s2,vector<vector<int>>&dp){
      if(i==s1.length()){
          dp[i][j]=s2.length()-j;
      }
      if(j==s2.length()){
          dp[i][j]=s1.length()-i;
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      if (s1[i] == s2[j]) {
        return dp[i][j] = solve(i + 1, j + 1, s1, s2, dp);
    }
      int insert=1+solve(i+1,j,s1,s2,dp);
      int del=1+solve(i,j+1,s1,s2,dp);
      int update=1+solve(i+1,j+1,s1,s2,dp);
      return dp[i][j]=min({insert,del,update});
  }
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,dp);
        
    }
};