// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>> &grid ){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        vector<vector<int>>dir={{-1,0},{0,-1},{0,1},{1,0}};
        for(int d=0;d<4;d++){
            int nr=i+dir[d][0];
            int nc=j+dir[d][1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                dfs(nr,nc,vis,grid);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !vis[0][i]){
                dfs(0,i,vis,grid);
            }
            if(grid[n-1][i]==1 && !vis[n-1][i]){
                dfs(n-1,i,vis,grid);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid);
            }
            if(!vis[i][m-1]&& grid[i][m-1]==1){
                dfs(i,m-1,vis,grid);
            }
        }
        int total_ones=0;
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j]==1) {
                    total_ones++;
                }
            }
        }
        return total_ones;
    }
};
