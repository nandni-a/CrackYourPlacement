// User function Template for C++

class Solution {
  public:
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int len=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mat[i-1][j-1]==1){
                    dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                    len=max(len,dp[i][j]);
                }
            }
        }
        return len;
    }
};