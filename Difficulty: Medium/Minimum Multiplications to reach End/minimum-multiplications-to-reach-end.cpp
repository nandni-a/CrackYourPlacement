// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        vector<int> countstep(100000,INT_MAX);
        q.push({start,0});
        while(!q.empty()){
            int node= q.front().first;
            int step=q.front().second;
            q.pop();
            
            if(node==end) return step;
            for(int i=0;i<arr.size();i++){
                int newNode=(arr[i]*node)%100000;
                if(step+1<countstep[newNode]){
                    countstep[newNode]=step+1;
                    q.push({newNode,countstep[newNode]});
                }
            }
        }
        return -1;
    }
};
