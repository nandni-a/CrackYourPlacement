class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n=arr.size();
        int sum=0;
        int l=0,r=0;
        while(r<n){
            sum+=arr[r];
            while(sum > target && l<=r){
                sum-=arr[l];
                l++;
            }
            if(sum==target){
                return {l+1,r+1};
            }
            r++;
        }
        return {-1};
    }
};