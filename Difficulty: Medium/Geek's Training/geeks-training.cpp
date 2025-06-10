class Solution {
  public:
    int solve(int ind,int last,vector<vector<int>>& arr,vector<vector<int>>&dp){
        if(ind==0){
            int maxi=0;
            for(int i=0;i<=2;i++){
                if(i!=last){
                    maxi=max(maxi,arr[0][i]);
                }
            }
            return maxi;
        }
        if(dp[ind][last]!=-1) return dp[ind][last];
        int maxi=0;
            for(int i=0;i<=2;i++){
                if(i!=last){
                    int points=arr[ind][i]+ solve(ind-1,i,arr,dp);
                    maxi=max(maxi,points);
                }
            }
            return dp[ind][last]=maxi;
        
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(n-1,3,arr,dp);
    }
};