class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int cnt=0;
        int presum=0;
        map[0]=1;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            cnt+=map[presum-k];
            map[presum]++;
            
            
        }
        return cnt;
        
    }
};