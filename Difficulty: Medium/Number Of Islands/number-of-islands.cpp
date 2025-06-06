// User function Template for C++
class Disjoint {
public:
    vector<int>par,sz;
    Disjoint(int n){
        par.resize(n+1);
        sz.resize(n+1,1);
        for(int i=0;i<=n;i++) par[i]=i;
    }
    int findpar(int x){
        if(par[x]==x) return x;
        return par[x]=findpar(par[x]);
    }
    void Union(int x,int y){
        int xp=findpar(x),yp=findpar(y);
        if(xp==yp) return;
        if(sz[xp]>sz[yp]){
            sz[xp]+=sz[yp];
            par[yp]=xp;
        }
        else{
            sz[yp]+=sz[xp];
            par[xp]=yp;
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        Disjoint ds(n*m);
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        vector<int>ans;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            for(int i=0;i<4;i++){
                int nr=row+dx[i];
                int nc=col+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int node= row*m + col;
                    int adjNode=nr*m + nc;
                    if(vis[nr][nc]==1){
                        if(ds.findpar(node)!=ds.findpar(adjNode)){
                            cnt--;
                            ds.Union(node,adjNode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
            
        }
        
        return ans;
    }
};
