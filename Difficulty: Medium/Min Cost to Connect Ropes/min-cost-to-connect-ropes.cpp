class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n=arr.size();
        int ans=0;
        priority_queue<int,vector<int>,greater<>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        while(pq.size()>1){
            int rope=pq.top();
            pq.pop();
            rope+=pq.top();
            pq.pop();
            ans+=rope;
            pq.push(rope);
        }
        return ans;
    }
};