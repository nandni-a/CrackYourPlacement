class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int sum=0;
        int maxSum=INT_MIN;
        int maxi=arr[0];
        for(int i=1;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
        }
        if(maxi<0) return maxi;
        for(int i=0;i<arr.size();i++){
            sum+= arr[i];
            if(sum<0){
                sum=0;
            }
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};