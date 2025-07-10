class Solution {
  public:
    bool solve(int i,int j,string& s1, string& s2, string& s3,vector<vector<bool>>&dp){
        if(i==s1.length() && j==s2.length()) return true;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int k= i+j;
        bool string1=false,string2=false;
        if(i<s1.length() && s1[i]==s3[k]){
            string1=solve(i+1,j,s1,s2,s3,dp);
            
        }
        if(j<s2.length() && s2[j]==s3[k]){
            string2=solve(i,j+1,s1,s2,s3,dp);
            
        }
        return dp[i][j]= string1 || string2;
        
    }
    bool isInterleave(string& s1, string& s2, string& s3) {
        // code here
        int n = s1.size(), m = s2.size(), t = s3.size();
        if (n + m != t) return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};