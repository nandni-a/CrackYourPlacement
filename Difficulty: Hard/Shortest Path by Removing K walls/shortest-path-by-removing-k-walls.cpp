// User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        if(m==1 && n==1 ){
            return 0;
            
        }
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(k+1,0)));
        queue<vector<int>>q;
        q.push({0,0,k});
        int steps=1;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto it=q.front();
                q.pop();
                
                int i=it[0];
                int j=it[1];
                int w=it[2];
                vis[i][j][w]=1;
                for(int x=0;x<4;x++){
                    int r=i+dx[x];
                    int c=j+ dy[x];
                    int new_k=w;
                    if(r>=0 && r<n && c>=0 && c<m){
                        if(mat[r][c]==0 && !vis[r][c][new_k]){
                            if(r==n-1 && c==m-1) return steps;
                            q.push({r,c,new_k});
                            vis[r][c][new_k]=1;
                        }
                        else if(mat[r][c]==1 && new_k>=1 && !vis[r][c][new_k -1]){
                            if(r==n-1 && c==m-1) return steps;
                            q.push({r,c,new_k-1});
                            vis[r][c][new_k-1]=1;
                        }
                    }
                }
            }
            steps++;
            
            
        }
        return -1;
    }
};