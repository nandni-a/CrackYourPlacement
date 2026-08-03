class Solution {
  public:
    int timer=0;
    void dfs(int node,int par,vector<int>&tin,vector<int>&low,vector<int>&vis,unordered_map<int,vector<int>>&adj,
            vector<int>&mark){
                vis[node]=1;
                tin[node]=low[node]=timer;
                timer++;
                int child=0;
                for(auto it:adj[node]){
                    if(it==par) continue;
                    if(!vis[it]){
                        dfs(it,node,tin,low,vis,adj,mark);
                        low[node]=min(low[node],low[it]);
                        if(low[it]>=tin[node] && par!=-1){
                            mark[node]=1;
                        }
                        child++;
                    }
                    else{
                        low[node]=min(low[node],tin[it]);
                    }
                }
                if(child>1 && par==-1){
                    mark[node]=1;
                }
            }
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
        // code here
        vector<int>vis(n,0);
        vector<int>tin(n,0);
        vector<int>low(n,0);
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>mark(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,tin,low,vis,adj,mark);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0) return {-1};
        return ans;
        
    }
};