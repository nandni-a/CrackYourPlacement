class Solution {
  public:
    bool isInterleave(string& s1, string& s2, string& s3) {
        // code here
        int n=s1.length();
        int m=s2.length();
        if(s3.length()!=n+m) return false;
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        dp[0][0]=true;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i>0 && s1[i-1]==s3[i+j-1]){
                    dp[i][j]= dp[i][j]|| dp[i-1][j];
                }
                if(j>0 && s2[j-1]==s3[i+j-1]){
                    dp[i][j]= dp[i][j]|| dp[i][j-1];
                }
                
            }
        }
        return dp[n][m];
    }
};