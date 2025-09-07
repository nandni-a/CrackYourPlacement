class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int>pq(arr.begin(),arr.end());
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};