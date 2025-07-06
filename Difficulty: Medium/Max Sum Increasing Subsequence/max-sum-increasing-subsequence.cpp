class Solution {
  public:
   int solve(vector<int>& arr, int ind, int prev, vector<vector<int>>& dp) {
        if (ind == arr.size()) return 0;

        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int take = 0;
        if (prev == -1 || arr[ind] > arr[prev]) {
            take = arr[ind] + solve(arr, ind + 1, ind, dp);
        }

        int notTake = solve(arr, ind + 1, prev, dp);

        return dp[ind][prev + 1] = max(take, notTake);
    }

    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(arr, 0, -1, dp);
        
    }
};