class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int sum=0;
        vector<int>vist(V,0);
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            if(vist[node]==1) continue;
            vist[node]=1;
            sum+=wt;
            
            for(auto i:adj[node]){
                int adjNode=i[0];
                int adjW=i[1];
                if(!vist[adjNode]){
                    pq.push({adjW,adjNode});
                }
            }
        }
        return sum;
    }
};