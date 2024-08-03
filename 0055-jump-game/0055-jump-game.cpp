class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxDistance=0;
        int target=nums.size()-1;
        for(int i=0;i<nums.size() && i<=maxDistance;i++){
            maxDistance=max(nums[i]+i,maxDistance);
        }
        return maxDistance >=target;

    }
};