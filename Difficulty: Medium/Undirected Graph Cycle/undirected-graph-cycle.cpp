class Solution {
  public:
    bool bfs(unordered_map<int,list<int>>&adj,int src,vector<int>&vis){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]!=1 ){
                    vis[it]=1;
                    q.push({it,node});
                    
                    
                }
                else if(it!=par){
                    return true;
                }
            }
        }
        return false;
        
        
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,list<int>>adj;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(bfs(adj,i,vis)) return true;
            }
        }
        return false;
    }
};