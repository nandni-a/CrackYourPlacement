// User function Template for C++

class Solution {
  public:
  
    bool dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsvisited,
         vector<int> adj[], int check[]) {
    visited[node] = true;
    dfsvisited[node] = true;
    check[node] = 0;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (dfs(neighbour, visited, dfsvisited, adj, check)) {
                return true;
            }
        } else {
            if (dfsvisited[neighbour]) {
                return true;
            }
        }
    }

    check[node] = 1;
    dfsvisited[node] = false;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;
    vector<int> safe;
    int check[V] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, dfsvisited, adj, check);
        }
    }

    for (int i = 0; i < V; i++) {
        if (check[i] == 1) {
            safe.push_back(i);
        }
    }

    return safe;
}
};
