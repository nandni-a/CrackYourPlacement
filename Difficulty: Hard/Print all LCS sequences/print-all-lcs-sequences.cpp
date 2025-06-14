class Solution {
public:
    unordered_map<string, vector<string>> memo;

    vector<string> fn(int i, int j, vector<vector<int>>& dp, string& s, string& t) {
        if (i == 0 || j == 0) return {""};

        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];

        vector<string> res;

        if (s[i - 1] == t[j - 1]) {
            vector<string> temp = fn(i - 1, j - 1, dp, s, t);
            for (string str : temp) {
                res.push_back(str + s[i - 1]);  // keep order, no need to reverse
            }
        } else {
            if (dp[i - 1][j] >= dp[i][j - 1]) {
                vector<string> top = fn(i - 1, j, dp, s, t);
                res.insert(res.end(), top.begin(), top.end());
            }
            if (dp[i][j - 1] >= dp[i - 1][j]) {
                vector<string> left = fn(i, j - 1, dp, s, t);
                res.insert(res.end(), left.begin(), left.end());
            }
        }

        // Remove duplicates
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());

        return memo[key] = res;
    }

    int solve(string& text1, string& text2, vector<vector<int>>& dp) {
        int n = text1.size();
        int m = text2.size();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }

    vector<string> allLCS(string& text1, string& text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        solve(text1, text2, dp);

        vector<string> result = fn(n, m, dp, text1, text2);
        sort(result.begin(), result.end());  // final sort for lexicographic order
        return result;
    }
};
