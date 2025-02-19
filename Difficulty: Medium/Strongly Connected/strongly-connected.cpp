//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Position this line where user code will be pasted.
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void GetTopologicalOrderDFS(int Node,vector<int> &visit,vector<vector<int>> &AdjList,stack<int> &st){
        visit[Node]=1;

        for(auto &AdjNode:AdjList[Node]){
            if(!visit[AdjNode]){
                GetTopologicalOrderDFS(AdjNode,visit,AdjList,st);
            }
        }
        st.push(Node);
    }
    void HelperDFS(int Node,vector<vector<int>> &ReversedAdjList,vector<int> &visit,vector<int> &CurrentSCC){
        visit[Node]=1;
        CurrentSCC.push_back(Node);

        for(auto &AdjNode:ReversedAdjList[Node]){
            if(!visit[AdjNode]){
                HelperDFS(AdjNode,ReversedAdjList,visit,CurrentSCC);
            }
        }
    }
    int GetCountOfSCC(vector<vector<int>> &AdjList){
        int V=AdjList.size();
        vector<int> visit(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!visit[i]){
                GetTopologicalOrderDFS(i,visit,AdjList,st);
            }
        }
        
        vector<vector<int>> ReversedAdjList(V);
        for(int i=0;i<V;i++){
            for(auto AdjNode:AdjList[i]){
                ReversedAdjList[AdjNode].push_back(i);
            }
        }
        
        visit.assign(V,0);
        vector<vector<int>> answer;
        vector<int> CurrentSCC;
        int CountSCC=0;
       
        while(!st.empty()){
            int Node=st.top();
            st.pop();
            if(!visit[Node]){
                HelperDFS(Node,ReversedAdjList,visit,CurrentSCC);
                
                answer.push_back(CurrentSCC);
                CountSCC++;
                
                CurrentSCC.clear();
            }
        }
        
        return CountSCC;
    }
    int kosaraju(vector<vector<int>> &adj) {
        return GetCountOfSCC(adj);
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
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends