class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int l=0;
        int r=n-1;
        while(l<r){
            if(arr[l]+arr[r]==target){
                return true;
            }
            else if(arr[l]+arr[r]>target){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
};