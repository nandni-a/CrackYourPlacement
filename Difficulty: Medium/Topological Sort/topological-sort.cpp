class Solution {
  public:
    void dfs(int node,stack<int>&st , vector<int>&vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,st,vis,adj);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        // code here
        stack<int>st;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,st,vis,adj);
            }
        }
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};