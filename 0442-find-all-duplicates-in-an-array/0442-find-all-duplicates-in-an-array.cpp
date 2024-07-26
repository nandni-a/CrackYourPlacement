class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
            
        }
        for(auto pair:map){
            if(pair.second==2){
                ans.push_back(pair.first);
            }
            
        }
        

        return ans;

        
    }
};