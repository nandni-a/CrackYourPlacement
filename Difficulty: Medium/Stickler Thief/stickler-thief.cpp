class Solution {
public:
    int solve(int ind, int steal, vector<int>& arr,vector<vector<int>>&dp) {

        

        if(ind == 0) {
            if(steal == 1)
                return arr[0];
            return 0;
        }
        if(dp[ind][steal]!=-1){
            return dp[ind][steal];
        }

        int exc = solve(ind - 1, 1, arr,dp);

        int inc = 0;

        if(steal == 1) {
            inc = arr[ind] + solve(ind - 1, 0, arr,dp);
        }

        return dp[ind][steal] = max(exc, inc);
    }

    int findMaxSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(arr.size() - 1, 1, arr,dp);
    }
};