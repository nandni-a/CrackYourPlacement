class Solution {
  public:
    vector<vector<int>>dir={{-1,-1},{1,-1},{-1,1},{1,1},{0,1},{1,0},{-1,0},{0,-1}};
    
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=1;
        for(auto d:dir){
            int nr=i+d[0];
            int nc=j+d[1];
            if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]=='L' && !vis[nr][nc]){
                dfs(nr,nc,vis,grid);
                
            }
        }
        
    }
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='L' && !vis[i][j]){
                    dfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};