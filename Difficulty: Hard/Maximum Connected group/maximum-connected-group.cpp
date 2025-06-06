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
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        Disjoint ds(n*n);
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                for(int i=0;i<4;i++){
                    int nr=row+dx[i];
                    int nc=col+dy[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int nab=row*n + col;
                        int na=nr*n + nc;
                        ds.Union(nab,na);
                    }
                }
            }
        }
        int ans=0;
        
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                set<int>comp;
                for(int i=0;i<4;i++){
                    int nr=row+dx[i];
                    int nc=col+dy[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int na=nr*n + nc;
                        comp.insert(ds.findpar(na));
                    }
                }
                int size=1;
                for(auto it:comp){
                    size+=ds.sz[it];
                }
                ans=max(ans,size);
            }
        }
        for(int i=0;i<n*n;i++){
            ans=max(ans,ds.sz[ds.findpar(i)]);
        }
        return ans;
        
        
    }
};
