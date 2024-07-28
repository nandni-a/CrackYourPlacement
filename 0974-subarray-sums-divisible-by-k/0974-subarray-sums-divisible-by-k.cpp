class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        int presum=0;
        unordered_map<int,int>map;
        map[0]=1;
        for(int i=0;i<nums.size();i++){
            presum=(presum+(nums[i]%k)+k)%k;
            count+=map[presum];
            map[presum]++;
            
        }
        return count;
        
        
    }
};