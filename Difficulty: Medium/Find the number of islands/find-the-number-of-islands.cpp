class Solution {
  public:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({row, col});
        int delRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
    
            for (int i = 0; i < 8; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 'L' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='L' ){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};