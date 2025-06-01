class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n=adj.size();
        vector<int>dist(n,INT_MAX);
        queue<int>q;
        dist[src]=0;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            
            q.pop();
            for(auto it:adj[node]){
                if(dist[it] > dist[node]+1){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};