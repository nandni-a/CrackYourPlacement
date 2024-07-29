class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
               
                if(j>i+1 && nums[j]==nums[j-1]){
                continue;
                }
                int c=j+1;
                int d=nums.size()-1;
        
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                while(c<d){
                    if((long long)nums[c]+(long long)nums[d]==newTarget){
                    res.push_back({nums[i],nums[j],nums[c],nums[d]});
                    while (c < d && nums[c] == nums[c + 1]) c++;
                    while (c < d && nums[d] == nums[d - 1]) d--;

                    c++;
                    d--;

                    }
                    else if((long long)nums[c]+(long long)nums[d]>newTarget){
                        d--;

                    }
                    else{
                        c++;

                    }
                }
                

            }
        }
        return res;
        
    }
};