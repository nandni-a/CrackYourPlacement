class Solution {
  public:
    int longestSubarray(vector<int>& a, int k) {
        // code here
        map<long long ,int > mp;
        mp[0]=-1;
        long long sum=0;
        int ans=0;
    
        for(int i=0;i<a.size();i++){
            sum+=a[i];
            
            long long rem=sum-k;
            if(mp.find(rem)!=mp.end()){
                int len = i-mp[rem];
                ans=max(ans,len);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
                
        }
        return ans;
        
    }
};