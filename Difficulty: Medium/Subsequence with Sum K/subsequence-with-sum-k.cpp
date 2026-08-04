class Solution {
public:
    bool solve(int ind, int target, vector<int>& arr,
               vector<vector<int>>& dp) {

        if (target == 0)
            return true;

        if (ind == 0)
            return arr[0] == target;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notPick = solve(ind - 1, target, arr, dp);

        bool pick = false;
        if (target >= arr[ind])
            pick = solve(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = (pick || notPick);
    }

    bool checkSubsequenceSum(vector<int>& arr, int k) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        return solve(n - 1, k, arr, dp);
    }
};