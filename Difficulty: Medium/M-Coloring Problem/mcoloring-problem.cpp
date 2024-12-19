//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isValid(unordered_map<int,list<int>> &map, int node,int i,vector<int>& colors){
        for(int j:map[node]){
            if(colors[j]==i){
                return false;
            }
        }
        return true;
    }
    bool solve(int v , int m , unordered_map<int,list<int>> &map, vector<int>& colors,int node){
        if(node==v){
            return true;
        }
        for(int i=1;i<=m;i++){
            if(isValid(map,node,i,colors)){
                colors[node]=i;
                if(solve(v,m,map,colors,node+1)){
                    return true;
                }
                colors[node]=0;
            }
        }
        return false;
        
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        unordered_map<int,list<int>> map;
        for(auto i:edges){
            int u=i.first;
            int v=i.second;
            map[u].push_back(v);
            map[v].push_back(u);
        }
        vector<int>colors(v,0);
        if(solve(v,m,map,colors,0)){
            return true;
        }
        return false;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends