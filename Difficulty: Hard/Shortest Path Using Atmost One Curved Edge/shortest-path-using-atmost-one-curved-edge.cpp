// User function Template for C++

class Solution {
  public:
    vector<int>dijkstra(int src,int n,unordered_map<int, vector<pair<int,int>>>& adj){
        vector<int>dist(n+1,1e9);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            if(d>dist[node]) continue;
            for(auto [v,wt]:adj[node]){
                if(dist[v]>d+wt){
                    dist[v]=d+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
        
        
    }
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<pair<int,int>>>adj;
        vector<vector<int>>curved;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            int c=it[3];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            curved.push_back({u,v,c});
        }
        vector<int>A=dijkstra(a,n,adj);
        vector<int>B=dijkstra(b,n,adj);
        int ans=A[b];
        for(auto it:curved){
            int u=it[0];
            int v=it[1];
            int c=it[2];
            if(A[u]!=1e9 && B[v]!=1e9){
                ans=min(ans,A[u]+c+B[v]);
            }
            if(A[v]!=1e9 && B[u]!=1e9){
                ans=min(ans,A[v]+c+B[u]);
            }
        }
        return ans;
    }
};