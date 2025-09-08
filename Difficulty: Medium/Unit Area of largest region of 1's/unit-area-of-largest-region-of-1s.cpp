class Solution {
  public:
    // Function to find unit area of the largest region of 1s.
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int &ans){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        ans++;
        vector<vector<int>>dir={{-1,0},{0,-1},{0,1},{1,0},{-1,-1},{1,-1},{1,1},{-1,1}};
        for(int d=0;d<8;d++){
            int nr=i+dir[d][0];
            int nc=j+dir[d][1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                dfs(nr,nc,grid,vis,ans);
            }
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int ans=0;
                    dfs(i,j,grid,vis,ans);
                    maxi=max(maxi,ans);
                }
            }
        }
        return maxi;
    }
};