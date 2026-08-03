class DSU{
    vector<int>size,par;
    public:
    DSU(int n){
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }
    int findUpar(int node){
        if(node==par[node]){
            return node;
        }
        return par[node]=findUpar(par[node]);
    }
    void unionbysize(int u,int v){
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            par[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            par[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DSU ds(n*m);
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        vector<int>ans;
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
                
            }
            vis[row][col]=1;
            cnt++;
            int dr[]={-1,1,0,0};
            int dc[]={0,0,1,-1};
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==1){
                    int node=row*m + col;
                    int adjNode= nr*m + nc;
                    if(ds.findUpar(node)!=ds.findUpar(adjNode)){
                        cnt--;
                        ds.unionbysize(node,adjNode);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
