// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<V;i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int w=it[2];
                if( dist[u]!=1e8 && dist[u]+w < dist[v]){
                    dist[v]=dist[u]+w;
                    
                }
            }
        }
        // nth relaxation
        for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int w=it[2];
                if( dist[u]!=1e8 && dist[u]+w < dist[v]){
                    return {-1};
                } 
        }
        
        return dist;
        
    }
};
