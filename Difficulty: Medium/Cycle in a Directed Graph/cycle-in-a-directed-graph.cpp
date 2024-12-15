//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsvisited,
    vector<vector<int>> &adj){
        visited[node]=true;
        dfsvisited[node]=true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                if(dfs(neighbour,visited,dfsvisited,adj)){
                    return true;
                }
            }
            else{
                if(dfsvisited[neighbour]){
                    return true;
                }
            }
        }
        dfsvisited[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsvisited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,visited,dfsvisited,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends