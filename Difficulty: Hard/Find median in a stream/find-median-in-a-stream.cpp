class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        int n=arr.size();
        vector<double>ans;
        for(int i=0;i<n;i++){
            if(maxHeap.size()==0){
                maxHeap.push(arr[i]);
            }
            else if(maxHeap.size()>minHeap.size()){
                if(maxHeap.top()> arr[i]){
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(arr[i]);
                }
                else{
                    minHeap.push(arr[i]);
                }
            }
            else{
                if(minHeap.top()<arr[i]){
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(arr[i]);
                }
                else{
                    maxHeap.push(arr[i]);
                }
                
            }
            
            if(maxHeap.size()==minHeap.size()){
                ans.push_back((maxHeap.top() + minHeap.top())/2.0);
            }
            else{
                ans.push_back(maxHeap.top()/1.0);
            }
        }
        return ans;
    }
};
