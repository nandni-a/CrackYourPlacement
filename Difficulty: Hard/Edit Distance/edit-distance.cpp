class Solution {
  public:
    // Function to compute the edit distance between two strings
    int solve(int i , int j,string& s1, string& s2,vector<vector<int>>&dp){
        if(i==s1.size()){
            return s2.size()-j;
        }
        if(j==s2.length()){
            return s1.size()-i;
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return solve(i+1,j+1,s1,s2,dp);
        }
        int add= 1+ solve(i,j+1,s1,s2,dp);
        int del=1+ solve(i+1,j,s1,s2,dp);
        int up=1+ solve(i+1,j+1,s1,s2,dp);
        return dp[i][j]=min({add,del,up});
    }
    int editDistance(string& s1, string& s2) {
        // code here
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,s1,s2,dp);
        
    }
};