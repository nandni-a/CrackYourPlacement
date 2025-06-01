class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> parent(n+1);
        vector<int> dis(n+1, INT_MAX);
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        
        dis[1] = 0;
        
        set<pair<int, int>> st;
        st.insert({0, 1});
        
        while (!st.empty()) {
            auto it = *(st.begin());
            int currDis = it.first;
            int node = it.second;
            st.erase(it);
            
            for (auto& itr : adj[node]) {
                int adjNode = itr.first;
                int cost = itr.second;
                
                if (currDis + cost < dis[adjNode]) {
                    if (dis[adjNode] != INT_MAX) {
                        st.erase({dis[adjNode], adjNode});
                    }
                    
                    dis[adjNode] = currDis + cost;
                    parent[adjNode] = node;
                    st.insert({dis[adjNode], adjNode});
                }
            }
        }
        
        if (dis[n] == INT_MAX) return {-1};
        
        vector<int> res;
        int curr = n;
        while (parent[curr] != curr) {
            res.push_back(curr);
            curr = parent[curr];
        }
        res.push_back(1);
        res.push_back(dis[n]);
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};