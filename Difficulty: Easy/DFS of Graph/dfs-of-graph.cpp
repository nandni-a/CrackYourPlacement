class Solution {
  public:
    void solve(vector<vector<int>>& adj,vector<int>&ans,vector<bool>&vis,int node){
        vis[node]=true;
        ans.push_back(node);
        for(int i:adj[node]){
            if(!vis[i]){
                solve(adj,ans,vis,i);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        int n=adj.size();
        vector<bool>vis(n,false);
        solve(adj,ans,vis,0);
        return ans;
    }
};