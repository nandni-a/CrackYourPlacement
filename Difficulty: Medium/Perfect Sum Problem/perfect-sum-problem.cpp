class Solution {
  public:
    int mod = 1e9 + 7;
    
    int solve(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if (i == arr.size()) {
            return sum == 0 ? 1 : 0;
        }

        if (dp[i][sum] != -1) return dp[i][sum];

        int take = 0;
        if (arr[i] <= sum)
            take = solve(i + 1, sum - arr[i], arr, dp) % mod;

        int notTake = solve(i + 1, sum, arr, dp) % mod;

        return dp[i][sum] = (take + notTake) % mod;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(0, target, arr, dp);
    }
};