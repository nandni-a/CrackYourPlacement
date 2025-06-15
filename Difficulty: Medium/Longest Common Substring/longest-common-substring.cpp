class Solution {
  public:
    int longestCommonSubstr(string& text1, string& text2) {
        // your code here
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        int res=0;
        
        for(int i=text1.length()-1;i>=0;i--){
            for(int j=text2.length()-1;j>=0;j--){
                int ans=0;
                if(text1[i]==text2[j]){
                    dp[i][j]=1+ dp[i+1][j+1];
                    res=max(res,dp[i][j]);
                }
                else{
                    dp[i][j]= 0;
                }
                
            }
        }
        
        
        return res;
    }
};