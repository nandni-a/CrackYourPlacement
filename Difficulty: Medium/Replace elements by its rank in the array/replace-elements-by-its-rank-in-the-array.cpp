// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<N;i++){
            pq.push({arr[i],i});
        }
        int i=0;
        int prev=-1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if(it.first==prev){
                arr[it.second]=i;
            }
            else{
                arr[it.second]=++i;
            }
            prev=it.first;
        }
        return arr;
        
    }
};
