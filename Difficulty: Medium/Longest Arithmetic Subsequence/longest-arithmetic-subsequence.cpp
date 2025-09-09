// User function template for C++

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n<=2) return n;
        vector<unordered_map<int,int>>dp(n);
        int ans=2;
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                int diff=arr[j]-arr[i];
                if(dp[i].count(diff)){
                    dp[j][diff]= dp[i][diff]+1;
                }
                else{
                    dp[j][diff]=2;
                }
                ans=max(ans,dp[j][diff]);
            }
        }
        return ans;
    }
};