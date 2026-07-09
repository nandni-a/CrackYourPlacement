class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum<0){
                sum=0;
            }
            sum+=arr[i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};