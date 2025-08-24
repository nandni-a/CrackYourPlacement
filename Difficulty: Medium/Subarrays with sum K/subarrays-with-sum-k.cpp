class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>prefix;
        int ans=0;
        int curr=0;
        for(int i=0;i<arr.size();i++){
            curr+= arr[i];
            if(curr==k) ans++;
            if(prefix.find(curr-k)!=prefix.end()){
                ans+= prefix[curr-k];
            }
            prefix[curr]++;
        }
        return ans;
    }
};