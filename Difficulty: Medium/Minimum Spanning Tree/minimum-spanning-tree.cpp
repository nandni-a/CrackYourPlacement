//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> key(V);
        vector<bool>mst(V);
        vector<int> parent(V);
        
        for(int i=0;i<V;i++){
            key[i]=INT_MAX;
            mst[i]=false;
            parent[i]=-1;
            
        }
        key[0]=0;
        parent[0]=-1;
        for(int i=0;i<V-1;i++){
            int mini=INT_MAX;
            int u;
            for(int j=0;j<V;j++){
                if(mst[j]==false && key[j]<mini){
                    u=j;
                    mini=key[j];
                    
                }
            }
            mst[u]=true;
            for(auto neighbour:adj[u]){
                int v=neighbour[0];
                int w=neighbour[1];
                if(mst[v]==false && w<key[v]){
                    parent[v]=u;
                    key[v]=w;
                    
                }
            }
            
            
        }
        int ans=0;
        for(int i=0;i<V;i++){
            ans+=key[i];
        }
        return ans;
        
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends