// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        // Code Here
        int ans=INT_MAX;
        int low=0,high=nums.size()-1;
        int index=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[low]<=nums[high]){
                if(nums[low]<ans){
                    index=low;
                    ans=nums[low];
                }
                break;
            }
            if(nums[mid]>=nums[low]){
                if(nums[low]<ans){
                    index=low;
                    ans=nums[low];
                }
                low=mid+1;
            }
            else{
                if(nums[mid]<ans){
                    index=mid;
                    ans=nums[mid];
                }
                high=mid-1;
            }
        }
        return index;
    }
};
