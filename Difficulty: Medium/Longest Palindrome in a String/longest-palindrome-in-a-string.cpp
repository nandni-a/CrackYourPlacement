class Solution {
  public:
  bool isPal(int i,int j,vector<vector<int>>&dp,string &s){
      if(i>=j) return true;
      if(dp[i][j]!=-1) return dp[i][j];
      if(s[i]==s[j] && isPal(i+1,j-1,dp,s)){
          return dp[i][j]=1;
      }
      return dp[i][j]=0;
  }
    string longestPalindrome(string &s) {
        // code here
        string ans="";
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal(i,j,dp,s)){
                    if(j-i+1 > ans.size()){
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};