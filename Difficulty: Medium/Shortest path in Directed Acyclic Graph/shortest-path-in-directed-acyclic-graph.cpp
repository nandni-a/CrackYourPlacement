class Solution {
  public:
    void topo(int node,vector<int>&vis,unordered_map<int,list<pair<int,int>>>&adj,stack<int>&st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first]){
                topo(it.first,vis,adj,st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<E;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topo(i,vis,adj,st);
            }
        }
        vector<int>dist(V,1e9);
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it:adj[node]){
                int v=it.first;
                int d=it.second;
                if(dist[node]+d < dist[v]){
                    dist[v]=dist[node]+d;
                }
            }
        }
        for(int i=0;i<V;i++){
                if(dist[i]==1e9) dist[i]=-1;
            }
        return dist;
        
    }
};
