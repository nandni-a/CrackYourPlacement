// User function Template for C++

class Solution {
  public:
  void dfs(int row, int col, vector<vector<int>>& arr, vector<vector<int>>& vis, vector<pair<int, int>>& vec, int row0, int col0, int n, int m) {
    vis[row][col] = 1;
    vec.push_back({row - row0, col - col0});

    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    for (const auto& dir : directions) {
        int r = row + dir[0];
        int c = col + dir[1];
        if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && arr[r][c] == 1) {
            dfs(r, c, arr, vis, vec, row0, col0, n, m);
        }
    }
}
    int countDistinctIslands(vector<vector<int>>& arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        set<vector<pair<int, int>>> st;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] && arr[i][j] == 1) {
                vector<pair<int, int>> vec;
                dfs(i, j, arr, vis, vec, i, j, n, m);
                st.insert(vec);
            }
        }
    }
    return st.size();
    }
};
