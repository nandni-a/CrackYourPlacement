// User function Template for C++

class Solution {
  public:
    int minThrow(int n, int arr[]) {
        // code here
        unordered_map<int,int>adj;
        for(int i=1;i<2*n;i+=2){
            adj[arr[i-1]]=arr[i];
        }
        queue<pair<int,int>>q;
        vector<int>vis(31,0);
        vis[1]=1;
        q.push({1,0});
        while(!q.empty()){
           
            int size=q.size();
            for(int i=0;i<size;i++){
                int node=q.front().first;
                int step=q.front().second;
                q.pop();
                for(int dice=1;dice<=6 && (node+dice) <=30 ; dice++){
                    int newNode= node+ dice;
                    if(adj.count(newNode)){
                        newNode=adj[newNode];
                    }
                    if(!vis[newNode]){
                        if(newNode==30) return step+1;
                        vis[newNode]=1;
                        q.push({newNode,step+1});
                    }
                    
                }
            }
            
        }
        return -1;
    }
};