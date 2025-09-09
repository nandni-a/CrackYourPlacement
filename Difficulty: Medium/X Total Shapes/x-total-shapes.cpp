

class Solution {
  public:
    int n,m;
    // Function to find the number of 'X' total shapes.
    bool isValid(int i,int j){
        if(i>=0 && j>=0 && i<n && j<m){
            return true;
        }
        return false;
    }
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& grid){
        vis[i][j]=1;
        vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        for(int d=0;d<4;d++){
            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(isValid(r,c) && grid[r][c]=='X' && !vis[r][c]){
                dfs(r,c,vis,grid);
            }
        }
        
    }
    int xShape(vector<vector<char>>& grid) {
        // Code here
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X' && !vis[i][j]){
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return count;
        
    }
};