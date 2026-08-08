class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for(int a : arr){
            mp[a]++;
            
            if(mp[a]==2) ans.push_back(a);
        }
        
        return ans;
    }
};