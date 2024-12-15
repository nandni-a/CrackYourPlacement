//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node,int parent,vector<bool> &visited,vector<vector<int>>& adj){
        visited[node]=true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                if(dfs(neighbour,node,visited,adj)){
                    return true;
                }
            }
            else if(neighbour!=parent){
                return true;
                
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<bool> visited(v,false);
        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(dfs(i,-1,visited,adj)){
                    return true;
                }
            }
        }
        return false;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends