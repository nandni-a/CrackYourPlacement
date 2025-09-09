class Solution {
  public:
    int solve(int i,int j,string &txt, string &pat,vector<vector<int>>&dp){
        int n=txt.size();
        int m=pat.size();
        if(j==m) return 1;
        if(i==n && j<m) return 0;
        if(dp[i][j]!=-1){
            dp[i][j];
        }
        if(txt[i]==pat[j]){
            return dp[i][j]=solve(i+1,j+1,txt,pat,dp) + solve(i+1,j,txt,pat,dp);
        }
        else{
            return dp[i][j]=solve(i+1,j,txt,pat,dp);
        }
    }
    int subseqCount(string &txt, string &pat) {
        // code here
        int n=txt.size();
        int m=pat.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][m]=1;
            
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(txt[i]==pat[j]){
                    dp[i][j]=dp[i+1][j+1]+ dp[i+1][j];
                }
                else{
                    dp[i][j]=dp[i+1][j];
                }
            }
        }
        return dp[0][0];
        
    }
};