class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> map;
        for(int num:nums){
            map[num]++;
            if(map[num]>1){
                return num;
            }
        }
        return -1;

        
    }
};