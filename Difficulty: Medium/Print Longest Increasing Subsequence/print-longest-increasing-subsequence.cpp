class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        // Code here
        int n=nums.size();
        vector<int>dp(n,1),hash(n);
        int maxi=0;
        int last=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]> nums[prev] && 1+ dp[prev] > dp[i]){
                    dp[i]= 1+ dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }

        }
        vector<int> lis;
        lis.push_back(nums[last]);
        while (hash[last] != last) {
            last = hash[last];
            lis.push_back(nums[last]);
        }

        reverse(lis.begin(), lis.end());
        return lis;
        
    }
};