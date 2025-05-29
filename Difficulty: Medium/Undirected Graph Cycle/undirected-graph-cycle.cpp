class Solution {
  public:
    bool bfs(int src ,unordered_map<int,list<int>>&adj,vector<int>&vis ){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto neigh:adj[node]){
                if(!vis[neigh]){
                    vis[neigh]=1;
                    q.push({neigh,node});
                }
                else if(neigh!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,list<int>>adj;
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(i,adj,vis)==true){
                    return true;
                }
            }
        }
        return false;
    }
};